#include <iostream>
#include <vector>

class T{
    int *_buff;
    int _size;

    void reset() {
        _buff = nullptr;
        _size = 0;
    }
public:
    explicit T(int size) {
        std::cout<<"Constructor"<<std::endl;
        _size = size;
        _buff = new int[size];
        for(int i=0; i<size; i++ ) {
            _buff[i] = i;
        }
    }
    T () = delete;
    T( T&& rhs ) noexcept {
        std::cout<<"Move constructor"<<std::endl;
        _buff = rhs._buff;
        _size = rhs._size;
        rhs.reset();
    }

    T& operator=( T&& rhs) noexcept {
        std::cout<<"Move Assignment"<<std::endl;
        if( this != &rhs ) {
            _buff = rhs._buff;
            _size = rhs._size;
            rhs.reset();
        }

        return *this;
    }

    int getSize() const {
        return _size;
    }

    int* getBuff() const {
        return _buff;
    }

    bool checkEquality() const {
        for(int i=0; i<_size; i++ ) {
            if(_buff[i] != i ) {
                return false;
            }
        }
        return true;
    }

    ~T() {
        std::cout<<"Destructor"<<std::endl;
        if(_size) {
            delete _buff;
            _size = 0;
            _buff = nullptr;
        }
    }
};

void printVector(std::string name, std::vector<int> v) {
    std::cout<<name<<" : ";
    for(auto i: v) {
        std::cout<<i<<", ";
    }
    std::cout<<std::endl;
}

void copyingVsMoving() {
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::vector<int> v2;
    
    v2 = v1; // Data of v1 is copied to v2 and both will contain same data
    printVector("V1", v1);
    printVector("V2", v2);
    std::cout<<"After Move Semantics"<<std::endl;
    v2 = std::move(v1); // v1 will be empty and v2 will contain v1 data
    printVector("V1", v1);
    printVector("V2", v2);
}

void testMoveSemantics() {
    T t(10000);
    T x = std::move(t);
    std::cout<<t.getSize()<<" "<<x.getSize()<<std::endl;
    std::cout<<(x.checkEquality()?"Equal":"Not Equal")<<std::endl;
}

int main() {
    //copyingVsMoving();
    testMoveSemantics();
    return 0;
}