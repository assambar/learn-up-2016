#include <cstring>
#include "simple_test.h"

class Customer {
// Properties required by а)
private:
    unsigned int _id;
    char* _name;
    int _rank;
    int* _orders;
    unsigned int _ordersMax;
    unsigned int _ordersSize;

// Methods required by б)
public:
    Customer(const unsigned int id, const char* name);

// Methods required by в)
    Customer(const Customer& other);
    ~Customer();
    Customer& operator=(const Customer& other);

// Methods required by г)
public:
    const char* getName() const;
    int getRank() const;
    unsigned int getOrdersSize() const;
    unsigned int getOrdersCapacity() const;

// Methods required by д)
public:
    bool addOrder(int id);
    void increaseOrdersCapacity(unsigned int extraOrders);
    void changeName(const char* newName);
    void appendToName(const char* appendToName);
    void incRank();
    void decRank();
};

int main() {
    Customer c(1, "Ivan");

    std::cout << "\nTEST: valuesAfterConstruction" << std::endl;
    CHECK_STR_EQUAL(c.getName(), "Ivan");
    CHECK_EQUAL(c.getOrdersCapacity(), 4u);
    CHECK_EQUAL(c.getOrdersSize(), 0u);
    CHECK_EQUAL(c.getRank(), 0);

    std::cout << "\nTEST: operationsWithName" << std::endl;
    c.changeName("Go6o");
    CHECK_STR_EQUAL(c.getName(), "Go6o");
    c.appendToName(" Ivanov");
    CHECK_STR_EQUAL(c.getName(), "Go6o Ivanov");
    
    std::cout << "\nTEST: operationsWithOrders" << std::endl;
    CHECK_EQUAL(c.addOrder(3), true);
    CHECK_EQUAL(c.getOrdersSize(), 1);
    CHECK_EQUAL(c.addOrder(5), true);
    CHECK_EQUAL(c.addOrder(8), true);
    CHECK_EQUAL(c.addOrder(13), true);
    CHECK_EQUAL(c.getOrdersSize(), 4);
    CHECK_EQUAL(c.addOrder(21), false);
    
    c.increaseOrdersCapacity(3);
    CHECK_EQUAL(c.getOrdersCapacity(), 7);
    CHECK_EQUAL(c.addOrder(21), true);
    CHECK_EQUAL(c.getOrdersSize(), 5);
    
    std::cout << "\nTEST: operationsWithRank" << std::endl;
    c.incRank();
    CHECK_EQUAL(c.getRank(), 1);
    c.decRank(); c.decRank(); c.decRank(); c.decRank();
    CHECK_EQUAL(c.getRank(), -3);

    std::cout << "\nTEST: copyConstruction" << std::endl;
    Customer c2(c);
    CHECK_STR_EQUAL(c2.getName(), c.getName());
    CHECK_EQUAL(c2.getOrdersCapacity(), c.getOrdersCapacity());
    CHECK_EQUAL(c2.getOrdersSize(), c.getOrdersSize());
    CHECK_EQUAL(c2.getRank(), c.getRank());

    std::cout << "\nTEST: assignmentOperator" << std::endl;
    Customer c3(3, "Pe6o");
    c = c3;
    CHECK_STR_EQUAL(c3.getName(), c.getName());
    CHECK_EQUAL(c3.getOrdersCapacity(), c.getOrdersCapacity());
    CHECK_EQUAL(c3.getOrdersSize(), c.getOrdersSize());
    CHECK_EQUAL(c3.getRank(), c.getRank());
}

Customer::Customer(const unsigned int id, const char* name)
    :_id(id), _rank(0), _ordersMax(4u), _ordersSize(0u)
{
    _name = new char[std::strlen(name) + 1];
    std::strcpy(_name, name);

    _orders = new int[_ordersMax];
}

// Methods required by в)
Customer::Customer(const Customer& other)
{
    _id = other._id;
    _rank = other._rank;
    _ordersMax = other._ordersMax;
    _ordersSize = other._ordersSize;

    _name = new char[std::strlen(other._name) + 1];
    std::strcpy(_name, other._name);

    _orders = new int[other._ordersMax];
    for (unsigned int i=0; i<other._ordersSize; i++) {
        _orders[i] = other._orders[i];
    }
}

Customer::~Customer()
{
    delete [] _name;
    delete [] _orders;
}

Customer& Customer::operator=(const Customer& other)
{
    if (&other != this) {
        delete [] _name;
        delete [] _orders;

        _id = other._id;
        _rank = other._rank;
        _ordersMax = other._ordersMax;
        _ordersSize = other._ordersSize;

        _name = new char[std::strlen(other._name) + 1];
        std::strcpy(_name, other._name);

        _orders = new int[other._ordersMax];
        for (unsigned int i=0; i<other._ordersSize; i++) {
            _orders[i] = other._orders[i];
        }
    }
    return *this;
}

// Methods required by г)
const char* Customer::getName() const
{
    return _name;
}

int Customer::getRank() const
{
    return _rank;
}

unsigned int Customer::getOrdersSize() const
{
    return _ordersSize;
}

unsigned int Customer::getOrdersCapacity() const
{
    return _ordersMax;
}

// Methods required by д)
bool Customer::addOrder(int id)
{
    if (_ordersSize >= _ordersMax) {
        return false;
    }
    _orders[_ordersSize] = id;
    _ordersSize++;
    return true;
}

void Customer::increaseOrdersCapacity(unsigned int extraOrders)
{
    _ordersMax = _ordersMax + extraOrders;
    // allocate new space and copy current orders
    int* newOrders = new int[_ordersMax];
    for (unsigned int i=0; i<_ordersSize; i++) {
        newOrders[i] = _orders[i];
    }

    // free space for current orders
    delete [] _orders;

    // store pointer to the newly allocated space in _orders
    _orders = newOrders;
}

void Customer::changeName(const char* newName)
{
    delete _name;
    _name = new char[std::strlen(newName) + 1];
    std::strcpy(_name, newName);
}

void Customer::appendToName(const char* appendToName)
{
    // allocate space for concatenated name
    char* newName = new char[strlen(_name) + strlen(appendToName) + 1];

    // copy the current name in the new space
    std::strcpy(newName, _name);

    // now concatenate the suffix
    std::strcat(newName, appendToName);

    // free the space for the previous name and store address of new space in _name
    delete _name;
    _name = newName;
}

void Customer::incRank()
{
    ++_rank;
}

void Customer::decRank()
{
    --_rank;
} 