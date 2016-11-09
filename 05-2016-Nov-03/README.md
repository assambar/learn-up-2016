# Масиви в C++

## Задача 1
Напишете програма sort_05_selection.cpp, която въвежда 10 числа, след което ги отпечатва сортирани във възходящ ред, разделени с интервал. За сортиране да се използва метода на пряката селекция.
 
## Какво е сортиране чрез селекция
 
    1. намираме най-малкото число измежду всички числа
    2. разменяме го с първото
    3. намираме най-малкото число измежду числата от второто до последното
    4. разменяме го с второто
    ...
    Повтаряме докато стигнем до последните две числа и сложим по-малкото от тях на предпоследно място.
 
Ако не е ясно - потърсете из Интернет и ще видите много и всякакви примери:
 - [TutorialsPoint](https://www.tutorialspoint.com/data_structures_algorithms/selection_sort_algorithm.htm)
 - [Wikipedia](https://en.wikipedia.org/wiki/Selection_sort)
 - [Sonny Jr's Blog](http://sonnyjr.me/2015/12/21/selection-sort/)
 ![Sonny Jr's Animated Example](http://sonnyjr.me/wp-content/uploads/2016/07/selectionsort.gif)
  
 
## Да разбием задачата на парчета
 - въвеждаме 10 числа
   - как ще ги представим в паметта?
   - как ще ги въведем?
   - как ще проверим дали сме ги въвели правилно?
 - отпечатваме ги сортирани във възходящ ред
   - как ще ги отпечатаме?
   - как ще ги сортираме?

## Въвеждане на 10 числа
### Как да представим 10 числа в паметта
За целта ще използваме структурата от данни `масив`.
 - [TutorialsPoint](https://www.tutorialspoint.com/data_structures_algorithms/array_data_structure.htm)
 - [Wikipedia](https://en.wikipedia.org/wiki/Array_data_structure)
 - [Wikipedia на Български](https://bg.wikipedia.org/wiki/%D0%9C%D0%B0%D1%81%D0%B8%D0%B2_(%D0%BF%D1%80%D0%BE%D0%B3%D1%80%D0%B0%D0%BC%D0%B8%D1%80%D0%B0%D0%BD%D0%B5)) 

 - `int arrayOfNumbers[10];` - създава променлива `arrayOfNumbers`, която е масив от 10 цели числа
   - заделя се място в място в паметта, достатъчно за да се съберат 10 цели числа в него, разположени последователно
     - **ЗАБЕЛЕЖКА!** всяко от 10-те числа има произволна стойност, защото само сме заделили паметта, но не сме и задари стойности
   - името arrayOfNumbers е етикет на началото на тази памет
   - първото число е достъпно члез променливата `arrayOfNumbers[0]`, защото то е в началото на заделената памет
   - второто число е достъпно чрез променливата `arrayOfNumbers[1]`, защото в паметта то е на една позиция след първото   
 - `int arrayOfNumbers[10] = {};` - цялата памет заделена за масива се нулира. Понеже той е от цели числа, това означава че всяко от тях е 0
 - `int arrayOfNumbers[10] = {4, -10, 789, 7, 321, -2, 4, 89, -256, 15};` - при създаването на променливата задаваме и числата, които искаме да се запишат в паметта, като всяко е на съответната си позиция
 - `int arrayOfNumbers[10] = {1,2,3};` - първите 3 числа са съответно `1`, `2` и `3`. При останалите паметта се нулира, т.е. те са нули
 - `int arrayOfNumbers[10] = {0};` - първото число е `0`. При останалите 9 паметта се нулира
 - `int arrayOfNumbers[10] = {1};` - първото число е `1`. При останалите 9 паметта се нулира
 - `int arrayOfNumbers[] = {1,2,3};` - създаваме масив от 3 цели числа, като те са съответно `1`, `2` и `3`
 - `int arrayOfNumbers[] = {123, 5, -890, 19};` - създаваме масив от 4 цели числа, като те са съответно посочените
 - `bool arrayOfBools[5] = {true, false, false, true};` - създаваме масив от 5 булеви стойности. Последната е false, защото не е зададена изрично, а паметта е нулирана, заради присъствието на инициализационен списък
 - `char arrayOfChars[50] = {'H', 'e', 'l', 'l', 'o'};` - създаваме масив от 50 символни стойности. Последните 45 от тях са символа `\0`, защото не са зададени изрично, а паметтаа е нулирана, заради присъствието на инициализационен списък
 
### Как да въведем стойности за тях
 - Ще използваме променлива например `i` за брояч на индексите
 - Последователно ще пинем по всички индекси от 0 до 9
 - За всеки индекс ще въведем съответното число
[http://codepad.org/n3r1mHAe](http://codepad.org/n3r1mHAe)
```cpp
#include <iostream>
int main()
{
    int arrayOfNumbers[10];
    for (int i=0; i < 10; ++i) {
        std::cin >> arrayOfNumbers[i];
    }
}
```
### Как да проверим, че сме ги въвели правилно
 - След въвеждането, ще отпечатаме стойностите на екрана
[http://codepad.org/ziGyEfsU](http://codepad.org/ziGyEfsU)
```cpp
#include <iostream>
int main()
{
    int arrayOfNumbers[10];
    for (int i=0; i < 10; ++i) {
        std::cin >> arrayOfNumbers[i];
    }

    for (int i=0; i < 10; ++i) {
        std::cout << arrayOfNumbers[i];
    }
}
```

## Отпечатване на сортираните числа
### Как да отпечатаме числата разделени с интервал
 - След всяко число ще отпечатаме и по един интервал.
 - Така ще получим и интервал след последното число, но той не се вижда и засега ще го пренебрегнем
[http://codepad.org/RgPbieMB](http://codepad.org/RgPbieMB)
```cpp
#include <iostream>
int main()
{
    int arrayOfNumbers[10];
    for (int i=0; i < 10; ++i) {
        std::cin >> arrayOfNumbers[i];
    }

    for (int i=0; i < 10; ++i) {
        std::cout << arrayOfNumbers[i] << ' ';
    }
}
```

### Как да ги сортираме
 - как да намерим най-малкото число и да го заменим с първото
 - как да повторим горното действие от второто число нататък

#### Намиране на най-малкото число
 - първоначално предполагаме че най-добрия кандидат за най-малко число е първото число
 - сравняваме го с второто. ако второто и по-малко, то второто става най-добър кандидат.
 - сравняваме най-добрия кандидат за момента с третото число. ако третото е по-малко, то третото става най-добър кандидат
 - ще си помним кое според нас е най-малкото число като ползваме променлива `minValue`
http://codepad.org/G1XhjrjI
```cpp
#include <iostream>
int main()
{
    // Test - use some numbers for practice
    int arrayOfNumbers[10] = {34, 1, 89, -34, 15, 23, 3, 2, -123987, 837485};

    // Actual problem - find the min value
    int minValue = arrayOfNumbers[0];
    for (int i=1; i < 10; ++i) {
        if (minValue > arrayOfNumbers[i]) {
            minValue = arrayOfNumbers[i];
        }
    }

    // Test - print result to check that it works
    std::cout << minValue;
}
```

#### Как да разменим стойностите на две променливи
http://codepad.org/4G1PLKHs
```cpp
#include <iostream>
int main()
{
    // Test - use some numbers for practice
    int first = 987,
        second = 123;

    // Actual problem - swap the two values
    int temporary = first;
    first = second;
    second = temporary;

    // Test - print result to check that it works
    std::cout << "first = " << first << std::endl;
    std::cout << "second = " << second << std::endl;
}
```

#### Как да заменим най-малкия елемент с първия
 - **КОФТИ** - по-горе намерихме стойността на най-малкия елемент, но не и позицията му. Без позицията в масива не знаем къде е и няма да можем да преместим първия елемент на тази позиция.
 - Ще променим кода за да намерим позицията, а не стойността
http://codepad.org/eicj0cjB
```cpp
#include <iostream>
int main()
{
    // Test - use some numbers for practice
    int arrayOfNumbers[10] = {34, 1, 89, -34, 15, 23, 3, 2, -123987, 837485};

    // Actual problem - find the position of the min value
    int minPos = 0;
    for (int i=1; i < 10; ++i) {
        if (arrayOfNumbers[minPos] > arrayOfNumbers[i]) {
            minPos = i;
        }
    }

    // Test - print result to check that it works
    std::cout << "Min element is arrayOfNumbers[" << minPos << "]=" << arrayOfNumbers[minPos];
}
```
 - Сега вече е лесно да заменим намерения минимален елемент с първия
http://codepad.org/5Pl3BXDy
```cpp
#include <iostream>
int main()
{
    // Test - use some numbers for practice
    int arrayOfNumbers[10] = {34, 1, 89, -34, 15, 23, 3, 2, -123987, 837485};

    // Actual problem - find the minimal element, then swap it with the first element
    int minPos = 0;
    for (int i=1; i < 10; ++i) {
        if (arrayOfNumbers[minPos] > arrayOfNumbers[i]) {
            minPos = i;
        }
    }

    int temp = arrayOfNumbers[minPos];
    arrayOfNumbers[minPos] = arrayOfNumbers[0];
    arrayOfNumbers[0] = temp;

    // Test - print array to check first was swapped with min
    for (int i=0; i < 10; ++i) {
        std::cout << arrayOfNumbers[i] << ' ';
    }
}
```
 
## Какво можем да подобрим?
 - Числото 10 е навсякъде. Ами ако искам да работя с 20 числа
 - А ако искам да сортирам повече от един масиви

# Упражнение
 - Напишете същата програма, но с метода на мехурчето - sort_05_bubble.cpp

 
