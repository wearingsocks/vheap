#ifndef MEM_HEAP_H
#define MEM_HEAP_H

#include "v_heap.h"

class MemHeap : public VHeap
{
    struct Header
    {
        int size;
        bool isSet;
        Header *prev;
        Header *next;
    };

    void* mStartOfHeap;
    void* mEndOfHeap;
    int mHeaderSize;

public:
    MemHeap();

    void* vmalloc(size_t size);
    void* vcalloc(size_t size);
    void vfree(void* mem);
    size_t vsizeof(void* mem);
    
    void printHeapState();

private:

};

#endif /* MEM_HEAP_H */