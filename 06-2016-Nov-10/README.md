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


# Рекурсия
 - Какво е математическа индукция
 - Напишете функция `int factorialRecursive(int n)` като използвате рекурентната дефиниция на `n!`
 - Напишете функция `int factorialIterative(int n)` като използвате итеративен процес
 - Напишете съответно `int fibRecursive(int n)` и `int fibIterative(int n)`, които връщат n-тото подрев число на фибоначи
 
# Низове
