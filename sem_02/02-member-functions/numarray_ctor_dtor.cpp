#include <iostream>
#include <algorithm>

using namespace std;

void fillValues(int* v, const unsigned int size) {
  for (int i=0; i<size; i++) {
    v[i] = std::rand()%100 - 50;  // произволно число между -50 и 50
  }
}

void inputAndSort(int* numbers, const int N) {
  fillValues(numbers, N);
  sort(numbers, numbers+N);
  for (unsigned int i=0; i<N; i++) {
    cout << numbers[i] << " ";
  }
  cout << endl;
}

struct NumArray {
  int* arr;
  const unsigned int size;
  NumArray(const unsigned int sizeArg);
  ~NumArray();
};

NumArray::NumArray(const unsigned int sizeArg)
  :size(sizeArg)
{
  cout << "Constructor" << endl;
  this->arr = new int[size];
}

NumArray::~NumArray()
{
  cout << "Destructor" << endl;
  delete [] this->arr;
}


int main() {
  int N;
  cout << "Enter count of numbers:" << endl;
  cin >> N;

  cout << "\nManual memory usage:" << endl;
  {
    int * numbers = new int[N];
    inputAndSort(numbers, N);
    delete [] numbers;
  }

  cout << "\nAutomated memory usage:" << endl;
  {
    NumArray a(N);
    inputAndSort(a.arr, a.size);
  }
  cout << "a is out of scope" << endl;
}