#pragma once

#include "ArrayNode.hpp"
#include "ArrayLinkedQueue.hpp"
#include "Util.hpp"


namespace fifo_queues {


template<typename T, size_t LENGTH>
ArrayLinkedQueue<T, LENGTH>::ArrayLinkedQueue(size_t size) : QueueObject<T>(size) {
    if (size == 0)
        utils::error("ArrayLinkedQueue::ArrayLinkedQueue(0), cannot create a queue with size=0");

    nodes::ArrayNode<T>* node = nullptr;
    nodes::ArrayNode<T>* prev = nullptr;

    for (size_t i = 0; i < _size; ++i) {
        node = new nodes::ArrayNode<T>(LENGTH);

        if (i == 0) {
            _head = node;
            prev = node;
        } else {
            prev->next(static_cast<nodes::NodeObject<T>*>(node));
            prev = static_cast<nodes::ArrayNode<T>*>(prev->next());
        }
    }
}

template<typename T, size_t LENGTH>
ArrayLinkedQueue<T, LENGTH>::ArrayLinkedQueue(const ArrayLinkedQueue<T, LENGTH> &queue) : QueueObject<T>(queue._size){
    nodes::ArrayNode<T>* node = nullptr;
    nodes::ArrayNode<T>* prev = nullptr;

    for (size_t i = 0; i < queue._size; ++i) {
        node = new nodes::ArrayNode<T>(queue[i]);

        if (i == 0) {
            _head = node;
            prev = node;
        } else {
            prev->next(static_cast<nodes::NodeObject<T>*>(node));
            prev = static_cast<nodes::ArrayNode<T>*>(prev->next());
        }
    }


}

template<typename T, size_t LENGTH>
ArrayLinkedQueue<T, LENGTH>::~ArrayLinkedQueue() {
    delete _head;
}

template<typename T, size_t LENGTH>
void ArrayLinkedQueue<T, LENGTH>::push(T element) {
    _head->push(element);
    _length++;
}

template<typename T, size_t LENGTH>
T ArrayLinkedQueue<T, LENGTH>::pop() {
    _length--;
    return _head->pop();
}

template<typename T, size_t LENGTH>
size_t ArrayLinkedQueue<T, LENGTH>::length() const {
    return _length;
}

template<typename T, size_t LENGTH>
size_t ArrayLinkedQueue<T, LENGTH>::size() const {
    return _size;
}

template<typename T, size_t LENGTH>
std::string ArrayLinkedQueue<T, LENGTH>::to_string() const {
    std::string s;

    nodes::ArrayNode<T>* current = _head;

    for (size_t i = 0; i < _size; i ++) {
        s += current->to_string();
        if (i < _size -1)
            s += " -> ";
        current = static_cast<nodes::ArrayNode<T>*>(current->next());
    }
    return s + ";";
}

template<typename T, size_t LENGTH>
ArrayLinkedQueue<T, LENGTH> &ArrayLinkedQueue<T, LENGTH>::operator=(const ArrayLinkedQueue<T, LENGTH> &l) {
    if (this == &l)
        return *this;

    delete _head;
    _length = l._length;
    _size = l._size;
    nodes::ArrayNode<T>* current = nullptr;
    nodes::ArrayNode<T>* prev = nullptr;
    for (size_t i = 0; i < l._size; i ++) {
        current = new nodes::ArrayNode<T>(l[i]);
        if (i == 0)
            _head = current;
        if (prev != nullptr)
            prev->next(current);
        prev = current;
    }
    return *this;
}

template<typename T, size_t LENGTH>
const nodes::ArrayNode<T> &ArrayLinkedQueue<T, LENGTH>::operator[](size_t index) const {
    if (index >= _length || index < 0)
        utils::error("ArrayLinkedQueue::[] index out of bounds");

    nodes::ArrayNode<T>* current = _head;
    for (size_t i = 0; i < index; i ++) {
        current = static_cast<nodes::ArrayNode<T>*>(current->next());
    }
    return *current;
}

} // namespace fifo_queues
