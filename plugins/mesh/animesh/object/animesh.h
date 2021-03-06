/*
  Copyright (C) 2008 by Marten Svanfeldt

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
  Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.3
*/

#ifndef __CS_ANIMESH_H__
#define __CS_ANIMESH_H__

#include "csgeom/box.h"
#include "csgfx/shadervarcontext.h"
#include "cstool/objmodel.h"
#include "cstool/rendermeshholder.h"
#include "csutil/dirtyaccessarray.h"
#include "csutil/flags.h"
#include "csutil/refarr.h"
#include "csutil/scf_implementation.h"
#include "iengine/movable.h"
#include "iengine/scenenode.h"
#include "iengine/material.h"
#include "imesh/animesh.h"
#include "imesh/object.h"
#include "iutil/comp.h"
#include "ivaria/decal.h"

#include "morphtarget.h"

CS_PLUGIN_NAMESPACE_BEGIN(Animesh)
{

  class FactorySubmesh;
  class FactorySocket;

  struct Subset
  {
    csArray<size_t> vertices;      // the vertices belonging to this subset
    size_t vertexCount;            // the number of vertices belonging to this subset
      
    Subset ()
    : vertexCount (0)
    {}
  };


  class AnimeshObjectType : 
    public scfImplementation2<AnimeshObjectType, 
                              iMeshObjectType, 
                              iComponent>
  {
  public:
    AnimeshObjectType (iBase* parent);

    //-- iMeshObjectType
    virtual csPtr<iMeshObjectFactory> NewFactory ();

    //-- iComponent
    virtual bool Initialize (iObjectRegistry*);

  private:
    iObjectRegistry* object_reg;
  };


  class AnimeshObjectFactory :
    public scfImplementationExt2<AnimeshObjectFactory,
                                 csObjectModel,
                                 CS::Mesh::iAnimatedMeshFactory,
                                 iMeshObjectFactory>
  {
  public:
    AnimeshObjectFactory (AnimeshObjectType* objType);

    //-- CS::Mesh::iAnimatedMeshFactory
    virtual CS::Mesh::iAnimatedMeshSubMeshFactory* CreateSubMesh (iRenderBuffer* indices,
      const char* name, bool visible);
    virtual CS::Mesh::iAnimatedMeshSubMeshFactory* CreateSubMesh (
      const csArray<iRenderBuffer*>& indices, 
      const csArray<csArray<unsigned int> >& boneIndices,
      const char* name,
      bool visible);
    virtual CS::Mesh::iAnimatedMeshSubMeshFactory* GetSubMesh (size_t index) const;
    virtual size_t FindSubMesh (const char* name) const;
    virtual size_t GetSubMeshCount () const;
    virtual void DeleteSubMesh (CS::Mesh::iAnimatedMeshSubMeshFactory* mesh);

    virtual uint GetVertexCount () const;

    virtual iRenderBuffer* GetVertices ();
    virtual bool SetVertices (iRenderBuffer* renderBuffer);
    virtual iRenderBuffer* GetTexCoords ();
    virtual bool SetTexCoords (iRenderBuffer* renderBuffer);
    virtual iRenderBuffer* GetNormals ();
    virtual bool SetNormals (iRenderBuffer* renderBuffer);
    virtual iRenderBuffer* GetTangents ();
    virtual bool SetTangents (iRenderBuffer* renderBuffer);
    virtual iRenderBuffer* GetBinormals ();
    virtual bool SetBinormals (iRenderBuffer* renderBuffer);
    virtual iRenderBuffer* GetColors ();
    virtual bool SetColors (iRenderBuffer* renderBuffer);

    virtual void Invalidate ();

    virtual void SetSkeletonFactory (CS::Animation::iSkeletonFactory* skeletonFactory);
    virtual CS::Animation::iSkeletonFactory* GetSkeletonFactory () const;
    virtual void SetBoneInfluencesPerVertex (uint num);
    virtual uint GetBoneInfluencesPerVertex () const;
    virtual CS::Mesh::AnimatedMeshBoneInfluence* GetBoneInfluences ();

    virtual CS::Mesh::iAnimatedMeshMorphTarget* CreateMorphTarget (const char* name);
    virtual CS::Mesh::iAnimatedMeshMorphTarget* GetMorphTarget (uint target);
    virtual uint GetMorphTargetCount () const;
    virtual void ClearMorphTargets ();
    virtual uint FindMorphTarget (const char* name) const;

    virtual void CreateSocket (CS::Animation::BoneID bone, 
      const csReversibleTransform& transform, const char* name);
    virtual size_t GetSocketCount () const;
    virtual CS::Mesh::iAnimatedMeshSocketFactory* GetSocket (size_t index) const;
    virtual uint FindSocket (const char* name) const;

    virtual void SetBoneBoundingBox (CS::Animation::BoneID bone, const csBox3& box); 
    virtual const csBox3& GetBoneBoundingBox (CS::Animation::BoneID bone) const; 

    virtual size_t AddSubset ();
    virtual void AddSubsetVertex (const size_t subset, const size_t vertexIndex);
    virtual size_t GetSubsetVertex (const size_t subset, const size_t vertexIndex) const;
    virtual size_t GetSubsetVertexCount (const size_t subset) const;
    virtual size_t GetSubsetCount () const;
    virtual void ClearSubsets ();

    //-- iMeshObjectFactory
    virtual csFlags& GetFlags ();

    virtual csPtr<iMeshObject> NewInstance ();

    virtual csPtr<iMeshObjectFactory> Clone ();

    virtual void HardTransform (const csReversibleTransform& t);
    virtual bool SupportsHardTransform () const;

    virtual void SetMeshFactoryWrapper (iMeshFactoryWrapper* logparent);
    virtual iMeshFactoryWrapper* GetMeshFactoryWrapper () const;

    virtual iMeshObjectType* GetMeshObjectType () const;

    virtual iObjectModel* GetObjectModel ();

    virtual bool SetMaterialWrapper (iMaterialWrapper* material);
    virtual iMaterialWrapper* GetMaterialWrapper () const;

    virtual void SetMixMode (uint mode);
    virtual uint GetMixMode () const;

    //-- iObjectModel
    virtual const csBox3& GetObjectBoundingBox ();
    virtual void SetObjectBoundingBox (const csBox3& bbox);
    virtual void GetRadius (float& radius, csVector3& center);

    //-- Private
    inline uint GetVertexCountP () const
    {
      return vertexCount;
    }

    void ComputeTangents ();

  private: 
    void UpdateBoundingBoxes ();

    void UpdateSubsets ();
    void RebuildMorphTargets ();

    // Main mesh factory properties
    csRef<AnimeshObjectType> objectType;
    iMeshFactoryWrapper* logParent;
    csRef<iMaterialWrapper> material;
    csFlags factoryFlags;
    uint mixMode;

    // Version of this factory
    unsigned int version;

    // Main data storage...
    uint vertexCount;
    csRef<iRenderBuffer> vertexBuffer;
    csRef<iRenderBuffer> texcoordBuffer;
    csRef<iRenderBuffer> normalBuffer;
    csRef<iRenderBuffer> tangentBuffer;
    csRef<iRenderBuffer> binormalBuffer;
    csRef<iRenderBuffer> colorBuffer;
    csDirtyAccessArray<CS::Mesh::AnimatedMeshBoneInfluence> boneInfluences;
    csRef<iRenderBuffer> masterBWBuffer;
    csRef<iRenderBuffer> boneWeightAndIndexBuffer[2];

    csRef<CS::Animation::iSkeletonFactory> skeletonFactory;

    // Submeshes
    csRefArray<FactorySubmesh> submeshes;

    csRefArray<MorphTarget> morphTargets;         // Morph targets without optimization
    csRefArray<MorphTarget> subsetMorphTargets;   // Optimized morph targets (e.i. without null offsets)
    csHash<uint, csString> morphTargetNames;

    // Sockets
    csRefArray<FactorySocket> sockets;

    // Whether or not the user has manually set any of the bone bounding boxes
    bool userBoneBBoxes;

    // Global bounding box of the whole mesh, and list of the bounding boxes
    // linked to each bones
    csBox3 globalBBox;
    csHash<csBox3, CS::Animation::BoneID> boneBBoxes;

    // Subsets
    csArray<Subset> subsets; 
    bool userSubsets;

    struct SubsetTargets
    {
      csArray<uint> morphTargets;   // the indices of the morph targets influencing this subset
      uint morphTargetCount;        // the number of morph targets influencing this subset

      SubsetTargets ()
      : morphTargetCount (0)
      {}
    };

    friend class AnimeshObject;
  };

  class FactorySubmesh : 
    public scfImplementation1<FactorySubmesh, 
                              CS::Mesh::iAnimatedMeshSubMeshFactory>
  {
  public:
    FactorySubmesh (const char* name)
      : scfImplementationType (this), material(0), name(name), visible (true),
	zbufMode (CS_ZBUF_USE)
    {}

    virtual iRenderBuffer* GetIndices (size_t set)
    {
      return indexBuffers[set];
    }

    virtual uint GetIndexSetCount () const
    {
      return (uint)indexBuffers.GetSize ();
    }

    virtual const csArray<unsigned int>& GetBoneIndices (size_t set)
    {
      static const csArray<unsigned int> noBI;
      if (boneMapping.GetSize () > 0)
      {
        return boneMapping[set].boneRemappingTable;
      }
      else
      {
        return noBI;
      }
    }

    csRefArray<iRenderBuffer> indexBuffers;
    csRefArray<csRenderBufferHolder> bufferHolders;

    // For every subpart(index buffer), hold:
    //  the "real" bone index to use for "virtual" bone index i
    // When using remappings, have these two RBs...
    struct RemappedBones
    {
      csArray<unsigned int> boneRemappingTable;
      csRef<iRenderBuffer> masterBWBuffer;
      csRef<iRenderBuffer> boneWeightAndIndexBuffer[2];
    };
    csArray<RemappedBones> boneMapping;
    
    csRef<iMaterialWrapper> material;

    /// Get the material
    virtual iMaterialWrapper* GetMaterial () const { return material; }

    /// Set the material, or 0 to use default.
    virtual void SetMaterial (iMaterialWrapper* m) { material = m; }
    
    csString name;

    /// Get the submesh name.
    virtual const char* GetName () const { return name.GetData(); }

    virtual void SetRendering (bool doRender)
      { visible = doRender; }
    virtual bool IsRendering () const
      { return visible; }
    virtual void SetRenderPriority (CS::Graphics::RenderPriority rp)
      { renderPriority = rp; }
    virtual CS::Graphics::RenderPriority GetRenderPriority () const
      { return renderPriority; }
    virtual void SetZBufMode (csZBufMode mode)
      { zbufMode = mode; }
    virtual csZBufMode GetZBufMode () const
      { return zbufMode; }
    virtual iShaderVariableContext* GetShaderVariableContext(size_t buffer) const
    {
      return svContexts[buffer];
    }

    bool visible;
    CS::Graphics::RenderPriority renderPriority;
    csZBufMode zbufMode;
    csRefArray<csShaderVariableContext> svContexts;
  };


  class FactorySocket :
    public scfImplementation1<FactorySocket,
                              CS::Mesh::iAnimatedMeshSocketFactory>
  {
  public:
    FactorySocket (AnimeshObjectFactory* factory, CS::Animation::BoneID bone, const char* name,
                   csReversibleTransform transform);

    //-- CS::Mesh::iAnimatedMeshSocketFactory
    virtual const char* GetName () const;
    virtual void SetName (const char*);
    virtual const csReversibleTransform& GetTransform () const;
    virtual void SetTransform (csReversibleTransform& tf);
    virtual CS::Animation::BoneID GetBone () const;
    virtual void SetBone (CS::Animation::BoneID bone);
    virtual CS::Mesh::iAnimatedMeshFactory* GetFactory ();

    AnimeshObjectFactory* factory;
    CS::Animation::BoneID bone;
    csString name;
    csReversibleTransform transform;        
  };


  class AnimeshObject :
    public scfImplementationExt2<AnimeshObject,
                                 csObjectModel,
                                 CS::Mesh::iAnimatedMesh,
                                 iMeshObject>, public iDecalAnimationControl
  {
  public:
    AnimeshObject (AnimeshObjectFactory* factory);

    //-- CS::Mesh::iAnimatedMesh
    virtual void SetSkeleton (CS::Animation::iSkeleton* skeleton);
    virtual CS::Animation::iSkeleton* GetSkeleton () const;

    virtual CS::Mesh::iAnimatedMeshSubMesh* GetSubMesh (size_t index) const;
    virtual size_t GetSubMeshCount () const;

    virtual void SetMorphTargetWeight (uint target, float weight);
    virtual float GetMorphTargetWeight (uint target) const;
    virtual void ClearMorphTargetWeights ();

    virtual size_t GetSocketCount () const;
    virtual CS::Mesh::iAnimatedMeshSocket* GetSocket (size_t index) const;

    virtual CS::Mesh::iAnimatedMeshFactory* GetAnimatedMeshFactory () const;
    virtual iRenderBufferAccessor* GetRenderBufferAccessor () const;

    virtual void SetBoneBoundingBox (CS::Animation::BoneID bone, const csBox3& box); 
    virtual const csBox3& GetBoneBoundingBox (CS::Animation::BoneID bone) const; 

    //-- iMeshObject
    virtual iMeshObjectFactory* GetFactory () const;

    virtual csFlags& GetFlags ();

    virtual csPtr<iMeshObject> Clone ();

    virtual CS::Graphics::RenderMesh** GetRenderMeshes (int& num, iRenderView* rview, 
      iMovable* movable, uint32 frustum_mask);

    virtual void SetVisibleCallback (iMeshObjectDrawCallback* cb);

    virtual iMeshObjectDrawCallback* GetVisibleCallback () const;

    virtual void NextFrame (csTicks current_time,const csVector3& pos,
      uint currentFrame);

    virtual void HardTransform (const csReversibleTransform& t);
    virtual bool SupportsHardTransform () const;

    virtual bool HitBeamBBoxes (const csVector3& start, const csVector3& end);
    virtual bool HitBeamOutline (const csVector3& start,
      const csVector3& end, csVector3& isect, float* pr);
    virtual bool HitBeamObject (const csVector3& start, const csVector3& end,
      csVector3& isect, float* pr, int* polygon_idx,
      iMaterialWrapper** material, bool bf);

    virtual void SetMeshWrapper (iMeshWrapper* logparent);
    virtual iMeshWrapper* GetMeshWrapper () const;

    virtual iObjectModel* GetObjectModel ();

    virtual bool SetColor (const csColor& color);
    virtual bool GetColor (csColor& color) const;

    virtual bool SetMaterialWrapper (iMaterialWrapper* material);
    virtual iMaterialWrapper* GetMaterialWrapper () const;

    virtual void SetMixMode (uint mode);
    virtual uint GetMixMode () const;

    virtual void PositionChild (iMeshObject* child,csTicks current_time);

    virtual void BuildDecal(const csVector3* pos, float decalRadius,
      iDecalBuilder* decalBuilder);

    virtual void UnsetObjectBoundingBox ();

    //-- iObjectModel
    virtual const csBox3& GetObjectBoundingBox ();
    virtual void SetObjectBoundingBox (const csBox3& bbox);
    virtual void GetRadius (float& radius, csVector3& center);

    //-- iRenderBufferAccessor
    void PreGetBuffer (csRenderBufferHolder* holder, 
      csRenderBufferName buffer);    

    //-- iDecalAnimationControl
    virtual void UpdateDecal (iDecalTemplate* decalTemplate,
			      size_t baseIndex,
			      csArray<size_t>& indices,
			      csRenderBuffer& vertices,
			      csRenderBuffer& normals);

  private:
    void SetupSubmeshes ();
    void SetupSockets ();
    void UpdateLocalBoneTransforms ();
    void UpdateSocketTransforms ();

    void SkinVertices ();
    void SkinNormals ();
    void SkinVerticesAndNormals ();
    void SkinTangentAndBinormal ();
    void SkinAll ();

    template<bool SkinVerts, bool SkinNormals, bool SkinTB>
    void Skin ();

    void MorphVertices ();

    void PreskinLF ();

    void UpdateBoundingBoxes ();

    class RenderBufferAccessor :
      public scfImplementation1<RenderBufferAccessor, 
                                iRenderBufferAccessor>
    {
    public:
      RenderBufferAccessor (AnimeshObject* meshObject)
        : scfImplementationType (this), meshObject (meshObject)
      {}

      void PreGetBuffer (csRenderBufferHolder* holder, 
        csRenderBufferName buffer)
      { meshObject->PreGetBuffer (holder, buffer); }
      
      AnimeshObject* meshObject;
    };
 
    class Submesh : 
      public scfImplementation1<Submesh, 
                                CS::Mesh::iAnimatedMeshSubMesh>
    {
    public:
      Submesh (AnimeshObject* meshObject, FactorySubmesh* factorySubmesh)
        : scfImplementationType (this), meshObject (meshObject),
        factorySubmesh (factorySubmesh), material(0), isRendering (factorySubmesh->visible)
      {}

      virtual CS::Mesh::iAnimatedMeshSubMeshFactory* GetFactorySubMesh ()
      {
        return factorySubmesh;
      }

      virtual void SetRendering (bool doRender)
      {
        isRendering = doRender;
      }

      virtual bool IsRendering () const
      {
        return isRendering;
      }

      virtual iShaderVariableContext* GetShaderVariableContext(size_t buffer) const
      {
        return svContexts[buffer];
      }

      virtual iMaterialWrapper* GetMaterial () const
      {
          return material;
      }

      virtual void SetMaterial (iMaterialWrapper* mat)
      {
          material = mat;
      }

      AnimeshObject* meshObject;
      FactorySubmesh* factorySubmesh;
      csRef<iMaterialWrapper> material;
      bool isRendering;

      csRefArray<csShaderVariableContext> svContexts;
      csRefArray<csRenderBufferHolder> bufferHolders;
      csRefArray<csShaderVariable> boneTransformArray;
    };

    class Socket : public scfImplementation1<Socket, 
                                             CS::Mesh::iAnimatedMeshSocket>
    {
    public:
      Socket (AnimeshObject* object, FactorySocket* factorySocket);

      //-- CS::Mesh::iAnimatedMeshSocket
      virtual const char* GetName () const;
      virtual CS::Mesh::iAnimatedMeshSocketFactory* GetFactory ();
      virtual const csReversibleTransform& GetTransform () const;
      virtual void SetTransform (csReversibleTransform& tf);
      virtual const csReversibleTransform GetFullTransform () const;     
      virtual CS::Animation::BoneID GetBone () const;
      virtual CS::Mesh::iAnimatedMesh* GetMesh () const;
      virtual iSceneNode* GetSceneNode () const;
      virtual void SetSceneNode (iSceneNode* sn);

      void UpdateSceneNode ();

      AnimeshObject* object;
      FactorySocket* factorySocket;
      CS::Animation::BoneID bone;
      csReversibleTransform transform;
      csReversibleTransform socketBoneTransform;
      iSceneNode* sceneNode;
    };

    AnimeshObjectFactory* factory;
    iMeshWrapper* logParent;
    csRef<iMaterialWrapper> material;
    uint mixMode;
    csFlags meshObjectFlags;

    // Last version of the factory
    unsigned int factoryVersion;

    csRef<CS::Animation::iSkeleton> skeleton;
    unsigned int skeletonVersion;
    bool animationInitialized;

    // Hold the bone transforms
    csRef<csShaderVariable> boneTransformArray;
    csRef<CS::Animation::AnimatedMeshState> lastSkeletonState;

    csRenderMeshHolder rmHolder;
    csDirtyAccessArray<CS::Graphics::RenderMesh*> renderMeshList;

    csRefArray<Submesh> submeshes;
    csRefArray<Socket> sockets;

    // Whether or not the user has manually set the global bounding box of the mesh
    bool userGlobalBBox;

    // Global bounding box of the whole mesh, and list of the bounding boxes
    // linked to each bones
    csBox3 globalBBox;
    csHash<csBox3, CS::Animation::BoneID> boneBBoxes;

    // Holder for skinned vertex buffers
    csRef<RenderBufferAccessor> bufferAccessor;
    csRef<iRenderBuffer> skinnedVertices;
    csRef<iRenderBuffer> skinnedNormals;
    csRef<iRenderBuffer> skinnedTangents;
    csRef<iRenderBuffer> skinnedBinormals;

    csRef<iRenderBuffer> postMorphVertices;

    csArray<float> morphTargetWeights;
    unsigned int morphVersion;
    bool morphStateChanged;

    // Version numbers for the skinning
    unsigned int skinVertexVersion, skinNormalVersion, skinTangentBinormalVersion;
    unsigned int morphVertexVersion;
    // Things we skinned last frame
    bool skinVertexLF, skinNormalLF, skinTangentBinormalLF;

    // LOD on the animation
    csTicks lastUpdate;
    char accumulatedFrames;
  };

}
CS_PLUGIN_NAMESPACE_END(Animesh)


#endif
