# Object Oriented Programming with C++

This repository consists of full course details, notes, and programs that can be used for studying Object Oriented Programming with C++. This course is structured and developed based on the curriculum developed by Purbanchal University, Gothgaun, Nepal.

Each topic below includes: **Notes**, a **Real-life Analogy**, a **Program**, and an **Explanation** of the program.

---

## Table of Contents

**Chapter 1: Introduction to Object Oriented Programming**
- [1.1 Procedural Language vs OOP](#11-procedural-language-vs-oop)
- [1.2 Characteristics of Object-Oriented Languages](#12-characteristics-of-object-oriented-languages)
  - [1.2.1 Objects](#121-objects)
  - [1.2.2 Classes](#122-classes)
  - [1.2.3 Inheritance](#123-inheritance)
  - [1.2.4 Reusability](#124-reusability)
  - [1.2.5 Polymorphism & Overloading](#125-polymorphism--overloading)
- [1.3 Applications of OOP](#13-applications-of-oop)

**Chapter 2: C++ Programming Concepts**
- [2.1 Introduction to Programming in C++](#21-introduction-to-programming-in-c)
- [2.2 Extraction Operator (>>)](#22-extraction-operator-)
- [2.3 Insertion Operator (<<)](#23-insertion-operator-)
- [2.4 Type Conversion: Automatic Conversion, Cast](#24-type-conversion-automatic-conversion-cast)
- [2.5 Arrays and Pointers in C++](#25-arrays-and-pointers-in-c)
- [2.6 New and Delete Operators](#26-new-and-delete-operators)
- [2.7 Manipulators](#27-manipulators)
- [2.8 Const](#28-const)
- [2.9 Enumeration](#29-enumeration)

**Chapter 3: Functions Used in C++**
- [3.1 Introduction to Functions](#31-introduction-to-functions)
- [3.2 Passing Arguments to Functions](#32-passing-arguments-to-functions)
- [3.3 Returning Values from Functions](#33-returning-values-from-functions)
- [3.4 Reference Arguments](#34-reference-arguments)
- [3.5 Returning by Reference](#35-returning-by-reference)
- [3.6 Function Overloading](#36-function-overloading)
  - [3.6.1 Different Number of Arguments](#361-different-number-of-arguments)
  - [3.6.2 Different Kinds of Arguments](#362-different-kinds-of-arguments)
- [3.7 Default Arguments](#37-default-arguments)
- [3.8 Inline Functions](#38-inline-functions)

---

# Chapter 1: Introduction to Object Oriented Programming

## 1.1 Procedural Language vs OOP


A **procedural language** (C, Pascal, FORTRAN) organizes a program as a sequence of instructions grouped into functions. Data and functions are separate; data is typically passed around as parameters between functions, and any function can usually access and change any data it is given. As programs grow, this separation makes it hard to control which parts of the code can touch a given piece of data, so bugs and unintended side effects multiply.

An **object-oriented language** (C++, Java, Python) organizes a program around **objects** — bundles that combine data (attributes) and the functions that operate on that data (methods) into a single unit. Access to the data is controlled through the object's own methods (encapsulation), which keeps the "what" (data) and the "how" (behavior) together and protected.

| Aspect | Procedural | Object-Oriented |
|---|---|---|
| Focus | Functions / procedures | Objects (data + behavior) |
| Data security | Data is global/passed freely, less secure | Data is encapsulated, access controlled |
| Approach | Top-down | Bottom-up |
| Code reuse | Limited (copy-paste, functions) | High (inheritance, classes) |
| Real-world mapping | Weak | Strong (models real entities) |
| Examples | C, COBOL, Pascal | C++, Java, C#, Python |

**Real-life Analogy**

Think of a **hospital**. A procedural approach would be like having one giant instruction manual that lists every single step for every task — admit patient, check vitals, bill insurance, dispense medicine — all mixed together, and any staff member could act on any part of it. An OOP approach is like the actual hospital: there's a `Doctor` object, a `Nurse` object, a `Receptionist` object, a `Patient` object — each with its own data (their own records, own responsibilities) and its own defined behaviors. A nurse doesn't directly rewrite billing records; she asks the `Billing` department (object) to do it. Responsibilities are distributed and protected.

**Program**

```cpp
// Procedural style
#include <iostream>
using namespace std;

// Data and functions are separate
struct Student {
    string name;
    int marks;
};

void printStudent(Student s) {   // function operates on external data
    cout << s.name << " scored " << s.marks << endl;
}

int main() {
    Student s1 = {"Sita", 88};
    printStudent(s1);
    return 0;
}
```

```cpp
// Object-Oriented style
#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int marks;
public:
    void setData(string n, int m) { name = n; marks = m; }
    void display() { cout << name << " scored " << marks << endl; } // behavior bundled with data
};

int main() {
    Student s1;
    s1.setData("Sita", 88);
    s1.display();
    return 0;
}
```

**Explanation**

In the procedural version, `Student` is a passive data structure (`struct`) and `printStudent()` is a completely separate function that must be handed the data to work on — anyone, anywhere in the program, could modify `s1.marks` directly. In the OOP version, `marks` and `name` are `private`, so they can only be changed through the class's own methods (`setData`, `display`). The data and the logic that manipulates it now live together as one unit — this is the core shift from procedural to object-oriented thinking.

---

## 1.2 Characteristics of Object-Oriented Languages

### 1.2.1 Objects


An **object** is a run-time entity that combines **state** (data members/attributes) and **behavior** (member functions/methods). It is a concrete instance of a class — if a class is the blueprint, the object is the actual thing built from that blueprint. Every object has its own copy of the data members (unless declared `static`), but shares the class's member functions.

**Real-life Analogy**

A **car blueprint** (class) describes what every car of that model will have: 4 wheels, an engine, a color, a speedometer, and behaviors like `accelerate()` and `brake()`. Your actual red Honda Civic parked in your driveway is an **object** — a specific instance with its own state (red color, 40,000 km on the odometer) built from that blueprint.

**Program**

```cpp
#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    int speed = 0;

    void accelerate(int by) {
        speed += by;
        cout << brand << " is now going " << speed << " km/h" << endl;
    }
};

int main() {
    Car myCar;             // myCar is an object of class Car
    myCar.brand = "Honda";
    myCar.accelerate(30);  // object's own state changes independently

    Car friendsCar;        // another, independent object
    friendsCar.brand = "Toyota";
    friendsCar.accelerate(50);

    return 0;
}
```

**Explanation**

`myCar` and `friendsCar` are both objects of the same class `Car`, but each maintains its own independent `speed` and `brand`. Calling `accelerate()` on `myCar` has no effect on `friendsCar` — this is what "each object has its own state" means in practice.

---

### 1.2.2 Classes


A **class** is a user-defined blueprint or template that defines the data members and member functions common to all objects of that type. It does not occupy memory by itself — memory is allocated only when an object of that class is created. A class typically groups members into `private` (hidden, accessible only within the class), `protected` (accessible within the class and its derived classes), and `public` (accessible from outside).

**Real-life Analogy**

An **architectural blueprint for a house** specifies rooms, dimensions, and wiring plans, but you cannot live inside a blueprint — it's just a plan. Once a builder constructs an actual house from that blueprint, people can move in. The blueprint is the **class**; each constructed house is an **object**.

**Program**

```cpp
#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;      // hidden — cannot be accessed directly from outside
public:
    BankAccount(double initial) { balance = initial; }  // constructor

    void deposit(double amt) { balance += amt; }

    void showBalance() { cout << "Balance: " << balance << endl; }
};

int main() {
    BankAccount acc(1000.0);   // object created from the class
    acc.deposit(500.0);
    acc.showBalance();         // Balance: 1500
    // acc.balance = 999999;   // ERROR: balance is private
    return 0;
}
```

**Explanation**

`BankAccount` is the class — the definition of what data (`balance`) and operations (`deposit`, `showBalance`) an account has. `balance` is marked `private`, so it can only be changed through the class's own methods (`deposit`), never assigned directly from `main()`. This protects the account's integrity — a direct client-side edit like `acc.balance = 999999;` would fail to compile.

---

### 1.2.3 Inheritance


**Inheritance** lets a new class (**derived/child class**) acquire the properties and behaviors of an existing class (**base/parent class**), and then extend or override them. It models "is-a" relationships (a `Car` **is a** `Vehicle`) and is a major mechanism for code reuse. C++ supports single, multiple, multilevel, hierarchical, and hybrid inheritance, and access to inherited members is controlled by `public`, `protected`, or `private` inheritance mode.

**Real-life Analogy**

Think of **inheritance in a family business**. A general `Employee` has a name and a salary and can `work()`. A `Manager` **is an** `Employee` — they inherit the name, salary, and `work()` ability, but additionally have their own extra ability, `approveLeave()`. The manager didn't have to redefine what an employee is; they just extended it.

**Program**

```cpp
#include <iostream>
using namespace std;

class Employee {              // base class
protected:
    string name;
    double salary;
public:
    void setDetails(string n, double s) { name = n; salary = s; }
    void work() { cout << name << " is working." << endl; }
};

class Manager : public Employee {   // derived class inherits Employee
public:
    void approveLeave(string empName) {
        cout << name << " approved leave for " << empName << endl;
    }
};

int main() {
    Manager m;
    m.setDetails("Ramesh", 80000);  // inherited from Employee
    m.work();                        // inherited from Employee
    m.approveLeave("Sita");          // Manager's own method
    return 0;
}
```

**Explanation**

`Manager` does not redefine `setDetails()` or `work()` — it inherits them directly from `Employee` through `public` inheritance. It only adds what's genuinely new to a manager's role: `approveLeave()`. This avoids duplicating code that already exists in the base class.

---

### 1.2.4 Reusability


**Reusability** is the ability to use existing classes/code to build new functionality without rewriting it, achieved mainly through inheritance and composition (building an object out of other objects) in OOP. It reduces development time, testing effort, and bugs, since well-tested code is reused rather than reproduced.

**Real-life Analogy**

An **electrician** doesn't rebuild a plug from raw copper and plastic every time they wire a new lamp — they reuse a standard, pre-tested plug component. In software, once a `Rectangle` class is written and tested, a `Square` class can reuse it (a square is a special rectangle) instead of writing area/perimeter logic from scratch.

**Program**

```cpp
#include <iostream>
using namespace std;

class Rectangle {
protected:
    double length, width;
public:
    void setDimensions(double l, double w) { length = l; width = w; }
    double area() { return length * width; }
};

class Square : public Rectangle {   // reuses Rectangle's logic
public:
    void setSide(double s) { setDimensions(s, s); }  // reuses setDimensions()
};

int main() {
    Square sq;
    sq.setSide(5);
    cout << "Area: " << sq.area() << endl;  // reuses Rectangle::area()
    return 0;
}
```

**Explanation**

`Square` never re-implements `area()` — it reuses `Rectangle`'s already-written and tested logic simply by inheriting from it. This is reusability in action: new functionality (`Square`) is built on top of proven, existing code (`Rectangle`).

---

### 1.2.5 Polymorphism & Overloading

**Polymorphism** ("many forms") means the same function name or operator behaves differently depending on the context — the object it's called on, or the arguments passed to it. C++ supports two main kinds:
- **Compile-time (static) polymorphism** — resolved by the compiler at compile time. Achieved via **function overloading** (same function name, different parameter lists) and **operator overloading**.
- **Run-time (dynamic) polymorphism** — resolved during program execution, achieved via **virtual functions** and inheritance (a base class pointer calling a derived class's overridden method).

**Real-life Analogy**

The word "**draw**" means different things depending on context: `draw` a gun, `draw` a picture, `draw` a card from a deck, `draw` water from a well. The same action name, applied differently based on what/who is doing it — that's polymorphism. Function overloading is like a Swiss Army knife's single "open" mechanism behaving differently on the blade vs. the scissors vs. the bottle opener, depending on which tool you pull.

**Program**

```cpp
#include <iostream>
using namespace std;

// Compile-time polymorphism: function overloading
class Calculator {
public:
    int add(int a, int b) { return a + b; }
    double add(double a, double b) { return a + b; }
    int add(int a, int b, int c) { return a + b + c; }
};

// Run-time polymorphism: virtual functions
class Shape {
public:
    virtual void draw() { cout << "Drawing a generic shape" << endl; }
};

class Circle : public Shape {
public:
    void draw() override { cout << "Drawing a circle" << endl; }  // overrides base
};

int main() {
    Calculator calc;
    cout << calc.add(2, 3) << endl;         // calls int version
    cout << calc.add(2.5, 3.5) << endl;     // calls double version
    cout << calc.add(1, 2, 3) << endl;      // calls 3-argument version

    Shape* s = new Circle();
    s->draw();   // "Drawing a circle" — resolved at runtime via virtual function
    delete s;
    return 0;
}
```

**Explanation**

`calc.add()` is called three times with different argument types/counts; the compiler decides at compile time which `add()` to invoke — that's overloading (static polymorphism). `s->draw()` is decided at run time: even though `s` is declared as a `Shape*`, because `draw()` is `virtual` and `s` actually points to a `Circle` object, the `Circle` version runs — that's dynamic polymorphism.

---

## 1.3 Applications of OOP


OOP's ability to model real-world entities directly makes it the dominant paradigm for large, complex, and long-lived software. Common application areas include:
- **GUI and desktop applications** — windows, buttons, menus as objects.
- **Web and enterprise applications** — frameworks like Spring (Java), Django (Python), ASP.NET model requests, users, and services as objects.
- **Game development** — characters, weapons, physics bodies as objects with behavior and inheritance (C++ dominates here — Unreal Engine).
- **CAD/simulation software** — real-world objects (beams, circuits, molecules) modeled directly as classes.
- **Database and ORM systems** — tables mapped to classes, rows to objects.
- **Operating systems and device drivers** — C++ is used for performance-critical, hardware-close OOP (parts of Windows).
- **Embedded systems and robotics** — sensors, actuators, controllers modeled as reusable, testable objects.

**Real-life Analogy**

A **car manufacturing plant** doesn't build every car from raw materials on the spot. It designs reusable "class" blueprints for the engine, chassis, and electronics, then mass-produces "objects" (actual cars) from them, sharing quality-tested designs across thousands of units, and swapping or upgrading individual components (inheritance/polymorphism) without redesigning the whole car. That is exactly how large software systems — game engines, banking software, hospital systems — are built with OOP.

**Program**

```cpp
#include <iostream>
using namespace std;

// A tiny illustration: OOP modeling a real-world domain (a library system)
class Book {
    string title;
    bool isIssued = false;
public:
    Book(string t) : title(t) {}
    void issue() {
        if (!isIssued) { isIssued = true; cout << title << " issued.\n"; }
        else cout << title << " is already issued.\n";
    }
    void returnBook() { isIssued = false; cout << title << " returned.\n"; }
};

int main() {
    Book b1("Introduction to C++");
    b1.issue();
    b1.issue();       // demonstrates state check
    b1.returnBook();
    return 0;
}
```

**Explanation**

Real applications like library management, hospital records, and e-commerce systems all follow this same pattern: model each real-world entity (`Book`, `Patient`, `Order`) as a class with its own state and rules, then let objects interact. This is why OOP scales well to large, real-world software.

---

# Chapter 2: C++ Programming Concepts

## 2.1 Introduction to Programming in C++


C++ was developed by **Bjarne Stroustrup** at Bell Labs (starting 1979, originally "C with Classes") as an extension of C, adding OOP features while retaining C's low-level control and performance. Every C++ program has one `main()` function, the program's entry point. Key building blocks: headers (`#include`), namespaces (`using namespace std;`), statements, and functions. C++ is a compiled, statically-typed, multi-paradigm language (supports procedural, object-oriented, and generic programming).

**Real-life Analogy**

Learning C++ is like learning to **cook in a professional, fully-equipped kitchen** rather than with just a campfire (C). You get all of C's raw control over your ingredients (memory, pointers) plus organized stations, standardized tools, and recipes (classes, the Standard Library) that let you build far more complex dishes reliably.

**Program**

```cpp
#include <iostream>   // header for input/output
using namespace std;  // avoids writing std:: everywhere

int main() {           // program entry point
    cout << "Hello, Object Oriented World!" << endl;
    return 0;           // 0 signals successful execution to the OS
}
```

**Explanation**

`#include <iostream>` brings in the input/output stream library. `using namespace std;` lets us write `cout` instead of `std::cout`. Execution always begins at `main()`. `cout << "..."` prints to the console, and `return 0;` tells the operating system the program finished without errors.

---

## 2.2 Extraction Operator (>>)


The **extraction operator `>>`** (also called the **stream extraction / input operator**) reads (extracts) data **from** an input stream (like `cin`, the keyboard) **into** a variable. It automatically skips leading whitespace for most types and stops reading at the next whitespace. It can be chained: `cin >> a >> b;`.

**Real-life Analogy**

Think of `>>` as **pouring liquid from a jug into a cup** — data flows *out of* the input stream (`cin`, the jug) *into* your variable (the cup). The arrows visually point in the direction data is extracted: into your variable.

**Program**

```cpp
#include <iostream>
using namespace std;

int main() {
    string name;
    int age;

    cout << "Enter your name and age: ";
    cin >> name >> age;   // extracts two values from the input stream

    cout << "Hello " << name << ", you are " << age << " years old." << endl;
    return 0;
}
```

**Explanation**

`cin >> name >> age;` reads a word into `name`, then an integer into `age`, in one chained statement. `cin` is the standard input stream object; `>>` extracts whitespace-separated tokens from it into the variables on its right, converting the text automatically to match each variable's type.

---

## 2.3 Insertion Operator (<<)


The **insertion operator `<<`** (stream insertion / output operator) sends (inserts) data **from** a variable or literal **into** an output stream (like `cout`, the screen). It can also be chained, and works with manipulators (see 2.7) to control formatting.

**Real-life Analogy**

`<<` is like **inserting mail into a mailbox** — you're pushing information *into* the output stream (`cout`), which then displays it. The arrows point toward the destination stream.

**Program**

```cpp
#include <iostream>
using namespace std;

int main() {
    string city = "Kathmandu";
    int population = 3000000;

    cout << "City: " << city << ", Population: " << population << endl; // chained insertion
    return 0;
}
```

**Explanation**

Each `<<` inserts the item on its right into `cout`, and the operator returns the stream itself, which is why multiple `<<` can be chained in a single statement — `cout << a << b << c;` is really `((cout << a) << b) << c;`.

---

## 2.4 Type Conversion: Automatic Conversion, Cast


- **Automatic (implicit) conversion**: The compiler converts one data type to another automatically when it's "safe" or well-defined — e.g., `int` to `double` in a mixed expression, or during assignment/function calls. This follows C++'s standard promotion/conversion rules (`char` → `int` → `float` → `double`, etc.).
- **Explicit conversion (casting)**: The programmer forces a conversion using a cast. C++ offers:
  - **C-style cast**: `(int)x`
  - **Function-style cast**: `int(x)`
  - **C++-style casts** (safer, preferred): `static_cast<int>(x)`, `dynamic_cast`, `const_cast`, `reinterpret_cast`.

Implicit conversion can silently lose data (e.g., `double` → `int` truncates); explicit casts make the programmer's intent visible and are safer for maintenance.

**Real-life Analogy**

Automatic conversion is like a **currency exchange counter that auto-rounds** small change without asking you — convenient but you might lose a few cents without noticing. An explicit cast is like **deliberately asking the teller**, "please give me only whole dollars, I know I'll lose the coins" — you consciously accept the loss.

**Program**

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    double b = 3.5;

    double result = a + b;   // automatic (implicit) conversion: a promoted to double
    cout << "Implicit: " << result << endl;   // 13.5

    double pi = 3.14159;
    int truncated = static_cast<int>(pi);     // explicit cast
    cout << "Explicit cast: " << truncated << endl;  // 3

    return 0;
}
```

**Explanation**

In `a + b`, the compiler implicitly promotes `a` (an `int`) to `double` before adding, so no data is lost and `result` is `13.5`. In the second case, `static_cast<int>(pi)` explicitly truncates the decimal part of `pi`, clearly signaling to any reader of the code that data loss is intentional here.

---

## 2.5 Arrays and Pointers in C++


An **array** is a fixed-size, contiguous block of memory holding elements of the same type, accessed via an index (`arr[0]`, `arr[1]`, ...). A **pointer** is a variable that stores the memory address of another variable. In C++, the array name itself decays into a pointer to its first element in most expressions, which is why `arr[i]` and `*(arr + i)` are equivalent. Pointers enable dynamic memory access, passing large data efficiently, and building dynamic data structures (linked lists, trees).

**Real-life Analogy**

An **array** is like a **row of numbered mailboxes** in an apartment building — fixed number of boxes, each holding one item, accessed by box number. A **pointer** is like a **piece of paper with an address written on it** — it doesn't hold the mail itself, it just tells you where to go find it. Following that address to check the mailbox is called "dereferencing."

**Program**

```cpp
#include <iostream>
using namespace std;

int main() {
    int marks[5] = {70, 85, 90, 60, 95};   // array
    int* ptr = marks;                       // pointer to the first element (array decays to pointer)

    cout << "Using array indexing:\n";
    for (int i = 0; i < 5; i++)
        cout << marks[i] << " ";
    cout << endl;

    cout << "Using pointer arithmetic:\n";
    for (int i = 0; i < 5; i++)
        cout << *(ptr + i) << " ";   // dereference pointer offset by i
    cout << endl;

    return 0;
}
```

**Explanation**

`marks` is an array of 5 integers stored contiguously in memory. `ptr` is a pointer initialized to the address of `marks[0]`. `*(ptr + i)` moves the pointer `i` elements forward (pointer arithmetic automatically scales by `sizeof(int)`) and dereferences it — accessing the same memory as `marks[i]`. Both loops print identical output, proving the array-pointer equivalence.

---

## 2.6 New and Delete Operators


`new` and `delete` manage **dynamic memory** (heap memory) in C++, replacing C's `malloc()`/`free()`.
- `new` allocates memory at run time and returns a pointer to it; `new Type[n]` allocates an array.
- `delete` frees memory allocated with `new`; `delete[]` must be used to free memory allocated with `new[]`.
- Failing to `delete` causes a **memory leak**; using memory after `delete` (a "dangling pointer") causes undefined behavior.

**Real-life Analogy**

`new` is like **checking into a hotel room** — you request a room (memory) as you need it, and you get a room key (pointer) with its number. `delete` is **checking out** — you must return the key so the room becomes available for the next guest. If you leave without checking out, that room stays "occupied" forever even though nobody's using it — that's a memory leak.

**Program**

```cpp
#include <iostream>
using namespace std;

int main() {
    int* single = new int(42);         // allocate a single int on the heap
    cout << "Value: " << *single << endl;
    delete single;                      // free it

    int n = 5;
    int* arr = new int[n];              // allocate an array on the heap
    for (int i = 0; i < n; i++) arr[i] = i * 10;

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    delete[] arr;   // must match new[] with delete[]
    return 0;
}
```

**Explanation**

`new int(42)` reserves heap memory for one integer, initializes it to 42, and returns its address into `single`. `delete single;` releases that memory back to the system. `new int[n]` reserves a block for `n` integers; because it was allocated as an array, it must be released with `delete[] arr;` (not plain `delete arr;`), or the program's behavior is undefined.

---

## 2.7 Manipulators


**Manipulators** are special functions used with `<<` and `>>` to format stream input/output (from `<iomanip>` and `<iostream>`). Common ones:
- `endl` — inserts a newline and flushes the stream.
- `setw(n)` — sets the field width for the next output.
- `setprecision(n)` — sets decimal precision for floating-point output.
- `fixed` — displays floating-point numbers in fixed notation.
- `setfill(c)` — sets the fill character for padded fields.
- `left` / `right` — set text alignment within a field.

**Real-life Analogy**

Manipulators are like the **formatting toolbar in a word processor** (bold, alignment, column width) — the underlying text/data doesn't change, only how it is displayed. `setw(10)` is like setting a fixed column width in a printed table so numbers line up neatly.

**Program**

```cpp
#include <iostream>
#include <iomanip>   // required for setw, setprecision, setfill
using namespace std;

int main() {
    double pi = 3.14159265;

    cout << fixed << setprecision(2) << pi << endl;   // 3.14

    cout << setw(10) << "Name" << setw(10) << "Marks" << endl;
    cout << setw(10) << "Sita"  << setw(10) << 88 << endl;

    cout << setfill('*') << setw(10) << 42 << endl;   // ******42

    return 0;
}
```

**Explanation**

`fixed` plus `setprecision(2)` forces `pi` to print with exactly two digits after the decimal point (`3.14`) instead of the default six significant digits. `setw(10)` reserves 10 characters of width for the *next* single output only (it must be reapplied each time), right-aligning by default — producing neatly columned output. `setfill('*')` changes the padding character used to fill unused width.

---

## 2.8 Const


The `const` keyword marks a value as **immutable** after initialization — the compiler enforces this and rejects any code that tries to modify it. Uses include:
- `const int x = 10;` — a constant variable.
- `const` function parameters — promise the function won't modify the argument.
- `const` member functions (`void show() const`) — promise the method won't modify the object's data members.
- `const` pointers — `const int* p` (pointer to constant data), `int* const p` (constant pointer to data).

**Real-life Analogy**

`const` is like **engraving something in stone** rather than writing it on a whiteboard. Once engraved (initialized), it cannot be altered — any attempt to "erase and rewrite" is caught immediately, before the mistake can cause real damage.

**Program**

```cpp
#include <iostream>
using namespace std;

class Circle {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double getArea() const {         // const member function: promises not to modify the object
        return 3.14159 * radius * radius;
    }
};

void printValue(const int& x) {      // const parameter: promises not to modify x
    cout << "Value: " << x << endl;
    // x = 100;  // ERROR: cannot modify a const reference
}

int main() {
    const double PI = 3.14159;   // const variable
    // PI = 3.14;                // ERROR: cannot reassign a const

    Circle c(5.0);
    cout << "Area: " << c.getArea() << endl;

    printValue(42);
    return 0;
}
```

**Explanation**

`PI` cannot be reassigned once initialized — the compiler flags any attempted change. `getArea() const` guarantees to callers that calling this method will never alter the `Circle` object's state, which lets it be safely called even on a `const Circle` object. `printValue(const int& x)` promises the caller that `x` will not be modified inside the function, while still avoiding the cost of copying the argument.

---

## 2.9 Enumeration


An **enumeration (`enum`)** defines a named set of integer constants, improving code readability compared to raw "magic numbers." By default, values start at 0 and increase by 1, but can be assigned explicitly. C++11 introduced **scoped enums** (`enum class`) which avoid naming clashes and require explicit qualification (`Color::RED`), unlike plain `enum` values which leak into the surrounding scope.

**Real-life Analogy**

An `enum` is like the **days-of-the-week dial on a mechanical watch** — instead of remembering "day 3" means Wednesday, the dial shows the actual name. It restricts the value to one of a fixed, named set of options, exactly like the dial can only land on one of seven positions, never "day 9."

**Program**

```cpp
#include <iostream>
using namespace std;

enum Day { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY };  // SUNDAY=0, ..., SATURDAY=6

enum class TrafficLight { RED, YELLOW, GREEN };   // scoped enum (C++11)

int main() {
    Day today = WEDNESDAY;
    cout << "Day number: " << today << endl;   // prints 3

    TrafficLight signal = TrafficLight::RED;    // must qualify with TrafficLight::
    if (signal == TrafficLight::RED)
        cout << "Stop!" << endl;

    return 0;
}
```

**Explanation**

`today` holds the value `3` internally (since `SUNDAY=0, MONDAY=1, TUESDAY=2, WEDNESDAY=3`), but the code reads clearly as `WEDNESDAY` rather than a mysterious literal `3`. `TrafficLight`, declared with `enum class`, requires the `TrafficLight::` prefix even inside `main()` — this prevents its `RED` from accidentally clashing with some other unrelated `RED` constant elsewhere in a large program.

---

# Chapter 3: Functions Used in C++

## 3.1 Introduction to Functions


A **function** is a named, reusable block of code that performs a specific task, optionally taking inputs (parameters) and optionally returning a value. Functions have a **declaration/prototype** (signature) and a **definition** (body). Benefits: modularity, reusability, easier debugging/testing, and abstraction (hiding implementation detail behind a name).

**Real-life Analogy**

A function is like a **vending machine**: you provide inputs (coins + a button press = parameters), it performs an internal process you don't need to see, and it returns an output (a snack = return value). You don't need to know the machine's internal mechanics every time you use it — you just trust the interface.

**Program**

```cpp
#include <iostream>
using namespace std;

int square(int n) {        // function definition
    return n * n;
}

int main() {
    int result = square(6);   // function call
    cout << "Square: " << result << endl;
    return 0;
}
```

**Explanation**

`square(int n)` is defined once and can be called any number of times with different inputs. `main()` calls it with `6`, receives `36` back, and stores it in `result` — the caller doesn't need to know or care *how* squaring is computed internally, only what it does.

---

## 3.2 Passing Arguments to Functions


C++ supports two primary ways of passing arguments:
- **Pass by value**: A *copy* of the argument is passed; changes inside the function do not affect the original variable. Default in C++.
- **Pass by reference**: The function receives an alias (`&`) to the original variable; changes inside the function directly affect the caller's variable. (Pass by pointer is a related third approach, passing an address explicitly.)

**Real-life Analogy**

**Pass by value** is like handing someone a **photocopy** of a document — they can scribble on it all they want, your original stays untouched. **Pass by reference** is like handing someone the **original document itself** — any edits they make are permanent changes to your actual document.

**Program**

```cpp
#include <iostream>
using namespace std;

void addTenByValue(int n) {       // receives a copy
    n += 10;
}

void addTenByReference(int& n) {  // receives an alias to the original
    n += 10;
}

int main() {
    int a = 5, b = 5;

    addTenByValue(a);
    cout << "By value, a = " << a << endl;         // a = 5 (unchanged)

    addTenByReference(b);
    cout << "By reference, b = " << b << endl;      // b = 15 (changed)

    return 0;
}
```

**Explanation**

`addTenByValue(a)` operates on a private copy of `a`, so the increment is lost once the function returns — `a` remains `5`. `addTenByReference(b)` operates directly on `b` itself (via the reference `int& n`), so the modification persists after the function returns — `b` becomes `15`.

---

## 3.3 Returning Values from Functions


A function's **return type**, declared before its name, specifies the type of value it sends back to the caller using the `return` statement. A function can return at most one value directly (though a `struct`/`class`/`pair`/`tuple` can bundle multiple values into one returned object). `void` means the function returns nothing.

**Real-life Analogy**

Returning a value is like an **ATM giving you cash** after you complete a transaction — the machine (function) processes your request internally and hands back exactly one result (the requested amount) through its designated output slot (the `return` statement).

**Program**

```cpp
#include <iostream>
using namespace std;

double calculateBMI(double weightKg, double heightM) {
    double bmi = weightKg / (heightM * heightM);
    return bmi;    // sends the computed value back to the caller
}

int main() {
    double result = calculateBMI(70, 1.75);
    cout << "BMI: " << result << endl;
    return 0;
}
```

**Explanation**

`calculateBMI` computes a `double` and sends it back via `return bmi;`. In `main()`, the call `calculateBMI(70, 1.75)` is itself replaced by the value it returns, which is then stored in `result` — this is what makes function calls usable directly inside expressions.

---

## 3.4 Reference Arguments


A **reference parameter** (`Type& name`) is an alias for the caller's actual variable — no copy is made, and any change inside the function is reflected outside it. References are commonly used to (a) avoid the cost of copying large objects, and (b) allow a function to modify multiple caller variables (something a single `return` cannot do alone). Use `const Type&` when you want the efficiency of a reference without allowing modification.

**Real-life Analogy**

A reference argument is like giving someone a **nickname that refers to the same person** — "call the doctor" and "call Dr. Sharma" both refer to the exact same individual; there aren't two different people. Any action taken on "the doctor" happens to Dr. Sharma directly, not to a stand-in.

**Program**

```cpp
#include <iostream>
using namespace std;

void swapValues(int& x, int& y) {   // reference parameters
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int p = 10, q = 20;
    cout << "Before: p=" << p << " q=" << q << endl;

    swapValues(p, q);   // no & needed at call site; references bind automatically

    cout << "After: p=" << p << " q=" << q << endl;
    return 0;
}
```

**Explanation**

`x` and `y` inside `swapValues` are not copies — they are aliases directly bound to `p` and `q` from `main()`. So swapping `x` and `y` inside the function genuinely swaps `p` and `q` themselves — this could not be achieved by pass-by-value, since a value-based swap would only swap local copies and be lost when the function returns.

---

## 3.5 Returning by Reference


A function can return a **reference** (`Type&`) instead of a value, meaning it hands back an alias to an existing variable rather than a copy. This is efficient for large objects and is essential for enabling expressions like `a[i] = 5` (where `operator[]` returns a reference so it can appear on the *left* side of an assignment). **Caution**: never return a reference to a local variable — it will be destroyed when the function ends, leaving a **dangling reference**.

**Real-life Analogy**

Returning by value is like handing someone a **printed copy** of a page from your notebook — they can mark it up freely, and your notebook is untouched. Returning by reference is like handing someone a **bookmark that points directly to the actual page in your notebook** — anything they write there is written in your real notebook.

**Program**

```cpp
#include <iostream>
using namespace std;

int arr[5] = {10, 20, 30, 40, 50};

int& getElement(int index) {   // returns a reference to the actual array element
    return arr[index];
}

int main() {
    cout << "Before: " << arr[2] << endl;    // 30

    getElement(2) = 999;   // modifies arr[2] directly, since a reference was returned

    cout << "After: " << arr[2] << endl;     // 999
    return 0;
}
```

**Explanation**

Because `getElement()` returns `int&` (a reference), the expression `getElement(2)` is not a temporary copy — it *is* `arr[2]` itself, which is why it's legal to assign to it directly: `getElement(2) = 999;`. Had the function returned a plain `int` (by value), that same assignment would fail to compile, since you cannot assign to a temporary value.

---

## 3.6 Function Overloading


**Function overloading** lets multiple functions share the same name as long as their **parameter lists differ** (in number and/or type) — this is compile-time (static) polymorphism (see 1.2.5). The compiler picks the correct version based on the arguments used at each call site. The return type alone is *not* enough to distinguish overloaded functions.

**Real-life Analogy**

The word "**cut**" is overloaded in everyday language: "cut the cake" (with a knife), "cut the grass" (with a mower), "cut the deck of cards" (by hand). Same word, different meaning determined entirely by what you hand it — that's overloading.

### 3.6.1 Different Number of Arguments

**Program**

```cpp
#include <iostream>
using namespace std;

int volumeBox(int side) {                       // 1 argument: cube
    return side * side * side;
}

int volumeBox(int length, int width, int height) {  // 3 arguments: cuboid
    return length * width * height;
}

int main() {
    cout << "Cube volume: " << volumeBox(4) << endl;              // uses 1-arg version
    cout << "Cuboid volume: " << volumeBox(2, 3, 4) << endl;      // uses 3-arg version
    return 0;
}
```

**Explanation**

Both functions are named `volumeBox`, but the compiler distinguishes them purely by how many arguments are supplied at the call site — one integer selects the cube version, three integers select the cuboid version.

### 3.6.2 Different Kinds of Arguments

**Program**

```cpp
#include <iostream>
using namespace std;

void show(int i) {
    cout << "Integer: " << i << endl;
}

void show(double d) {
    cout << "Double: " << d << endl;
}

void show(string s) {
    cout << "String: " << s << endl;
}

int main() {
    show(10);        // matches show(int)
    show(3.14);       // matches show(double)
    show("Hello");    // matches show(string)
    return 0;
}
```

**Explanation**

Here, all three `show()` functions take exactly one parameter, but of different **types**. The compiler examines the type of the argument at each call and selects the matching overload — passing `10` selects the `int` version, `3.14` selects `double`, and a string literal selects the `string` version.

---

## 3.7 Default Arguments

A **default argument** supplies a fallback value for a parameter, used automatically when the caller omits that argument. Default values are specified in the function's **declaration** (or definition if there's no separate declaration), and once a parameter has a default value, every parameter after it must also have one. Callers can override any default simply by supplying their own value.

**Real-life Analogy**

Ordering a coffee with a "**default**" size (medium) means if you just say "one latte," you automatically get a medium — but you can still explicitly say "large latte" to override the default. The barista (function) has a sensible fallback so you don't have to specify everything every time.

**Program**

```cpp
#include <iostream>
using namespace std;

void greet(string name, string greeting = "Hello") {   // greeting has a default
    cout << greeting << ", " << name << "!" << endl;
}

int main() {
    greet("PK");                  // uses default: "Hello, PK!"
    greet("PK", "Good morning");  // overrides default: "Good morning, PK!"
    return 0;
}
```

**Explanation**

The first call omits the second argument, so the compiler automatically substitutes the default value `"Hello"`. The second call explicitly supplies `"Good morning"`, which overrides the default entirely — default arguments are only used to fill in *missing trailing* arguments, never to override ones that were actually provided.

---

## 3.8 Inline Functions


An `inline` function is a *hint* to the compiler to replace each call to a small function with its actual code body directly at the call site, instead of doing a normal function call (which has overhead: pushing arguments to the stack, jump, return). This can speed up execution for small, frequently-called functions, at the cost of a larger compiled binary (code duplication). The compiler is free to ignore the `inline` hint for larger or recursive functions.

**Real-life Analogy**

A normal function call is like **calling a specialist at another office** every time you need a small task done — there's overhead in placing the call, waiting, and getting a reply. An inline function is like **keeping a sticky note with the answer right on your own desk** — for something quick and simple, it's faster to just have the answer right there than to place a call each time.

**Program**

```cpp
#include <iostream>
using namespace std;

inline int square(int n) {    // suggests the compiler inline this call
    return n * n;
}

int main() {
    for (int i = 1; i <= 5; i++)
        cout << "Square of " << i << " = " << square(i) << endl;
    return 0;
}
```

**Explanation**

Because `square()` is marked `inline` and is trivially small, the compiler may replace every `square(i)` call directly with `i * i` in the compiled code, avoiding the overhead of five separate function calls in the loop. The program's output is identical either way — `inline` is purely a performance/optimization consideration, not a functional one.

---

## Repository Structure (Suggested)

```
ProgrammingCPlusPlus/
├── README.md
├── 01-Introduction-to-OOP/
│   ├── 1.1-Procedural-vs-OOP/
│   ├── 1.2-Characteristics/
│   │   ├── 1.2.1-Objects/
│   │   ├── 1.2.2-Classes/
│   │   ├── 1.2.3-Inheritance/
│   │   ├── 1.2.4-Reusability/
│   │   └── 1.2.5-Polymorphism-Overloading/
│   └── 1.3-Applications-of-OOP/
├── 02-CPP-Programming-Concepts/
│   ├── 2.1-Introduction/
│   ├── 2.2-Extraction-Operator/
│   ├── 2.3-Insertion-Operator/
│   ├── 2.4-Type-Conversion/
│   ├── 2.5-Arrays-and-Pointers/
│   ├── 2.6-New-Delete/
│   ├── 2.7-Manipulators/
│   ├── 2.8-Const/
│   └── 2.9-Enumeration/
├── 03-Functions-in-CPP/
│    ├── 3.1-Introduction-to-Functions/
│    ├── 3.2-Passing-Arguments/
│    ├── 3.3-Returning-Values/
│    ├── 3.4-Reference-Arguments/
│    ├── 3.5-Returning-by-Reference/
│    ├── 3.6-Function-Overloading/
│    │   ├── 3.6.1-Different-Number-of-Arguments/
│    │   └── 3.6.2-Different-Kinds-of-Arguments/
│    ├── 3.7-Default-Arguments/
│    └── 3.8-Inline-Functions/
├── 04-Classes and objects/
│     ├── 4.1- Introduction/
│	  ├── 4.2 Access specifier (public, private and protected)/
│	  ├── 4.3 Accessing class members/
│	  ├── 4.4 Defining member functions/
│	  │   ├──	4.4.1 Member function inside the class body/
│	  │   └──	4.4.2 Member function outside the class body/
│	  ├── 4.5 “this” pointer/
│	  ├── 4.6 Constructor & destructor/
│	  ├── 4.7 Types of constructor/
│	  │	  ├──4.7.1 Default constructor/
│	  │	  ├──4.7.2 Parameterized constructor/ 
│	  │	  └──4.7.3 Copy constructor/
│	  ├── 4.8 Overloaded constructors/
│	  ├── 4.9 Static data member/ 
│	  ├── 4.10 Static member functions/
│	  ├── 4.11 Passing objects as arguments/
│	  ├── 4.12 Friend functions/
│	  └── 4.13 Friend classes/
├── 05-Operator overloading/
│	├── 5.1 Introduction to operator overloading/
│	├── 5.2 General rules for overloading operator/
│	├── 5.3 Operator overloading restrictions/
│	├── 5.4 Overloading unary and binary operators/
│	├── 5.5 Operator overloading using friend functions/
│	└── 5.6 Data conversion/
│	    ├── 5.6.1 Conversion between basic types and object/
│	    ├── 5.6.2 Conversion between object and basic types/
│	    └── 5.6.3 Conversion between objects of different classes/
├── 06-Virtual functions and Polymorphism/
│    ├── 6.1 Introduction/
│	 ├── 6.2 Early vs late binding/
│	 ├── 6.3 Virtual functions/
│	 ├── 6.4 Pure virtual functions/
│	 ├── 6.5 Abstract classes/
│	 └── 6.6 Virtual base classes/
├── 07-Inheritance/
│    ├── 7.1 Introduction & benefits of inheritance/
│	 ├── 7.2 Types of inheritance/
│	 ├── 7.3 Inheritance: base classes & derived classes/
│	 ├── 7.4 Using constructors and destructors in derived classes/
│	 ├── 7.5 Abstract base class/
│	 ├── 7.6 Public, private and protected inheritance/
│    ├── 7.7 Structural Crisis/
│    │   ├── 7.7.1 Multipath Ambiguity/
│    │   └── 7.7.2 Diamond Problem/
│    │       ├── 7.7.2.1 Virtual Inheritance, Virtual Base Classes & Scope Resolution/
│    │       ├── 7.7.2.2 Method Overriding/
│    │       └── 7.7.2.3 Abstract Base Classes/
│    └── 7.8 Containership 
│        ├── 7.8.1 Constructors Build Up
│        └── 7.8.2 Destructors Tear Down
├── 08-Templates/
│
│
│
│
│
│
│
│
│



```

---

## About

Curriculum reference: Purbanchal University, Gothgaun, Nepal.
Maintained by [Pawan KC](https://github.com/kcpawan).


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
	2.1 Introduction to programming in C++<br />
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
	
