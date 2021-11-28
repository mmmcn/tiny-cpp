#ifndef _SHARED_PTR_H_
#define _SHARED_PTR_H_

#include<iostream>

template<typename T> class Counter;
template<typename T> class WeakPtr;

template<typename T>
class SharedPtr {
    friend class WeakPtr<T>;
public:
    SharedPtr(T* ptr) : _ptr(ptr), _cnt(new Counter<T>) {
        if (ptr != nullptr) {
            _cnt->_ref_count = 1;

            std::cout << "call SharedPtr(T*) " << std::endl;
        }
    }
    ~SharedPtr() { release(); }


    // copy constructor, construct from another shared_ptr
    SharedPtr(const SharedPtr<T> &rhs) {
        _ptr = rhs._ptr;
        rhs._cnt->_ref_count++;       // the reference count increase by 1
        _cnt = rhs._cnt;
        std::cout << "Call SharedPtr(const SharedPtr&) " << std::endl;
    }

    // copy constructor, construct from another weak_ptr
    SharedPtr(const WeakPtr<T> &rhs) {
        _ptr = rhs._ptr;
        rhs._cnt->_ref_count++;
        _cnt = rhs._cnt;
        std::cout << "Call SharedPtr(const WeakPtr&) " << std::endl;
    }


    // override operator=
    SharedPtr<T>& operator=(const SharedPtr<T> &rhs) {
        if (this != &rhs) {
            this->release();
            _ptr = rhs._ptr;
            rhs._cnt->_ref_count++;
            _cnt = rhs._cnt;
            std::cout << "call SharedPtr<T>& operator=(const SharedPtr<T>&) " << std::endl;
        }
        return *this;
    }

    // override operator*
    T& operator*() { return *_ptr; }

    // override operator->
    T* operator->() { return _ptr; }


    // get the number of reference
    int count() const { return _cnt->_ref_count; }

protected:
    void release() {
        _cnt->_ref_count--;
        if (_cnt->_ref_count < 1) {
            delete _ptr;
            std::cout << "SharedPtr delete Ptr: " << _ptr << std::endl;
            _ptr = nullptr;

            if (_cnt->_weak_count < 1) {
                delete _cnt;
                std::cout << "SharedPtr delete Cnt: " << _cnt << std::endl;
                _cnt = nullptr;
            }

            // std::cout << "SharedPtr release" << std::endl;
        }
        std::cout << "call SharedPtr release" << std::endl;
    }


private:
    T* _ptr;
    Counter<T>* _cnt;
};


#endif // !_SHARED_PTR_H_
