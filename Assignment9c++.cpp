#include <iostream>
using namespace std;

class Solution {
private:
    int x;

public:
    Solution(int num1) : x(num1) {}

    int friend operator+(int a, Solution p);

    void display() {
        cout << x;
    }
};

int operator+(int a, Solution p) {
  return a + p.x;
}

int main() {
    Solution p1(5);
    Solution p2 = 5 + p1;

    p2.display();
    cout << endl;

    return 0;
}