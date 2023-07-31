//
// Created by sergiy on 18/06/22.
//
#include <iostream>

// idea of allocators
// new is bad, because it asks OS to give us new memory, which stops your code.
// so we will ask OS to give us a lot of memory. and work with it.

// allocate & deallocate
// construct & destroy

template <typename T, typename Alloc = std::allocator<T>>
class Vector{
private:
    size_t cap;
    size_t sz;
    T* arr;
    Alloc alloc;

    using AllocTraits = std::allocator_traits<Alloc>;
public:

    void reserve (size_t newcap) {
        if (newcap <= cap)
            return;

//        T* newarr = alloc.allocate(newcap); //allocated new memory
        T* newarr = AllocTraits::allocate(alloc, newcap);
        for (size_t i = 0; i < sz; ++i)  {
            try {
//                alloc.construct(newarr + i, arr[i]); //constructed elements in new memory
                AllocTraits::construct(alloc, newarr + i, arr[i]);
            } catch(...) {
                for (size_t j = 0; j < i; ++j) {
//                    alloc.destroy(newarr + i); //if smth went wrong - destroyed elements
                    AllocTraits::destroy(alloc, newarr + i);
                }
//                alloc.deallocate(newarr, newcap); //and deallocated new memory
                AllocTraits::deallocate(alloc, newarr, newcap); //and deallocated new memory
                throw;
            }
        }

        for (size_t i = 0; i < sz; ++i) {
//            alloc.destroy(arr + i); //destroyed old elements
            AllocTraits::destroy(alloc, newarr + i);
        }

//        alloc.deallocate(arr, cap); //dealocated (aka "free") old memory
        AllocTraits::deallocate(alloc, arr, cap);

        cap = newcap;
        arr = newarr;
    }
};
