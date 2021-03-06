/*
    Crystal Space 3D engine
    Copyright (C) 1998-2001 by Jorrit Tyberghein
                  2004 by Marten Svanfeldt

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public
    License along with this library; if not, write to the Free
    Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#ifndef __CS_IENGINE_SECTOR_H__
#define __CS_IENGINE_SECTOR_H__

/**\file
 * Sector
 */
/**
 * \addtogroup engine3d
 * @{ */

#include "ivideo/rendermesh.h"

#include "csutil/cscolor.h"
#include "csutil/scf.h"
#include "csutil/set.h"
#include "csgeom/vector3.h"
#include "csgeom/aabbtree.h"

#include "iutil/threadmanager.h"

struct iMeshWrapper;
struct iMeshGenerator;
struct iMeshList;
struct iLightList;
struct iLight;
struct iPortal;
struct iVisibilityCuller;
struct iMovable;

struct iObject;

struct iRenderView;
struct iSector;
struct iDocumentNode;

struct iShaderVariableContext;

class csBox3;
class csRenderMeshList;
class csReversibleTransform;
class csVector3;

/// Modes for per-sector fog
enum csFogMode
{
  /// Fog is disabled.
  CS_FOG_MODE_NONE = 0,
  /**
   * Combination of linear fog and &ldquo;CrystalSpace&rdquo; fog.
   * This computes a linear fog for the sector: there is no fog until the
   * distance csFog::start, and it will linearly increase until it's fully
   * opaque at the distance csFog::end. (For a distance \em d, the fog function
   * is <em>1 - ((e - d)/(e - s))</em>.
   * 
   * There's also the specialty that the
   * fog is cut off (fully transparent) at the distance csFog::limit if that
   * distance is greated than the end distance:
   * 
   * \em And this computed linear fog is modulated with the sector fog value
   * from CS_FOG_MODE_CRYSTALSPACE.
   */
  CS_FOG_MODE_LINEAR_CRYSTALSPACE,
  /**
   * &ldquo;CrystalSpace&rdquo; fog.
   * This fog has the special property to be correct across portals, even if
   * the sectors have different fog densities (or colors).
   * 
   * The basis for this fog mode is an exponential fog, the fog function for a
   * distance \em d is <em>1 - exp(-(d-0.1)*density*7)</em>.
   * The distance is either the distance from the viewer, or, if portals are
   * involved, the distance from the portal.
   */
  CS_FOG_MODE_CRYSTALSPACE,
  /**
   * Exponential fog.
   * The fog function for a distance \em d is <em>1 - exp(-d*density)</em>.
   * The distance is the distance from the viewer.
   * 
   * Note this fog will look wrong if viewed through a portal.
   */
  CS_FOG_MODE_EXP,
  /**
   * Exponential fog.
   * The fog function for a distance \em d is <em>1 - exp(-(d*density)^2)</em>.
   * The distance is the distance from the viewer.
   * 
   * Note this fog will look wrong if viewed through a portal.
   */
  CS_FOG_MODE_EXP2,
  /// Alternative name for CS_FOG_MODE_LINEAR_CRYSTALSPACE
  CS_FOG_MODE_LINEAR = CS_FOG_MODE_LINEAR_CRYSTALSPACE
};

/**
 * Sector fog structure.
 */
struct csFog
{
  /**
   * Density (for #CS_FOG_MODE_LINEAR_CRYSTALSPACE, #CS_FOG_MODE_EXP,
   * #CS_FOG_MODE_EXP2, #CS_FOG_MODE_CRYSTALSPACE)
   */
  float density;
  /// Color
  csColor4 color;
  /// Fog fade start distance (for #CS_FOG_MODE_LINEAR).
  float start;
  /// Fog fade end distance (for #CS_FOG_MODE_LINEAR).
  float end;
  /// The limit after which the fog is no longer shown (for rings of fog) (for #CS_FOG_MODE_LINEAR).
  float limit;
  /// Fog mode.
  csFogMode mode;

  csFog() : density (0), color (0, 0, 0, 1.0f), start (0), end (0), limit (0),
    mode (CS_FOG_MODE_NONE) {}
};

/**
 * Set a callback which is called when this sector is traversed.
 * The given context will be either an instance of iRenderView
 * or else 0.
 *
 * This callback is used by:
 * - iSector
 */
struct iSectorCallback : public virtual iBase
{
  SCF_INTERFACE (iSectorCallback, 0, 0, 1);

  /**
   * Sector will be traversed. It is safe to delete this callback
   * in this function.
   */
  virtual void Traverse (iSector* sector, iBase* context) = 0;
};

/**
 * Set a callback which is called when a mesh is added or removed
 * from this sector.
 *
 * This callback is used by:
 * - iSector
 */
struct iSectorMeshCallback : public virtual iBase
{
  SCF_INTERFACE (iSectorMeshCallback, 0, 0, 1);

  /**
   * New mesh. Note that this is also called if the mesh is added as child
   * of another mesh that is in the sector.
   */
  virtual void NewMesh (iSector* sector, iMeshWrapper* mesh) = 0;

  /**
   * Remove mesh.
   */
  virtual void RemoveMesh (iSector* sector, iMeshWrapper* mesh) = 0;
};

/**
 * A callback that is fired whenever a light is visible.
 *
 * This callback is used by:
 * - iSector
 */
struct iLightVisibleCallback : public virtual iBase
{
  SCF_INTERFACE (iLightVisibleCallback, 0, 0, 1);

  /// The light is visible.
  virtual void LightVisible (iSector* sector, iLight* light) = 0;
};

/**
 * Return structure for the iSector::HitBeam() and iSector::HitBeamPortals() routines.
 * \sa csHitBeamResult CS::Physics::Bullet::HitBeamResult
 */
struct csSectorHitBeamResult
{
  /// The resulting mesh that was hit, or 0 if no mesh was hit.
  iMeshWrapper* mesh;

  /// Intersection point in world space.
  csVector3 isect;

  /// The polygon/triangle index that was hit.
  int polygon_idx;

  /**
   * The final sector for the end point.
   * Only for iSector::HitBeamPortals().
   */
  iSector* final_sector;
};

/**
 * Container for render meshes for one mesh wrapper
 */
struct csSectorVisibleRenderMeshes
{
  /// The mesh wrapper which is the source of the render meshes
  iMeshWrapper* imesh;
  /// Number of render meshes
  int num;
  /// Render meshes
  csRenderMesh** rmeshes;
};

/**
 * The iSector interface is used to work with "sectors". A "sector"
 * is an empty region of space that can contain other objects (mesh
 * objects). A sector itself does not represent geometry but only
 * contains other geometry. A sector does contain lights though.
 * The sector is the basic building block for any Crystal Space level.
 * A level can be made from one or more sectors. Using the thing mesh
 * object one can use portals to connect multiple sectors.
 *
 * Main creators of instances implementing this interface:
 * - iEngine::CreateSector()
 *
 * Main ways to get pointers to this interface:
 * - iEngine::FindSector()
 * - iSectorList::Get()
 * - iSectorList::FindByName()
 * - iLoaderContext::FindSector()
 * - iPortal::GetSector()
 * - iCamera::GetSector()
 *
 * Main users of this interface:
 * - iEngine
 */
struct iSector : public virtual iBase
{
  SCF_INTERFACE(iSector,5,0,0);
  /// Get the iObject for this sector.
  virtual iObject *QueryObject () = 0;

  /**\name Mesh handling
   * @{ */
  /// Get the list of meshes in this sector.
  virtual iMeshList* GetMeshes () = 0;

  /**
   * Get a set of visible meshes for given camera. These will be cached for
   * a given frame and camera, but if the cached result isn't enough it will
   * be reculled. The returned pointer is valid as long as the sector exists
   * (the sector will delete it)
   */
  virtual csRenderMeshList* GetVisibleMeshes (iRenderView *) = 0;

  /**
   * Get the set of meshes containing portals that leave from this sector.
   * Note that portals are uni-directional. The portals represented
   * by this list are portals that are on some mesh object that is
   * actually located in this sector.
   */
  virtual const csSet<csPtrKey<iMeshWrapper> >& GetPortalMeshes () const = 0;

  /**
   * Unlink all mesh objects from this sector. This will not remove
   * the mesh objects but simply unlink them so that they are no longer
   * part of this sector. This happens automatically when the sector
   * is removed but you can force it by calling this function here.
   */
  virtual void UnlinkObjects () = 0;

  /**
   * Add a mesh callback. This will call IncRef() on the callback
   * So make sure you call DecRef() to release your own reference.
   */
  virtual void AddSectorMeshCallback (iSectorMeshCallback* cb) = 0;

  /**
   * Remove a mesh callback.
   */
  virtual void RemoveSectorMeshCallback (iSectorMeshCallback* cb) = 0;
  /** @} */

  /**\name Drawing related
   * @{ */
  /**
   * Prepare the sector to draw.
   * Must be called before any rendermesh is requested.
   */
  virtual void PrepareDraw (iRenderView* rview) = 0;

  /**
   * Get the current draw recursion level.
   */
  virtual int GetRecLevel () const = 0;

  /**
   * Add one draw recursion level.
   */
  virtual void IncRecLevel () = 0;

  /**
   * Remove one draw recursion level.
   */
  virtual void DecRecLevel () = 0;
  /** @} */

  /**\name Mesh generator handling
   * @{ */
  /**
   * Create a mesh generator.
   */
  virtual iMeshGenerator* CreateMeshGenerator (const char* name) = 0;

  /**
   * Get the number of mesh generators.
   */
  virtual size_t GetMeshGeneratorCount () const = 0;

  /**
   * Get the specific mesh generator.
   */
  virtual iMeshGenerator* GetMeshGenerator (size_t idx) = 0;

  /**
   * Get the specific mesh generator by name.
   */
  virtual iMeshGenerator* GetMeshGeneratorByName (const char* name) = 0;

  /**
   * Remove a mesh generator.
   */
  virtual void RemoveMeshGenerator (size_t idx) = 0;

  /**
   * Remove a mesh generator.
   */
  virtual void RemoveMeshGenerator (const char* name) = 0;

  /**
   * Remove all mesh generators.
   */
  virtual void RemoveMeshGenerators () = 0;
  /** @} */

  /**\name Fog handling
   * @{ */
  /// Has this sector fog?
  virtual bool HasFog () const = 0;
  /// Return the fog structure (even if fog is disabled)
  virtual const csFog& GetFog () const = 0;
  /// Fill the fog structure with the given values
  virtual void SetFog (float density, const csColor& color) = 0;
  /// Set a fog structure directly.
  virtual void SetFog (const csFog& fog) = 0;
  /// Disable fog in this sector
  virtual void DisableFog () = 0;
  /** @} */

  /**\name Light handling
   * @{ */
  /**
   * Get the list of static and pseudo-dynamic lights in this sector.
   */
  virtual iLightList* GetLights () = 0;

  /**
   * Add a light to the light lists in the main thread.
   */
  THREADED_INTERFACE1(AddLight, csRef<iLight> light);

  /**
   * Sets dynamic ambient light this sector. This works in addition
   * to the dynamic light you can specify for every object.
   */
  virtual void SetDynamicAmbientLight (const csColor& color) = 0;

  /// Get the last set dynamic ambient light for this sector.
  virtual csColor GetDynamicAmbientLight () const = 0;

  /**
   * Get the version number of the dynamic ambient color. This
   * number is increased whenever dynamic ambient changes.
   */
  virtual uint GetDynamicAmbientVersion () const = 0;
  /** @} */

  /**\name Visculling
   * @{ */
  /**
   * Calculate the bounding box of all objects in this sector.
   * This function is not very efficient as it will traverse all objects
   * in the sector one by one and compute a bounding box from that.
   */
  virtual void CalculateSectorBBox (csBox3& bbox,
    bool do_meshes) const = 0;

  /**
   * Use the specified plugin as the visibility culler for
   * this sector.
   * Pass NULL as plugin name to set the default culler.
   * Returns false if the culler could not be loaded for some
   * reason.
   * The optional culler parameters will be given to the new
   * visibility culler.
   */
  virtual bool SetVisibilityCullerPlugin (const char* name,
  	iDocumentNode* culler_params = 0) = 0;
  /**
   * Get the visibility culler that is used for this sector.
   * If there is no culler yet a culler of type 'crystalspace.culling.frustvis'
   * will be created and used for this sector.
   */
  virtual iVisibilityCuller* GetVisibilityCuller () = 0;

  /**
   * Follow a beam from start to end and return the first polygon that
   * is hit. This function correctly traverse portals and space warping
   * portals. Normally the sector you call this on should be the sector
   * containing the 'start' point. 'isect' will be the intersection point
   * if a polygon is returned. This function returns -1 if no polygon
   * was hit or the polygon index otherwise.
   * If 'bf' is set to true then backface culling will be used on the
   * set of triangles.
   * \sa csSectorHitBeamResult HitBeam() iMeshWrapper::HitBeam()
   * CS::Physics::Bullet::iDynamicSystem::HitBeam()
   */
  virtual csSectorHitBeamResult HitBeamPortals (const csVector3& start,
  	const csVector3& end, bool bf = false) = 0;

  /**
   * Follow a beam from start to end and return the first object
   * that is hit. In case it is a thing the polygon_idx field will be
   * filled with the indices of the polygon that was hit.
   * If polygon_idx is null then the polygon will not be filled in.
   * This function doesn't support portals.
   * If 'bf' is set to true then backface culling will be used on the
   * set of triangles. Note that in this case 'accurate' must be set to true
   * as well.
   * \sa csSectorHitBeamResult HitBeamPortals() iMeshWrapper::HitBeam()
   * CS::Physics::Bullet::iDynamicSystem::HitBeam()
   */
  virtual csSectorHitBeamResult HitBeam (const csVector3& start,
  	const csVector3& end, bool accurate = false, bool bf = false) = 0;

  /**
   * Follow a segment starting at this sector. If the segment intersects
   * with a polygon it will stop there unless the polygon is a portal in which
   * case it will recursively go to that sector (possibly applying warping
   * transformations) and continue there.<p>
   *
   * This routine will modify all the given parameters to reflect space warping.
   * These should be used as the new camera transformation when you decide to
   * really go to the new position.<p>
   *
   * This function returns the resulting sector, and \a new_position will be set
   * to the last position that you can go to before hitting a wall.<p>
   *
   * If \a only_portals is true then only portals will be checked. This
   * means that intersection with normal polygons is not checked. This
   * is a lot faster but it does mean that you need to use another
   * collision detection system to test with walls.
   *
   * \param t The transform to the start of the segment
   * \param new_position The end of the segment, in world coordinates
   * \param mirror Unused parameter...
   * \param only_portals Whether the collision has to be checked only with the portals, or also
   * with all meshes
   * \param crossed_portals The list where will be stored all portals that are crossed during
   * the following of this segment
   * \param portal_meshes The list where will be stored the portal container of all the portals
   * that are crossed during the following of this segment
   * \param firstIndex The starting index where the portals will be stored in the
   * \a crossed_portals and \a portal_meshes lists.
   * \param lastIndex The place where will be stored the index of the last portal crossed
   *
   * \warning The \a crossed_portals and \a portal_meshes arrays must be allocated to a
   * sufficient size
   * \warning The \a crossed_portals and \a portal_meshes arrays won't be filled with crossed
   * portals if \a lastIndex is not provided
   */
  virtual iSector* FollowSegment (csReversibleTransform& t,
      csVector3& new_position, bool& mirror, bool only_portals = false,
      iPortal** crossed_portals = 0, iMeshWrapper** portal_meshes = 0,
      int firstIndex = 0, int* lastIndex = 0) = 0;
  /** @} */

  /**\name Sector callbacks
   * @{ */
  /**
   * Set the sector callback. This will call IncRef() on the callback
   * So make sure you call DecRef() to release your own reference.
   */
  THREADED_INTERFACE1(SetSectorCallback, csRef<iSectorCallback> cb);

  /**
   * Remove a sector callback.
   */
  THREADED_INTERFACE1(RemoveSectorCallback, csRef<iSectorCallback> cb);

  /// Get the number of sector callbacks.
  virtual int GetSectorCallbackCount () const = 0;

  /// Get the specified sector callback.
  virtual iSectorCallback* GetSectorCallback (int idx) const = 0;
  /** @} */

  /**\name Light culling
   * @{ */
  /**
   * Set/reset culling objects for all lights in the sector.
   * This can be used for hardware accelerated lighting techniques that
   * want to know what lights (influence object) are visible for camera.
   * With this enabled every light will be registered to the culler of
   * this sector and a callback (see AddLightVisibleCallback) will be
   * called.
   */
  virtual void SetLightCulling (bool enable) = 0;
  /// Return true if light culling objects are enabled.
  virtual bool IsLightCullingEnabled () const = 0;
  /**
   * Add a callback that is called whenever a light is visible.
   * This only works if SetLightCulling() is enabled.
   */
  virtual void AddLightVisibleCallback (iLightVisibleCallback* cb) = 0;
  /**
   * Remove a light visible callback.
   */
  virtual void RemoveLightVisibleCallback (iLightVisibleCallback* cb) = 0;
  /** @} */

  /// Get the shader variable context for this sector.
  virtual iShaderVariableContext* GetSVContext() = 0;

  /**
   * This function precaches a sector by rendering one frame
   * with this sector visible. This will speed up later rendering.
   */
  virtual void PrecacheDraw () = 0;

  /**
   * Call all the sector callback functions
   */
  virtual void CallSectorCallbacks (iRenderView* rview) = 0;

  /**
   * Get the render meshes for a specific mesh wrapper. Also processes LOD.
   */
  virtual csSectorVisibleRenderMeshes* GetVisibleRenderMeshes (int& num,
    iMeshWrapper* mesh, iRenderView *rview, uint32 frustum_mask) = 0;

  /**
   * A new movable has been put in this sector. Make sure all is ok.
   * This function is normally not called by the user. It is called
   * automatically by the movable system.
   */
  virtual bool PrepareMovable (iMovable* movable) = 0;
};


/**
 * A list of sectors.
 *
 * Main ways to get pointers to this interface:
 *   - iEngine::GetSectors()
 *   - iMovable::GetSectors()
 *
 * Main users of this interface:
 *   - iEngine
 */
struct iSectorList : public virtual iBase
{
  SCF_INTERFACE(iSectorList, 2,0,0);
  /// Return the number of sectors in this list.
  virtual int GetCount () const = 0;

  /// Return the sector at the given index.
  virtual iSector *Get (int n) const = 0;

  /**
   * Add a sector.
   * \return The index of the newly added sector.
   */
  virtual int Add (iSector *obj) = 0;

  /**
   * Remove a sector.
   * \return True if the sector has been found and deleted, false otherwise.
   */
  virtual bool Remove (iSector *obj) = 0;

  /**
   * Remove the sector at the given index.
   * \return True if the given index was valid, false otherwise.
   */
  virtual bool Remove (int n) = 0;

  /// Remove all sectors.
  virtual void RemoveAll () = 0;

  /**
   * Find a sector and return its index.
   * \return The index of the sector, or csArrayItemNotFound if the sector was
   * not found
   */
  virtual int Find (iSector *obj) const = 0;

  /**
   * Find a sector by its name.
   * \return The sector with the given name, or 0 if the name was not found.
   */
  virtual iSector *FindByName (const char *Name) const = 0;
};


/**
 * An iterator to iterate over sectors. Some functions in CS
 * return this.
 *
 * Main creators of instances implementing this interface:
 * - iEngine::GetNearbySectors()
 */
struct iSectorIterator : public virtual iBase
{
  SCF_INTERFACE(iSectorIterator,2,0,0);
  /// Return true if there are more elements.
  virtual bool HasNext () const = 0;

  /**
   * Return the next sector in the list and increment the iterator. Return
   * 0 at the end.
   */
  virtual iSector* Next () = 0;

  /**
   * Get last position that was used from Fetch. This can be
   * different from 'pos' because of space warping.
   */
  virtual const csVector3& GetLastPosition () const = 0;

  /// Reset the iterator to the first element.
  virtual void Reset () = 0;
};

/** @} */

#endif // __CS_IENGINE_SECTOR_H__
