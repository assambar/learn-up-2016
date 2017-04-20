#include <iostream>
#include "simple_test.h"

struct Node {
    int data;
    Node* next;
};

unsigned int size(Node* s);
bool getAt(Node* s, unsigned int i, int& outData);

void addFront(Node** s, int value);
void removeFront(Node** s);

Node* findFirst(Note* s, int value);

int main() {
    Node* start = NULL;

    int tempData = -10;  // just some number
    CHECK_EQUAL(getAt(start, 0u, tempData), false); // expect false, because the list is empty
    CHECK_EQUAL(tempData, -1); // expect that the value of tempData remained the same
    CHECK_EQUAL(size(start), 0u); // expect zero size
    CHECK_EQUAL(findFirst(start, 23), NULL);
    
    addFront(&start, 45);
    CHECK_EQUAL(size(start), 1u);
    CHECK_EQUAL(getAt(start, 0u, tempData), true);
    CHECK_EQUAL(tempData, 45);
    CHECK_EQUAL(findFirst(start, 45), start);
    CHECK_EQUAL(findFirst(start, 23), NULL);

    addFront(&start, 23);
    CHECK_EQUAL(size(start), 2u);
    CHECK_EQUAL(getAt(start, 1u, tempData), true);
    CHECK_EQUAL(tempData, 45);
    CHECK_EQUAL(findFirst(start, 45), start->next);
    CHECK_EQUAL(getAt(start, 0u, tempData), true);
    CHECK_EQUAL(tempData, 23);
    CHECK_EQUAL(findFirst(start, 23), start);

    removeFront(&start);
    CHECK_EQUAL(size(start), 1u);
    CHECK_EQUAL(getAt(start, 0u, tempData), true);
    CHECK_EQUAL(tempData, 45);
    CHECK_EQUAL(findFirst(start, 45), start);
    CHECK_EQUAL(findFirst(start, 23), NULL);

    removeFront(&start);
    tempData = -10;
    CHECK_EQUAL(getAt(start, 0u, tempData), false);
    CHECK_EQUAL(tempData, -1);
    CHECK_EQUAL(size(start), 0u);
    CHECK_EQUAL(findFirst(start, 45), start);
    CHECK_EQUAL(findFirst(start, 23), NULL);
}

unsigned int size(Node* s)
{
    unsigned int result = 0;
    while(s != NULL) {
        s=s->next;
        result++;
    }
    return result;
}

bool getAt(Node* s, unsigned int i, int& outData)
{
    if (s == NULL) { return false; }
    while(i!=0) {
        i--;
        s=s->next;
        if (s == NULL) { return false; }
    }
    outData = s->data;
    return true;
}

void addFront(Node** s, int value)
{
    Node* tmp = new Node;
    tmp->data = value;
    // This if is actually not needed.
    // if (*s == NULL) {
    //     tmp->next = NULL;
    // } else 
    tmp->next = *s;
    *s = tmp;
}

void removeFront(Node** s)
{
    if (*s == NULL) { return; }
    Node* tmp = *s;
    *s = (*s)->next;
    delete tmp;
}

Node* findFirst(Note* s, int value)
{
    while(s != NULL) {
        if (s->data == value) { return s; }
        s = s->next;
    }
    return NULL;
}
