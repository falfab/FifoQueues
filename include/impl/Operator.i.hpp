#pragma once

#include <iostream>
#include <ArrayNode.hpp>
#include "ScalarNode.hpp"
#include "Linked.hpp"
#include "Contiguous.hpp"

template <typename R>
std::ostream& operator<<(std::ostream& stream, const fifo_queues::Contiguous<R>& c) {
    return stream << c.to_string();
}

template<typename R>
fifo_queues::Contiguous<R> operator+(fifo_queues::Contiguous<R>& c1, fifo_queues::Contiguous<R>& c2) {
    size_t size_sum = c1.size() + c2.size();
//    size_t length_sum = c1.length() + c2.length();

    fifo_queues::Contiguous<R> r(size_sum);
    for (size_t i = 0; i < c1.length(); i++) {
        r.push(c1[i]);
    }
    for (size_t i = 0; i < c2.length(); i++) {
        r.push(c2[i]);
    }

    return r;
}

template <typename R>
std::ostream& operator<< (std::ostream& stream, const fifo_queues::Linked<R>& c) {
    return stream << c.to_string();
}

template <typename R>
fifo_queues::Linked<R> operator+(fifo_queues::Linked<R>& l1, fifo_queues::Linked<R>& l2) {
    size_t size_sum = l1.size() + l2.size();

    auto values = new R[l1.length() + l2.length()];
    size_t i;
    nodes::ScalarNode<R>* current = l1.head();
    for (i = 0; i < l1.length(); ++i) {
        values[i] = current->value();
        current = static_cast<nodes::ScalarNode<R>*>(current->next());
    }

    current = l2.head();
    for(size_t j = 0; j < l2.length(); ++j) {
        values[i+j] = current->value();
        current = static_cast<nodes::ScalarNode<R>*>(current->next());
    }

    fifo_queues::Linked<R> concat(size_sum);
    for (size_t j = 0; j < l1.length() + l2.length(); ++j) {
        concat.push(values[j]);
    }

    return concat;
}

template<typename R>
std::ostream& operator<< (std::ostream& stream, const nodes::ArrayNode<R>& node){
    std::string s = "[ ";
    for (size_t i = 0; i < node.size(); ++i) {
        if (i < node.size() -1)
            s += std::to_string(node._values[i]) + ", ";
        else
            s += std::to_string(node._values[i]) + " ";
    }
    s += "];";
    return stream << s;
}
