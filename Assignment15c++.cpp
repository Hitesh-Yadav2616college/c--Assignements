/*Propose a solution by which private members of two different classes can be assesed and their sum can be provided.*/

#include <iostream>

class ClassB;

class ClassA {
private:
    int privateMemberA;

public:
    ClassA(int a) : privateMemberA(a) {}

    friend int sum(ClassA a, ClassB b);
};

class ClassB {
private:
    int privateMemberB;

public:
    ClassB(int b) : privateMemberB(b) {}

    friend int sum(ClassA a, ClassB b);
};

int sum(ClassA a, ClassB b) {
    return a.privateMemberA + b.privateMemberB;
}

int main() {
    ClassA objA(5);
    ClassB objB(10);

    std::cout << "Sum of private members: " << sum(objA, objB) << std::endl;

    return 0;
}