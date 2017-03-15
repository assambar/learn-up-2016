#include <iostream>
#include <cstring>

using namespace std;

/*BEGIN don't read this section*/
inline void checkEquality(const char* lhs, const char* rhs, bool expectedEqual, const char* expression) {
  if ((strcmp(lhs, rhs) == 0) == expectedEqual) {
    cout << "[SUCCEEDED] ";
  } else {
    cout << "[FAILED   ] ";
  }
  cout << ((expectedEqual)? "Equality" : "Difference")
       << " check for '" << expression << "' is comparison of '" << lhs << "' and '" << rhs << "'" << endl;
}

#define CHECK_STR_EQUAL(x, y) checkEquality((x), (y), (true), #x " and " #y)
#define CHECK_STR_NOT_EQUAL(x, y) checkEquality((x), (y), (false), #x " and " #y)

#define CHECK_EQUAL(x,y) cout << ( ((x) == (y))? "[SUCCEEDED] " : "[FAILED   ] " ) \
                              << "Equality check '" << #x << "' == '" #y << "' is " \
                              << "'" << (x) << "' == '" << (y) << "'" << endl
#define CHECK_NOT_EQUAL(x,y) cout << ( ((x) != (y))? "[SUCCEEDED] " : "[FAILED   ] " ) \
                                  << "Difference check '" << #x << "' == '" #y << "' is " \
                                  << "'" << (x) << "' == '" << (y) << "'" << endl

/*END don't read this section*/

class Animal
{
public:
  bool isAlive() const {
    return true;
  }

  virtual const char* getName() const {
    return "Animal";
  }

  virtual ~Animal() {}
};

class Cat : public Animal
{
public:
  virtual const char* getName() const {
    return "Cat";
  }
};

int main()
{
  Animal a;
  Cat c;
  CHECK_STR_NOT_EQUAL(a.getName(), c.getName());
  //[SUCCEEDED] Difference check for 'a.getName() and c.getName()' is comparison of 'Animal' and 'Cat'


  Animal* cAsAnimalPtr = &c;
  CHECK_STR_NOT_EQUAL(cAsAnimalPtr->getName(), a.getName());
  //[SUCCEEDED] Difference check for 'cAsAnimalPtr->getName() and a.getName()' is comparison of 'Cat' and 'Animal'

  CHECK_STR_EQUAL(cAsAnimalPtr->getName(), c.getName());
  //[SUCCEEDED] Equality check for 'cAsAnimalPtr->getName() and c.getName()' is comparison of 'Cat' and 'Cat'


  Animal& cAsAnimalRef = c;
  CHECK_STR_NOT_EQUAL(cAsAnimalRef.getName(), a.getName());
  //[SUCCEEDED] Difference check for 'cAsAnimalRef.getName() and a.getName()' is comparison of 'Cat' and 'Animal'

  CHECK_STR_EQUAL(cAsAnimalRef.getName(), c.getName());
  //[SUCCEEDED] Equality check for 'cAsAnimalRef.getName() and c.getName()' is comparison of 'Cat' and 'Cat'


  return 0;
}