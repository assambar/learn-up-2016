#Структури (structs)

## Как да пусна примерите
 - Необходимо:
   - `cmake`
   - `bash`
 - Отвори `bash` в текущата директория
 - Изпълни `./bld.sh` - това ще създаде директория `_build` в която ще са всички изпълними файлове, компилирани от изходния код както е описано в `CMakeLists.txt`
 - За да изпълниш кой да е от тях, просто го извикай - например така: `_build/student_example.exe`
 - Ако искаш да изтриеш всичко компилирано до момента, изпълни `./bld.sh clean`

## Дефиниране на тип и създаване на инстанции

 - Пълния код вижте в [student_example.cpp](student_example.cpp)
 - Ползваме ключовата дума `struct`
 - Името си го измисляме ние - `[_a-zA-Z][_a-zA-Z0-9]*` - например `Student`
 - Всяко поле си има собствени тип и име - например `unsigned int age`
 - Възможно е някои полета да са константни (понеже не очакваме да могат да се променят) - например `const unsigned int fn`
 - В края на дефиницията има `;` !!!

```cpp
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
```
    11111 John Doe 23
    11112 Jane Doe 22

 - Променливи от новия тип се създават по познатия начин.
 - Началните стойности на полетата може да се изброят в списък с къдрави скоби подобно на масивите.
 - Полетата на тези променливи се достъпват с `.` - например `s1.age`

### Поддържане на консистентни данни

 - Пълния код вижте в [studentex_consistency.cpp](studentex_consistency.cpp)
 - Понякога информацията в две или повече полета трябва да се променя едновременно, за да поддържаме данните валидни
 - Например, ако разширим `Student` с масив, от оценки може да получим следното
```cpp
#define MAX_MARKS 100
struct StudentEx {
  const unsigned int fn;
  const char* name;
  unsigned int age;
  unsigned int marks[MAX_MARKS];
  unsigned int countMarks;
};
```
 - Студента може да има най-много 100 оценки, като точният им брой е countMarks
 - Това означава, че когато разглеждаме оценките на някаква променлива от типа Student2, не ни интересуват всичките елементи на масива `marks`, а само първите `countMarks` на брой от тях. Например:
```cpp
/*! Отпечатва оценките на дадения студент.*/
void printMarks(const StudentEx& s) {
  std::cout << "Marks for " << s.name << ": ";
  for (unsigned int i=0; i<s.countMarks; i++) {
    std::cout << s.marks[i] << " ";
  }
}

int main() {
  StudentEx john = {123456, "John", 23, {4,6,5,6}, 2};
  printMarks(john);   //Marks for John: 4 6
}
```
 - В случаи като този е важно всички функции, които работят със структурата от данни да са наясно със зависимостите между нейните полета.
 - Например за `StudentEx` може да дефинираме още `addMark` - функция която добавя оценка, като знае че не можем да имаме повече от 100 оценки и, че валидни са само оценки между 2 и 6
```cpp
bool addMark(StudentEx& s, unsigned int mark) {
  if (mark < 2 || mark > 6 || s.countMarks == MAX_MARKS) {
    return false;
  }
  s.marks[s.countMarks] = mark;
  s.countMarks++;
  return true;
}
```
 - `addMark` ще върне `false` ако оценката не може да бъде добавена
 - Или пък `calculateAverageMark`, която изчислява средното аритметично на въведените оценки
```cpp
double calculateAverageMark(const StudentEx& s) {
  unsigned int sum = 0;
  for (unsigned int i=0; i<s.countMarks; i++) {
    sum += s.marks[i];
  }
  return static_cast<double>(sum)/s.countMarks;
}
```

### Работа с динамична памет
 - Пълния код вижте в [dynamic_memory.cpp](dynamic_memory.cpp)

### Сортиране на масив от структури по поле
 - Пълния код вижте в [sort_products.cpp](sort_products.cpp)
 - А [тук](http://cpp.sh/4dbbu) можете да го изпробвате.

### Записване в и четене от файл

### Съставна структура от данни

### (И баба знае) Пакетиране
