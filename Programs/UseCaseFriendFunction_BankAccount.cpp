#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string holderName;
    double balance;
    
public:
    BankAccount(string accNo, string name, double bal) 
        : accountNumber(accNo), holderName(name), balance(bal) {}
    
    // Friend function to transfer money between accounts
    friend void transferMoney(BankAccount& from, BankAccount& to, double amount);
    
    // Friend function to display account details (with privacy check)
    friend void displayAccount(const BankAccount& account);
};

// Friend function implementation
void transferMoney(BankAccount& from, BankAccount& to, double amount) {
    if (from.balance >= amount && amount > 0) {
        from.balance -= amount;
        to.balance += amount;
        cout << "Transferred $" << amount << " from " 
             << from.holderName << " to " << to.holderName << endl;
    } else {
        cout << "Transfer failed! Insufficient balance or invalid amount." << endl;
    }
}

void displayAccount(const BankAccount& account) {
    cout << "Account: " << account.accountNumber << endl;
    cout << "Holder: " << account.holderName << endl;
    cout << "Balance: $" << account.balance << endl;
    cout << "------------------------" << endl;
}

int main() {
    BankAccount acc1("A001", "John Doe", 1000);
    BankAccount acc2("A002", "Jane Smith", 500);
    
    cout << "Initial Accounts:" << endl;
    displayAccount(acc1);
    displayAccount(acc2);
    
    transferMoney(acc1, acc2, 300);
    
    cout << "\nAfter Transfer:" << endl;
    displayAccount(acc1);
    displayAccount(acc2);
    
    transferMoney(acc1, acc2, 1000);  // Insufficient balance
    
    return 0;
}