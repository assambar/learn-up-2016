#include <iostream>
#include <cassert>

using std::cout;
using std::endl;

class NumArray
{
private:
  int *_arr;
  unsigned int _size;

  /**
   * @pre All dynamic memory for the current object has been freed
   * @post New memory is allocated and values from 'other' are copied in it
   */
  void copyFrom(const NumArray& other);

  /**
   * @post All dynamic memory for the current object is freed
   */
  void deleteMe();

public:

  /**
   * Конструктор по подразбиране
   *
   * Трябва да се добави изрично, защото щом добавим някакъв друг конструктор,
   * няма да имаме скрито генериране на к-тор по подразбиране. (default c-tor)
   */
  NumArray();

  /**
   * Създава масив с големина argSize
   */
  NumArray(const unsigned int argSize);

  /**
   * Конструктор с копиране.
   *
   * Позволява да създаваме нови обекти от вече съществуващи такива.
   */
  NumArray(const NumArray& other);

  /**
   * Деструктор.
   *
   * Чрез него си осигуряваме, че ще зачистим динамичната памет, когато
   * променливата излезе от обхват, т.е. спре да се използва.
   */
  ~NumArray();

  /**
   * Оператор за присвояване.
   *
   * Позволява да присвоим стойностите от една променлива на друга
   */
  NumArray& operator=(const NumArray& other);

  /**
   * @return Големината на създадения масив
   */
  unsigned int size() const { return _size; }


  //bonus
  /**
   * Индексен оператор.
   *
   * Позволява ни да достъпим елементите на съответния индекс.
   */
  int& operator[](const unsigned int i) { return _arr[i]; }

  /**
   * Оператор за сравнение.
   */
  bool operator==(const NumArray& other) const;
  bool operator!=(const NumArray& other) const { return !(*this == other); }
};

int main() {
  // Check default c-tor
  {
    NumArray na;
    assert(na.size()==0 || !"Expected zero size by default c-tor");
  }

  // Check normal c-tor
  {
    NumArray na(5);
    assert(na.size()==5 || !"Expected size as given in c-tor");
  }

  // Check copy c-tor
  {
    NumArray na(2);
    na[0] = 3;
    na[1] = 18;
    NumArray na2(na);
    assert(na2 == na || !"Expected created object to be equal to one passed in c-tor");
  }

  // Check assignment operator-tor
  {
    NumArray na(2);
    na[0] = 3;
    na[1] = 18;
    NumArray na2(na);
    na[0] = 5;
    assert(na2 != na || !"Expected that na is now diferent from na2");
    na = na2;
    assert(na2 == na || !"Expected na is now the same as na2");
  }
}

NumArray::NumArray()
  :_arr(NULL), _size(0)
{}

NumArray::~NumArray()
{
  this->deleteMe();
  if (this->_arr != NULL) {
    delete [] this->_arr;
  }
}

NumArray::NumArray(const NumArray& other)
  :_arr(NULL), _size(0)
{
  this->copyFrom(other);
}

NumArray::NumArray(const unsigned int size)
{
  this->_arr = new int[size];
  this->_size = size;
}

NumArray& NumArray::operator=(const NumArray& other) {
  if (this != &other) {
    this->deleteMe();
    this->copyFrom(other);
  }
  return *this;
}

void NumArray::copyFrom(const NumArray& other) {
  this->_arr = new int[other._size];
  this->_size = other._size;
  for (int i=0; i<other._size;++i) {
    this->_arr[i] = other._arr[i];
  }
}

void NumArray::deleteMe()
{
  if (this->_arr != NULL) {
    delete [] this->_arr;
    this->_arr = 0;
    this->_size = 0;
  }
}


bool NumArray::operator==(const NumArray& other) const
{
  if (this->_size != other._size) {
    return false;
  }

  for (int i=0; i<other._size;++i) {
    if(this->_arr[i] != other._arr[i]) {
      return false;
    }
  }
  return true;
}