#pragma once

#include <cstdlib>  // std::exit, EXIT_FAILURE
#include <iostream> // std::cerr

namespace utils {

[[noreturn]]
inline void error(const char* msg) {
    std::cerr << msg << std::endl;
    std::exit(EXIT_FAILURE);
}

} // namespace utils
