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
static char const metainfo_frustvis[] =
"<?xml version=\"1.0\"?>"
"<!-- frustvis.csplugin -->"
"<plugin>"
"  <scf>"
"    <classes>"
"      <class>"
"        <name>crystalspace.culling.frustvis</name>"
"        <implementation>csFrustumVis</implementation>"
"        <description>Simple Frustum Visibility System</description>"
"      </class>"
"    </classes>"
"  </scf>"
"</plugin>"
;
  #ifndef csFrustumVis_FACTORY_REGISTER_DEFINED 
  #define csFrustumVis_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(csFrustumVis) 
  #endif

class frustvis
{
SCF_REGISTER_STATIC_LIBRARY(frustvis,metainfo_frustvis)
  #ifndef csFrustumVis_FACTORY_REGISTERED 
  #define csFrustumVis_FACTORY_REGISTERED 
    csFrustumVis_StaticInit csFrustumVis_static_init__; 
  #endif
public:
 frustvis();
};
frustvis::frustvis() {}

}
