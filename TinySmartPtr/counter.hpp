#ifndef _COUNTER_H_
#define _COUNTER_H_


template<typename T> class SharedPtr;
template<typename T> class WeakPtr;


template<typename T>
class Counter {

    friend class SharedPtr<T>;
    friend class WeakPtr<T>;

public:
    Counter() : _ref_count(0), _weak_count(0) {}
    //virtual ~Counter() {}
    ~Counter() {}

public:
    Counter(const Counter&) = delete;
    Counter& operator=(const Counter&) = delete;

private:
    /*atomic_unit _ref_count;
    atomic_uint _weak_count;*/

    unsigned int _ref_count;
    unsigned int _weak_count;
};


#endif // !_COUNTER_H_
