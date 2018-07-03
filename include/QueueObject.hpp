#pragma once
#include <cstddef> // size_t

/**
 * @brief Queues namespace
 */
namespace fifo_queues {

/**
 * @brief Queues abstract class
 * @tparam T
 */
template <typename T>
class QueueObject {
public:
    /**
     * @brief Push element into queue
     * @param element
     */
    virtual void push(T element)= 0;

    /**
     * @brief Pop element from queue
     * @return
     */
    virtual T pop()= 0;

    /**
     * @brief Return the number of nodes into queue
     * @return
     */
    virtual size_t length() const = 0;

    /**
     * @brief Return the size of the queue
     * @return
     */
    virtual size_t size() const = 0;

    /**
     * @brief Return a string representation of the queue
     * @return
     */
    virtual std::string to_string() const = 0;

protected:
    /// @brief Number of nodes
    size_t _length;
    /// @brief Size of queue
    size_t _size;

    /**
     * @brief
     * @param size
     */
    explicit QueueObject(size_t size);

    /**
     * @brief
     */
    virtual ~QueueObject()= 0;
};

} // namespace fifo_queues

#include "impl/QueueObject.i.hpp"



