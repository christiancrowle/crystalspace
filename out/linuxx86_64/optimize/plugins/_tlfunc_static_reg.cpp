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
static char const metainfo_tlfunc[] =
"<?xml version=\"1.0\"?>"
"<!-- tlfunc.csplugin -->"
"<plugin>"
"  <scf>"
"    <classes>"
"      <class>"
"        <name>crystalspace.texture.loader.func</name>"
"        <implementation>csFuncTexLoader</implementation>"
"        <description>Function texture loader</description>"
"        <requires>"
"          <class>crystalspace.graphics3d.</class>"
"        </requires>"
"      </class>"
"    </classes>"
"  </scf>"
"</plugin>"
;
  #ifndef csFuncTexLoader_FACTORY_REGISTER_DEFINED 
  #define csFuncTexLoader_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(csFuncTexLoader) 
  #endif

class tlfunc
{
SCF_REGISTER_STATIC_LIBRARY(tlfunc,metainfo_tlfunc)
  #ifndef csFuncTexLoader_FACTORY_REGISTERED 
  #define csFuncTexLoader_FACTORY_REGISTERED 
    csFuncTexLoader_StaticInit csFuncTexLoader_static_init__; 
  #endif
public:
 tlfunc();
};
tlfunc::tlfunc() {}

}
