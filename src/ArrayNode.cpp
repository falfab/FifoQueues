#include "ArrayNode.hpp"

#include "Util.hpp"

namespace nodes {

template<typename T>
ArrayNode<T>::ArrayNode(size_t size) : _size(size){
    _values = new T[_size];
}

template<typename T>
ArrayNode<T>::ArrayNode(T *values, size_t size) : _size(size) {
    _values = new T[_size];
    for (size_t i = 0; i < _size; ++i) {
        _values[i] = values[i];
    }
    _length = _size;
}

template<typename T>
ArrayNode<T>::ArrayNode(const ArrayNode &node) : _size(node._size) {
    _values = new T[_size];
    for (size_t i = 0; i < _size; ++i) {
        _values[i] = node._values[i];
    }
    _length = node._length;
}

template<typename T>
NodeObject<T> *ArrayNode<T>::next() const {
    return _next;
}

template<typename T>
void ArrayNode<T>::next(NodeObject<T> *node) {
    _next = static_cast<ArrayNode<T>*>(node);
}

template<typename T>
ArrayNode<T>::~ArrayNode() {
    delete[] _values;
    delete _next;
}
template<typename T>
const T &ArrayNode<T>::operator[](size_t index) {
    if (index >= _size) {
//        error("ArrayNode::operator[] index out of bound");
    }

    return _values[index];
}

template<typename T>
size_t ArrayNode<T>::size() const {
    return _size;
}

template<typename T>
T ArrayNode<T>::pop() {
    if (_length <= 0)
        utils::error("ArrayNode::pop() pop on an empty queue");
    T value = _values[0];
    for (size_t i = 1; i < _size; ++i) {
        _values[i - 1] = _values[i];
    }

    if (_next != nullptr) {
        auto n = _next->pop();
        _values[_size - 1] = n;
    } else {
        _values[_size - 1] = 0;
    }

    return value;
}

template<typename T>
void ArrayNode<T>::push(T value) {
    if (_length >= _size)
        if (_next != nullptr)
            _next->push(value);
        else
            utils::error("ArrayNode::push() pop on a full queue");
    else {
        _values[_length] = value;
        _length++;
    }
}

template<typename T>
const std::string ArrayNode<T>::to_string() const {
    std::string s = "[ ";
    for (size_t i = 0; i < _size; ++i) {
        if (i < _size -1) {
            s += std::to_string(_values[i]) + ", ";
        } else {
            s += std::to_string(_values[i]) + " ";
        }
    }
    return s + "]";
}
template<typename T>
bool ArrayNode<T>::operator==(const ArrayNode<T> &node) const {
    if (_length != node._length)
        return false;
    for (size_t i = 0; i < _length; ++i) {
        if (_values[i] != node._values[i])
            return false;
    }
    return true;
}

template class ArrayNode<int>;
template class ArrayNode<float>;

} // namespace array_node
