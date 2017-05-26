#include "simple_test.h"
#include <cstdlib>

struct IntNode {
    int data;
    IntNode* next;
};

class IntStack {    
public:
    IntStack();
    IntStack(const IntStack& other);
    ~IntStack();
    IntStack& operator=(const IntStack& other);

    void push(int value);
    int peek() const;
    void pop();
    bool isEmpty() const;

    friend std::ostream& operator<<(std::ostream& o, const IntStack& s) {
        if (s.isEmpty()) {
            o << "IntStack(EMPTY)";
        } else {
            o << "IntStack({(bottom) > ";
            for (IntNode* t = s.start; t != NULL; t = t->next) {
                o << t->data << " > ";
            }
            o << "(top)})";
        }
        return o;
    }

private:
    IntNode* start;
};

IntStack::IntStack() : start(NULL) {}
    
IntStack::IntStack(const IntStack& other) : start(NULL) {
    if(other.isEmpty()) { 
        return; 
    }
    start = new IntNode;
    start->data = other.start->data;
    start->next = NULL;
    
    IntNode* tmpOther = other.start->next;
    IntNode* tmpThis = start;

    while(tmpOther != NULL) {
        tmpThis->next = new IntNode;
        tmpThis = tmpThis->next;
        tmpThis->next = NULL;
        tmpThis->data = tmpOther->data;
        tmpOther = tmpOther->next;
    }
}

IntStack::~IntStack() {
    while(!isEmpty()) {
        pop();
    }
}

IntStack& IntStack::operator=(const IntStack& other) {
    if(&other == this) { 
        return *this; 
    }

    // erase
    while(!isEmpty()) {
        pop();
    }

    // copy
    start = new IntNode;
    start->data = other.start->data;
    start->next = NULL;
    
    IntNode* tmpOther = other.start->next;
    IntNode* tmpThis = start;

    while(tmpOther != NULL) {
        tmpThis->next = new IntNode;
        tmpThis = tmpThis->next;
        tmpThis->next = NULL;
        tmpThis->data = tmpOther->data;
        tmpOther = tmpOther->next;
    }

    return *this;
}

void IntStack::push(int value) {
    IntNode* tmp = new IntNode;
    tmp->next = start;
    tmp->data = value;
    start = tmp;
}

int IntStack::peek() const {
    if (isEmpty()) {
        std::exit(1);
    }
    return start->data;
}

void IntStack::pop() {
    if (isEmpty()) {
        std::exit(1);
    }
    IntNode* tmp = start;
    start = start->next;
    delete tmp;
}

bool IntStack::isEmpty() const {
    return start == NULL;
}


int main() {
    IntStack s;
    
    // TestEmptyStack
    CHECK_EQUAL(s.isEmpty(), true);
    
    // TestOneElement
    s.push(4);
    CHECK_EQUAL(s.isEmpty(), false);
    CHECK_EQUAL(s.peek(), 4);
    s.pop();
    CHECK_EQUAL(s.isEmpty(), true);
    
    // TestSeveralElements
    const unsigned int N = 6;
    int testValues[N] = {45, 3, 98, -12312, 0454, 0x1234};
    for (unsigned int i=0; i<N; i++) {
        s.push(testValues[i]);
    }
    std::cout << "The stack is " << s << std::endl;
    // elements are pop-ed in reverse order
    for (unsigned int i=N-1; !s.isEmpty(); i--) {
        CHECK_EQUAL(s.peek(), testValues[i]);
        s.pop();
    }
    CHECK_EQUAL(s.isEmpty(), true);
    return 0;
}