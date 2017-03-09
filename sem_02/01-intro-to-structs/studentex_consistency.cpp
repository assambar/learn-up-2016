#include <iostream>   //cout, endl
#include <iomanip>    //setw

#define MAX_MARKS 100
struct StudentEx {
  const unsigned int fn;
  const char* name;
  unsigned int age;
  unsigned int marks[MAX_MARKS];
  unsigned int countMarks;
};

using std::cout;
using std::setw;
using std::endl;

/*! Отпечатва данните за подадения Student на стандартния изход. */
void printStudent(const StudentEx& s);

/*! Добавя дадената оценка към дадения Student.
  \param s      Студента, за когото ще се добави оценката.
  \param mark   Оценката, който ще се добави. Трябва да е между 2 и 6 включително.
  \return
    - true Ако оценката е била добавена успешно
    - false Ако mark е невалидна оценка или s.countMarks == MAX_MARKS
*/
bool addMark(StudentEx& s, unsigned int mark);

/*! Изчислява и връща средно аритметичното на оцентите на дадения Student. */
double calculateAverageMark(const StudentEx& s);

int main()
{
  StudentEx s1 = {11111, "John Doe", 23, {5, 3, 6, 3, 4}, 5};
  StudentEx s2 = {11112, "Jane Doe", 22, {4}, 1};

  cout << "\n\n--------\nStudentEx s1" << endl;
  printStudent(s1);
  cout << "Average of s1: " << calculateAverageMark(s1) << endl;
  cout << "Adding mark 6" << endl;
  addMark(s1, 6);
  printStudent(s1);
  cout << "Average of s1: " << calculateAverageMark(s1) << endl;

  cout << "\n\n--------\nStudentEx s2" << endl;
  printStudent(s2);
  cout << "Average of s2: " << calculateAverageMark(s2) << endl;
  cout << "Adding marks 6, 4, 5, 6, 5, 6, 6" << endl;
  unsigned int marksToAdd[] = {6, 4, 5, 6, 5, 6, 6};
  for (unsigned int i=0; i<7; ++i) {
    addMark(s2, marksToAdd[i]);
  }
  printStudent(s2);
  cout << "Average of s2: " << calculateAverageMark(s2) << endl;
}


void printStudent(const StudentEx& s) {
  cout << setw(8) << s.fn << setw(40) << s.name << setw(5) << s.age << endl;
  cout << "Marks: ";
  for (unsigned int i=0; i<s.countMarks; i++) {
      cout << s.marks[i] << " ";
  }
  cout << endl;
}


bool addMark(StudentEx& s, unsigned int mark) {
  if (mark < 2 || mark > 6 || s.countMarks == MAX_MARKS) {
    return false;
  }
  s.marks[s.countMarks] = mark;
  s.countMarks++;
  return true;
}

double calculateAverageMark(const StudentEx& s) {
  unsigned int sum = 0;
  for (unsigned int i=0; i<s.countMarks; i++) {
    sum += s.marks[i];
  }
  return static_cast<double>(sum)/s.countMarks;
}