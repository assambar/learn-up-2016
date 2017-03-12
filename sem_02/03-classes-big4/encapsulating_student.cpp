#include <iostream>
#include <iomanip>

using std::cout;
using std::ostream;
using std::setw;
using std::setprecision;
using std::endl;

const unsigned int MAX_MARKS = 100;
/**
 * Represents a student in a system. The student is identified by name and fn.
 * A student has a list of marks. The class allows recording of up to MAX_MARKS
 * marks per student.
 */
struct Student {
private:
  const char* name;
  const unsigned int fn;
  unsigned int marks[MAX_MARKS];
  unsigned int countMarks;

public:
  Student(const char* argName, const unsigned int argFn);
  /**
   * Adds the given mark to the Student's list of marks
   * @return true if the mark was added, false if mark is invalid value or if
   *    no more marks can be added to the student.
   */
  bool addMark(unsigned int mark);

  /**
   * Gives the average of the known marks of the student.
   */
  double calculateAverageMark() const;

  /**
   * Because this has to be a function outside of the class, we have to declare
   * it as 'friend'.
   */
  friend ostream& operator<<(ostream& o, const Student& s);
};

Student::Student(const char* argName, const unsigned int argFn)
  :name(argName), fn(argFn), countMarks(0u)
{}

bool Student::addMark(const unsigned int mark)
{
  if (mark<2 || mark>6 || this->countMarks == MAX_MARKS) {
    return false;
  }
  this->marks[this->countMarks] = mark;
  this->countMarks++;
  return true;
}

double Student::calculateAverageMark() const
{
  unsigned int sum = 0;
  for (unsigned int i=0; i<this->countMarks; ++i) {
    sum += this->marks[i];
  }
  // this->countMarks = 0    // Грешка, защото функцията е const
  return (sum==0) ? 0 : sum / static_cast<double>(this->countMarks);
}


ostream& operator<<(ostream& o, const Student& s)
{
  o << setw(6) << s.fn << " "
    << setw(8) << setprecision(3) << s.calculateAverageMark() << " "
    << s.name << endl;
  o << "Marks: ";
  for (unsigned int i=0; i<s.countMarks; ++i) {
    o << s.marks[i] << " ";
  }
  o << endl;
  return o;
}

int main()
{
  Student s1("Иван", 123456);
  cout << s1;
  s1.addMark(5);
  s1.addMark(6);
  s1.addMark(5);
  cout << s1;
  // cout << s1.countMarks;  // Грешка при компилация
  // cout << s1.name;        // Грешка при компилация
  return 0;
}