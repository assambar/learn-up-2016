#Структури (structs)

## Дефиниране

```cpp
#include <iostream>

struct Student {
  const unsigned int fn;
  const char* name;
  unsigned int age;
};

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
```
    11111 John Doe 23
    11112 Jane Doe 22

## Примери

### Сортиране на масив по поле

### Записване в и четене от файл

### Съставна структура от данни

### (И баба знае) Пакетиране