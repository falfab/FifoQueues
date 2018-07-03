#pragma once

/**
 * @brief Nodes namespace
 */
namespace nodes {

/**
 * @brief Node interface
 * @tparam T
 */
template<typename T>
class NodeObject {

public:
    /**
     * @brief Return the pointer to the next node
     * @return
     */
    virtual NodeObject<T> *next() const = 0;

    /**
     * @brief Set the pointer to the next node
     * @param node
     */
    virtual void next(NodeObject<T>* node) = 0;

protected:
    /**
     * @brief
     */
    explicit NodeObject() = default;

    /**
     * @brief
     */
    virtual ~NodeObject() = default;
};

} // namespace nodes

