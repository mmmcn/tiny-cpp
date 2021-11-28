#include<iostream>
#include "smartptr"


void test_shared_ptr() {
    SharedPtr<int> p1(static_cast<int*>(new int(10)));
    SharedPtr<int> p2(p1);
    SharedPtr<int> p3 = p1;
    std::cout << "ref count: " << p1.count() << std::endl;

    SharedPtr<int> pp1(static_cast<int*>(new int(20)));
    p3 = pp1;
    std::cout << "ref count: " << p1.count() << std::endl;
    std::cout << "ref count: " << pp1.count() << std::endl;

    std::cout << *p1 << std::endl;
}


void test_weak_ptr() {

    SharedPtr<int> sp1(static_cast<int*>(new int(100)));
    SharedPtr<int> sp2(static_cast<int*>(new int(200)));

    std::cout << "before the definition of weak_ptr: " << std::endl;
    std::cout << "number of reference for sp1: " << sp1.count() << std::endl;
    std::cout << "number of reference for sp2: " << sp2.count() << std::endl;

    {
        std::cout << "after the definition of weak_ptr: " << std::endl;
        WeakPtr<int> wp1(sp1);       // call copy constructor
        WeakPtr<int> wp2 = sp2;      // call copy constructor
        //SharedPtr<int> sp3 = wp1.lock();
        WeakPtr<int> wp3;

	//std::cout << (wp3._ptr == nullptr ? "nullptr" : "something else") <<std::endl;
        wp3 = sp2;                   // call operator=

        std::cout << "number of reference for sp1: " << sp1.count() << std::endl;
        std::cout << "number of reference for sp2: " << sp2.count() << std::endl;

    }

    std::cout << "number of reference for sp1: " << sp1.count() << std::endl;
    std::cout << "number of reference for sp2: " << sp2.count() << std::endl;
}

int main() {
    //test_shared_ptr();
    test_weak_ptr();
    std::cin.get();
}
