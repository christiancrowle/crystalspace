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
static char const metainfo_xext86vm[] =
"<?xml version=\"1.0\"?>"
"<!-- xext86vm.csplugin -->"
"<plugin>"
"  <scf>"
"    <classes>"
"      <class>"
"        <name>crystalspace.window.x.extf86vm</name>"
"        <implementation>csXExtF86VM</implementation>"
"        <description>X-Window extension video mode plugin</description>"
"      </class>"
"    </classes>"
"  </scf>"
"</plugin>"
;
  #ifndef csXExtF86VM_FACTORY_REGISTER_DEFINED 
  #define csXExtF86VM_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(csXExtF86VM) 
  #endif

class xext86vm
{
SCF_REGISTER_STATIC_LIBRARY(xext86vm,metainfo_xext86vm)
  #ifndef csXExtF86VM_FACTORY_REGISTERED 
  #define csXExtF86VM_FACTORY_REGISTERED 
    csXExtF86VM_StaticInit csXExtF86VM_static_init__; 
  #endif
public:
 xext86vm();
};
xext86vm::xext86vm() {}

}