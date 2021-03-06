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
static char const metainfo_csconin[] =
"<?xml version=\"1.0\"?>"
"<!-- csconin.csplugin -->"
"<plugin>"
"  <scf>"
"    <classes>"
"      <class>"
"        <name>crystalspace.console.input.standard</name>"
"        <implementation>csConsoleInput</implementation>"
"        <description>Crystal Space standard input console</description>"
"      </class>"
"    </classes>"
"  </scf>"
"</plugin>"
;
  #ifndef csConsoleInput_FACTORY_REGISTER_DEFINED 
  #define csConsoleInput_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(csConsoleInput) 
  #endif

class csconin
{
SCF_REGISTER_STATIC_LIBRARY(csconin,metainfo_csconin)
  #ifndef csConsoleInput_FACTORY_REGISTERED 
  #define csConsoleInput_FACTORY_REGISTERED 
    csConsoleInput_StaticInit csConsoleInput_static_init__; 
  #endif
public:
 csconin();
};
csconin::csconin() {}

}
