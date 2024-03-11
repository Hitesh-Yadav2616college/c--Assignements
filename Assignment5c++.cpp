#include <iostream>
#include <string>

using namespace std;

class User {
private:
    string name;
    int birth_year;
    int birth_day;
    int birth_month;
    double salary;

public:
    // Constructor
    User(string _name, int _birth_year, int _birth_day, int _birth_month, double _salary) :
        name(_name), birth_year(_birth_year), birth_day(_birth_day), birth_month(_birth_month), salary(_salary) {}

    // Comparison operator ==
    int operator==(const User& ref) {
        if (this->birth_year < ref.birth_year) return -1;
        else if (this->birth_year > ref.birth_year) return 1;
        else {
            if (this->birth_month < ref.birth_month) return -1;
            else if (this->birth_month > ref.birth_month) return 1;
            else {
                if (this->birth_day < ref.birth_day) return -1;
                else if (this->birth_day > ref.birth_day) return 1;
                else
                    return 0;
            }
        }
    }

    // Addition operator +
    double operator+(const User& ref) {
        return (this->salary + ref.salary) / 2;
    }

    // Add percentage increment
    void operator+(int increment_percentage) {
        double increment_factor = (double)increment_percentage / 100.0;
        this->salary += this->salary * increment_factor;
    }

    // Display user details
    void displayDetails() {
        cout << "Name: " << name << endl << "Birth Year: " << birth_year << endl << "Birth Month: " << birth_month << endl
         << "Birth Day: " << birth_day << endl << "Salary: " << salary << endl;
    }
};

int main() {
    User user1("Hitesh", 1990, 15, 5, 50000);
    User user2("Rohan", 1995, 20, 10, 60000);

    int result = user1 == user2;
    cout << "Comparison Result: " << result << endl;

    double average_sal = user1 + user2;
    cout << "Average Salary: " << average_sal << endl;

    user1 + 5; // Adding 5% increment in user1's salary
    user2 + 10; // Adding 10% increment in user2's salary

    cout << "\nUser 1 Details:\n";
    user1.displayDetails();

    cout << "\nUser 2 Details:\n";
    user2.displayDetails();

    return 0;
}