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
static char const metainfo_lghtng[] =
"<?xml version=\"1.0\"?>"
"<!-- lghtng.csplugin -->"
"<plugin>"
"  <scf>"
"    <classes>"
"      <class>"
"        <name>crystalspace.mesh.object.lightning</name>"
"        <implementation>csLightningMeshObjectType</implementation>"
"        <description>Crystal Space Lightning Mesh Type</description>"
"      </class>"
"    </classes>"
"  </scf>"
"</plugin>"
;
  #ifndef csLightningMeshObjectType_FACTORY_REGISTER_DEFINED 
  #define csLightningMeshObjectType_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(csLightningMeshObjectType) 
  #endif

class lghtng
{
SCF_REGISTER_STATIC_LIBRARY(lghtng,metainfo_lghtng)
  #ifndef csLightningMeshObjectType_FACTORY_REGISTERED 
  #define csLightningMeshObjectType_FACTORY_REGISTERED 
    csLightningMeshObjectType_StaticInit csLightningMeshObjectType_static_init__; 
  #endif
public:
 lghtng();
};
lghtng::lghtng() {}

}
