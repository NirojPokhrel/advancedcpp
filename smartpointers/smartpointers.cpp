#include <iostream>
#include <memory>

namespace smartpointers {
    
    /**
     * SPointer is a testing class which stores the id of an instance of the object being created. The constructor and destructor prints the id when creating 
     * or destroying an object.
     **/
    class SPointer {
        int mPointerID;
    public:
        explicit SPointer(int _id) : mPointerID(_id) {
            std::cout<<"Constructor : "<<mPointerID<<std::endl;
        }
        ~SPointer() {
            std::cout<<"Destructor : "<<mPointerID<<std::endl;
        }
        int getPointerID() const { return mPointerID; }
        void setPointerID( int _id) { mPointerID = _id; }
    };

    void testUniquePtr() {
        std::cout<<"Entering unique ptr."<<std::endl;
        // Can create a pointer with a new semantics
        std::unique_ptr<SPointer> a(new SPointer(1));
        // Unique pointer can also be created with make_unique but it can be done only with c++14 
        auto b = std::make_unique<SPointer>(2);
        // A reset will call a destructor and calls a constructor again
        a.reset(new SPointer(3));
        // Move will move pointer b to pointer c
        std::cout<<"A pointer should be released."<<std::endl;
        auto c = std::move(b);
        std::cout<<"Leaving unique Ptr."<<std::endl;
    }

    void testSharedPtr() {
        std::cout<<"Entering shared ptr."<<std::endl;
        // Can create a shared pointer using make_shared with c++11
        auto a = std::make_shared<SPointer>(1);
        auto b = a;
        // use_count gives the number of times the pointer is accessed
        std::cout<<"Use count : "<<a.use_count()<<std::endl;;
        std::shared_ptr<SPointer>  c(new SPointer(2));
        std::cout<<"Leaving shared ptr."<<std::endl;
    }

    void testWeakPtr() {
        std::cout<<"Entering Weak Ptr."<<std::endl;
        auto a = std::make_shared<SPointer>(1);
        auto w = std::weak_ptr<SPointer>(a);
        std::cout<<"Use count : "<<a.use_count()<<std::endl;
        if(auto c = w.lock()) {
            std::cout<<"Access shared pointer now"<<std::endl;
            std::cout<<"Pointer ID : "<<c->getPointerID()<<std::endl;
            std::cout<<"Use Count : "<<c.use_count()<<std::endl;
        }
        std::cout<<"Use Count : "<<a.use_count()<<std::endl;
        std::cout<<"Leaving Weak Ptr."<<std::endl;
    }
}

int main() {
    smartpointers::testUniquePtr();
    smartpointers::testSharedPtr();
    smartpointers::testWeakPtr();

    return 0;
}