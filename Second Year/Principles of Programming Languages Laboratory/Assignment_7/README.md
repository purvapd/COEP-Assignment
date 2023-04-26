
# Assignment_7

## Problem Statement:-

Write a program to demonstrate event and event handlers using Object Oriented 
Programming. 

### Code_1 :- event.cpp

	In this example, we define an Event class that has methods to register event handlers and trigger the event. The EventHandler1 
	and EventHandler2 classes are event handlers that define how to handle the event when it is triggered. In the main function, 
	we create an instance of the Event class, register the EventHandler1 and EventHandler2 handlers to handle the event, and then 
	trigger the event using the Trigger() method. When the event is triggered, both event handlers registered to the event will be 
	called to handle the event, demonstrating the concept of event and event handlers using OOP in C++.

### Run the program.

	VSK@DESKTOP-8LMS4JT MINGW64 ~

	$ g++ event.cpp -o event



	VSK@DESKTOP-8LMS4JT MINGW64 ~

	$ ./event

	Event Triggered!

	EventHandler1: Event handled!

	EventHandler2: Event handled!


