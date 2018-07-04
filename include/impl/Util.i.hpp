#pragma once

#include <cstdlib>  // std::exit, EXIT_FAILURE
#include <iostream> // std::cerr

namespace utils {

[[noreturn]]
inline void error(const char* msg) {
    std::cerr << msg << std::endl;
    std::exit(EXIT_FAILURE);
}

template <typename T>
static T first_mismatch(fifo_queues::QueueObject<T> &q1, fifo_queues::QueueObject<T> &q2) {
    auto v1 = q1.to_vector();
    auto v2 = q2.to_vector();

    for(size_t i = 0; i < v1.size() && i < v2.size(); ++i) {
        if (v1[i] != v2[i])
            return v1[i];
    }
    return -1;
};

} // namespace utils
