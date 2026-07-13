#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Forward declaration
class PayrollSystem;

class Employee {
private:
    string name;
    int employeeID;
    double salary;
    double bonus;
    int performanceRating;  // 1-5
    
public:
    Employee(string n, int id, double sal) 
        : name(n), employeeID(id), salary(sal), bonus(0), performanceRating(3) {}
    
    // Grant full access to PayrollSystem
    friend class PayrollSystem;
    
    void displayInfo() const {
        cout << "Name: " << name << ", ID: " << employeeID 
             << ", Salary: $" << salary << ", Bonus: $" << bonus << endl;
    }
};

class PayrollSystem {
private:
    vector<Employee> employees;
    double taxRate;
    
public:
    PayrollSystem(double tax = 0.15) : taxRate(tax) {}
    
    void addEmployee(const Employee& emp) {
        employees.push_back(emp);
    }
    
    void calculateSalary(int empID) {
        for (auto& emp : employees) {
            if (emp.employeeID == empID) {
                // Accessing private members directly
                double netSalary = emp.salary - (emp.salary * taxRate) + emp.bonus;
                cout << "Net salary for " << emp.name << ": $" << netSalary << endl;
                break;
            }
        }
    }
    
    void setPerformanceBonus(int empID, int rating) {
        for (auto& emp : employees) {
            if (emp.employeeID == empID) {
                emp.performanceRating = rating;
                // Calculate bonus based on rating (accessing private members)
                if (rating == 5) emp.bonus = emp.salary * 0.20;
                else if (rating == 4) emp.bonus = emp.salary * 0.10;
                else if (rating == 3) emp.bonus = emp.salary * 0.05;
                else emp.bonus = 0;
                
                cout << "Bonus updated for " << emp.name << ": $" << emp.bonus << endl;
                break;
            }
        }
    }
    
    void displayAllEmployees() const {
        cout << "\nAll Employees:" << endl;
        cout << "----------------" << endl;
        for (const auto& emp : employees) {
            emp.displayInfo();
        }
    }
    
    void processPayroll() {
        cout << "\nProcessing Payroll:" << endl;
        cout << "-------------------" << endl;
        for (auto& emp : employees) {
            double net = emp.salary - (emp.salary * taxRate) + emp.bonus;
            cout << emp.name << " (ID: " << emp.employeeID 
                 << "): $" << net << endl;
        }
    }
};

int main() {
    PayrollSystem payroll(0.15);
    
    // Add employees
    payroll.addEmployee(Employee("John Doe", 101, 50000));
    payroll.addEmployee(Employee("Jane Smith", 102, 60000));
    payroll.addEmployee(Employee("Bob Johnson", 103, 45000));
    
    payroll.displayAllEmployees();
    
    // Set performance bonuses
    cout << "\nSetting Bonuses:" << endl;
    cout << "----------------" << endl;
    payroll.setPerformanceBonus(101, 5);  // John gets 20% bonus
    payroll.setPerformanceBonus(102, 4);  // Jane gets 10% bonus
    payroll.setPerformanceBonus(103, 2);  // Bob gets no bonus
    
    // Process payroll
    payroll.processPayroll();
    
    return 0;
}