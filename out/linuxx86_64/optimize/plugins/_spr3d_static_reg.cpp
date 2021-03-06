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
static char const metainfo_spr3d[] =
"<?xml version=\"1.0\"?>"
"<!-- spr3d.csplugin -->"
"<plugin>"
"  <scf>"
"    <classes>"
"      <class>"
"        <name>crystalspace.mesh.object.sprite.3d</name>"
"        <implementation>csSprite3DMeshObjectType</implementation>"
"        <description>Crystal Space Sprite3D Mesh Type</description>"
"      </class>"
"    </classes>"
"  </scf>"
"</plugin>"
;
  #ifndef csSprite3DMeshObjectType_FACTORY_REGISTER_DEFINED 
  #define csSprite3DMeshObjectType_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(csSprite3DMeshObjectType) 
  #endif

class spr3d
{
SCF_REGISTER_STATIC_LIBRARY(spr3d,metainfo_spr3d)
  #ifndef csSprite3DMeshObjectType_FACTORY_REGISTERED 
  #define csSprite3DMeshObjectType_FACTORY_REGISTERED 
    csSprite3DMeshObjectType_StaticInit csSprite3DMeshObjectType_static_init__; 
  #endif
public:
 spr3d();
};
spr3d::spr3d() {}

}
