#pragma once

#include <cstdlib>  // std::exit, EXIT_FAILURE
#include <iostream> // std::cerr

namespace fifo_queues {

[[noreturn]]
inline void error(const char* msg) {
    std::cerr << msg << std::endl;
    std::exit(EXIT_FAILURE);
}

} // namespace fifo_queues
