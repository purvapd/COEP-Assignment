
# Assignment_5

## Problem Statement:-

Write a program to develop a software to introduce animals to kids. Implement classes for 
animals like Dog, Cat, Elephant, Fish etc. With constructor destructor interfaces and 
variables with public or private access specifies.

### Code_1 :- animal.cpp

		In this program, we have defined three classes: Animal, Dog, and Cat, Elephant, Fish. Animal is the base class with a constructor, destructor, and a public method to make a sound. Dog and Cat, Elephant, Fish are derived classes from Animal with their own constructors, destructors, and methods to make specific sounds (bark for Dog and meow for Cat and so on). The Animal class has protected member variables for name and age, which can be accessed by the derived classes. Dog, Cat, Elephant, Fish classes have private member variables for breed and color, respectively, which can only be accessed within their own classes.

		In the main function, we create objects of Dog, Cat, Elephant, Fish and call their respective methods to make sounds. When the program is executed, it will output messages indicating the creation and destruction of objects, along with the sounds made by the animals.

### Run the program.


		VSK@DESKTOP-8LMS4JT MINGW64 ~

		$ g++ animal.cpp -o animal



		VSK@DESKTOP-8LMS4JT MINGW64 ~

		$ ./animal

		An animal named Buddy was created.

		A dog named Buddy was created.

		The dog barks.

		An animal named Fluffy was created.

		A cat named Fluffy was created.

		The cat meows.

		An animal named Jumbo was created.

		A Elephant named Jumbo was created.

		The Elephant trumpets.

		An animal named Nemo was created.

		A fish named Nemo was created.

		The fish makes bubbles.

		A fish named Nemo was destroyed.

		An animal named Nemo was destroyed.

		A Elephant named Jumbo was destroyed.

		An animal named Jumbo was destroyed.

		A cat named Fluffy was destroyed.

		An animal named Fluffy was destroyed.

		A dog named Buddy was destroyed.

		An animal named Buddy was destroyed.



