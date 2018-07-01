#pragma once

#include <iostream>
#include "QueueObject.hpp"
#include "ContiguousNode.hpp"

namespace fifo_queues {

template <typename T>
class LinkedContiguous : public QueueObject<T> {

    using QueueObject<T>::_size;
    using QueueObject<T>::_length;

public:
    explicit LinkedContiguous() = default;
    explicit LinkedContiguous(size_t size);
    explicit LinkedContiguous(const LinkedContiguous<T>& l);

    ~LinkedContiguous();

    void push(T element);
    T pop();
    size_t length() const;
    size_t size() const;
    std::string to_string() const;

protected:
    nodes::ContiguousNode<T>* _head;
};

} // namespace fifo_queues
