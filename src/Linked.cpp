#include "Linked.hpp"
#include "Util.hpp"
#include <iostream>

namespace fifo_queues {

template<typename T>
Linked<T>::Linked(size_t size) : QueueObject<T>(size) {
    if (size == 0) {
        error("Linked::Linked(0), cannot create a queue with size=0");
    }

    Node<T>* node = nullptr;
    Node<T>* prev = nullptr;

    for (size_t i = 0; i < size; ++i) {
        node = new Node<T>();

        if (i == 0) {
            _head = node;
            prev = node;
        } else {
            prev->next(node);
            prev = prev->next();
        }
    }
}

template<typename T>
Linked<T>::Linked(const Linked<T> &l) : QueueObject<T>(l._size){
    Node<T>* node = nullptr;
    Node<T>* prev = nullptr;

    for (size_t i = 0; i < l._size; ++i) {
        node = new Node<T>();

        if (i == 0) {
            _head = node;
            prev = node;
        } else {
            prev->next(node);
            prev = prev->next();
        }
    }

    node = l._head;
    for (size_t i = 0; i < l._length; ++i) {
        push(node->value());
        node = node->next();
    }
}

template<typename T>
Node<T> *Linked<T>::head() const {
    return _head;
}

template<typename T>
void Linked<T>::push(T element) {
    if (_size == _length)
        error("Linked::push() on a full queue");

    Node<T>* current = _head;
    for (size_t i = 0; i < _length; ++i) {
        current = current->next();
    }

    current->value(element);

    _length++;
}

template<typename T>
T Linked<T>::pop() {
    if (_head == nullptr)
        error("Linked::pop() on an empty queue");

    T value = _head->value();
    auto values = new T[_length];

    Node<T>* current = _head;
    for (size_t i = 0; i < _length; ++i) {
        values[i] = current->value();
        current = current->next();
    }

    current = _head;
    for (size_t i = 1; i < _length; ++i) {
        current->value(values[i]);
        current = current->next();
    }

    _length--;
    delete[] values;
    return value;
}

template<typename T>
Linked<T>::~Linked() {
    Node<T>* node = _head;
    Node<T>* next = nullptr;
    for(size_t i = 0; i < _size; ++i) {
        next = node->next();
        delete node;
        node = next;
    }
}

template<typename T>
size_t Linked<T>::length() const {
    return _length;
}

template<typename T>
size_t Linked<T>::size() const {
    return _size;
}

template<typename T>
std::string Linked<T>::to_string() const {
    std::string s = "[ ";

    Node<T>* node = _head;

    for (size_t i = 0; i < _length; ++i) {
        if (i != _length - 1)
            s += std::to_string(node->value()) + ", ";
        else
            s += std::to_string(node->value());
        node = node->next();
    }
    return s += " ];";
}

template<typename T>
const T& Linked<T>::operator[](size_t index) const {
    if (index < _length && index > 0) {
        Node<T>* node = _head;
        for (size_t i = 0; i < index; i ++) {
            node = node->next();
        }
        return node->value();
    }
    error("Linked::[] Index out of bound.");
}

template class Linked<int>;
template class Linked<float>;

} // namespace fifo_queues
