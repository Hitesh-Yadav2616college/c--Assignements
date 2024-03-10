#include<iostream>
using namespace std;

class sample {
public:
    int Compute(int (sample::*func)(int), int n) {
        return (this->*func)(n);
    }

    int findFactorial(int n) {
        int fact = 1;
        for (int i = 1; i <= n; i++) {
            fact *= i;
        }
        return fact;
    }

    int findSquare(int n) {
        return n * n;
    }

    int findCube(int n) {
        return n * n * n;
    }
};

int main(int argc, char* argv[]) {
    sample obj;
    int n = 0;

    if (argc > 1) {
        n = atoi(argv[1]); // Convert command line argument to integer
    } else {
        cout << "Enter a value for N: ";
        cin >> n;
    }

    int factorial = obj.Compute(&sample::findFactorial, n);
    cout << "Factorial of " << n << " is: " << factorial << endl;

    int square = obj.Compute(&sample::findSquare, n);
    cout << "Square of " << n << " is: " << square << endl;

    int cube = obj.Compute(&sample::findCube, n);
    cout << "Cube of " << n << " is: " << cube << endl;

    return 0;
}