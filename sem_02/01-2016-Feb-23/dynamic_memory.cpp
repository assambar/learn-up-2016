#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using std::endl;
using std::cout;


struct Point {
  int x, y;
};

double distance(const Point& p1, const Point& p2) {
  return std::sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

double scalarProduct(double* v1, double* v2, const unsigned int size) {
  double sp = 1.0;
  for (int i=0; i<size; i++) {
    sp += v1[i]*v2[i];
  }
  return sp;
}

void fillVector(double* v, const unsigned int size) {
  for (int i=0; i<size; i++) {
    v[i] = std::rand()%100 - 50;  // произволно число между -50 и 50
  }
}


int main() {
  std::srand(std::time(NULL));

  const int MAX_SIZE = 250;
  double vectorOnStack[MAX_SIZE];
  double* vectorOnHeap = NULL;
  const unsigned int size = std::rand() % MAX_SIZE;
  vectorOnHeap = new double[size];

  cout  << "This is our code:" << endl
        << "  const int MAX_SIZE = 250;" << endl
        << "  double vectorOnStack[MAX_SIZE];" << endl
        << "  double* vectorOnHeap = NULL;" << endl
        << "  const unsigned int size = std::rand() % MAX_SIZE;" << endl
        << "  vectorOnHeap = new double[size];" << endl << endl;


  cout << "On this run 'size' is " << size << endl;
  cout << "'vectorOnStack' always takes memory for " << MAX_SIZE << " values, but we use only " << size << " of them." << endl;
  cout << "'vectorOnHeap' takes memory for exactly " << size << " values." << endl;

  cout << "The addresses of 'vectorOnStack'(" << vectorOnStack << ") and "
       << "'size'(" << &size << ") are very close because they are both "
       << "within the stack frame of the 'main' method" << endl;

  cout << "However the address of 'vectorOnHeap'(" << vectorOnHeap << ") looks quite different, because it points to the heap" << endl << endl;

  cout << "At the end, we should never forget to free the allocated heap memory:" << endl
       << "  delete [] vectorOnHeap;" << endl;
  delete [] vectorOnHeap;
  return 0;
}