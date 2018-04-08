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
static char const metainfo_vproc_std[] =
"<?xml version=\"1.0\"?>"
"<!-- vproc_std.csplugin -->"
"<plugin>"
"  <scf>"
"    <classes>"
"      <class>"
"        <name>crystalspace.graphics3d.shader.vproc_std</name>"
"        <implementation>csVProc_Std</implementation>"
"        <description>Standard vertex preprocessor plugin</description>"
"      </class>"
"    </classes>"
"  </scf>"
"</plugin>"
;
  #ifndef csVProc_Std_FACTORY_REGISTER_DEFINED 
  #define csVProc_Std_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(csVProc_Std) 
  #endif

class vproc_std
{
SCF_REGISTER_STATIC_LIBRARY(vproc_std,metainfo_vproc_std)
  #ifndef csVProc_Std_FACTORY_REGISTERED 
  #define csVProc_Std_FACTORY_REGISTERED 
    csVProc_Std_StaticInit csVProc_Std_static_init__; 
  #endif
public:
 vproc_std();
};
vproc_std::vproc_std() {}

}
