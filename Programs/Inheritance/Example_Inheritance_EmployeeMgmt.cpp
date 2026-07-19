// ═══════════════════════════════════════════════════════════
// EMPLOYEE MANAGEMENT SYSTEM
// Demonstrates: complete visibility matrix in C++
//   - class-level: public / protected / private members
//   - inheritance-level: public / protected / private inherit
// ═══════════════════════════════════════════════════════════
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ───────────────────────────────────────────────────────────
// LEVEL 1 — BASE CLASS : Person
//   public    → accessible everywhere
//   protected → accessible in this class + all derived
//   private   → accessible ONLY in this class, NEVER derived
// ───────────────────────────────────────────────────────────
class Person {
  private:
    // PRIVATE: only Person's own methods can touch these
    string nationalId;    // tax/NID — never expose directly
    float  calcTax(float income) const {
        return income * 0.15f;  // 15% flat — internal logic only
    }

  protected:
    // PROTECTED: Employee and Manager can read/write directly
    string name;
    int    age;
    string address;
    string phone;

  public:
    // PUBLIC: anyone can call these
    Person(string n, int a, string addr,
           string ph, string nid)
        : name(n), age(a), address(addr),
          phone(ph), nationalId(nid) {}

    virtual void display() const {
        cout << "\n====== Person Record ======\n"
             << "Name    : " << name    << "\n"
             << "Age     : " << age     << "\n"
             << "Address : " << address << "\n"
             << "Phone   : " << phone   << "\n";
        // NID never printed — private, hidden from everyone
    }

    string getName()    const { return name; }
    int    getAge()     const { return age; }

    virtual ~Person() {}
};

// ───────────────────────────────────────────────────────────
// LEVEL 2A — Employee : public Person
//
// INHERITANCE MODE: public
//   Person::public   → remains public   in Employee
//   Person::protected → remains protected in Employee
//   Person::private  → INACCESSIBLE (calcTax, nationalId)
// ───────────────────────────────────────────────────────────
class Employee : public Person {
  private:
    float  grossSalary;   // not exposed directly
    string bankAccount;   // sensitive — private

  protected:
    // protected: Manager can access these directly
    int    empId;
    string department;
    string designation;
    float  salary;

  public:
    Employee(string n, int a, string addr,
             string ph, string nid,
             int id, string dept,
             string desig, float sal)
        : Person(n, a, addr, ph, nid),  // chain to Person
          empId(id), department(dept),
          designation(desig), salary(sal),
          grossSalary(sal * 1.2f),
          bankAccount("NIC-****" + to_string(id)) {}

    void display() const override {
        Person::display();                      // reuse base output
        cout << "------ Employee --------\n"
             << "Emp ID  : " << empId       << "\n"
             << "Dept    : " << department  << "\n"
             << "Desig   : " << designation << "\n"
             << "Salary  : Rs." << fixed
             << setprecision(0) << salary      << "\n";
        // bankAccount NOT printed — private
    }

    void generatePayslip() const {
        cout << "\n--- Payslip: " << name << " ---\n"  // name is protected
             << "Basic   : Rs." << salary << "\n"
             << "Gross   : Rs." << grossSalary << "\n";
    }

    float  getSalary()  const { return salary; }
    int    getEmpId()   const { return empId; }
    string getDept()    const { return department; }

    virtual ~Employee() {}
};

// ───────────────────────────────────────────────────────────
// LEVEL 3 — Manager : public Employee
//
// INHERITANCE MODE: public (again)
//   Employee::public   → public   in Manager
//   Employee::protected → protected in Manager
//   Employee::private  → INACCESSIBLE (grossSalary, bankAccount)
//   Person members flow through Employee unchanged
// ───────────────────────────────────────────────────────────
class Manager : public Employee {
  private:
    int   teamSize;
    float annualBudget;
    string reportingTo;

  public:
    Manager(string n, int a, string addr,
            string ph, string nid,
            int id, string dept,
            string desig, float sal,
            int team, float budget, string rpt)
        : Employee(n, a, addr, ph, nid, id, dept, desig, sal),
          teamSize(team), annualBudget(budget), reportingTo(rpt) {}

    void display() const override {
        Employee::display();
        cout << "------ Manager ---------\n"
             << "Team    : " << teamSize    << " members\n"
             << "Budget  : Rs." << annualBudget << "\n"
             << "Reports : " << reportingTo << "\n";
    }

    void approveLeave(string who) {
        // 'name' and 'empId' reachable — protected through two levels
        cout << name << " (ID:" << empId
             << ") approved leave for: " << who << "\n";
    }

    void hike(float pct) {
        // 'salary' is protected in Employee, reachable here
        salary += salary * pct / 100;
        cout << "Salary after hike: Rs." << salary << "\n";
    }

    ~Manager() {}
};

// ───────────────────────────────────────────────────────────
// LEVEL 2B — Contractor : private Employee
//
// INHERITANCE MODE: private  ← KEY DIFFERENCE
//   Employee::public    → PRIVATE in Contractor
//   Employee::protected → PRIVATE in Contractor
//   Everything from Employee is locked inside Contractor
//   Outside code CANNOT call display() via Contractor object
//   Further derived classes get NOTHING from Employee/Person
// ───────────────────────────────────────────────────────────
class Contractor : private Employee {
  private:
    float  dailyRate;
    int    contractDays;
    string agencyName;

  public:
    Contractor(string n, int a, string addr,
               string ph, string nid,
               int id, string dept, float rate,
               int days, string agency)
        : Employee(n, a, addr, ph, nid,
                   id, dept, "Contractor", rate * days),
          dailyRate(rate), contractDays(days), agencyName(agency) {}

    // Must explicitly re-expose what outside code needs
    void display() const {         // NOT override — private inheritance
        cout << "\n====== Contractor ======\n";
        Employee::display();         // can call internally — we are derived
        cout << "------ Contract --------\n"
             << "Daily   : Rs." << dailyRate    << "\n"
             << "Days    : "   << contractDays << "\n"
             << "Agency  : "   << agencyName   << "\n"
             << "Total   : Rs." << dailyRate * contractDays << "\n";
    }

    // Selectively expose what is needed (using declaration)
    using Employee::getName;       // re-expose ONE method publicly
    using Employee::getEmpId;

    ~Contractor() {}
};

// ───────────────────────────────────────────────────────────
// MAIN — shows what is and is NOT accessible
// ───────────────────────────────────────────────────────────
int main() {
    Manager mgr("Dr. Dipesh Bhandari", 38, "Kathmandu",
                "9801234567", "NID-001",
                2001, "IT", "HOD", 120000,
                12, 500000, "Dean");

    Employee emp("Sriju Basnet", 32, "Lalitpur",
                 "9807654321", "NID-002",
                 1001, "CS", "Lecturer", 75000);

    Contractor con("Kapil Puri", 28, "Bhaktapur",
                   "9809999999", "NID-003",
                   3001, "IT", 5000, 90, "TechNepal Ltd");

    // ── Polymorphism: Person* holds Manager and Employee ──────
    Person* roster[2] = {&mgr, &emp};
    for(int i = 0; i < 2; i++) roster[i]->display();

    // ── Manager-specific operations ───────────────────────────
    mgr.approveLeave("Sriju Basnet");
    mgr.hike(10);

    // ── Employee payslip ──────────────────────────────────────
    emp.generatePayslip();

    // ── Contractor — private inheritance in action ────────────
    con.display();               // Contractor's own display()
    cout << con.getName() << "\n"; // OK — re-exposed with 'using'
    // con.getSalary();          // ERROR: private inheritance
    // con.department;           // ERROR: private inheritance

    // ── Direct member access attempts ─────────────────────────
    // mgr.name = "X";           // ERROR: protected, not public
    // mgr.calcTax(1000);        // ERROR: private in Person
    // mgr.bankAccount = "X";    // ERROR: private in Employee
    cout << mgr.getName() << "\n"; // OK: public getter
    cout << mgr.getSalary() << "\n";// OK: public getter

    return 0;
}