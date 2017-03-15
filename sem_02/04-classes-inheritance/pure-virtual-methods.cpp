#include <iostream>

using namespace std;

class Animal
{
public:
  bool isAlive() const {
    return true;
  }

  virtual const char* getName() const {
    return "Animal";
  }

  virtual const char* typicalSound() const = 0;

  virtual ~Animal() {}
};

class Cat : public Animal
{
public:
  virtual const char* getName() const {
    return "Cat";
  }

  virtual const char* typicalSound() const {
    return "Meow";
  }
};

class Dog : public Animal
{
public:
  virtual const char* getName() const {
    return "Dog";
  }

  virtual const char* typicalSound() const {
    return "Baw";
  }
};

class Cow : public Animal
{
public:
  virtual const char* getName() const {
    return "Cow";
  }

  virtual const char* typicalSound() const {
    return "Moo";
  }
};

class Ghost : public Animal
{
public:
  virtual const char* getName() const {
    return "Ghost";
  }

  virtual const char* typicalSound() const {
    return "Boo, I am not an animal, but the coder wrote me as one. "
      "I am the ghost of bad OOP design...";
  }
};


void printAnimal(const Animal& a) {
  cout << "A '" << a.getName() << "' makes the sound: " << a.typicalSound() << endl;
}

int main()
{
  //A a;  //ERROR. Cannot create instances of a class with pure virtual method

  Dog myDog;
  Cat yourCat;
  Cow hisCow;
  Ghost herGhost;

  printAnimal(myDog);
  printAnimal(yourCat);
  printAnimal(hisCow);
  printAnimal(herGhost);
  return 0;
}