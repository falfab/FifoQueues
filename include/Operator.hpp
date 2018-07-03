#pragma once

#include <iosfwd>
namespace fifo_queues{

template <typename R>
class ContiguousQueue;   // forward declaration

template <typename R>
class LinkedQueue;       // forward declaration

template <typename R, size_t T>
class ArrayLinkedQueue;

} // namespace fifo_queues


namespace nodes {

template <typename R>
class ArrayNode;    // forward declaration

} // namespace nodes

/**
 * @brief Stream operator overload
 * @tparam R
 * @param stream
 * @param c
 * @return
 */
template <typename R>
std::ostream& operator<< (std::ostream&                          stream,
                          const fifo_queues::ContiguousQueue<R>& c     );

/**
 * @brief Concatenation operator
 * @tparam R
 * @param c1
 * @param c2
 * @return
 */
template<typename R>
fifo_queues::ContiguousQueue<R> operator+ (fifo_queues::ContiguousQueue<R>& c1, fifo_queues::ContiguousQueue<R>& c2);

/** Stream operator overload
 * @brief
 * @tparam R
 * @param stream
 * @param c
 * @return
 */
template <typename R>
std::ostream& operator<< (std::ostream&                      stream,
                          const fifo_queues::LinkedQueue<R>& c     );

/**
 * @brief Concatenation operator
 * @tparam R
 * @param l1
 * @param l2
 * @return
 */
template <typename R>
fifo_queues::LinkedQueue<R> operator+ (fifo_queues::LinkedQueue<R>& l1, fifo_queues::LinkedQueue<R>& l2);

/**
 * @brief Stream operator overload
 * @tparam R
 * @param stream
 * @param node
 * @return
 */
template<typename R>
std::ostream& operator<< (std::ostream&              stream,
                          const nodes::ArrayNode<R>& node);

/**
 * @brief Conateniation opertator
 * @tparam R
 * @tparam L
 * @param c1
 * @param c2
 * @return
 */
template <typename R, size_t L>
fifo_queues::ArrayLinkedQueue<R, L> operator+ (fifo_queues::ArrayLinkedQueue<R, L>& c1,
                                               fifo_queues::ArrayLinkedQueue<R, L>& c2);

#include "impl/Operator.i.hpp"
