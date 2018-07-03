#pragma once

#include <iostream>
#include "QueueObject.hpp"
#include "ArrayNode.hpp"
#include "Operator.hpp"

namespace fifo_queues {

template <typename T, size_t LENGTH>
class ArrayLinkedQueue : public QueueObject<T> {

    using QueueObject<T>::_size;
    using QueueObject<T>::_length;

public:
    explicit ArrayLinkedQueue() = default;
    explicit ArrayLinkedQueue(size_t size);
    ArrayLinkedQueue(const ArrayLinkedQueue<T, LENGTH>& queue);

    ~ArrayLinkedQueue();

    void push(T element);
    T pop();
    size_t length() const;
    size_t size() const;
    std::string to_string() const;

    const nodes::ArrayNode<T>& operator[] (size_t index) const;

    template<typename R>
    friend std::ostream& operator<< (std::ostream&                       stream,
                                     const ArrayLinkedQueue<R, LENGTH>&  queue) {
        return stream << queue.to_string();
    }

    ArrayLinkedQueue<T, LENGTH> &operator= (const ArrayLinkedQueue<T, LENGTH>& l);

protected:
    nodes::ArrayNode<T>* _head;
};

} // namespace fifo_queues

#include "impl/ArrayLinkedQueue.i.hpp"




