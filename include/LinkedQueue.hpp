#pragma once

#include <iostream>
#include "ScalarNode.hpp"
#include "QueueObject.hpp"
#include "Operator.hpp"

namespace fifo_queues {

/**
 * @brief Linked queue
 * @tparam T
 */
template <typename T>
class LinkedQueue : public QueueObject<T> {

    using QueueObject<T>::_size;
    using QueueObject<T>::_length;

public:
    /**
     * @brief Default deleted constructor
     */
    explicit LinkedQueue() = delete;

    /**
     * @brief Create a queue of desired size
     * @param size
     */
    explicit LinkedQueue(size_t size);

    /**
     * @brief Copy constructor
     * @param l
     */
    LinkedQueue(const LinkedQueue<T> &l);

    /**
     * @brief Destroyer
     */
    ~LinkedQueue();

    /**
     * @brief Push an element into queue
     * @param element
     */
    void push(T element) override;

    /**
     * @brief Pop a element from queue
     * @return
     */
    T pop() override;

    /**
     * @brief Return the number of elements into queue
     * @return
     */
    size_t length() const override;

    /**
     * @brief Return the size of the queue
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
     * @brief Return the element at index position
     * @param index
     * @return
     */
    const T& operator[] (size_t index) const;
//    T& operator[] (size_t index);

    /**
     * @brief Concatenation operator
     * @tparam R
     */
    template <typename R>
    friend LinkedQueue<R> (::operator+) (LinkedQueue<R>& l1,
                                         LinkedQueue<R>& l2);

    /**
     * @brief Assignment operator overload
     * @param l1
     * @return
     */
    LinkedQueue<T> &operator= (const LinkedQueue<T>& l1);

    /**
     * @brief Return the pointer to the first node of queue
     * @return
     */
    nodes::ScalarNode<T>* head() const;

protected:
    /// @brief Pointer to the first node
    nodes::ScalarNode<T>* _head;


};

} // namespace fifo_queues

#include "impl/LinkedQueue.i.hpp"
