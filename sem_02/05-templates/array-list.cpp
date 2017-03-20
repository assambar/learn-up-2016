#include <iostream>
#include <cassert>
#include "simple_test.h"

/**
 * @tparam ValueType - default constructible, copyable type
 */
template<class ValueType>
class ArrayList {
public:
  ArrayList(unsigned int size);
  ArrayList(unsigned int size, const ValueType* values);
  ArrayList(const ArrayList<ValueType>& other);
  ~ArrayList();
  ValueType& operator[](unsigned int index);
  unsigned int size() const;
  bool operator==(const ArrayList<ValueType>& other) const;

  friend std::ostream& operator<<(std::ostream& out,
                                  const ArrayList<ValueType> list)
  {
    for (unsigned int i=0; i<list._size; ++i) {
      out << list._arr[i] << " ";
    }
    return out;
  }
private:
  ValueType* _arr;
  unsigned int _size;
  void deleteMe();
  void copyFrom(const ArrayList<ValueType>& other);
};

template<class ValueType>
ArrayList<ValueType>::ArrayList(unsigned int size)
  :_size(size)
{
  _arr = new ValueType[_size];
}

template<class ValueType>
ArrayList<ValueType>::ArrayList(unsigned int size, const ValueType* values)
  :_size(size)
{
  _arr = new ValueType[_size];
  for (unsigned int i=0; i<_size; ++i) {
    _arr[i] = values[i];
  }
}

template<class ValueType>
ArrayList<ValueType>::ArrayList(const ArrayList<ValueType>& other)
{
  copyFrom(other);
}

template<class ValueType>
ArrayList<ValueType>::~ArrayList()
{
  deleteMe();
}

template<class ValueType>
ValueType& ArrayList<ValueType>::operator[](unsigned int index)
{
  assert(_arr != NULL && index < _size);
  return _arr[index];
}

template<class ValueType>
unsigned int ArrayList<ValueType>::size() const
{
  return _size;
}

template<class ValueType>
void ArrayList<ValueType>::copyFrom(const ArrayList<ValueType>& other)
{
  _size = other.size();
  if (_size == 0) {
    _arr = NULL;
  } else {
    _arr = new ValueType[_size];
    for (unsigned int i=0; i<_size; ++i) {
      _arr[i] = other._arr[i];
    }
  }
}

template<class ValueType>
void ArrayList<ValueType>::deleteMe()
{
  delete [] _arr;
}

template<class ValueType>
bool ArrayList<ValueType>::operator==(const ArrayList<ValueType>& other) const
{
  if (_size != other._size) {
    return false;
  }
  for (unsigned int i=0; i<_size; ++i) {
    if (_arr[i] != other._arr[i]) {
      return false;
    }
  }
  return true;
}


int main()
{
  ArrayList<int> arr1(5);
  for (int i=0; i<arr1.size(); ++i) {
    arr1[i] = i+1;
  }

  int rawArr[5] = {1,2,3,4,5};
  ArrayList<int> arr2(5, rawArr);
  CHECK_EQUAL(arr1, arr2);

  arr1[4] = 13;
  CHECK_NOT_EQUAL(arr1, arr2);

  arr2[4] = 13;
  CHECK_EQUAL(arr1, arr2);

  return 0;
}

