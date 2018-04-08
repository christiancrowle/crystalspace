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
static char const metainfo_csddsimg[] =
"<?xml version=\"1.0\"?>"
"<!-- csddsimg.csplugin -->"
"<plugin>"
"  <scf>"
"    <classes>"
"      <class>"
"        <name>crystalspace.graphic.image.io.dds</name>"
"        <implementation>csDDSImageIO</implementation>"
"        <description>DDS image format I/O plugin</description>"
"      </class>"
"      <class>"
"        <name>crystalspace.graphic.dxt.decompress.default</name>"
"        <implementation>DXTDecompressor</implementation>"
"        <description>Default DXT decompressor plugin</description>"
"      </class>"
"    </classes>"
"  </scf>"
"</plugin>"
;
  #ifndef csDDSImageIO_FACTORY_REGISTER_DEFINED 
  #define csDDSImageIO_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(csDDSImageIO) 
  #endif
  #ifndef DXTDecompressor_FACTORY_REGISTER_DEFINED 
  #define DXTDecompressor_FACTORY_REGISTER_DEFINED 
    SCF_DEFINE_FACTORY_FUNC_REGISTRATION(DXTDecompressor) 
  #endif

class csddsimg
{
SCF_REGISTER_STATIC_LIBRARY(csddsimg,metainfo_csddsimg)
  #ifndef csDDSImageIO_FACTORY_REGISTERED 
  #define csDDSImageIO_FACTORY_REGISTERED 
    csDDSImageIO_StaticInit csDDSImageIO_static_init__; 
  #endif
  #ifndef DXTDecompressor_FACTORY_REGISTERED 
  #define DXTDecompressor_FACTORY_REGISTERED 
    DXTDecompressor_StaticInit DXTDecompressor_static_init__; 
  #endif
public:
 csddsimg();
};
csddsimg::csddsimg() {}

}
