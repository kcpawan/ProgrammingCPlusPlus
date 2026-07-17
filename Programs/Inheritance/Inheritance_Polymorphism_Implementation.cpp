#include <iostream>
#include <string>
using namespace std;

// ══════════════════════════════════════════════════════════
// LEVEL 1 — BASE CLASS
// ══════════════════════════════════════════════════════════
class Person {
  protected:
    string name;
    int    age;
    string address;
    string phone;

  public:
    Person(string n, int a, string addr, string ph)
        : name(n), age(a), address(addr), phone(ph) {}

    virtual void display() const {
        cout << "=== Person ===\n"
             << "Name   : " << name    << "\n"
             << "Age    : " << age     << "\n"
             << "Address: " << address << "\n"
             << "Phone  : " << phone   << "\n";
    }

    string getName()    const { return name; }
    int    getAge()     const { return age; }

    virtual ~Person() {}
};

// ══════════════════════════════════════════════════════════
// LEVEL 2 — DERIVED FROM PERSON
// ══════════════════════════════════════════════════════════
class Employee : public Person {
  protected:
    int    empId;
    string department;
    float  salary;
    string designation;

  public:
    Employee(string n, int a, string addr, string ph,
             int id, string dept, float sal, string desig)
        : Person(n, a, addr, ph),
          empId(id), department(dept), salary(sal), designation(desig) {}

    void display() const override {
        Person::display();
        cout << "--- Employee ---\n"
             << "Emp ID : " << empId       << "\n"
             << "Dept   : " << department  << "\n"
             << "Desig  : " << designation << "\n"
             << "Salary : Rs." << salary    << "\n";
    }

    float  getSalary() const { return salary; }
    string getDept()   const { return department; }

    virtual ~Employee() {}
};

// ══════════════════════════════════════════════════════════
// LEVEL 3 — DERIVED FROM EMPLOYEE (WHICH DERIVES FROM PERSON)
// ══════════════════════════════════════════════════════════
class Manager : public Employee {
  private:
    int    teamSize;
    float  annualBudget;
    string reportingTo;

  public:
    Manager(string n, int a, string addr, string ph,
            int id, string dept, float sal, string desig,
            int team, float budget, string reportsTo)
        : Employee(n, a, addr, ph, id, dept, sal, desig),
          teamSize(team), annualBudget(budget), reportingTo(reportsTo) {}

    void display() const override {
        Employee::display();
        cout << "--- Manager ---\n"
             << "Team   : "   << teamSize     << " members\n"
             << "Budget : Rs." << annualBudget << "\n"
             << "Reports: "   << reportingTo  << "\n";
    }

    void approveLeave(string empName) {
        cout << name << " approved leave for " << empName << "\n";
    }

    ~Manager() {}
};

// ══════════════════════════════════════════════════════════
// MAIN — demonstrating polymorphism + all features
// ══════════════════════════════════════════════════════════
int main() {
    // Create objects at each level
    Person   p("Ram Bahadur",    45, "Kathmandu", "9800000001");
    Employee e("Sita Kumari",   32, "Lalitpur",  "9800000002",
                1001, "Computer Science", 75000, "Lecturer");
    Manager  m("Dr. Hari Prasad",50, "Bhaktapur", "9800000003",
                2001, "IT", 120000, "HOD",
                12, 500000, "Dean");

    // ── Polymorphism: one pointer, three behaviors ────────────
    Person* people[3] = {&p, &e, &m};

    for (int i = 0; i < 3; i++) {
        people[i]->display();  // runtime picks correct version
        cout << "--------------------\n";
    }

    // Manager-specific method (not in base)
    m.approveLeave("Sita Kumari");

    return 0;
}