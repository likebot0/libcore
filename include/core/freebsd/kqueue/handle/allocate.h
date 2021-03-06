#ifndef _core_freebsd_kqueue_handle_allocate
#define _core_freebsd_kqueue_handle_allocate ::core_freebsd_kqueue_handle_allocate

#include <core/preprocessor/define_map.h>

_core_preprocessor_define_map(core_freebsd_kqueue_handle_allocate, core_freebsd_kqueue_handle_allocate_);

#include <core/freebsd/kqueue/Handle.type.h>
#include <core/ieee/std/1003dot1/last_error.h>

#if __has_include(<sys/types.h>)
extern "C" {

#include <sys/types.h>

}
#endif

#if __has_include(<sys/event.h>)
extern "C" {

#include <sys/event.h>

}
#endif

#if __has_include(<sys/time.h>)
extern "C" {

#include <sys/time.h>

}
#endif

#if __has_include(<sys/event.h>)
template<typename Continuation>
inline constexpr auto core_freebsd_kqueue_handle_allocate_<
    Continuation
> = [] (
    auto & k
) {
    auto x = ::kqueue();

    if (x == -1)
        _core_ieee_std_1003dot1_last_error(k);
    else
        k(_core_freebsd_kqueue_Handle{x});
};
#endif

#endif
