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
static char const metainfo_protomeshldr[] =
"<?xml version=\"1.0\"?>"
"<!-- protomeshldr.csplugin -->"
"<plugin>"
"  <scf>"
"    <classes>"
"      <class>"
"        <name>crystalspace.mesh.loader.factory.protomesh</name>"
"        <implementation>csProtoFactoryLoader</implementation>"
"        <description>Crystal Space Proto Mesh Factory Loader</description>"
"      </class>"
"      <class>"
"        <name>crystalspace.mesh.loader.protomesh</name>"
"        <implementation>csProtoMeshLoader</implementation>"
"        <description>Crystal Space Proto Mesh Mesh Loader</description>"
"      </class>"
"      <class>"
"        <name>crystalspace.mesh.saver.factory.protomesh</name>"
"        <implementation>csProtoFactorySaver</implementation>"
"        <description>Crystal Space Proto Mesh Factory Saver</description>"
"      </class>"
"      <class>"
"        <name>crystalspace.mesh.saver.protomesh</name>"
"        <implementation>csProtoMeshSaver</implementation>"
"        <description>Crystal Space Proto Mesh Mesh Saver</description>"
"      </class>"
"    </classes>"
"  </scf>"
"</plugin>"
;
  #ifndef csProtoFactoryLoader_FACTORY_REGISTER_DEFINED 
  #define csProtoFactoryLoader_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(csProtoFactoryLoader) 
  #endif
  #ifndef csProtoMeshLoader_FACTORY_REGISTER_DEFINED 
  #define csProtoMeshLoader_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(csProtoMeshLoader) 
  #endif
  #ifndef csProtoFactorySaver_FACTORY_REGISTER_DEFINED 
  #define csProtoFactorySaver_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(csProtoFactorySaver) 
  #endif
  #ifndef csProtoMeshSaver_FACTORY_REGISTER_DEFINED 
  #define csProtoMeshSaver_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(csProtoMeshSaver) 
  #endif

class protomeshldr
{
SCF_REGISTER_STATIC_LIBRARY(protomeshldr,metainfo_protomeshldr)
  #ifndef csProtoFactoryLoader_FACTORY_REGISTERED 
  #define csProtoFactoryLoader_FACTORY_REGISTERED 
    csProtoFactoryLoader_StaticInit csProtoFactoryLoader_static_init__; 
  #endif
  #ifndef csProtoMeshLoader_FACTORY_REGISTERED 
  #define csProtoMeshLoader_FACTORY_REGISTERED 
    csProtoMeshLoader_StaticInit csProtoMeshLoader_static_init__; 
  #endif
  #ifndef csProtoFactorySaver_FACTORY_REGISTERED 
  #define csProtoFactorySaver_FACTORY_REGISTERED 
    csProtoFactorySaver_StaticInit csProtoFactorySaver_static_init__; 
  #endif
  #ifndef csProtoMeshSaver_FACTORY_REGISTERED 
  #define csProtoMeshSaver_FACTORY_REGISTERED 
    csProtoMeshSaver_StaticInit csProtoMeshSaver_static_init__; 
  #endif
public:
 protomeshldr();
};
protomeshldr::protomeshldr() {}

}
