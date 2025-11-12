#include <iostream>
#include <string>
#include <limits>
using namespace std;

class ATM {
private:
    string username;
    int pin;
    double balance;

public:
    // Constructor
    ATM(string name, int pinCode, double initialBalance) {
        username = name;
        pin = pinCode;
        balance = initialBalance;
    }

    // PIN verification
    bool login(int enteredPin) {
        if (enteredPin == pin) {
            cout << "\n✅ Login successful! Welcome, " << username << "." << endl;
            return true;
        } else {
            cout << "\n❌ Incorrect PIN. Try again.\n";
            return false;
        }
    }

    // Check balance
    void checkBalance() {
        cout << "\n💰 Your current balance is: ₹" << balance << endl;
    }

    // Deposit money
    void depositMoney(double amount) {
        if (amount <= 0) {
            cout << "\n⚠️ Invalid deposit amount.\n";
            return;
        }
        balance += amount;
        cout << "\n✅ Successfully deposited ₹" << amount << endl;
        checkBalance();
    }

    // Withdraw money
    void withdrawMoney(double amount) {
        if (amount <= 0) {
            cout << "\n⚠️ Invalid withdrawal amount.\n";
            return;
        }
        if (amount > balance) {
            cout << "\n❌ Insufficient balance!\n";
            return;
        }
        balance -= amount;
        cout << "\n✅ Successfully withdrawn ₹" << amount << endl;
        checkBalance();
    }
};

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    string name;
    int pin;
    double initialBalance;

    cout << "=====================================\n";
    cout << "       🏧 Welcome to ATM System       \n";
    cout << "=====================================\n";
    cout << "\nCreate your account to begin.\n";

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Set a 4-digit PIN: ";
    while (!(cin >> pin) || pin < 1000 || pin > 9999) {
        cout << "⚠️ Please enter a valid 4-digit PIN: ";
        clearInput();
    }

    cout << "Enter initial deposit amount: ₹";
    while (!(cin >> initialBalance) || initialBalance < 0) {
        cout << "⚠️ Enter a valid amount: ₹";
        clearInput();
    }

    ATM user(name, pin, initialBalance);

    cout << "\nInsert your card (enter your PIN to continue): ";
    int enteredPin;
    cin >> enteredPin;

    if (!user.login(enteredPin)) {
        cout << "Access denied. Exiting program...\n";
        return 0;
    }

    int choice;
    do {
        cout << "\n=====================================\n";
        cout << "              ATM Menu               \n";
        cout << "=====================================\n";
        cout << "1. 💰 Check Balance\n";
        cout << "2. 💵 Deposit Money\n";
        cout << "3. 💸 Withdraw Money\n";
        cout << "4. ❎ Exit\n";
        cout << "-------------------------------------\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
        case 1:
            user.checkBalance();
            break;
        case 2: {
            double amount;
            cout << "Enter amount to deposit: ₹";
            cin >> amount;
            user.depositMoney(amount);
            break;
        }
        case 3: {
            double amount;
            cout << "Enter amount to withdraw: ₹";
            cin >> amount;
            user.withdrawMoney(amount);
            break;
        }
        case 4:
            cout << "\n🙏 Thank you for using our ATM, " << name << "!\n";
            cout << "Have a great day! 🌟\n";
            break;
        default:
            cout << "\n⚠️ Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    cout << "=====================================\n";
    cout << "         ATM Session Ended           \n";
    cout << "=====================================\n";

    return 0;
}
