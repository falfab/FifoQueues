#include <iostream>
#include "LinkedQueue.hpp"
#include "Util.hpp"

namespace fifo_queues {

template<typename T>
LinkedQueue<T>::LinkedQueue(size_t size) : QueueObject<T>(size) {
    if (size == 0) {
        utils::error("LinkedQueue::LinkedQueue(0), cannot create a queue with size=0");
    }

    nodes::ScalarNode<T>* node = nullptr;
    nodes::ScalarNode<T>* prev = nullptr;

    for (size_t i = 0; i < size; ++i) {
        node = new nodes::ScalarNode<T>();

        if (i == 0) {
            _head = node;
            prev = node;
        } else {
            prev->next(static_cast<nodes::NodeObject<T>*>(node));
            prev = static_cast<nodes::ScalarNode<T>*>(prev->next());
        }
    }
}

template<typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T> &l) : QueueObject<T>(l._size){
    nodes::ScalarNode<T>* node = nullptr;
    nodes::ScalarNode<T>* prev = nullptr;

    for (size_t i = 0; i < l._size; ++i) {
        node = new nodes::ScalarNode<T>();

        if (i == 0) {
            _head = node;
            prev = node;
        } else {
            prev->next(static_cast<nodes::NodeObject<T>*>(node));
            prev = static_cast<nodes::ScalarNode<T>*>(prev->next());
        }
    }

    node = l._head;
    for (size_t i = 0; i < l._length; ++i) {
        push(node->value());
        node = static_cast<nodes::ScalarNode<T>*>(node->next());
    }
}

template<typename T>
nodes::ScalarNode<T> *LinkedQueue<T>::head() const {
    return _head;
}

template<typename T>
void LinkedQueue<T>::push(T element) {
    if (_size == _length)
        utils::error("LinkedQueue::push() on a full queue");

    nodes::ScalarNode<T>* current = _head;
    for (size_t i = 0; i < _length; ++i) {
        current = static_cast<nodes::ScalarNode<T>*>(current->next());
    }

    current->value(element);

    _length++;
}

template<typename T>
T LinkedQueue<T>::pop() {
    if (_head == nullptr)
        utils::error("LinkedQueue::pop() on an empty queue");

    T value = _head->value();
    auto values = new T[_length];

    nodes::ScalarNode<T>* current = _head;
    for (size_t i = 0; i < _length; ++i) {
        values[i] = current->value();
        current = static_cast<nodes::ScalarNode<T>*>(current->next());
    }

    current = _head;
    for (size_t i = 1; i < _length; ++i) {
        current->value(values[i]);
        current = static_cast<nodes::ScalarNode<T>*>(current->next());
    }

    _length--;
    delete[] values;
    return value;
}

template<typename T>
LinkedQueue<T>::~LinkedQueue() {
    delete _head;
}

template<typename T>
size_t LinkedQueue<T>::length() const {
    return _length;
}

template<typename T>
size_t LinkedQueue<T>::size() const {
    return _size;
}

template<typename T>
std::string LinkedQueue<T>::to_string() const {
    std::string s;

    nodes::ScalarNode<T>* node = _head;

    for (size_t i = 0; i < _size; ++i) {
        if (i != _size - 1)
            s += std::to_string(node->value()) + " -> ";
        else
            s += std::to_string(node->value());
        node = static_cast<nodes::ScalarNode<T>*>(node->next());
    }
    return s += ";";
}

template<typename T>
const T& LinkedQueue<T>::operator[](size_t index) const{
    if (index < _length && index >= 0) {
        nodes::ScalarNode<T>* node = _head;
        for (size_t i = 0; i < index; i ++) {
            node = static_cast<nodes::ScalarNode<T>*>(node->next());
        }
        return node->value();
    }
    utils::error("LinkedQueue::[] Index out of bound.");
}

//template<typename T>
//T &LinkedQueue<T>::operator[](size_t index) {
//    if (index < _length && index > 0) {
//        nodes::ScalarNode<T>* node = _head;
//        for (size_t i = 0; i < index; i ++) {
//            node = static_cast<nodes::ScalarNode<T>*>(node->next());
//        }
//        return &node->value();
//    }
//    utils::error("LinkedQueue::[] Index out of bound.");
//}

template<typename T>
LinkedQueue<T> &LinkedQueue<T>::operator=(const LinkedQueue<T> &l1) {
    if (this == &l1)
        return *this;

    delete _head;
    nodes::ScalarNode<T>* current = nullptr;
    nodes::ScalarNode<T>* prev = nullptr;
    for (size_t i = 0; i < l1._size; i++) {
        current = new nodes::ScalarNode<T>(l1[i]);
        if (i == 0)
            _head = current;
        if (prev != nullptr)
            prev->next(current);
        prev = current;
    }
    return *this;
}

template class LinkedQueue<int>;
template class LinkedQueue<float>;

} // namespace fifo_queues
