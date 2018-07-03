#pragma once

#include "NodeObject.hpp"

namespace nodes {

/**
 * @brief Node containing a scalar
 * @tparam T
 */
template<typename T>
class ScalarNode : public NodeObject<T> {

public:
    /**
     * @brief Default deleted constructor
     */
    explicit ScalarNode() = default;

    /**
     * @brief Create a node with desired value
     * @param value
     */
    explicit ScalarNode(T value);

    /**
     * @brief Destroyer
     */
    ~ScalarNode();

    /**
     * @brief Return pointer to next node
     * @return
     */
    NodeObject<T> *next() const override;

    /**
     * @brief Set pointer to next node
     * @param node
     */
    void next(NodeObject<T>* node) override;

    /**
     * @brief Return the value in the node
     * @return
     */
    const T& value() const;

    /**
     * @brief Set the value in the node
     * @param value
     */
    void value(T value);

protected:
    /// @brief The scalar
    T _value;

    /// @brief The pointer to next node
    ScalarNode<T> *_next = nullptr;
};

} // namespace nodes
