#pragma once

#include "NodeObject.hpp"
#include "Contiguous.hpp"

namespace nodes {

template <typename T>
class ContiguousNode : NodeObject<T> {
public:
    explicit ContiguousNode() = default;
    explicit ContiguousNode(size_t size);
    explicit ContiguousNode(fifo_queues::Contiguous<T>* queue);
    explicit ContiguousNode(T* array, size_t size);

    ~ContiguousNode() override;

    NodeObject<T> *next() const override;
    void next(NodeObject<T>* node) override;

    const T& operator[] (size_t index) const;

protected:
    fifo_queues::Contiguous<T>* _queue;
    ContiguousNode<T>* _next;
};

} // namespace nodes
