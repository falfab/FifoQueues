#pragma once

namespace fifo_queues {

template<typename T>
class Node {

public:
    explicit Node() = default;
    explicit Node(T value);

    ~Node();

    Node<T> *next() const;
    void next(Node<T>* node);
    const T value() const;
    void value(T value);

protected:
    T _value;
    Node<T> *_next = nullptr;
};

} // namespace fifo_queues
