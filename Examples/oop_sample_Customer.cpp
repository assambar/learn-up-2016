#include <cstring>

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
    c.decRank();
    c.decRank();
    c.decRank();
    c.decRank();
    c.decRank();
    c.increaseOrdersCapacity(3);
    c.addOrder(5);
    c.addOrder(13);
    c.addOrder(21);
    c.addOrder(34);
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
    int _ordersMax = _ordersMax + extraOrders;
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