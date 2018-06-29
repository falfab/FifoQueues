#pragma once

#include <iostream>
//#include <Contiguous.hpp>

template <typename R>
std::ostream& operator<<(std::ostream& stream, const fifo_queues::Contiguous<R>& c) {
    return stream << c.to_string();
}

template<typename R>
fifo_queues::Contiguous<R> operator+(fifo_queues::Contiguous<R>& c1, fifo_queues::Contiguous<R>& c2) {
    size_t size_sum = c1.size() + c2.size();
//    size_t length_sum = c1.length() + c2.length();

    fifo_queues::Contiguous<R> r (size_sum);
    for (size_t i = 0; i < c1.length(); i++) {
        r.push(c1[i]);
    }
    for (size_t i = 0; i < c2.length(); i++) {
        r.push(c2[i]);
    }

    return r;
}
