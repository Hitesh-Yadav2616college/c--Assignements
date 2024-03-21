#include<iostream>
using namespace std;

class Sum {
    private:
    int n;
    int sum;
    int temp;
    public:
    void get() {
        cout << "Enter a number: ";
        cin >> n;
    }
    int compute() {
        sum = 0;
        temp = 0;
         for(int i=1; i<=n; i++) {
            sum += i;
            temp += sum;
         }
         return temp;
    }
};

int main() {
    Sum obj;
    obj.get();
    cout << "Sum of the series: " << obj.compute();
}