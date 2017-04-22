#ifndef _SIMPLE_TEST_H_
#define _SIMPLE_TEST_H_

#include <iostream>
#include <cstring>

namespace _test {
  inline void checkStrEquality(const char* lhs, const char* rhs, bool expectedEqual, const char* expression)
  {
    if ((std::strcmp(lhs, rhs) == 0) == expectedEqual) {
      std::cout << "[SUCCEEDED] ";
    } else {
      std::cout << "[FAILED   ] ";
    }
      std::cout << ((expectedEqual)? "Equality" : "Difference")
                << " check for '" << expression << "' is comparison of '"
                << lhs << "' and '" << rhs << "'" << std::endl;
  }

  template<class ComparedType1, class ComparedType2>
  inline void checkEquality(const ComparedType1& lhs, const ComparedType2& rhs, bool expectedEqual,
                            const char* lhExpression, const char* rhExpression)
  {
    std::cout << ( ((lhs == rhs) == expectedEqual)? "[SUCCEEDED] " : "[FAILED   ] " )
              << ((expectedEqual)? "Equality" : "Difference")
              << " check for '" << lhExpression << "'='" << lhs
              << "' and '" << rhExpression << "'='" << rhs << "'" << std::endl;
  }
}

#define CHECK_STR_EQUAL(x, y) _test::checkStrEquality((x), (y), true, #x " and " #y)
#define CHECK_STR_NOT_EQUAL(x, y) _test::checkStrEquality((x), (y), false, #x " and " #y)

#define CHECK_EQUAL(x,y) _test::checkEquality((x), (y), true, #x, #y)
// cout << ( ((x) == (y))? "[SUCCEEDED] " : "[FAILED   ] " ) \
//                               << "Equality check '" << #x << "' == '" #y << "' is " \
//                               << "'" << (x) << "' == '" << (y) << "'" << endl
#define CHECK_NOT_EQUAL(x,y) _test::checkEquality((x), (y), false, #x, #y)
// cout << ( ((x) != (y))? "[SUCCEEDED] " : "[FAILED   ] " ) \
//                                   << "Difference check '" << #x << "' == '" #y << "' is " \
//                                   << "'" << (x) << "' == '" << (y) << "'" << endl

#endif // _SIMPLE_TEST_H_
