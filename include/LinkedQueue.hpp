#pragma once

#include <iostream>
#include "ScalarNode.hpp"
#include "QueueObject.hpp"
#include "Operator.hpp"

namespace fifo_queues {

template <typename T>
class LinkedQueue : public QueueObject<T> {

    using QueueObject<T>::_size;
    using QueueObject<T>::_length;

public:
    explicit LinkedQueue() = default;
    explicit LinkedQueue(size_t size);
    LinkedQueue(const LinkedQueue<T> &l);

    ~LinkedQueue();

    void push(T element);
    T pop();
    size_t length() const;
    size_t size() const;
    std::string to_string() const;

    const T& operator[] (size_t index) const;
//    T& operator[] (size_t index);

    template <typename R>
    friend LinkedQueue<R> (::operator+) (LinkedQueue<R>& l1,
                                         LinkedQueue<R>& l2);

    LinkedQueue<T> &operator= (const LinkedQueue<T>& l1);

    nodes::ScalarNode<T>* head() const;

protected:
    nodes::ScalarNode<T>* _head;


};

} // namespace fifo_queues
