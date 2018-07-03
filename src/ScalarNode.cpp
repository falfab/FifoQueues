#include <ContiguousQueue.hpp>
#include "ScalarNode.hpp"

namespace nodes {

template<typename T>
ScalarNode<T>::ScalarNode(T value) {
    _value = value;
}

template<typename T>
NodeObject<T> *ScalarNode<T>::next() const{
    return _next;
}

template<typename T>
void ScalarNode<T>::next(NodeObject<T>* node) {
    _next = static_cast<ScalarNode<T>*>(node);
}

template<typename T>
const T& ScalarNode<T>::value() const{
    return _value;
}

template<typename T>
ScalarNode<T>::~ScalarNode() {
    delete _next;
}

template<typename T>
void ScalarNode<T>::value(T value) {
    _value = value;
}

template class ScalarNode<int>;
template class ScalarNode<float>;
//template class ScalarNode<int[]>;

} // namespace nodes
