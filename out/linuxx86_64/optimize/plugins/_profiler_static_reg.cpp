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
static char const metainfo_profiler[] =
"<?xml version=\"1.0\"?>"
"<!-- profiler.csplugin -->"
"<plugin>"
"  <scf>"
"    <classes>"
"      <class>"
"        <name>crystalspace.utilities.profiler</name>"
"        <implementation>ProfilerFactory</implementation>"
"        <description>Profiling utility</description>"
"      </class>"
"    </classes>"
"  </scf>"
"</plugin>"
;
  #ifndef ProfilerFactory_FACTORY_REGISTER_DEFINED 
  #define ProfilerFactory_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(ProfilerFactory) 
  #endif

class profiler
{
SCF_REGISTER_STATIC_LIBRARY(profiler,metainfo_profiler)
  #ifndef ProfilerFactory_FACTORY_REGISTERED 
  #define ProfilerFactory_FACTORY_REGISTERED 
    ProfilerFactory_StaticInit ProfilerFactory_static_init__; 
  #endif
public:
 profiler();
};
profiler::profiler() {}

}
