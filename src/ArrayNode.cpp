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
}

template<typename T>
ArrayNode<T>::ArrayNode(const ArrayNode &node) : _size(node._size) {
    _values = new T[_size];
    for (size_t i = 0; i < _size; ++i) {
        _values[i] = node._values[i];
    }
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

template class ArrayNode<int>;
template class ArrayNode<float>;

} // namespace array_node
