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
static char const metainfo_cssaver[] =
"<?xml version=\"1.0\"?>"
"<!-- cssaver.csplugin -->"
"<plugin>"
"  <scf>"
"    <classes>"
"      <class>"
"        <name>crystalspace.level.saver</name>"
"        <implementation>csSaver</implementation>"
"        <description>Level and library file saver</description>"
"        <requires>"
"          <class>crystalspace.kernel.</class>"
"        </requires>"
"      </class>"
"    </classes>"
"  </scf>"
"</plugin>"
;
  #ifndef csSaver_FACTORY_REGISTER_DEFINED 
  #define csSaver_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(csSaver) 
  #endif

class cssaver
{
SCF_REGISTER_STATIC_LIBRARY(cssaver,metainfo_cssaver)
  #ifndef csSaver_FACTORY_REGISTERED 
  #define csSaver_FACTORY_REGISTERED 
    csSaver_StaticInit csSaver_static_init__; 
  #endif
public:
 cssaver();
};
cssaver::cssaver() {}

}
