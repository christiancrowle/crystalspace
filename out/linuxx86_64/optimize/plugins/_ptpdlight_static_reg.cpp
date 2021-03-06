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
static char const metainfo_ptpdlight[] =
"<?xml version=\"1.0\"?>"
"<!-- ptpdlight.csplugin -->"
"<plugin>"
"  <scf>"
"    <classes>"
"      <class>"
"        <name>crystalspace.texture.loader.pdlight</name>"
"        <implementation>ProctexPDLightLoader</implementation>"
"        <description>Pseudo-dynamic lightmap procedural texture loader</description>"
"        <requires>"
"          <class>crystalspace.graphics3d.</class>"
"          <class>crystalspace.level.loader</class>"
"	  <class>crystalspace.engine.</class>"
"	</requires>"
"      </class>"
"    </classes>"
"  </scf>"
"</plugin>"
;
  #ifndef ProctexPDLightLoader_FACTORY_REGISTER_DEFINED 
  #define ProctexPDLightLoader_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(ProctexPDLightLoader) 
  #endif

class ptpdlight
{
SCF_REGISTER_STATIC_LIBRARY(ptpdlight,metainfo_ptpdlight)
  #ifndef ProctexPDLightLoader_FACTORY_REGISTERED 
  #define ProctexPDLightLoader_FACTORY_REGISTERED 
    ProctexPDLightLoader_StaticInit ProctexPDLightLoader_static_init__; 
  #endif
public:
 ptpdlight();
};
ptpdlight::ptpdlight() {}

}
