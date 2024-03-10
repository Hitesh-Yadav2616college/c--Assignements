/* #include<iostream>
#include<cstring>
using namespace std;
class sample {
public:
 char *name;
 sample() { }
 sample(char *str, int length) {
 name = new char[length+1];
 strcpy(name,str);
 }
};
int main(int argc, char *argv[]) {
 sample user1((char *)"chitkara",8);
 sample user2 = user1;
 strcpy(user2.name,"dummy");
 cout<<user2.name<<user1.name<<endl;
 return 0;
} */

// In this example shallow copy is followed.
/* The issue with this code is that it leads to a dangling pointer problem. When user2 is assigned the value of user1,
 it simply copies the pointer name, resulting in two objects (user1 and user2) sharing the same dynamically allocated memory
for the name variable. When strcpy(user2.name, "dummy") is executed, it modifies the content of the shared memory,
 affecting both user1 and user2. */

#include<iostream>
#include<cstring>
using namespace std;

class sample {
public:
    char *name;
    sample() { }
    sample(const char *str, int length) {
        name = new char[length + 1];
        strcpy(name, str);
    }
    // Copy constructor for deep copy
    sample(const sample &other) {
        int length = strlen(other.name);
        name = new char[length + 1];
        strcpy(name, other.name);
    }
};

int main(int argc, char *argv[]) {
    sample user1("chitkara", 8);
    sample user2 = user1; // Deep copy performed here

    // Modify user2's name
    strcpy(user2.name, "dummy");

    // Print names
    cout << "user2.name: " << user2.name << endl;
    cout << "user1.name: " << user1.name << endl;

    return 0;
}