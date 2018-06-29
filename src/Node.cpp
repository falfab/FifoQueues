#include "Node.hpp"

namespace fifo_queues {

template<typename T>
Node<T>::Node(T value) : _value(value) {}

template<typename T>
Node<T> *Node<T>::next() const{
    return _next;
}

template<typename T>
void Node<T>::next(Node<T>* node) {
    _next = node;
}

template<typename T>
const T Node<T>::value() const{
    return _value;
}

template<typename T>
Node<T>::~Node() {
    delete _next;
}

template<typename T>
void Node<T>::value(T value) {
    _value = value;
}

template class Node<int>;
template class Node<float>;

} // namespace fifo_queues
