# Псевдоними (references)
 - Напишете функция swap, която разменя стойностите на две променливи.

## Първи опит - неуспешен
[https://glot.io/snippets/ek6t8rltgz](https://glot.io/snippets/ek6t8rltgz)
```cpp
#include <iostream>

/**
 * Attempts to change the values of the two variables.
 */
void swapAttempt(int var1, int var2) {
   int temp = var1;
   var1 = var2;
   var2 = temp; 
}

int main() {
   // Setup - prepare test vars
   int firstVar = 3, secondVar = 5;
   
   // Action - call the swap method
   swapAttempt(firstVar, secondVar);

   // Check - print to see if it works
   std::cout << firstVar << "," << secondVar;
}
```
 - оказва се обаче че това не работи
 - програмата отпечатва `3,5`, т.е. стойностите на firstVar и secondVar не са били разменени

### ЗАЩО?
 - нека заместим извикването `swapAttempt(firstVar, secondVar)` с кода на самата функция
```cpp
   // Setup - prepare test vars
   int firstVar = 3, secondVar = 5;
   
   // Action - call the swap method
   // swapAttempt(firstVar, secondVar);
   {
      // Assignment of the arguments firstVar and secondVar to the parameters var1 and var2
      int var1 = firstVar;      // We create a new variable var1, which only stores the copy of firstVar
      int var2 = secondVar;     // We create a new variable var2, which only stores the copy of secondVar
      
      // Body of the function
      int temp = var1;
      var1 = var2;
      var2 = temp; 
   }
```
 - оказва се, че във функцията `swapAttempt` всъщност работим с други променливи, които са копия на аргументите
 
## Какво е псевдоним - друго име за същата променлива
 - името на една променлива е всъщност етикет, който слагаме на паметта в която се записва стойността на променливата
```cpp
// So lets declare some varialbes                  // Imagine reserved memory blocks with respective labels
                                                   // age                       gender      hasStress
int age = 23;                                      // +-------------------+     +----+      +----+
char gender = 'm';                                 // |23                 |     |'m' |      |f   |
bool hasStress = false;                            // +-------------------+     +----+      +----+
                                                   // 
                                                   // probabilityOfWhiteHairByAgeOf30
double probabilityOfWhiteHairByAgeOf30 = 0.4568;   // +---------------------------------------+
                                                   // |0.4568                                 |
                                                   // +---------------------------------------+
```

 - езика C++ ни позволява да използваме колкото искаме различни етикети за една и съща променлива
   - когато дефинираме допълнителен етикет (наречен псевдоним или reference), задължително трябва да укажем за коя променлива ще се използва
   - формата на дефиницията е `<тип на променливата>& <име на нов етикет/псевдоним> = <някой от текущите етикети>;`
   - след това може да използваме новия етикет изцяло заменимо с кой да е от останалите
```cpp
// I prefer to use short names.                    // Now we have two labels for each block in memory
int& a = age;                                      // age, a                    gender, g   hasStress, hS
char& g = gender;                                  // +-------------------+     +----+      +----+
bool& hS = hasStress;                              // |23                 |     |'m' |      |f   |
double& pOWHBAO30                                  // +-------------------+     +----+      +----+
   = probabilityOfWhiteHairByAgeOf30;              // 
                                                   // probabilityOfWhiteHairByAgeOf30, pOWHBAO30
                                                   // +---------------------------------------+
                                                   // |0.4568                                 |
                                                   // +---------------------------------------+


// I want a name that explicitly says that         // age, a, ageInYears
// the age is in years.                            // +-------------------+ 
int &ageInYears = a;                               // |23                 | 
                                                   // +-------------------+ 


// Let's check if it worked
assert(age == 23);
assert(ageInYears == 23);
a = 27;
assert(age == 27);
assert(ageInYears == 27);
age = 15
assert(a == 15);
assert(ageInYears == 15);

assert(hasStress == false);
hS = true;
assert(hasStress == true);
```

  

# Рекурсия
 - Какво е математическа индукция
 - Напишете функция `int factorialRecursive(int n)` като използвате рекурентната дефиниция на `n!`
 - Напишете функция `int factorialIterative(int n)` като използвате итеративен процес
 - Напишете съответно `int fibRecursive(int n)` и `int fibIterative(int n)`, които връщат n-тото подрев число на фибоначи
 
# Низове
