#include <iostream>

namespace smartpointers {
    class SPointer {
        int mPointerID;
    public:
        explicit SPointer(int _id) : mPointerID(_id) {
            std::cout<<"Ctor : "<<mPointerID<<std::endl;
        }
        ~SPointer() {
            std::cout<<"Dtor : "<<mPointerID<<std::endl;
        }
    };
}

int main() {
    return 0;
}