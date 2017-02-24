#include <iostream>

struct Student {
  const unsigned int fn;
  const char* name;
  unsigned int age;
};

/*! Отпечатва подадения студент на стандартния изход */
void printStudent(const Student& s) {
  std::cout << s.fn << " " << s.name << " " << s.age << std::endl;
}

int main()
{
  Student s1 = {11111, "John Doe", 23};
  Student s2 = {11112, "Jane Doe", 22};
  printStudent(s1);
  printStudent(s2);
}
