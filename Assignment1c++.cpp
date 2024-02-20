#include <iostream>
#include <map>
#include <string>

using namespace std;

// Define a structure for bank account
struct BankAccount {
    string password;
    double balance;
};

// Global map to store user IDs and corresponding bank accounts
map<string, BankAccount> accounts;

// Function prototypes
void printIntroMenu();
void printMainMenu();
void start();
void login();
void createAccount();

int main() {
    start();
    return 0;
}

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

    if(accounts.find(userId) != accounts.end() && accounts[userId].password == password) {
        cout << "Access Granted!\n";
        BankAccount dep;
        do {
            printMainMenu();
        cin >> choice;
        switch(choice) {
            case 'd':
            cout << "Amount of deposit: $";
            cin >> money;
            dep.balance += money;
            cout << "\nAmount deposited!";
            break;

            case 'w':
            cout << "Amount of withdrawl: $";
            cin >> money;
            dep.balance -= money;
            break;

            case 'r':
            cout << "\nYour balance: $" << dep.balance;
            break;

            default : cout << "Enter valid option!";

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
        BankAccount newAccount;
        newAccount.password = password;
        newAccount.balance = 0.0;
        accounts[userId] = newAccount;
        cout << "Thank You! Your account has been created!\n";
    } else {
        cout << "User ID already exists. Please try again with a different ID.\n";
    }
}
