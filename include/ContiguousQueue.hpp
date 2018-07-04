#pragma once

#include <iostream>

#include "QueueObject.hpp"
#include "Operator.hpp"

namespace fifo_queues {

/**
 * @brief Queue with contiguous allocation
 * @tparam T
 */
template <typename T>
class ContiguousQueue : public QueueObject<T> {

    using QueueObject<T>::_length;
    using QueueObject<T>::_size;

public:
    /**
     * @brief Create a queue of desired size
     * @param size
     */
    explicit ContiguousQueue(size_t size);

    /**
     * @brief Copy constructor
     * @param c
     */
    ContiguousQueue(const ContiguousQueue<T> &c);

    /**
     * @brief Destroyer
     */
    ~ContiguousQueue() override;

    /**
     * @brief Push element in queue
     * @param element
     */
    void push(T element) override;

    /**
     * @brief Pop element from queue
     * @return
     */
    T pop() override;

    /**
     * @brief Return the number of element in queue
     * @return
     */
    size_t length() const override;

    /**
     * @brief Return a string representation of the object
     * @return
     */
    std::string to_string() const override;

    /**
     * @brief Return the size of the queue
     * @return
     */
    size_t size() const override;

    /**
     * @brief Return the vector representation of the queue
     * @return
     */
    std::vector<T> to_vector() const override;

    /**
     * @brief Return the desired element at index position
     * @param index
     * @return
     */
    const T& operator[] (size_t index) const;
    T& operator[] (size_t index);

    /**
     * @brief Assignment operator overload
     * @param c
     * @return
     */
    ContiguousQueue<T>& operator=(const ContiguousQueue<T>& c);

    /**
     * @brief Stream operator overload
     * @tparam R
     * @param stream
     * @param c
     */
    template<typename R>
    friend std::ostream& (::operator<<)(std::ostream&        stream,
                                        const ContiguousQueue<R>& c);

    /**
     * @brief Concatenation operator
     * @tparam R
     */
    template <typename R>
    friend ContiguousQueue<R> (::operator+) (ContiguousQueue<R>& c1,
                                        ContiguousQueue<R>& c2);

protected:
    /// @brief pointer to the queue
    T* _queue = nullptr;

};

} // namespace fifo_queues

#include "impl/ContiguousQueue.i.hpp"



