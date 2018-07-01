#pragma once

namespace nodes {

template<typename T>
class NodeObject {

public:
    virtual NodeObject<T> *next() const = 0;
    virtual void next(NodeObject<T>* node) = 0;
    virtual const T value() const = 0;
    virtual void value(T value) = 0;

protected:
    explicit NodeObject() = default;
    virtual ~NodeObject() = default;
};

} // namespace nodes

