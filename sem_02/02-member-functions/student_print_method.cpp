#include <iostream>

using namespace std;

struct Student {
  const char* name;
  const unsigned int fn;
  unsigned int age;
  unsigned int marks[100];
  unsigned int countMarks;

  // Член функция.
  void printMarks();
};

void printMarksByReference(const Student& s) {
  for (unsigned int i=0; i < s.countMarks; i++) {
    cout << s.marks[i] << " ";
  }
  cout << endl;
}

void printMarksByPointer(const Student* s) {
  for (unsigned int i=0; i < (*s).countMarks; i++) {
    cout << (*s).marks[i] << " ";
  }
  cout << endl;
}

void Student::printMarks() {
  for (unsigned int i=0; i < (*this).countMarks; i++) {
    cout << (*this).marks[i] << " ";
  }
  cout << endl;
}

int main() {
  Student st = {"Ivan", 123456, 23, {4, 3, 6, 5, 6, 6, 6}, 7};
  cout << "Print by calling member function : ";
  st.printMarks();
  cout << "Print by passing to function by reference : ";
  printMarksByReference(st);
  cout << "Print by passing to function by pointer : ";
  printMarksByPointer(&st);
}