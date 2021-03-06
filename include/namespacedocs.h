/*
  Copyright (C) 2007 by Marten Svanfeldt

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

#ifndef CS_NAMESPACEDOCS_H
#define CS_NAMESPACEDOCS_H

/** \file
 * Documentation for namespaces in CS
 */

/**
 * Main namespace for CrystalSpace
 */
namespace CS
{
  /**
   * Animation-related types  
   */
  namespace Animation
  {}

  /**
   * Checksums and message digests
   */
  namespace Checksum
  {}

  /**
   * Collision detection and utilities
   */
  namespace Collisions
  {}

  /**
   * Container classes
   */
  namespace Container
  {}

  /**
   * Debugging utilities and helpers
   */
  namespace Debug
  {}

  /**
   * Contains deprecated code that will be removed after next stable release.
   * Do not use of any members.
   */
  namespace Deprecated
  {}

  /**
   * Document system / XML helper classes
   */
  namespace DocSystem
  {}

  /**
   * Loading and saving helper classes.
   */
  namespace Persistence
  {}

  /**
   * Geometry and mesh tools related classes.
   */
  namespace Geometry
  {}

  /**
   * Graphics and rendering related classes.
   */
  namespace Graphics
  {}

  /**
   * Material and texture related classes.
   */
  namespace Material
  {}

  /**
   * Mathematical functions and definitions
   */
  namespace Math
  {
    /**
     * Noise generation and utilities. Objects from this namespace
     * use the libnoise library, see http://libnoise.sourceforge.net for
     * more information.
     */
    namespace Noise
    {
      /**
       * Geometric models for noise generation. Objects from this namespace
       * use the libnoise library, see http://libnoise.sourceforge.net for
       * more information.
       */
      namespace Model
      {}

      /**
       * Noise modules for the combination of noise functions. Objects from this
       * namespace use the libnoise library, see http://libnoise.sourceforge.net
       * for more information.
       */
      namespace Module
      {}
    }
  }

  /**
   * Multimedia content manipulation
   */
  namespace Media
  {}

  /**
   * Memory allocation
   */
  namespace Memory
  {}

  /**
   * Meshes
   */
  namespace Mesh
  {}

  /**
   * Meta-programming helpers
   */
  namespace Meta
  {}

  /**
   * Platform specific code and wrappers
   */
  namespace Platform
  {
    /**
     * Win32-specific classes and functions
     */
    namespace Win32 {}
  }

  /**
   * Implementation of all plugins
   */
  namespace Plugin
  {}

  /**
   * Common code shared among a number of plugins
   */
  namespace PluginCommon
  {
    /**
     * Common code shared among plugins using OpenGL
     */
    namespace GL
    {}
  
    /**
     * Common code for shader caching
     */
    namespace ShaderCacheHelper
    {}
    
    /**
     * Common code for plugins implementing shader weaver combiners
     */
    namespace ShaderWeaver
    {}
  }

  /**
   * Objects of a dynamic simulation
   */
  namespace Physics
  {
    /**
     * Objects of a dynamic simulation with the Bullet plugin
     */
    namespace Bullet
    {
    }
  }

  /**
   * Classes for render manager plugin implementation
   */
  namespace RenderManager
  {
    /**
     * Classes for "automatic effects" (usually providing special textures or
     * similar on an if-uses basis).
     */
    namespace AutoFX
    {}
    
    /**
     * Helpers for HDR effects
     */
    namespace HDR
    {
      /// Rendered scene luminance computation
      namespace Luminance
      {}
      
      /// Exposure computation
      namespace Exposure
      {}
    }
  }

  /**
   * Sound system classes
   */
  namespace SndSys
  {}

  /**
   * Functions and classes for threading, locking and atomic operations
   */
  namespace Threading
  {}

  /**
   * Assorted utility functions and classes that doesn't belong anywhere 
   * else
   */
  namespace Utility
  {}

  /**
   * Classes/helpers for wxWidgets integration
   */
  namespace WX
  {}
}

#endif
