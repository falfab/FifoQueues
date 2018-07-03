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
inline void error(const char* msg);

} // namespace utils

#include "impl/Util.i.hpp"
