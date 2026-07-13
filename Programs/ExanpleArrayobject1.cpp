#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolder;
    double balance;
    static int totalAccounts;  // Static member to track total accounts

public:
    BankAccount() {
        accountNumber = "0000";
        accountHolder = "Unknown";
        balance = 0.0;
        totalAccounts++;
    }

    BankAccount(string accNo, string holder, double bal) {
        accountNumber = accNo;
        accountHolder = holder;
        balance = bal;
        totalAccounts++;
    }

    ~BankAccount() {
        totalAccounts--;
    }

    void deposit(double amount) {
        if(amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        }
    }

    bool withdraw(double amount) {
        if(amount > 0 && balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
            return true;
        }
        cout << "Insufficient balance!" << endl;
        return false;
    }

    void display() const {
        cout << "Account: " << accountNumber 
             << ", Holder: " << accountHolder 
             << ", Balance: $" << balance << endl;
    }

    double getBalance() const { return balance; }
    
    static int getTotalAccounts() { return totalAccounts; }
};

// Initialize static member
int BankAccount::totalAccounts = 0;

int main() {
    // Create array of 5 bank accounts
    const int MAX_ACCOUNTS = 5;
    BankAccount accounts[MAX_ACCOUNTS] = {
        BankAccount("ACC001", "John Doe", 1000.0),
        BankAccount("ACC002", "Jane Smith", 2500.0),
        BankAccount("ACC003", "Bob Johnson", 500.0)
    };

    // Display all accounts
    cout << "All Accounts:" << endl;
    for(int i = 0; i < MAX_ACCOUNTS; i++) {
        accounts[i].display();
    }

    cout << "\nTotal accounts created: " << BankAccount::getTotalAccounts() << endl;

    // Perform operations on specific account
    cout << "\nPerforming operations on account 2:" << endl;
    accounts[1].deposit(500.0);
    accounts[1].withdraw(300.0);
    accounts[1].display();

    // Find account with highest balance
    int maxIndex = 0;
    for(int i = 1; i < MAX_ACCOUNTS; i++) {
        if(accounts[i].getBalance() > accounts[maxIndex].getBalance()) {
            maxIndex = i;
        }
    }
    
    cout << "\nAccount with highest balance:" << endl;
    accounts[maxIndex].display();

    return 0;
}