#include <iostream>
#include <map>
#include <string>

using namespace std;

class BankAccount {
private:
    string password;
    double balance;

public:
    BankAccount() : password(""), balance(0.0) {}

    BankAccount(const string& pass, double bal) : password(pass), balance(bal) {}

    string getPassword() const {
        return password;
    }

    double getBalance() const {
        return balance;
    }

    void setPassword(const string& pass) {
        password = pass;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        balance -= amount;
    }
};

class ATM {
private:
    map<string, BankAccount> accounts;

public:
    void printIntroMenu() {
        cout << "Please select an option from the menu below:\n"
             << "l -> Login\n"
             << "c -> Create New Account\n"
             << "q -> Quit\n"
             << "> ";
    }

    void printMainMenu() {
        cout << "d -> Deposit Money\n"
             << "w -> Withdraw Money\n"
             << "r -> Request Balance\n"
             << "q -> Quit\n"
             << "> ";
    }

    void start() {
        char choice;
        do {
            cout << "Hi! Welcome to Mr. Zamar’s ATM Machine!\n";
            printIntroMenu();
            cin >> choice;
            switch(choice) {
                case 'l':
                    login();
                    break;
                case 'c':
                    createAccount();
                    break;
                case 'q':
                    cout << "Thanks for stopping by!\n";
                    exit(0);
                default:
                    cout << "Invalid option. Please try again.\n";
            }
        } while(choice != 'q');
    }

    void login() {
        char choice;
        double money;
        string userId, password;
        cout << "Please enter your user id: ";
        cin >> userId;
        cout << "Please enter your password: ";
        cin >> password;

        if(accounts.find(userId) != accounts.end() && accounts[userId].getPassword() == password) {
            cout << "Access Granted!\n";
            BankAccount& acc = accounts[userId];
            do {
                printMainMenu();
                cin >> choice;
                switch(choice) {
                    case 'd':
                        cout << "Amount of deposit: $";
                        cin >> money;
                        acc.deposit(money);
                        cout << "Amount deposited!\n";
                        break;
                    case 'w':
                        cout << "Amount of withdrawal: $";
                        cin >> money;
                        acc.withdraw(money);
                        break;
                    case 'r':
                        cout << "\nYour balance: $" << acc.getBalance() << endl;
                        break;
                    default:
                        cout << "Enter valid option!\n";
                }
            } while(choice != 'q');
        } else {
            cout << "*** LOGIN FAILED! ***\n";
        }
    }

    void createAccount() {
        string userId, password;
        cout << "Please enter your user id: ";
        cin >> userId;
        cout << "Please enter your password: ";
        cin >> password;

        // Check if the user id already exists
        if(accounts.find(userId) == accounts.end()) {
            BankAccount newAccount(password, 0.0);
            accounts[userId] = newAccount;
            cout << "Thank You! Your account has been created!\n";
        } else {
            cout << "User ID already exists. Please try again with a different ID.\n";
        }
    }
};

int main() {
    ATM atm;
    atm.start();
    return 0;
}