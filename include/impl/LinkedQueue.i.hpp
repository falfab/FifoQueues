#pragma once

#include "LinkedQueue.hpp"

namespace fifo_queues {

template <typename T>
std::vector<T> LinkedQueue<T>::to_vector() const {
    std::vector<T> v({});
    auto current = _head;
    for(size_t i = 0; i < length(); i++) {
        v.push_back(current->value());
        current = static_cast<nodes::ScalarNode<T>*>(current->next());
    }
    return v;
}

} // namespace fifo_queues
