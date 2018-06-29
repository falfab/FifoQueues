#include <iostream>

#include "Contiguous.hpp"

int main(){
    std::cout << "Hello, world!" << std::endl;
    size_t size = 10;
    fifo_queues::Contiguous<int> c(10);
    c.push(0);
    c.push(1);
    c.push(2);
    c.push(30);

    std::cout << c << std::endl;

    auto a = new fifo_queues::Contiguous<int>(5);
    a->push(1);
    a->push(1);

    std::cout << *a << std::endl;

    auto b = *a + c;

    std::cout << b << std::endl;

    c = b;
    std::cout << c << std::endl;

    fifo_queues::Contiguous<int> d(b);
    std::cout << d << std::endl;

    std::cout << &d << " " << &b << std::endl;

//    c << std::cout;

//    std::cout << std::to_string(c[3]) << std::endl;
}
