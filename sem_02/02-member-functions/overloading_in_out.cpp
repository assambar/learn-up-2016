#include <iostream>

using namespace std;

struct Complex {
  double real;
  double imaginary;
};

std::ostream& operator<<(std::ostream& o, const Complex& n) {
  o << n.real << " + i*" << n.imaginary;
  return o;
}

std::istream& operator>>(std::istream& in, Complex& n) {
  in >> n.real >> n.imaginary;
  return in;
}

Complex operator+(const Complex& lhs, const Complex& rhs) {
  Complex result;
  result.real = lhs.real + rhs.real;
  result.imaginary = lhs.imaginary + rhs.imaginary;
  return result;
}

int main() {
  Complex c1,c2;
  cout << "Enter a complex number (real + imaginary parts): ";
  cin >> c1;
  cout << "You entered " << c1 << endl;
  cout << "Enter another complex number (real + imaginary parts): ";
  cin >> c2;
  cout << "You entered " << c2 << endl;
  cout << "\nThe sum is " << c1 + c2 << endl;
}