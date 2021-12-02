/*==================================================
*  Copyright (C) 2021 mmmcn. All right reserved.
*  
*  Author: WangMingyuan
*  Date: 2021-12-02
*  Description: 
*  
==================================================*/


#ifndef _UNIQUE_PTR_H
#define _UNIQUE_PTR_H

#include<iostream>


template<typename T> class Counter;

template<typename T>
class UniquePtr {

public:
	//UniquePtr() = default;
	UniquePtr() : _ptr(nullptr) {}

	// construct from a naive pointer
	UniquePtr(T* ptr) : _ptr(ptr) {
	
		std::cout << "call UniquePtr(T*) " <<std::endl;
	}

	~UniquePtr() {
	    if (_ptr != nullptr) {
			std::cout << "UniquePtr delete Ptr: " << _ptr << std::endl;
			delete _ptr;
			_ptr = nullptr;
		}
		std::cout << "call ~UniquePtr() " << std::endl;
	}


public:
	/*UniquePtr not support copy and assignment operations
	e.g.
	UniquePtr<int> p1(new int(10)); // ok
	UniquePtr<int> p2(p1);
	UniquePtr<int> p3 = p1;    // the above two lines are incorrect, copy construct is not allowe
	UniquePtr<int> p4;
	p4 = p1;                  // assiginment operation is not allowed.
	*/
	
	UniquePtr(const UniquePtr<T>&) = delete;
	UniquePtr<T>& operator=(const UniquePtr<T>&) = delete;


public:

	T* get() const { return _ptr; }

	T* release() {
		T* tmp = _ptr;
		_ptr = nullptr;
		return tmp;
	}

	void reset() {
		if (_ptr != nullptr) {
		
			delete _ptr;
			_ptr = nullptr;
		}
	}
	
	void reset(T* ptr) {
		_ptr = ptr;
	}

	T& operator*() { return *_ptr; }






private:
	T* _ptr;
	//Counter<T>* _cnt;

};




#endif // !_UNIQUE_PTR_H
