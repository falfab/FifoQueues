#pragma once

#include <iosfwd>
//#include "Contiguous.hpp"
namespace fifo_queues{

template <typename R>
class Contiguous;   // forward declaration

} // namespace fifo_queues


template <typename R>
std::ostream& operator<< (std::ostream&                     stream,
                          const fifo_queues::Contiguous<R>& c     );

template<typename R>
fifo_queues::Contiguous<R> operator+ (fifo_queues::Contiguous<R>& c1, fifo_queues::Contiguous<R>& c2);

#include "impl/Operator.i.hpp"