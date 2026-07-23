#include <iostream>
#include <string>
using namespace std;

// Base Class with Virtual Inheritance
class Person {
protected:
    string name;
    int personID;
    
public:
    Person() : name("Unknown"), personID(0) {
        cout << "Person constructor called" << endl;
    }
    
    void introduce() {
        cout << "I am " << name << " with ID: " << personID << endl;
    }
    
    void setDetails(string n, int id) {
        name = n;
        personID = id;
    }
};

// Virtual Inheritance from Person
class Teacher : virtual public Person {
//class Teacher : virtual public Person {
protected:
    string staffID;
    string department;
    
public:
    Teacher() : staffID("T000"), department("General") {
        cout << "Teacher constructor called" << endl;
    }
    
    void teach() {
        cout << staffID << " is teaching in " << department << endl;
    }
    
    void setTeacherDetails(string sid, string dept) {
        staffID = sid;
        department = dept;
    }
};

// Virtual Inheritance from Person
class Researcher : virtual public Person {
//class Researcher : virtual public Person {
protected:
    string projectID;
    string researchArea;
    
public:
    Researcher() : projectID("R000"), researchArea("General") {
        cout << "Researcher constructor called" << endl;
    }
    
    void research() {
        cout << projectID << " is researching in " << researchArea << endl;
    }
    
    void setResearcherDetails(string pid, string area) {
        projectID = pid;
        researchArea = area;
    }

    void helloWorld(){
        cout << "Hello World. I am Researcher" << endl;
    }
};

// Professor inherits virtually from both
class Professor : public Teacher, public Researcher {
private:
    string professorID;
    int experience;
    
public:
    Professor() : professorID("P000"), experience(0) {
        cout << "Professor constructor called" << endl;
    }
    
    // NOW RESOLVED: Only one copy of Person
    void displayInfo() {
        introduce(); // Works fine - only ONE Person
        cout << name << endl; // Works fine - only ONE Person
        teach();
        research();
    }
    
    void setProfessorDetails(string pid, int exp) {
        professorID = pid;
        experience = exp;
    }
    
    void setPersonDetails(string n, int id) {
        setDetails(n, id); // Works fine - only ONE Person
    }
};

int main() {
    Professor prof;
    
    // Now works perfectly!
    prof.setTeacherDetails("T123", "Computer Science");
    prof.setResearcherDetails("R456", "AI Research");
    prof.setPersonDetails("Anish Thapa", 1001);
    
    cout << endl;
    cout << "===================== Virtual Class Implementation ================================" << endl;

    prof.displayInfo();
    
    // Memory is optimized!
    // Only ONE copy of Person exists
    cout << "\nMemory is optimized - one Person shared!" << endl;

    cout << "====================================================================================" << endl;

    prof.helloWorld();
    
    return 0;
}