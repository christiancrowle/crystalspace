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
static char const metainfo_an_lookat[] =
"<?xml version=\"1.0\"?>"
"<!-- lookat.csplugin -->"
"<plugin>"
"  <scf>"
"    <classes>"
"      <class>"
"        <name>crystalspace.mesh.animesh.animnode.lookat</name>"
"        <implementation>LookAtNodeManager</implementation>"
"        <description>Crystal Space LookAt animation node of an animated mesh</description>"
"      </class>"
"    </classes>"
"  </scf>"
"</plugin>"
;
  #ifndef LookAtNodeManager_FACTORY_REGISTER_DEFINED 
  #define LookAtNodeManager_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(LookAtNodeManager) 
  #endif

class an_lookat
{
SCF_REGISTER_STATIC_LIBRARY(an_lookat,metainfo_an_lookat)
  #ifndef LookAtNodeManager_FACTORY_REGISTERED 
  #define LookAtNodeManager_FACTORY_REGISTERED 
    LookAtNodeManager_StaticInit LookAtNodeManager_static_init__; 
  #endif
public:
 an_lookat();
};
an_lookat::an_lookat() {}

}
