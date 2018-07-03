#pragma once

#include <iosfwd>
namespace fifo_queues{

template <typename R>
class Contiguous;   // forward declaration

template <typename R>
class Linked;       // forward declaration

} // namespace fifo_queues


namespace nodes {

template <typename R>
class ArrayNode;    // forward declaration

} // namespace nodes

template <typename R>
std::ostream& operator<< (std::ostream&                     stream,
                          const fifo_queues::Contiguous<R>& c     );

template<typename R>
fifo_queues::Contiguous<R> operator+ (fifo_queues::Contiguous<R>& c1, fifo_queues::Contiguous<R>& c2);

template <typename R>
std::ostream& operator<< (std::ostream&                 stream,
                          const fifo_queues::Linked<R>& c     );

template <typename R>
fifo_queues::Linked<R> operator+ (fifo_queues::Linked<R>& l1, fifo_queues::Linked<R>& l2);

template<typename R>
std::ostream& operator<< (std::ostream&               stream,
                          const nodes::ArrayNode<R>&  node);

#include "impl/Operator.i.hpp"
