#pragma once

#include <iostream>
#include "ArrayNode.hpp"
#include "ScalarNode.hpp"
#include "LinkedQueue.hpp"
#include "ContiguousQueue.hpp"
#include "ArrayLinkedQueue.hpp"

template <typename R>
std::ostream& operator<<(std::ostream& stream, const fifo_queues::ContiguousQueue<R>& c) {
    return stream << c.to_string();
}

template<typename R>
fifo_queues::ContiguousQueue<R> operator+(fifo_queues::ContiguousQueue<R>& c1, fifo_queues::ContiguousQueue<R>& c2) {
    size_t size_sum = c1.size() + c2.size();
//    size_t length_sum = c1.length() + c2.length();

    fifo_queues::ContiguousQueue<R> r(size_sum);
    for (size_t i = 0; i < c1.length(); i++) {
        r.push(c1[i]);
    }
    for (size_t i = 0; i < c2.length(); i++) {
        r.push(c2[i]);
    }

    return r;
}

template <typename R>
std::ostream& operator<< (std::ostream& stream, const fifo_queues::LinkedQueue<R>& c) {
    return stream << c.to_string();
}

template <typename R>
fifo_queues::LinkedQueue<R> operator+(fifo_queues::LinkedQueue<R>& l1, fifo_queues::LinkedQueue<R>& l2) {
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

    fifo_queues::LinkedQueue<R> concat(size_sum);
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

template <typename R, size_t L>
fifo_queues::ArrayLinkedQueue<R, L> operator+ (fifo_queues::ArrayLinkedQueue<R, L>& c1,
                                               fifo_queues::ArrayLinkedQueue<R, L>& c2) {
    size_t size_sum = c1.size() + c2.size();

    fifo_queues::ArrayLinkedQueue<R, L> concat(size_sum);

    for (size_t i = 0; i < c1.size(); ++i){
        nodes::ArrayNode<R> arr = c1[i];
        for (size_t j = 0; j < arr.size(); ++j){
            concat.push(arr[j]);
        }
    }

    for (size_t i = 0; i < c1.size(); ++i){
        nodes::ArrayNode<R> arr = c2[i];
        for (size_t j = 0; j < arr.size(); ++j){
            concat.push(arr[j]);
        }
    }

    return concat;
}
