#pragma once
#include <cstddef> // size_t

namespace fifo_queues {

template <typename T>
class QueueObject {
public:
    virtual void push(T element)= 0;
    virtual T pop()= 0;
    virtual size_t length() const = 0;
    virtual size_t size() const = 0;
    virtual std::string to_string() const = 0;

protected:
    size_t _length;
    size_t _size;

    explicit QueueObject(size_t size);
    virtual ~QueueObject()= 0;
};

} // namespace fifo_queues

#include "impl/QueueObject.i.hpp"



