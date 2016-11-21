#ifndef _SINGLETON_FINALIZER_H
#define _SINGLETON_FINALIZER_H

#include <iostream>
#include <assert.h>     /* assert */
using namespace std;

class SingletonFinalizer
{
public:
    typedef void(*FinalizerFunc)();

    static void addFinalizer(FinalizerFunc func);
    static void finalize();
};

template <typename T>
class singleton final
{
public:
    static T& get_instance()
    {
        std::call_once(initFlag, create);
        assert(instance);
        return *instance;
    }

private:
    static void create() {
        instance = new T;
        SingletonFinalizer::addFinalizer(&singleton<T>::destroy);
    }

    static void destroy() {
        delete instance;
        instance = nullptr;
    }

    static std::once_flag initFlag;
    static T* instance;
};

template <typename T> std::once_flag singleton<T>::initFlag;
template <typename T> T* singleton<T>::instance = nullptr;

#endif // _SINGLETON_FINALIZER_H