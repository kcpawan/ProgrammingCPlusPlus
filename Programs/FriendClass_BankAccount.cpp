#include <iostream>
using namespace std;

class Account {
private:
    double balance;
    string accountNumber;
    
public:
    Account(string accNo, double bal) : accountNumber(accNo), balance(bal) {}
    
    // Declare Manager as friend class
    friend class Manager;
};

class Manager {
public:
    void displayAccount(const Account& acc) {
        // Accessing private members directly
        cout << "Account: " << acc.accountNumber << endl;
        cout << "Balance: $" << acc.balance << endl;
    }
    
    void updateBalance(Account& acc, double amount) {
        acc.balance += amount;
        cout << "Balance updated to $" << acc.balance << endl;
    }
    
    void transfer(Account& from, Account& to, double amount) {
        if (from.balance >= amount) {
            from.balance -= amount;
            to.balance += amount;
            cout << "Transferred $" << amount << " successfully" << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }
};

int main() {
    Account acc1("A001", 1000.0);
    Account acc2("A002", 500.0);
    
    Manager manager;
    
    cout << "Initial Accounts:" << endl;
    manager.displayAccount(acc1);
    manager.displayAccount(acc2);
    
    cout << "\nTransferring $300 from A001 to A002:" << endl;
    manager.transfer(acc1, acc2, 300);
    
    cout << "\nUpdated Accounts:" << endl;
    manager.displayAccount(acc1);
    manager.displayAccount(acc2);
    
    return 0;
}