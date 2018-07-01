#include <iostream>
#include <ContiguousNode.hpp>
#include <LinkedContiguous.hpp>

#include "Linked.hpp"
#include "Contiguous.hpp"

int main(){
//    std::cout << "Hello, world!" << std::endl;
//    auto l = new fifo_queues::Linked<int>(10);
//
//    l->push(10);
//    l->push(20);
//
//    std::cout << l->to_string() << std::endl;
//
//    int val = l->pop();
//    std::cout << "Popped value: " << val << std::endl;
//
//    std::cout << l->to_string() << std::endl;
//    delete l;
//
//    fifo_queues::Linked<int> g(10);
//
//    g.push(30);
//    g.push(40);
//    g.push(50);
//    g.push(60);
//    std::cout << "Hello" << std::endl;
//
//    std::cout << g << std::endl;
//
//    fifo_queues::Linked<int> h(5);
//    h.push(3);
//    h.push(4);
//
//    auto f = g + h;
//
//    std::cout << f << std::endl;
//
//    auto k = new fifo_queues::Linked<int>(f);
//
//    std::cout << *k << std::endl;

//    auto a = new int[3] {10, 20, 30};
//
//    std::cout << sizeof(a) / sizeof(*a) << std::endl;
//
//    auto n = new fifo_queues::ScalarNode<int[]> (a);
//
//    auto v = n->value();
//
//    for (size_t i = 0; i < n->size(); i++) {
//        std::cout << i << ": " << v[i] << std::endl;
//    }
//
//    delete n;
//
//    fifo_queues::ScalarNode<fifo_queues::Contiguous<int>> c(1);

//    fifo_queues::ContiguousNode c(10);

    fifo_queues::LinkedContiguous<int> c(10);

}
