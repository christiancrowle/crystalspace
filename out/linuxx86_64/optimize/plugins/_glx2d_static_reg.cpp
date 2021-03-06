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
static char const metainfo_glx2d[] =
"<?xml version=\"1.0\"?>"
"<!-- glx2d.csplugin -->"
"<plugin>"
"  <scf>"
"    <classes>"
"      <class>"
"        <name>crystalspace.graphics2d.glx</name>"
"        <implementation>csGraphics2DGLX</implementation>"
"        <description>Crystal Space 2D driver for OpenGL using GL/X</description>"
"        <requires>"
"          <class>crystalspace.font.server.</class>"
"        </requires>"
"      </class>"
"    </classes>"
"  </scf>"
"</plugin>"
;
  #ifndef csGraphics2DGLX_FACTORY_REGISTER_DEFINED 
  #define csGraphics2DGLX_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(csGraphics2DGLX) 
  #endif

class glx2d
{
SCF_REGISTER_STATIC_LIBRARY(glx2d,metainfo_glx2d)
  #ifndef csGraphics2DGLX_FACTORY_REGISTERED 
  #define csGraphics2DGLX_FACTORY_REGISTERED 
    csGraphics2DGLX_StaticInit csGraphics2DGLX_static_init__; 
  #endif
public:
 glx2d();
};
glx2d::glx2d() {}

}
