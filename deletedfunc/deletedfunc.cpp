#include <iostream>


class T {
    int _arg1;
    int _arg2;
public:
    explicit T(int arg1, int arg2) : _arg1(arg1), _arg2(arg2) { 
        std::cout<<"Function created: "<<arg1 <<", "<<arg2<<std::endl;
    }
    T() = delete; //Remove default constructor. Assigning T x; will throw an error 
    void* operator new(std::size_t) = delete; //Cannot dynamically allocate memory for this class
};

void testDeletedFunc() {
    //T x; // This throws an error --> use of deleted functions
    T y(10, 11);
    //T *x = new T(10, 100); //Throws error --> use of deleted functions
}

int main() {
    testDeletedFunc();
    std::cout<<"Test deleted functions"<<std::endl;
}