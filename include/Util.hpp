#pragma once

namespace fifo_queues {

[[noreturn]]
inline void error(const char* msg);

} // namespace fifo_queues

#include "impl/Util.i.hpp"
