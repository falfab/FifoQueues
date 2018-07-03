#pragma once

#include <iostream>

#include "QueueObject.hpp"
#include "Operator.hpp"

namespace fifo_queues {

template <typename T>
class ContiguousQueue : public QueueObject<T> {

    using QueueObject<T>::_length;
    using QueueObject<T>::_size;

public:
    explicit ContiguousQueue(size_t size);
    ContiguousQueue(const ContiguousQueue<T> &c);
    ~ContiguousQueue() override;

    void push(T element) override;
    T pop() override;
    size_t length() const override;
    std::string to_string() const override;
    size_t size() const override;

    const T& operator[] (size_t index) const;
    T& operator[] (size_t index);

    ContiguousQueue<T>& operator=(const ContiguousQueue<T>& c);

    template<typename R>
    friend std::ostream& (::operator<<)(std::ostream&        stream,
                                        const ContiguousQueue<R>& c);

    template <typename R>
    friend ContiguousQueue<R> (::operator+) (ContiguousQueue<R>& c1,
                                        ContiguousQueue<R>& c2);

protected:
    T* _queue = nullptr;

};

} // namespace fifo_queues



