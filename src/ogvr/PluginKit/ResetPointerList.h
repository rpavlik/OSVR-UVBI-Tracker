/** @file
    @brief Header

    @date 2014

    @author
    Ryan Pavlik
    <ryan@sensics.com>;
    <http://sensics.com>
*/

// Copyright 2014 Sensics, Inc.
//
// All rights reserved.
//
// (Final version intended to be licensed under
// the Apache License, Version 2.0)

#ifndef INCLUDED_ResetPointerList_h_GUID_067DF9C9_67F7_4293_94EF_DBC5B5266801
#define INCLUDED_ResetPointerList_h_GUID_067DF9C9_67F7_4293_94EF_DBC5B5266801

// Internal Includes
// - none

// Library/third-party includes
// - none

// Standard includes
#include <algorithm>

namespace ogvr {
namespace detail {

    /// @brief Functor for resetting smart pointers, for use with for_each or
    /// similar.
    template <typename SmartPointerType> struct PointerResetter {
        void operator()(SmartPointerType &p) { p.reset(); }
    };

    /// @brief Reset every smart pointer in a container one by one, from
    /// beginning to end.
    template <typename ListType>
    inline void resetPointerList(ListType &ptrlist) {
        typedef typename ListType::value_type PointerType;
        std::for_each(ptrlist.begin(), ptrlist.end(),
                      PointerResetter<PointerType>());
    }
    /// @brief Reset every smart pointer in a container one by one in reverse
    /// order.
    template <typename ListType>
    inline void resetPointerListReverseOrder(ListType &ptrlist) {
        typedef typename ListType::value_type PointerType;
        std::for_each(ptrlist.rbegin(), ptrlist.rend(),
                      PointerResetter<PointerType>());
    }
}
}

#endif // INCLUDED_ResetPointerList_h_GUID_067DF9C9_67F7_4293_94EF_DBC5B5266801