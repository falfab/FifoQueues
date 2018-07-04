#pragma once

#include <iostream>
#include "QueueObject.hpp"
#include "ArrayNode.hpp"
#include "Operator.hpp"

namespace fifo_queues {

/**
 * @brief           Pointer queue with array nodes
 * @tparam T        Type of contained data
 * @tparam LENGTH   Length of each array node
 */
template <typename T, size_t LENGTH>
class ArrayLinkedQueue : public QueueObject<T> {

    using QueueObject<T>::_size;
    using QueueObject<T>::_length;

public:
    /**
     * @brief Default deleted constructor
     */
    explicit ArrayLinkedQueue() = delete;

    /**
     * @brief Create the queue with the specified size
     * @param size
     */
    explicit ArrayLinkedQueue(size_t size);

    /**
     * @brief Copy constructor
     * @param queue
     */
    ArrayLinkedQueue(const ArrayLinkedQueue<T, LENGTH>& queue);

    /**
     * @brief Destroyer
     */
    ~ArrayLinkedQueue();

    /**
     * @brief Append element to tail
     * @param element
     */
    void push(T element) override;

    /**
     * @brief Pop the first element of the queue
     * @return
     */
    T pop() override;

    /**
     * @brief Length getter
     * @return
     */
    size_t length() const override;

    /**
     * @brief Size Getter
     * @return
     */
    size_t size() const override;

    /**
     * @brief Return a string representation of the object
     * @return
     */
    std::string to_string() const override;

    /**
     * @brief Return the vector representation of the queue
     * @return
     */
    std::vector<T> to_vector() const override;

    /**
     * @brief Return the element in queue at index position
     * @param index
     * @return
     */
    const nodes::ArrayNode<T>& operator[] (size_t index) const;

    /**
     * @brief Put the object in string representation into a stream
     * @tparam R
     * @param stream
     * @param queue
     * @return
     */
    template<typename R>
    friend std::ostream& operator<< (std::ostream&                       stream,
                                     const ArrayLinkedQueue<R, LENGTH>&  queue) {
        return stream << queue.to_string();
    }

    /**
     * @brief Assignment override
     * @param l
     * @return
     */
    ArrayLinkedQueue<T, LENGTH> &operator= (const ArrayLinkedQueue<T, LENGTH>& l);

    /**
     * @brief Concatenation operator
     * @tparam R
     */
    template <typename R, size_t L>
    friend ArrayLinkedQueue<R, L> (::operator+) (ArrayLinkedQueue<R, L>& c1,
                                              ArrayLinkedQueue<R, L>& c2);

protected:
    /// @brief Points to the first node of the queue
    nodes::ArrayNode<T>* _head;
};

} // namespace fifo_queues

#include "impl/ArrayLinkedQueue.i.hpp"




