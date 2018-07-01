#pragma once

#include <iostream>
#include "ScalarNode.hpp"
#include "QueueObject.hpp"

namespace fifo_queues {

template <typename T>
class Linked : public QueueObject<T> {

    using QueueObject<T>::_size;
    using QueueObject<T>::_length;

public:
    explicit Linked() = default;
    explicit Linked(size_t size);
    Linked(const Linked<T> &l);

    ~Linked();

    void push(T element);
    T pop();
    size_t length() const;
    size_t size() const;
    std::string to_string() const;

    const T& operator[] (size_t index) const;

    nodes::ScalarNode<T>* head() const;

protected:
    nodes::ScalarNode<T>* _head;


};

} // namespace fifo_queues



