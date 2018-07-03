#pragma once

#include <iosfwd>
namespace fifo_queues{

template <typename R>
class ContiguousQueue;   // forward declaration

template <typename R>
class LinkedQueue;       // forward declaration

} // namespace fifo_queues


namespace nodes {

template <typename R>
class ArrayNode;    // forward declaration

} // namespace nodes

template <typename R>
std::ostream& operator<< (std::ostream&                          stream,
                          const fifo_queues::ContiguousQueue<R>& c     );

template<typename R>
fifo_queues::ContiguousQueue<R> operator+ (fifo_queues::ContiguousQueue<R>& c1, fifo_queues::ContiguousQueue<R>& c2);

template <typename R>
std::ostream& operator<< (std::ostream&                      stream,
                          const fifo_queues::LinkedQueue<R>& c     );

template <typename R>
fifo_queues::LinkedQueue<R> operator+ (fifo_queues::LinkedQueue<R>& l1, fifo_queues::LinkedQueue<R>& l2);

template<typename R>
std::ostream& operator<< (std::ostream&              stream,
                          const nodes::ArrayNode<R>& node);

#include "impl/Operator.i.hpp"
