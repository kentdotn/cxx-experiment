// Copyright (C) 2013 Kent.N.
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef XXCXX_NOCHECKING_SEQUENCE_HPP_INCLUDED
#define XXCXX_NOCHECKING_SEQUENCE_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#   pragma once
#endif

#include <utility>

namespace xxcxx {

template <class T> class nochecking_sequence
{
public:
    nochecking_sequence(T* ptr) : ptr(ptr) {}

    void push_back(const T& obj)
    {
            *ptr = obj;
            ++ptr;
    }

    void push_back(T&& obj)
    {
            *ptr = std::move(obj);
            ++ptr;
    }

private:
    T* ptr;
};

template <class C> nochecking_sequence<typename C::value_type>
nochecking(C& cnt)
{
    return nochecking_sequence<typename C::value_type>(&cnt[0]);
}

} // namespace xxcxx

#endif /* XXCXX_NOCHECKING_SEQUENCE_HPP_INCLUDED */

