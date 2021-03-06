// This file is automatically generated.
#include "cssysdef.h"
#include "csutil/scf.h"

// Put static linking stuff into own section.
// The idea is that this allows the section to be swapped out but not
// swapped in again b/c something else in it was needed.
#if !defined(CS_DEBUG) && defined(CS_COMPILER_MSVC)
#pragma const_seg(".CSmetai")
#pragma comment(linker, "/section:.CSmetai,r")
#pragma code_seg(".CSmeta")
#pragma comment(linker, "/section:.CSmeta,er")
#pragma comment(linker, "/merge:.CSmetai=.CSmeta")
#endif

namespace csStaticPluginInit
{
static char const metainfo_terrain2ldr[] =
"<?xml version=\"1.0\"?>"
"<!-- terrain2ldr.csplugin -->"
"<plugin>"
"  <scf>"
"    <classes>"
"      <class>"
"        <name>crystalspace.mesh.loader.factory.terrain2</name>"
"        <implementation>csTerrain2FactoryLoader</implementation>"
"        <description>Terrain Factory Loader</description>"
"      </class>"
"      <class>"
"        <name>crystalspace.mesh.loader.terrain2</name>"
"        <implementation>csTerrain2ObjectLoader</implementation>"
"        <description>Terrain Object Loader</description>"
"      </class>"
"      <class>"
"        <name>crystalspace.mesh.saver.factory.terrain2</name>"
"        <implementation>Terrain2FactorySaver</implementation>"
"        <description>Terrain Factory Saver</description>"
"      </class>"
"      <class>"
"        <name>crystalspace.mesh.saver.terrain2</name>"
"        <implementation>Terrain2ObjectSaver</implementation>"
"        <description>Terrain Object Saver</description>"
"      </class>"
"    </classes>"
"  </scf>"
"</plugin>"
;
  #ifndef csTerrain2FactoryLoader_FACTORY_REGISTER_DEFINED 
  #define csTerrain2FactoryLoader_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(csTerrain2FactoryLoader) 
  #endif
  #ifndef csTerrain2ObjectLoader_FACTORY_REGISTER_DEFINED 
  #define csTerrain2ObjectLoader_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(csTerrain2ObjectLoader) 
  #endif
  #ifndef Terrain2FactorySaver_FACTORY_REGISTER_DEFINED 
  #define Terrain2FactorySaver_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(Terrain2FactorySaver) 
  #endif
  #ifndef Terrain2ObjectSaver_FACTORY_REGISTER_DEFINED 
  #define Terrain2ObjectSaver_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(Terrain2ObjectSaver) 
  #endif

class terrain2ldr
{
SCF_REGISTER_STATIC_LIBRARY(terrain2ldr,metainfo_terrain2ldr)
  #ifndef csTerrain2FactoryLoader_FACTORY_REGISTERED 
  #define csTerrain2FactoryLoader_FACTORY_REGISTERED 
    csTerrain2FactoryLoader_StaticInit csTerrain2FactoryLoader_static_init__; 
  #endif
  #ifndef csTerrain2ObjectLoader_FACTORY_REGISTERED 
  #define csTerrain2ObjectLoader_FACTORY_REGISTERED 
    csTerrain2ObjectLoader_StaticInit csTerrain2ObjectLoader_static_init__; 
  #endif
  #ifndef Terrain2FactorySaver_FACTORY_REGISTERED 
  #define Terrain2FactorySaver_FACTORY_REGISTERED 
    Terrain2FactorySaver_StaticInit Terrain2FactorySaver_static_init__; 
  #endif
  #ifndef Terrain2ObjectSaver_FACTORY_REGISTERED 
  #define Terrain2ObjectSaver_FACTORY_REGISTERED 
    Terrain2ObjectSaver_StaticInit Terrain2ObjectSaver_static_init__; 
  #endif
public:
 terrain2ldr();
};
terrain2ldr::terrain2ldr() {}

}
