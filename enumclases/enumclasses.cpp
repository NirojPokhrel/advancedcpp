#include <iostream>


enum A {a, b, c, d};
//int a; //Throws error in C++ --> ‘int a’ redeclared as different kind of symbol

enum class B { e, f, g, h};
int e; //Compiles fine

int main() {
    A x;
    x = a;
    int m = b; //Compiles fine automatically stored as integer

    B y;
    y = B::e;
    //int n = B::f; //Throws an error in C++ --> error: cannot convert ‘B’ to ‘int’ in initialization

    std::cout<<"Testing enum classes"<<std::endl;
}