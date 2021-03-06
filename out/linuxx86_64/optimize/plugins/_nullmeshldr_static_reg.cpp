/ This file is automatically generated.
#include "cssysdef.h"
#include "csutil/scf.h"

/ Put static linking stuff into own section.
/ The idea is that this allows the section to be swapped out but not
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
static char const metainfo_nullmeshldr[] =
"<?xml version=\"1.0\"?>"
"<!-- nullmeshldr.csplugin -->"
"<plugin>"
"  <name>nullmeshldr</name>"
"  <scf>"
"    <classes>"
"      <class>"
"        <name>crystalspace.mesh.loader.factory.null</name>"
"        <implementation>csNullFactoryLoader</implementation>"
"        <description>Crystal Space Null Mesh Factory Loader</description>"
"      </class>"
"      <class>"
"        <name>crystalspace.mesh.loader.null</name>"
"        <implementation>csNullMeshLoader</implementation>"
"        <description>Crystal Space Null Mesh Mesh Loader</description>"
"      </class>"
"      <class>"
"        <name>crystalspace.mesh.saver.factory.null</name>"
"        <implementation>csNullFactorySaver</implementation>"
"        <description>Crystal Space Null Mesh Factory Saver</description>"
"      </class>"
"      <class>"
"        <name>crystalspace.mesh.saver.null</name>"
"        <implementation>csNullMeshSaver</implementation>"
"        <description>Crystal Space Null Mesh Mesh Saver</description>"
"      </class>"
"    </classes>"
"  </scf>"
"</plugin>"
;
  #ifndef csNullFactoryLoader_FACTORY_REGISTER_DEFINED 
  #define csNullFactoryLoader_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(csNullFactoryLoader) 
  #endif
  #ifndef csNullMeshLoader_FACTORY_REGISTER_DEFINED 
  #define csNullMeshLoader_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(csNullMeshLoader) 
  #endif
  #ifndef csNullFactorySaver_FACTORY_REGISTER_DEFINED 
  #define csNullFactorySaver_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(csNullFactorySaver) 
  #endif
  #ifndef csNullMeshSaver_FACTORY_REGISTER_DEFINED 
  #define csNullMeshSaver_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(csNullMeshSaver) 
  #endif

class nullmeshldr
{
SCF_REGISTER_STATIC_LIBRARY(nullmeshldr,metainfo_nullmeshldr)
  #ifndef csNullFactoryLoader_FACTORY_REGISTERED 
  #define csNullFactoryLoader_FACTORY_REGISTERED 
    csNullFactoryLoader_StaticInit csNullFactoryLoader_static_init__; 
  #endif
  #ifndef csNullMeshLoader_FACTORY_REGISTERED 
  #define csNullMeshLoader_FACTORY_REGISTERED 
    csNullMeshLoader_StaticInit csNullMeshLoader_static_init__; 
  #endif
  #ifndef csNullFactorySaver_FACTORY_REGISTERED 
  #define csNullFactorySaver_FACTORY_REGISTERED 
    csNullFactorySaver_StaticInit csNullFactorySaver_static_init__; 
  #endif
  #ifndef csNullMeshSaver_FACTORY_REGISTERED 
  #define csNullMeshSaver_FACTORY_REGISTERED 
    csNullMeshSaver_StaticInit csNullMeshSaver_static_init__; 
  #endif
public:
 nullmeshldr();
};
nullmeshldr::nullmeshldr() {}

}
