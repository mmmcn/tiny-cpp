#ifndef _WEAK_PTR_H_
#define _WEAK_PTR_H_
#include<iostream>

template<typename T> class Counter;
template<typename T> class SharedPtr;


template<typename T>
class WeakPtr {
public:

//    WeakPtr() = default;
    WeakPtr() : _ptr(nullptr), _cnt(nullptr) {}
    // construct from another shared_ptr
    WeakPtr(const SharedPtr<T>& rhs) : _ptr(rhs._ptr), _cnt(rhs._cnt) {
        _cnt->_weak_count++;
        std::cout << "call WeakPtr(const SharedPtr&) " << std::endl;
    }

    // construct from another weak_ptr
    WeakPtr(const WeakPtr<T>& rhs) : _ptr(rhs._ptr), _cnt(rhs._cnt) {
        _cnt->_weak_count++;
        std::cout << "call WeakPtr(const WeakPtr&) " << std::endl;
    }


    // assign constructor, construct from another shared_ptr
    WeakPtr<T>& operator=(const SharedPtr<T>& rhs) {
        release();
        _cnt = rhs._cnt;
        _cnt->_weak_count++;
        _ptr = rhs._ptr;
        std::cout << "call WeakPtr<T>& operator=(const SharedPtr<T>&) " << std::endl;
        return *this;
    }

    // assign constructor, construct from another weak_ptr;
    WeakPtr<T>& operator=(const WeakPtr<T>& rhs) {
        if (this != &rhs) {
            release();
            _cnt = rhs._cnt;
            _cnt->_weak_count++;
            _ptr = rhs._ptr;
            std::cout << "call WeakPtr<T>& operator=(const WeakPtr<T>&) " << std::endl;
        }
        return *this;
    }


    SharedPtr<T>& lock() {
        return SharedPtr<T>(*this);
    }

    bool expired() {
        if (_cnt) {
            if (_cnt->_ref_count > 0)
                return false;
        }
        return true;
    }

    ~WeakPtr() { release(); }

public:
    //WeakPtr() = delete;        // only allow to construct a weak_ptr from another shared_ptr or weak_ptr
    T& operator*() = delete;
    T* operator->() = delete;

private:
    void release() {
        if (_cnt != nullptr) {
            _cnt->_weak_count--;
            if (_cnt->_weak_count < 1 && _cnt->_ref_count < 1) {
                delete _cnt;
                _cnt = nullptr;
                std::cout << "Delete Count" << std::endl;
            }
            std::cout << "WeakPtr release" << std::endl;
        }
    }


private:
    T* _ptr;
    Counter<T>* _cnt;
};

#endif // !_WEAK_PTR_H_
