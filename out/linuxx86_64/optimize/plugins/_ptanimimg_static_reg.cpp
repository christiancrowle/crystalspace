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
static char const metainfo_ptanimimg[] =
"<?xml version=\"1.0\"?>"
"<!-- ptanimimg.csplugin -->"
"<plugin>"
"  <scf>"
"    <classes>"
"      <class>"
"        <name>crystalspace.texture.loader.animimg</name>"
"        <implementation>csAnimateProctexLoader</implementation>"
"        <description>Animated image procedural texture loader</description>"
"        <requires>"
"          <class>crystalspace.graphics3d.</class>"
"          <class>crystalspace.level.loader</class>"
"        </requires>"
"      </class>"
"    </classes>"
"  </scf>"
"</plugin>"
;
  #ifndef csAnimateProctexLoader_FACTORY_REGISTER_DEFINED 
  #define csAnimateProctexLoader_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(csAnimateProctexLoader) 
  #endif

class ptanimimg
{
SCF_REGISTER_STATIC_LIBRARY(ptanimimg,metainfo_ptanimimg)
  #ifndef csAnimateProctexLoader_FACTORY_REGISTERED 
  #define csAnimateProctexLoader_FACTORY_REGISTERED 
    csAnimateProctexLoader_StaticInit csAnimateProctexLoader_static_init__; 
  #endif
public:
 ptanimimg();
};
ptanimimg::ptanimimg() {}

}