#include "simple_test.h"
#include <cstdlib>

struct IntNode {
    int data;
    IntNode* next;
};

class IntQueue {    
public:
    IntQueue();
    IntQueue(const IntQueue& other);
    ~IntQueue();
    IntQueue& operator=(const IntQueue& other);

    void push(int value);
    int peek() const;
    void pop();
    bool isEmpty() const;

    friend std::ostream& operator<<(std::ostream& o, const IntQueue& s) {
        if (s.isEmpty()) {
            o << "IntQueue(EMPTY)";
        } else {
            o << "IntQueue({(front) < ";
            for (IntNode* t = s.start; t != NULL; t = t->next) {
                o << t->data << " < ";
            }
            o << "(back)})";
        }
        return o;
    }

private:
    IntNode* start;
    IntNode* end;
};

IntQueue::IntQueue() : start(NULL), end(NULL) {}
    
IntQueue::IntQueue(const IntQueue& other) : start(NULL), end(NULL) {
    IntNode* tmp = other.start;
    while(tmp != NULL) {
        push(tmp->data);
        tmp = tmp->next;
    }
}

IntQueue::~IntQueue() {
    while(!isEmpty()) {
        pop();
    }
}

IntQueue& IntQueue::operator=(const IntQueue& other) {
    if(&other == this) { 
        return *this; 
    }

    // erase
    while(!isEmpty()) {
        pop();
    }

    // copy
    IntNode* tmp = other.start;
    while(tmp != NULL) {
        push(tmp->data);
        tmp = tmp->next;
    }

    return *this;
}

void IntQueue::push(int value) {
    IntNode* tmp = new IntNode;
    tmp->next = NULL;
    tmp->data = value;
    if(isEmpty()) {
        start = end = tmp;
    } else {
        end->next = tmp;
        end = tmp;
    }
}

int IntQueue::peek() const {
    if (isEmpty()) {
        std::exit(1);
    }
    return start->data;
}

void IntQueue::pop() {
    if (isEmpty()) {
        std::exit(1);
    }
    IntNode* tmp = start;
    start = start->next;
    if (start == NULL) {
        end = NULL;
    }
    delete tmp;
}

bool IntQueue::isEmpty() const {
    return start == NULL;
}

int main() {
    IntQueue q;
    int tmp;

    // TestEmptyQueue
    CHECK_EQUAL(q.isEmpty(), true);
    
    // TestOneElement
    q.push(4);
    CHECK_EQUAL(q.isEmpty(), false);
    CHECK_EQUAL(q.peek(), 4);
    q.pop();
    CHECK_EQUAL(q.isEmpty(), true);
    
    // TestSeveralElements
    const unsigned int N = 6;
    int testValues[N] = {45, 3, 98, -12312, 0454, 0x1234};
    for (unsigned int i=0; i<N; i++) {
        q.push(testValues[i]);
    }
    std::cout << "The queue is " << q << std::endl;
    for (unsigned int i=0; !q.isEmpty(); i++) {
        CHECK_EQUAL(q.peek(), testValues[i]);
        q.pop();
    }
    CHECK_EQUAL(q.isEmpty(), true);

    return 0;
}