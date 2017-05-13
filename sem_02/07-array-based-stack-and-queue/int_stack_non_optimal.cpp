#include "simple_test.h"

class IntStack {
public:
    static const int MAX_SIZE = 100;

    IntStack() : top(-1) {}

    bool push(int value) {
        if (top == MAX_SIZE-1) {
            return false;
        }
        top++;
        values[top] = value;
        return true;
    }

    bool peek(int& out) const {
        if (isEmpty()) {
            return false;
        }
        out = values[top];
        return true;
    }

    bool pop() {
        if (isEmpty()) {
            return false;
        }
        top--;
        return true;
    }

    bool isEmpty() const {
        return top == -1;
    }

    friend std::ostream& operator<<(std::ostream& o, const IntStack& s) {
        if (s.isEmpty()) {
            o << "IntStack(EMPTY)";
        } else {
            o << "IntStack(top=" << s.top << ", values={(bottom)>";
            for (int i = 0; i <= s.top; i++) {
                o << s.values[i] << ">";
            }
            o << "(top)})";
        }
        return o;
    }

private:
    int top;
    int values[MAX_SIZE];
};

int main() {
    IntStack s;
    int tmp;

    // TestEmptyStack
    CHECK_EQUAL(s.isEmpty(), true);
    CHECK_EQUAL(s.peek(tmp), false);
    CHECK_EQUAL(s.pop(), false);

    // TestOneElement
    s.push(4);
    CHECK_EQUAL(s.isEmpty(), false);
    CHECK_EQUAL(s.peek(tmp), true);
    CHECK_EQUAL(tmp, 4);
    CHECK_EQUAL(s.pop(), true);

    // TestSeveralElements
    const unsigned int N = 6;
    int testValues[N] = {45, 3, 98, -12312, 0454, 0x1234};
    for (unsigned int i=0; i<N; i++) {
        CHECK_EQUAL(s.push(testValues[i]), true);
    }
    std::cout << "The stack is " << s << std::endl;
    // elements are pop-ed in reverse order
    for (unsigned int i=N-1; !s.isEmpty(); i--) {
        CHECK_EQUAL(s.peek(tmp), true);
        CHECK_EQUAL(tmp, testValues[i]);
        CHECK_EQUAL(s.pop(), true);
    }
    CHECK_EQUAL(s.pop(), false);
    CHECK_EQUAL(s.isEmpty(), true);


    // TestFull
    bool allPushPass = true;
    for (int i=0; i<IntStack::MAX_SIZE; i++) {
        allPushPass = allPushPass && s.push(i);
    }
    CHECK_EQUAL(allPushPass, true);
    CHECK_EQUAL(s.isEmpty(), false);
    CHECK_EQUAL(s.push(1), false);  // full
    CHECK_EQUAL(s.pop(), true);     // one less
    CHECK_EQUAL(s.push(1), true);   // fill up
    CHECK_EQUAL(s.push(1), false);  // full

    return 0;
}