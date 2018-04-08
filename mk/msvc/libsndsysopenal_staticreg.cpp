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
static char const metainfo_sndsysopenal[] =
"<?xml version=\"1.0\"?>"
"<!-- sndsysopenal.csplugin -->"
"<plugin>"
"  <scf>"
"    <classes>"
"      <class>"
"        <name>crystalspace.sndsys.renderer.openal</name>"
"        <implementation>csSndSysRendererOpenAL</implementation>"
"        <description>Sound System OpenAL Renderer</description>"
"      </class>"
"    </classes>"
"  </scf>"
"</plugin>"
""
;
  #ifndef csSndSysRendererOpenAL_FACTORY_REGISTER_DEFINED 
  #define csSndSysRendererOpenAL_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(csSndSysRendererOpenAL) 
  #endif

class sndsysopenal
{
SCF_REGISTER_STATIC_LIBRARY(sndsysopenal,metainfo_sndsysopenal)
  #ifndef csSndSysRendererOpenAL_FACTORY_REGISTERED 
  #define csSndSysRendererOpenAL_FACTORY_REGISTERED 
    csSndSysRendererOpenAL_StaticInit csSndSysRendererOpenAL_static_init__; 
  #endif
public:
 sndsysopenal();
};
sndsysopenal::sndsysopenal() {}

}