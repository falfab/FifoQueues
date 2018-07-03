#include <iostream>
#include <ArrayNode.hpp>
#include <ArrayLinkedQueue.hpp>

#include "LinkedQueue.hpp"
#include "ContiguousQueue.hpp"

using namespace std;

int main(){
    fifo_queues::ContiguousQueue<int> q(2);
    fifo_queues::ContiguousQueue<int> r(2);
    q.push(1);q.push(2);
    r.push(3);r.push(4);
    cout << q << endl;
    cout << r << endl;
    r = q;
    cout<< r << endl;

    cout << "----------------------" << endl;

    fifo_queues::LinkedQueue<int> a(2);
    fifo_queues::LinkedQueue<int> b(2);
    a.push(1);b.push(2);
    a.push(3);b.push(4);
    cout << a << endl;
    cout << b << endl;
    a = b;
    cout<< a << endl;

    cout << "----------------------" << endl;

    fifo_queues::ArrayLinkedQueue<int, 2> d(2);
    fifo_queues::ArrayLinkedQueue<int, 2> e(2);
    for (int i = 0; i < 4; ++i) {
        d.push(i);
        e.push(i + 5);
    }
    cout << d << endl;
    cout << e << endl;
    d = e;
    cout << d << endl;
}
