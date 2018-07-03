#pragma once

#include <cstddef>
#include <ostream>
#include "NodeObject.hpp"
#include "Operator.hpp"

namespace nodes {

template <typename T>
class ArrayNode : public NodeObject<T> {
public:
    explicit ArrayNode() = delete;
    explicit ArrayNode(size_t size);
    explicit ArrayNode(T* values, size_t size);
    ArrayNode(const ArrayNode& node);

    ~ArrayNode();

    NodeObject<T> *next() const override;
    void next(NodeObject<T>* node) override;

    void push(T value);
    T pop();

    const std::string to_string() const;

    size_t size() const;

    const T& operator [] (size_t index);

    template<typename R>
    friend std::ostream& (::operator<<) (std::ostream&        stream,
                                         const ArrayNode<R>&  node);

protected:
    T* _values;
    size_t _size;
    size_t _length {0};

    ArrayNode<T>* _next = nullptr;
};

} // namespace fifo_queues



