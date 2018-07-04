#pragma once

/**
 * @brief Utils namespace
 */
namespace utils {

/**
 * @brief Error handler
 * @param msg
 */
[[noreturn]]
inline void error(const char *msg);

/**
 *
 * @tparam T
 * @tparam LENGTH
 * @param q1
 * @param q2
 * @return
 */
template<typename T>
static T first_mismatch(fifo_queues::QueueObject<T> &q1, fifo_queues::QueueObject<T> &q2);

} // namespace utils

#include "impl/Util.i.hpp"
