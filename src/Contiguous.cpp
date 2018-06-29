#include "Contiguous.hpp"
#include "Util.hpp"

namespace fifo_queues {



template<typename T>
Contiguous<T>::Contiguous(size_t size) : QueueObject<T>(size) {
    _queue = new T[size];
    _length = 0;
}

template<typename T>
Contiguous<T>::Contiguous(const Contiguous<T> &c) : QueueObject<T>(c._size){
    _queue = new T[c._size];
    for( size_t i = 0; i < c._length; i ++ ) {
        push(c[i]);
    }
}

template<typename T>
void Contiguous<T>::push(T element) {
    if (_length < _size) {
        _queue[_length] = element;
        _length++;
    }
}

template<typename T>
Contiguous<T>::~Contiguous() {
    delete[] _queue;
}

template<typename T>
size_t Contiguous<T>::length() const {
    return _length;
}

template<typename T>
size_t Contiguous<T>::size() const {
    return _size;
}

template<typename T>
T Contiguous<T>::pop() {
    if (_length == 0){
        error("Contiguous::pop() on a empty queue.");
    }

    T elem = _queue[0];
    for (size_t i = 0; i < _length-1; i ++) {
        _queue[i] = _queue[i + 1];
    }
    _length--;
    return elem;
}

template<typename T>
std::string Contiguous<T>::to_string() const {
    std::string s = "[";
    for (size_t i = 0; i < _length; i++) {
        if (i != _length - 1)
            s += std::to_string(_queue[i]) + ", ";
        else
            s += std::to_string(_queue[i]);
    }
    return s += " ];";
}

template<typename T>
T &Contiguous<T>::operator[](size_t index) {
    if (index < _length)
        return _queue[index];
    error("Contiguous::operator[] with an overflow index");
}

template<typename T>
const T &Contiguous<T>::operator[](size_t index) const {
    if (index < _length)
        return _queue[index];
    error("Contiguous::operator[] with an overflow index");
}
template<typename T>
Contiguous<T> &Contiguous<T>::operator=(const Contiguous<T> &c) {
    if (this == &c)
        return *this;
    delete[] _queue;
    _length = 0;
    _size = c.size();
    _queue = new T[_size];
    for (size_t i = 0; i < c.length(); i++) {
        push(c[i]);
    }
    return *this;
}

template class Contiguous<int>;
template class Contiguous<float>;

} // namespace fifo_queues
