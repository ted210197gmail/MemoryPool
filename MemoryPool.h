//
// Created by Ted Wu on 2023/7/4.
//

#ifndef MEMORYPOOL_MEMORYPOOL_H
#define MEMORYPOOL_MEMORYPOOL_H

#include <list>

using namespace std;

class MemoryPool {
    list<char*> freeBlock;
public:
    MemoryPool(int blockSize, int blockCount);
    ~MemoryPool();
    void* alloc();
    void dealloc(void* chunk);
    void free();
};


#endif //MEMORYPOOL_MEMORYPOOL_H
