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
static char const metainfo_csbmpimg[] =
"<?xml version=\"1.0\"?>"
"<!-- csbmpimg.csplugin -->"
"<plugin>"
"  <scf>"
"    <classes>"
"      <class>"
"        <name>crystalspace.graphic.image.io.bmp</name>"
"        <implementation>csBMPImageIO</implementation>"
"        <description>CrystalSpace BMP image format I/O plugin</description>"
"      </class>"
"    </classes>"
"  </scf>"
"</plugin>"
;
  #ifndef csBMPImageIO_FACTORY_REGISTER_DEFINED 
  #define csBMPImageIO_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(csBMPImageIO) 
  #endif

class csbmpimg
{
SCF_REGISTER_STATIC_LIBRARY(csbmpimg,metainfo_csbmpimg)
  #ifndef csBMPImageIO_FACTORY_REGISTERED 
  #define csBMPImageIO_FACTORY_REGISTERED 
    csBMPImageIO_StaticInit csBMPImageIO_static_init__; 
  #endif
public:
 csbmpimg();
};
csbmpimg::csbmpimg() {}

}
