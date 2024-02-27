#include <iostream>
using namespace std;

class computation {
public:

    int compute(int a, int b) {   return a + b; }
    float compute(int a, float b) { return a + b; }
    double compute(int a, double b) { return a + b; }
    int compute(char a, char b) { return int(a) + int(b); }
    int compute(char a, int b) { return int(a) + b; }
    int compute() { return 0; }
};

int main() {
    computation obj;
    
    cout << "1) 1 + 2 = " << obj.compute(1, 2) << endl;
    cout << "2) 1 + 2.5 = " << obj.compute(1, 2.5f) << endl;
    cout << "3) 1 + 2.5 = " << obj.compute(1, 2.5) << endl;
    cout << "4) ASCII value of 'a' + ASCII value of 'b' = " << obj.compute('a', 'b') << endl;
    cout << "5) ASCII value of 'a' + 10 = " << obj.compute('a', 10) << endl;
    cout << "6) Result when no values provided = " << obj.compute() << endl;

    return 0;
}