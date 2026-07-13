#include <iostream>
#include <string>
class BankAccount {
private:
    double balance; // Private to prevent direct modification
    std::string accountNumber;

public:
    BankAccount(std::string accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {}

    // Public interface to access/modify private members
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited: " << amount << ", New balance: " << balance << std::endl;
        } else {
            std::cout << "Invalid deposit amount" << std::endl;
        }
    }

    double getBalance() const { // const ensures method doesn't modify object
        return balance;
    }
};

int main() {
    BankAccount acc("12345", 1000.0);
    acc.deposit(500.0); // Works: uses public method
     acc.balance = 2000; // Error: balance is private
    std::cout << "Current balance: " << acc.getBalance() << std::endl;
    return 0;
}