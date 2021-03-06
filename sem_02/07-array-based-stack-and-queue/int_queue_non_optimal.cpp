#include "simple_test.h"

class IntQueue {
public:
    static const int MAX_SIZE = 100;

    IntQueue() : start(-1), end(-1) {}

    bool push(int value) {
        if ((end + 1) % MAX_SIZE == start) {
            return false;  // Cannot push. We are full
        }
        end = (end + 1) % MAX_SIZE;
        values[end] = value;
        if (start == -1) {
            start = end;
        }
        return true;
    }

    bool peek(int& out) const {
        if (isEmpty()) {
            return false;
        }
        out = values[start];
        return true;
    }

    bool pop() {
        if (isEmpty()) {
            return false;
        }
        
        if (start == end) { // We have just one element
            start = end = -1;
        } else {
            start = (start + 1) % MAX_SIZE;
        }
        return true;
    }

    bool isEmpty() const {
        return start == -1 && end == -1;
    }

    friend std::ostream& operator<<(std::ostream& o, const IntQueue& q) {
        if (q.isEmpty()) {
            o << "IntQueue(EMPTY)";
        } else {
            o << "IntQueue(start=" << q.start << ",end=" << q.end << ", values={ ";
            for (int i = q.start; i != q.end; i = (i+1)%MAX_SIZE) {
                o << q.values[i] << " ";
            }
            o << "})";
        }
        return o;
    }

private:
    int start, end;
    int values[MAX_SIZE];
};

int main() {
    IntQueue q;
    int tmp;

    // TestEmptyQueue
    CHECK_EQUAL(q.isEmpty(), true);
    CHECK_EQUAL(q.peek(tmp), false);
    CHECK_EQUAL(q.pop(), false);

    // TestOneElement
    q.push(4);
    CHECK_EQUAL(q.isEmpty(), false);
    CHECK_EQUAL(q.peek(tmp), true);
    CHECK_EQUAL(tmp, 4);
    CHECK_EQUAL(q.pop(), true);

    // TestSeveralElements
    const unsigned int N = 6;
    int testValues[N] = {45, 3, 98, -12312, 0454, 0x1234};
    for (unsigned int i=0; i<N; i++) {
        CHECK_EQUAL(q.push(testValues[i]), true);
    }
    std::cout << "The queue is " << q << std::endl;
    for (unsigned int i=0; !q.isEmpty(); i++) {
        CHECK_EQUAL(q.peek(tmp), true);
        CHECK_EQUAL(tmp, testValues[i]);
        CHECK_EQUAL(q.pop(), true);
    }
    CHECK_EQUAL(q.pop(), false);
    CHECK_EQUAL(q.isEmpty(), true);


    // TestFull
    bool allPushPass = true;
    for (int i=0; i<IntQueue::MAX_SIZE; i++) {
        allPushPass = allPushPass && q.push(i);
    }
    CHECK_EQUAL(allPushPass, true);
    CHECK_EQUAL(q.isEmpty(), false);
    CHECK_EQUAL(q.push(1), false);  // full
    CHECK_EQUAL(q.pop(), true);     // one less
    CHECK_EQUAL(q.push(1), true);   // fill up
    CHECK_EQUAL(q.push(1), false);  // full

    return 0;
}