#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#undef CATCH_CONFIG_MAIN
#include <iomanip>
#include <iostream>
#include "ContiguousQueue.hpp"
#include "ArrayLinkedQueue.hpp"
#include "Util.hpp"

TEST_CASE("Contiguous Queue", "[ContiguousQueue]") {
    using T = int;
    const size_t SIZE = 3;

    fifo_queues::ContiguousQueue<T> q1(SIZE);
    fifo_queues::ContiguousQueue<T> q2(SIZE);

    for( T i = 0; i < static_cast<int>(SIZE); ++i) {
        q1.push(i);
        q2.push(i+ static_cast<int>(SIZE));
    }

    fifo_queues::ContiguousQueue<T> q3(SIZE);
    q3 = q1 + q2;

    for( size_t i = 0; i < 2*SIZE; ++i) {
        REQUIRE(q3[i] == i);
    }
    REQUIRE(q3.length() == 2*SIZE);
    REQUIRE(q3.pop() == 0);
    REQUIRE(q3.length() == 2*SIZE - 1);

    fifo_queues::ContiguousQueue<T> q4(2*SIZE);
    q4 = q3;

    for( size_t i = 0; i < q3.length(); ++i) {
        REQUIRE(q4[i] == q3[i]);
    }
}

TEST_CASE("Linked Queue", "[LinkedQueue]") {
    using T = int;
    const size_t SIZE = 3;

    fifo_queues::LinkedQueue<T> q1(SIZE);
    fifo_queues::LinkedQueue<T> q2(SIZE);

    for( T i = 0; i < static_cast<int>(SIZE); ++i) {
        q1.push(i);
        q2.push(i+ static_cast<int>(SIZE));
    }

    fifo_queues::LinkedQueue<T> q3(SIZE);
    q3 = q1 + q2;

    for( size_t i = 0; i < q3.length(); ++i) {
        REQUIRE(q3[i] == i);
    }
    REQUIRE(q3.length() == 2*SIZE);
    REQUIRE(q3.pop() == 0);

    fifo_queues::LinkedQueue<T> q4(2*SIZE);
    q4 = q3;

    for( size_t i = 0; i < q3.length(); ++i) {
        REQUIRE(q4[i] == q3[i]);
    }
}

TEST_CASE("Array Linked Queue", "[ArrayLinkedQueue]") {
    using T = int;
    const size_t SIZE = 3;
    const size_t ARRAY_SIZE = 3;

    fifo_queues::ArrayLinkedQueue<T, ARRAY_SIZE> q1(SIZE);
    fifo_queues::ArrayLinkedQueue<T, ARRAY_SIZE> q2(SIZE);

    for( T i = 0; i < static_cast<int>(SIZE*ARRAY_SIZE); ++i) {
        q1.push(i);
        q2.push(i+ static_cast<int>(SIZE*ARRAY_SIZE));
    }

    fifo_queues::ArrayLinkedQueue<T, ARRAY_SIZE> q3(SIZE);
    q3 = q1 + q2;

    for( size_t i = 0; i < q3.size(); ++i) {
        if (i < q1.size())
            REQUIRE(q3[i] == q1[i]);
        else
            REQUIRE(q3[i] == q2[i - q1.size()]);
    }
    REQUIRE(q3.length() == 2*SIZE*ARRAY_SIZE);
    REQUIRE(q3.pop() == 0);

    fifo_queues::ArrayLinkedQueue<T, ARRAY_SIZE> q4(2*SIZE);
    q4 = q3;

    for( size_t i = 0; i < q3.size(); ++i) {
        REQUIRE(q4[i] == q3[i]);
    }
}

TEST_CASE("Test Polymorphism Queues", "[TestPolymorphismQueue]") {
    using T = int;
    const size_t SIZE = 3;
    const size_t ARRAY_SIZE = 3;

    const fifo_queues::QueueObject<T>& obj1 = fifo_queues::ContiguousQueue<T>(SIZE);
    const fifo_queues::QueueObject<T>& obj2 = fifo_queues::LinkedQueue<T>(SIZE);
    const fifo_queues::QueueObject<T>& obj3 = fifo_queues::ArrayLinkedQueue<T, ARRAY_SIZE>(SIZE);

    REQUIRE(obj1.size() == SIZE);
    REQUIRE(obj2.size() == SIZE);
    REQUIRE(obj3.size() == SIZE);
}

TEST_CASE("Mismatch Function", "[MismatchFunction]") {
    using T = int;
    const size_t SIZE = 3;
    const size_t ARRAY_SIZE = 3;

    fifo_queues::ContiguousQueue<T> q1(SIZE);
    fifo_queues::LinkedQueue<T> q2(SIZE);
    fifo_queues::ArrayLinkedQueue<T, ARRAY_SIZE> q3(SIZE);

    for (int i = 0; i < static_cast<int>(SIZE)-1; ++i) {
        q1.push(i);
        q2.push(i);
        q3.push(i);
    }

    q1.push(10);
    q2.push(20);
    q3.push(30);

    REQUIRE(utils::first_mismatch<T>(q1,q2) == 10);
    REQUIRE(utils::first_mismatch<T>(q1,q3) == 10);
    REQUIRE(utils::first_mismatch<T>(q2,q1) == 20);
    REQUIRE(utils::first_mismatch<T>(q2,q3) == 20);
    REQUIRE(utils::first_mismatch<T>(q3,q1) == 30);
    REQUIRE(utils::first_mismatch<T>(q3,q2) == 30);
}

TEST_CASE("Heap Allocation", "[HeapAlloc]") {
    using T = int;
    const size_t SIZE = 10;
    const size_t SIZE_ARRAY = 10;
    auto q1 = new fifo_queues::ContiguousQueue<T>(SIZE);
    auto q2 = new fifo_queues::LinkedQueue<T>(SIZE);
    auto q3 = new fifo_queues::ArrayLinkedQueue<T, SIZE_ARRAY>(SIZE);

    delete q1;
    delete q2;
    delete q3;
}
