/*Assume that you have two objects OBJ1 and OBJ2 and both of these objects hold a 3X3 matrix. I wish to calculate sum of these matrixes using the following statement.

OBJ3 = OBJ1 + OBJ3.  //The sum of matrix must be returned to OBJ3 matrix*/

#include<iostream>

using namespace std;

class Work {
    private:
    int mat[3][3];

    public:
    Work() {
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                mat[i][j] = 0;
            }
        }
    }
    void set(int nMat[3][3]) {
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                mat[i][j] = nMat[i][j];
            }
        }
    }
    Work operator+ (Work& obj) {
        Work res;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                res.mat[i][j] = this->mat[i][j] + obj.mat[i][j];
            }
        }
        return res;
    }
    void show() {
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int mat1[3][3] = {{0 ,2, 3}, {1,4,5}, {7,8,9}};
    int mat2[3][3] = {{0 ,2, 3}, {1,4,5}, {7,8,9}};
    Work obj1, obj2;
    obj1.set(mat1);
    obj2.set(mat2);

    Work obj3 = obj1 + obj2;
    obj3.show();
    return 0;
}