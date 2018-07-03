#pragma once

#include <cstddef>
#include <ostream>
#include "NodeObject.hpp"
#include "Operator.hpp"

namespace nodes {

/**
 * @brief Node containing an array
 * @tparam T
 */
template <typename T>
class ArrayNode : public NodeObject<T> {
public:
    /**
     * @brief Default deleted constructor
     */
    explicit ArrayNode() = delete;

    /**
     * @brief Create a node with a desired array size
     * @param size
     */
    explicit ArrayNode(size_t size);

    /**
     * @brief Create a node with desired array size and initialized values
     * @param values
     * @param size
     */
    explicit ArrayNode(T* values, size_t size);

    /**
     * @brief Copy constructor
     * @param node
     */
    ArrayNode(const ArrayNode& node);

    /**
     * @brief Destroyer
     */
    ~ArrayNode();

    /**
     * @brief Get the pointer to next node
     * @return
     */
    NodeObject<T> *next() const override;

    /**
     * @brief Set the next node
     * @param node
     */
    void next(NodeObject<T>* node) override;

    /**
     * @brief Push a value into array
     * @param value
     */
    void push(T value);

    /**
     * @brief Pop a value from array
     * @return
     */
    T pop();

    /**
     * @brief Return a string representation of the object
     * @return
     */
    const std::string to_string() const;

    /**
     * @brief Getter size
     * @return
     */
    size_t size() const;

    /**
     * @brief Return the element at index position in array
     * @param index
     * @return
     */
    const T& operator [] (size_t index);

    /**
     * @brief Stream override
     * @tparam R
     * @param stream
     * @param node
     */
    template<typename R>
    friend std::ostream& (::operator<<) (std::ostream&        stream,
                                         const ArrayNode<R>&  node);

protected:
    /// @brief values array
    T* _values;

    /// @brief size of the array
    size_t _size;

    /// @brief number of elements in array
    size_t _length {0};

    /// @brief pointer to next node
    ArrayNode<T>* _next = nullptr;
};

} // namespace fifo_queues



