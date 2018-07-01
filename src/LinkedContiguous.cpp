#include "LinkedContiguous.hpp"
#include "Util.hpp"

namespace fifo_queues {

template<typename T>
LinkedContiguous<T>::LinkedContiguous(size_t size) : QueueObject(size) {
    if (size == 0) {
        error("LinkedContiguous::LinkedContiguous(0), cannot create a queue with size=0");
    }

    nodes::ContiguousNode<T>* node = nullptr;
    nodes::ContiguousNode<T>* prev = nullptr;

    for (size_t i = 0; i < size; i++) {
        node = new nodes::ContiguousNode<T>();

        if (i == 0) {
            _head = node;
            prev = node;
        } else {
            prev->next(static_cast<nodes::NodeObject<T>*>(node));
            prev = static_cast<nodes::ScalarNode<T>*>(prev->next());
        }
    }
}


} // namespace fifo_queues
