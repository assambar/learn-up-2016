# Псевдоними (references)
 - Напишете функция swap, която разменя стойностите на две променливи.

## Първи опит - неуспешен

```cpp
#include <iostream>

/**
 * Attempts to change the values of the two variables.
 */
void swap(int var1, int var2) {
   int temp = var1;
   var1 = var2;
   var2 = temp; 
}

int main() {
   // Setup - prepare test vars
   int firstVar = 3, secondVar = 5;
   
   // Do it - call the swap method
   swap(firstVar, secondVar);

   // Check - print to see if it works
   std::cout << firstVar << "," << secondVar;
}
```


## Какво е псевдоним - друго име за същата променлива


# Рекурсия
 - Какво е математическа индукция
 - Напишете функция `int factorialRecursive(int n)` като използвате рекурентната дефиниция на `n!`
 - Напишете функция `int factorialIterative(int n)` като използвате итеративен процес
 - Напишете съответно `int fibRecursive(int n)` и `int fibIterative(int n)`, които връщат n-тото подрев число на фибоначи
 
# Низове
