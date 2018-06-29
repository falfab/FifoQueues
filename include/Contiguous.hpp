#pragma once

#include <array>
#include <iostream>

#include "QueueObject.hpp"
#include "Operator.hpp"

namespace fifo_queues {

template <typename T>
class Contiguous : public QueueObject<T> {

    using QueueObject<T>::_length;
    using QueueObject<T>::_size;

public:
    explicit Contiguous(size_t size);
    Contiguous(const Contiguous<T> &c);
    ~Contiguous() override;

    void push(T element) override;
    T pop() override;
    size_t length() const override;
    std::string to_string() const override;
    size_t size() const override;

    const T& operator[] (size_t index) const;
    T& operator[] (size_t index);

    Contiguous<T>& operator=(const Contiguous<T>& c);

    template<typename R>
    friend std::ostream& (::operator<<)(std::ostream&        stream,
                                        const Contiguous<R>& c);

    template <typename R>
    friend Contiguous<R> (::operator+) (Contiguous<R>& c1,
                                        Contiguous<R>& c2);

protected:
    T* _queue = nullptr;

};

} // namespace fifo_queues



