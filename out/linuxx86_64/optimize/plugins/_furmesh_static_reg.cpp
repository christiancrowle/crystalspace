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
static char const metainfo_furmesh[] =
"<?xml version=\"1.0\"?>"
"<!-- hairmaterial.csplugin -->"
"<plugin>"
"  <scf>"
"    <classes>"
"      <class>"
"        <name>crystalspace.mesh.object.furmesh</name>"
"        <implementation>FurMeshType</implementation>"
"        <description>Fur Mesh Type Plugin</description>"
"      </class>"
"    </classes>"
"  </scf>"
"</plugin>"
;
  #ifndef FurMeshType_FACTORY_REGISTER_DEFINED 
  #define FurMeshType_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(FurMeshType) 
  #endif

class furmesh
{
SCF_REGISTER_STATIC_LIBRARY(furmesh,metainfo_furmesh)
  #ifndef FurMeshType_FACTORY_REGISTERED 
  #define FurMeshType_FACTORY_REGISTERED 
    FurMeshType_StaticInit FurMeshType_static_init__; 
  #endif
public:
 furmesh();
};
furmesh::furmesh() {}

}
