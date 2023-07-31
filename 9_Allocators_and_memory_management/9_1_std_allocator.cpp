//
// Created by sergiy on 18/06/22.
//

#include <iostream>
#include <memory>

template <typename T>
struct allocator{
    T* allocate(size_t n){
        return reinterpret_cast<T*>(new char[n * sizeof(T)]);
    }

    void deallocate(T* ptr, size_t){ // size_t will not be used, because delete[] will delete all the array on ptr,
        // because elements lie in the row (but it can be used in other allocators)
        delete[] reinterpret_cast<char*>(ptr);
    }

    template <typename... Args>
    void construct(T* ptr, const Args&... args) {
        new(ptr) T(args...);
    }

    void destroy(T* ptr) {
        ptr->~T();
    }
};



class Pool {
    char* memory;
};

template <typename T>
class PoolAllocator {
    std::shared_ptr<Pool> pool;
};


int main() {
    char arr[1'000'000];
//    stackAllocator alloc(arr);
//    std::vector<int, stackAllocator<int>> v(alloc);

}

