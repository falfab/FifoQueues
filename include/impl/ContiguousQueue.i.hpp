#pragma once

#include "ContiguousQueue.hpp"

namespace fifo_queues {

template<typename T>
std::vector<T> ContiguousQueue<T>::to_vector() const {
    std::vector<T> v;
    for (size_t i = 0; i < _length; ++i)
        v.push_back(_queue[i]);
    return v;
}

} // namespace fifo_queues
