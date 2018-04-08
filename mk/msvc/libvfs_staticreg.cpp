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
static char const metainfo_vfs[] =
"<?xml version=\"1.0\"?>"
"<!-- vfs.csplugin -->"
"<plugin>"
"  <scf>"
"    <classes>"
"      <class>"
"        <name>crystalspace.kernel.vfs</name>"
"        <implementation>csVFS</implementation>"
"        <description>Crystal Space Virtual File System</description>"
"      </class>"
"    </classes>"
"  </scf>"
"</plugin>"
;
  #ifndef csVFS_FACTORY_REGISTER_DEFINED 
  #define csVFS_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(csVFS) 
  #endif

class vfs
{
SCF_REGISTER_STATIC_LIBRARY(vfs,metainfo_vfs)
  #ifndef csVFS_FACTORY_REGISTERED 
  #define csVFS_FACTORY_REGISTERED 
    csVFS_StaticInit csVFS_static_init__; 
  #endif
public:
 vfs();
};
vfs::vfs() {}

}
