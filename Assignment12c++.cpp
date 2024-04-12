/*You are suppose to create two classes, class smallUnit and class largerUnit. smallUnit class will hold measurement in inches. I wish to convert inches to feets using a type conversion. Write a code in

such a way so that I can write something like

largerUnit_OBJ = smallUnit_OBJ; //both objects are of different classes.

later on when I write largerUnit.display() I should be also to see the measurement in inches*/

#include<iostream>
using namespace std;

class SmallUnit {
private:
float inches;
public:
SmallUnit() {}
SmallUnit(int a) {
    inches = a;
}
float getInches() {
    return inches;
    }
    void show() {
        cout << "Inches: " << inches << endl;
    }
};
class LargeUnit {
private:
float feets;
public:
LargeUnit() {}
LargeUnit(SmallUnit obj) { 
    int x; 
    x = obj.getInches();
    feets = x/12.0;
    }
    void show() {
        cout << "In feets: " << feets << endl;
    }
};
int main() {
    SmallUnit obj1(34.5);
    LargeUnit obj2;

    obj2 = obj1;

    obj1.show();  //in inches

    obj2.show();  //in feets
    return 0;
}