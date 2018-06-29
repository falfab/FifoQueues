#pragma once

namespace fifo_queues {

template<typename T>
QueueObject<T>::QueueObject(size_t size) {
    _size = size;
    _length = 0;
}

template<typename T>
QueueObject<T>::~QueueObject() {};

} // namespace fifo_queues
