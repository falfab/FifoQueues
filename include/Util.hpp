#pragma once

namespace utils {

[[noreturn]]
inline void error(const char* msg);

} // namespace utils

#include "impl/Util.i.hpp"
