#include "ContiguousNode.hpp"
#include "Util.hpp"

namespace nodes {

template<typename T>
ContiguousNode<T>::ContiguousNode(size_t size) {
    _queue = new fifo_queues::Contiguous<T>(size);
}

template<typename T>
ContiguousNode<T>::ContiguousNode(fifo_queues::Contiguous<T> *queue) {
    _queue = queue;
}

template<typename T>
ContiguousNode<T>::ContiguousNode(T *array, size_t size) {
    _queue = new fifo_queues::Contiguous<T>(size);
    for (size_t i = 0; i < size; ++i) {
        _queue->push(array[i]);
    }
}

template<typename T>
ContiguousNode<T>::~ContiguousNode() {
    delete _queue;
    delete _next;
}

template<typename T>
NodeObject<T> *ContiguousNode<T>::next() const {
    return _next;
}

template<typename T>
void ContiguousNode<T>::next(NodeObject<T> *node) {
    _next = static_cast<ContiguousNode<T>*>(node);
}

template<typename T>
const T &ContiguousNode<T>::operator[](size_t index) const {
    return (*_queue)[index];
}

template class ContiguousNode<int>;
template class ContiguousNode<float>;

} // namespace nodes
