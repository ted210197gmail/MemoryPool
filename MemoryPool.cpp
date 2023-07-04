//
// Created by Ted Wu on 2023/7/4.
//

#include "MemoryPool.h"

using namespace std;

MemoryPool::MemoryPool(int blockSize, int blockCount) {
    for(int i=0;i<blockCount;++i) {
        freeBlock.push_back(new char[blockSize]);
    }
}

MemoryPool::~MemoryPool() {
    free();
}

void* MemoryPool::alloc() {
    if(freeBlock.empty()) {
        throw bad_alloc();
    }

    char* chunk = freeBlock.front();
    freeBlock.pop_front();
    return chunk;
}

void MemoryPool::dealloc(void* chunk) {
    freeBlock.push_back((char*) chunk);
}

void MemoryPool::free() {
    while(!freeBlock.empty()) {
        delete[] freeBlock.front();
        freeBlock.pop_front();
    }
}
