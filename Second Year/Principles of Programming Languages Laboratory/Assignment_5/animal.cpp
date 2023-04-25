#include <iostream>
#include <string>

class Animal {
public:
    Animal(const std::string& name, int age) : name_(name), age_(age) {
        std::cout << "An animal named " << name_ << " was created." << std::endl;
    }

    virtual ~Animal() {
        std::cout << "An animal named " << name_ << " was destroyed." << std::endl;
    }

    void makeSound() const {
        std::cout << "The animal makes a sound." << std::endl;
    }

protected:
    std::string name_;
    int age_;
};

class Dog : public Animal {
public:
    Dog(const std::string& name, int age, const std::string& breed) : Animal(name, age), breed_(breed) {
        std::cout << "A dog named " << name_ << " was created." << std::endl;
    }

    ~Dog() {
        std::cout << "A dog named " << name_ << " was destroyed." << std::endl;
    }

    void makeSound() const {
        std::cout << "The dog barks." << std::endl;
    }

private:
    std::string breed_;
};

class Cat : public Animal {
public:
    Cat(const std::string& name, int age, const std::string& color) : Animal(name, age), color_(color) {
        std::cout << "A cat named " << name_ << " was created." << std::endl;
    }

    ~Cat() {
        std::cout << "A cat named " << name_ << " was destroyed." << std::endl;
    }

    void makeSound() const {
        std::cout << "The cat meows." << std::endl;
    }

private:
    std::string color_;
};
class Elephant : public Animal {
public:
    Elephant(const std::string& name, int age, const std::string& color) : Animal(name, age), color_(color) {
        std::cout << "A Elephant named " << name_ << " was created." << std::endl;
    }

    ~Elephant() {
        std::cout << "A Elephant named " << name_ << " was destroyed." << std::endl;
    }

    void makeSound() const {
        std::cout << "The Elephant trumpets." << std::endl;
    }

private:
    std::string color_;
};
class Fish : public Animal {
public:
    Fish(const std::string& name, int age, const std::string& species) : Animal(name, age), species_(species) {
        std::cout << "A fish named " << name_ << " was created." << std::endl;
    }

    ~Fish() {
        std::cout << "A fish named " << name_ << " was destroyed." << std::endl;
    }

    void makeSound() const {
        std::cout << "The fish makes bubbles." << std::endl;
    }

private:
    std::string species_;
};
int main() {
    // Creating a dog object
    Dog dog("Buddy", 3, "Labrador");
    dog.makeSound();

    // Creating a cat object
    Cat cat("Fluffy", 2, "White");
    cat.makeSound();

    // Creating an elephant object
    Elephant elephant("Jumbo", 10,"Laksh");
    elephant.makeSound();

    // Creating a fish object
    Fish fish("Nemo", 1, "Clownfish");
    fish.makeSound();

    return 0;
}
