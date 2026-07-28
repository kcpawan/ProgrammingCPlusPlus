# Object Oriented Programming with C++

This repository consists of full course notes and programs for studying **Object Oriented Programming (OOP) with C++**. The course is structured and developed based on the curriculum prescribed by **Purbanchal University, Gothgaun, Nepal**.

Each topic includes detailed explanations, notes, and working programs, organized to move from programming fundamentals through to OOP concepts as implemented in C++.

<br />

## Background

### 1. What is Programming?

Programming is the process of instructing a computer to perform a specific set of tasks by writing code in a language it can interpret or compile. At its core, every program is built on three fundamentals:

- **Data** — the values a program works with (numbers, text, structures)
- **Logic** — the sequence of decisions and computations applied to that data (conditionals, loops, functions)
- **Control flow** — the order in which instructions execute

Before a student can reason about *objects*, *classes*, or *inheritance*, they need a solid grounding in **procedural programming**: variables and data types, operators and expressions, control structures (`if`/`else`, `switch`, loops), functions, arrays, pointers, and memory. This repository assumes and briefly reinforces that foundation, since C++ requires more explicit memory and type management than many higher-level languages.

### 2. What is Object Oriented Programming (OOP)?

As programs grow in size and complexity, purely procedural code (a long sequence of functions operating on shared data) becomes hard to extend, test, and maintain. **Object Oriented Programming** is a paradigm that organizes code around *objects* — self-contained units that bundle data (attributes) with the behavior (methods) that operates on that data.

OOP is built on four pillars, each covered as a dedicated unit in this repository:

| Concept | What it means | Why it matters |
|---|---|---|
| **Encapsulation** | Bundling data and methods together, restricting direct access to internal state | Protects data integrity, hides implementation detail |
| **Abstraction** | Exposing only relevant details, hiding complexity behind a clean interface | Reduces cognitive load, simplifies usage |
| **Inheritance** | Deriving new classes from existing ones to reuse and extend behavior | Promotes code reuse, models real-world hierarchies |
| **Polymorphism** | Allowing objects of different types to be treated through a common interface | Enables flexible, extensible design (compile-time and run-time) |

OOP shifts the design question from *"what steps does this program follow?"* to *"what are the entities in this problem, and how do they interact?"* — a mindset that maps naturally onto real-world systems and is the basis for most modern large-scale software.

### 3. Why C++?

C++ is used to teach OOP for a specific reason: it is a **multi-paradigm language** that sits close to the hardware while still offering full OOP support. This makes it an ideal teaching tool because it forces students to understand *both*:

- **What's happening underneath** — manual memory management (`new`/`delete`), pointers, references, and how objects are actually laid out and constructed/destructed — concepts that many higher-level OOP languages abstract away entirely.
- **How OOP is expressed in syntax** — classes, constructors/destructors, access specifiers, operator overloading, virtual functions, templates, and the Standard Template Library (STL).

Because C++ doesn't hide the machine, students who learn OOP through it build an intuition for *why* the paradigm works, not just how to use its syntax — a foundation that transfers cleanly to Java, C#, Python, and other OOP languages later.

<br />

## Repository Structure

The material is organized unit-by-unit, following the Purbanchal University syllabus sequence. Each unit typically contains:

- **Notes** — concept explanations and theory
- **Programs** — annotated `.cpp` source files demonstrating each concept
- **Practice problems** — where applicable, exercises to reinforce the unit

*(Add/update this section with your actual folder names once finalized — happy to tailor it to the exact structure if you share it.)*

## Who This Is For

Primarily built for students following the Purbanchal University B.E./BSc.CSIT OOP with C++ curriculum, but usable by anyone looking for a structured, notes-plus-code path from programming fundamentals into Object Oriented design using C++.

## How to Use This Repository

1. Work through units in order — later units assume earlier OOP concepts.
2. Read the notes for a topic first, then study the accompanying program.
3. Compile and run the programs yourself; modify them to test your understanding.
4. Attempt any included practice problems before checking solutions.

## Prerequisites

- A C++ compiler (GCC/G++, Clang, or MSVC)
- Basic familiarity with any programming language is helpful but not required — Unit 1 covers programming fundamentals from scratch.

## Course Content

1. Introduction to object oriented programming<br /> 
	1.1 Procedural language vs OOP<br />
	1.2 Characteristics of object-oriented languages<br />
			1.2.1 Objects<br />
			1.2.2 Classes<br />
			1.2.3 Inheritance<br />
			1.2.4 Reusability<br />
			1.2.5 Polymorphism & overloading<br />
	1.3 Applications of OOP<br />


2. C++ programming concept<br />
	2.1 Introduction to programming in C++[ HelloWorld](./Programs/Basic%20C++%20Pragrams/HelloWorld.cpp)<br />
	2.2 Extraction operator (>>)<br />
	2.3 Insertion operator (<<)<br />
	2.4 Type conversion: automatic conversion, cast<br />
	2.5 Arrays and pointers in C++<br />
	2.6 New and delete operators<br />
	2.7 Manipulators<br />
	2.8 Const<br />
	2.9 Enumeration<br /> 

3. Functions used in C++<br />
	3.1 Introduction to functions<br />
	3.2 Passing arguments to functions<br />
	3.3 Returning values from functions<br />
	3.4 Reference arguments<br />
	3.5 Returning by reference<br />
	3.6 Functions overloading<br />
			3.6.1 Different number of arguments<br />
			3.6.2 Different kinds of arguments<br />
	3.7 Default arguments<br />
	3.8 Inline functions<br />
	
4. Classes and objects<br />
	4.1 Introduction<br />
	4.2 Access specifier (public, private and protected)<br />
	4.3 Accessing class members<br />
	4.4 Defining member functions<br />
			4.4.1 Member function inside the class body<br />
			4.4.2 Member function outside the class body<br />
	4.5 “this” pointer<br />
	4.6 Constructor & destructor<br /> 
	4.7 Types of constructor<br /> 
		4.7.1 Default constructor<br /> 
		4.7.2 Parameterized constructor<br /> 
		4.7.3 Copy constructor<br /> 
	4.8 Overloaded constructors<br />
	4.9 Static data member<br /> 
	4.10 Static member functions<br /> 
	4.11 Passing objects as arguments<br />
	4.12 Friend functions<br />
	4.13 Friend classes<br />

5. Operator overloading<br />
	5.1 Introduction to operator overloading<br />
	5.2 General rules for overloading operator<br />
	5.3 Operator overloading restrictions<br />
	5.4 Overloading unary and binary operators<br />
	5.5 Operator overloading using friend functions<br />
	5.6 Data conversion<br />
		5.6.1 Conversion between basic types and object<br />
		5.6.2 Conversion between object and basic types<br />
		5.6.3 Conversion between objects of different classes<br />

6. Virtual functions and Polymorphism<br />
	6.1 Introduction<br />
	6.2 Early vs late binding<br />
	6.3 Virtual functions<br />
	6.4 Pure virtual functions<br />
	6.5 Abstract classes<br />
6.6 Virtual base classes<br />

7. Inheritance<br />
	7.1 Introduction & benefits of inheritance<br />
	7.2 Types of inheritance<br />
	7.3 Inheritance: base classes & derived classes<br />
	7.4 Using constructors and destructors in derived classes<br />
	7.5 Abstract base class<br />
	7.6 Public, private and protected inheritance<br />
	7.7 Structural Crisis<br />
		7.7.1 Multipath Ambiguity<br />
		7.7.2 Diamond Problem<br />
			7.7.2.1 Virtual Inheritance, Virtual Base Classes & Scope Resolution<br />
			7.7.2.2 Method Overriding<br />
			7.7.2.3 Abstract Base Classes<br />
	7.8 Containership<br />
		7.8.1 Constructors Build Up<br />
		7.8.2 Destructors Tear Down<br />

8. Templates<br />
	8.1 Introduction to templates<br />
		8.1.1 Function templates<br />
		8.1.2 Class templates<br />
	8.2 Vector<br />
	8.3 Namespaces<br />
		8.3.1 Using namespace<br />
		8.3.2 Using the scope resolution operator<br />
		8.3.3 through “using” keyword<br />

9. Exception handling<br />
	9.1 Introduction to exceptions<br />
	9.2 Exception handling model<br />
	9.3 Exception handling construct: try, catch, throw<br />

10. File handling<br />
	10.1 Introduction<br />
	10.2 Opening and closing file<br />
	10.3 Opening file using constructor<br />
	10.4 Opening file using open () and open() file modes<br />
	10.5 Basic functions of seekg(), seekp(), tellg(), tellp()<br />
	10.6 Sequential input/output operations<br />
		10.6.1 put() and get() functions<br />
		10.6.2 write() and read () functions<br />
	10.7 Reading and writing a class objects<br />
	
