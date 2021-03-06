/* csutil.h -- Generated automatically; do not edit. *
#ifndef __CSUTIL_H__
#define __CSUTIL_H__
/*
    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.
  
    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.
  
    You should have received a copy of the GNU Library General Public
    License along with this library; if not, write to the Free
    Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

/**@file 
 * Directory master header. This header file includes all headers in a
 * subdirectory of the top Crystal Space include directory.
 *
#include "cssysdef.h"
#include "csutil/algorithms.h"
#include "csutil/alignedalloc.h"
#include "csutil/allocator.h"
#include "csutil/allocatorimpl.h"
#include "csutil/ansicommand.h"
#include "csutil/ansiparse.h"
#include "csutil/array.h"
#include "csutil/base64.h"
#include "csutil/binder.h"
#include "csutil/bitarray.h"
#include "csutil/bitops.h"
#include "csutil/blockallocator.h"
#include "csutil/callstack.h"
#include "csutil/cfgacc.h"
#include "csutil/cfgdoc.h"
#include "csutil/cfgfile.h"
#include "csutil/cfgmgr.h"
#include "csutil/cfgnotifier.h"
#include "csutil/checksum.h"
#include "csutil/cmdhelp.h"
#include "csutil/cmdline.h"
#include "csutil/common_handlers.h"
#include "csutil/comparator.h"
#include "csutil/compileassert.h"
#include "csutil/compositefunctor.h"
#include "csutil/cowwrapper.h"
#include "csutil/csbaseeventh.h"
#include "csutil/cscolor.h"
#include "csutil/csendian.h"
#include "csutil/csevcord.h"
#include "csutil/csevent.h"
#include "csutil/cseventflattener.h"
#include "csutil/cseventq.h"
#include "csutil/csinput.h"
#include "csutil/csobject.h"
#include "csutil/cspmeter.h"
#include "csutil/csppulse.h"
#include "csutil/csshlib.h"
#include "csutil/csstring.h"
#include "csutil/cssubscription.h"
#include "csutil/csuctransform.h"
#include "csutil/csunicode.h"
#include "csutil/customallocated.h"
#include "csutil/databuf.h"
#include "csutil/digest.h"
#include "csutil/dirtyaccessarray.h"
#include "csutil/documentcommon.h"
#include "csutil/documenthelper.h"
#include "csutil/event.h"
#include "csutil/eventhandlers.h"
#include "csutil/eventnames.h"
#include "csutil/evoutlet.h"
#include "csutil/fifo.h"
#include "csutil/filereadhelper.h"
#include "csutil/fixedsizeallocator.h"
#include "csutil/fixedsizecache.h"
#include "csutil/flags.h"
#include "csutil/floatrand.h"
#include "csutil/formatter.h"
#include "csutil/fpu80x86.h"
#include "csutil/frameeventsignpost.h"
#include "csutil/genericresourcecache.h"
#include "csutil/graphalg.h"
#include "csutil/hash.h"
#include "csutil/hashcomputer.h"
#include "csutil/hashr.h"
#include "csutil/inputdef.h"
#include "csutil/invasivelist.h"
#include "csutil/leakguard.h"
#include "csutil/list.h"
#include "csutil/md5.h"
#include "csutil/measuretime.h"
#include "csutil/memdebug.h"
#include "csutil/memfile.h"
#include "csutil/memheap.h"
#include "csutil/mempool.h"
#include "csutil/metautils.h"
#include "csutil/mmapio.h"
#include "csutil/nobjvec.h"
#include "csutil/noncopyable.h"
#include "csutil/nulcache.h"
#include "csutil/nullptr.h"
#include "csutil/objiter.h"
#include "csutil/objreg.h"
#include "csutil/parasiticdatabuffer.h"
#include "csutil/parray.h"
#include "csutil/partialorder.h"
#include "csutil/physfile.h"
#include "csutil/platform.h"
#include "csutil/platformfile.h"
#include "csutil/plugldr.h"
#include "csutil/plugmgr.h"
#include "csutil/pooledscfclass.h"
#include "csutil/prfxcfg.h"
#include "csutil/priorityqueue.h"
#include "csutil/processorspecdetection.h"
#include "csutil/ptrwrap.h"
#include "csutil/radixsort.h"
#include "csutil/randomgen.h"
#include "csutil/redblacktree.h"
#include "csutil/ref.h"
#include "csutil/refarr.h"
#include "csutil/refcount.h"
#include "csutil/reftrackeraccess.h"
#include "csutil/regexp.h"
#include "csutil/rootedhiercache.h"
#include "csutil/scanstr.h"
#include "csutil/scf.h"
#include "csutil/scf_implementation.h"
#include "csutil/scf_interface.h"
#include "csutil/scfarray.h"
#include "csutil/scfstr.h"
#include "csutil/scfstringarray.h"
#include "csutil/scfstrset.h"
#include "csutil/schedule.h"
#include "csutil/scopeddelete.h"
#include "csutil/scopedlock.h"
#include "csutil/scopedpointer.h"
#include "csutil/set.h"
#include "csutil/setenv.h"
#include "csutil/sha256.h"
#include "csutil/simplejobqueue.h"
#include "csutil/snprintf.h"
#include "csutil/sparse3d.h"
#include "csutil/spinlock.h"
#include "csutil/strhash.h"
#include "csutil/strhashr.h"
#include "csutil/stringarray.h"
#include "csutil/stringconv.h"
#include "csutil/stringquote.h"
#include "csutil/stringreader.h"
#include "csutil/strset.h"
#include "csutil/sysfunc.h"
#include "csutil/syspath.h"
#include "csutil/systemopenmanager.h"
#include "csutil/threadevent.h"
#include "csutil/threading/atomicops.h"
#include "csutil/threading/barrier.h"
#include "csutil/threading/condition.h"
#include "csutil/threading/mutex.h"
#include "csutil/threading/rwmutex.h"
#include "csutil/threading/thread.h"
#include "csutil/threading/tls.h"
#include "csutil/threadjobqueue.h"
#include "csutil/threadmanager.h"
#include "csutil/timer.h"
#include "csutil/tree.h"
#include "csutil/tuple.h"
#include "csutil/typetraits.h"
#include "csutil/util.h"
#include "csutil/variant.h"
#include "csutil/verbosity.h"
#include "csutil/vfscache.h"
#include "csutil/vfshiercache.h"
#include "csutil/vfsplat.h"
#include "csutil/virtclk.h"
#include "csutil/weakkeyedhash.h"
#include "csutil/weakref.h"
#include "csutil/weakrefarr.h"
#include "csutil/weakreferenced.h"
#include "csutil/weakrefhash.h"
#include "csutil/xmltiny.h"
#if defined(CS_PLATFORM_MACOSX)
#include "csutil/macosx/OSXAssistant.h"
#elif defined(CS_PLATFORM_WIN32)
#include "csutil/win32/cachedll.h"
#include "csutil/win32/callstack.h"
#include "csutil/win32/csconfig-msvc.h"
#include "csutil/win32/registrycfg.h"
#include "csutil/win32/win32.h"
#include "csutil/win32/wintools.h"
#endif
#endif /* __CSUTIL_H__ *

