#include <iostream>
#include "MemoryPool.h"

int main() {
    MemoryPool* memoryPool = new MemoryPool(sizeof(int)*3, 10);

    int* arr = static_cast<int*>(memoryPool->alloc());
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;

    for(int i=0;i<3;++i) {
        cout<<arr[i]<<" ";
    }

    // point: let memoryPool to manage its allocated memory
    memoryPool->dealloc(arr);
    delete memoryPool;
    return 0;
}
