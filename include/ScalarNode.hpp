#pragma once

#include "NodeObject.hpp"

namespace nodes {

template<typename T>
class ScalarNode : public NodeObject<T> {

public:
    explicit ScalarNode() = default;
    explicit ScalarNode(T value);

    ~ScalarNode();

    NodeObject<T> *next() const override ;
    void next(NodeObject<T>* node) override ;
    const T& value() const;
    void value(T value);

protected:
    T _value;
    ScalarNode<T> *_next = nullptr;
};

} // namespace nodes
