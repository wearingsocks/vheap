/**
 * Program Aim: To allow allocation and de-allocation of memory to be performed on a chuck of upfront
 *              allocated memory through pointer manipulation to remove the overhead of calling the
 *              operating system multiple time.
 *
 * Author: Benjamin Martin
 * Email Address: benjamin.martin2@griffithuni.edu.au
 * Student ID: s2846492
 *
 * Note: Exceptions will be thrown when:
 *               - No more memory is available
 *               - vmalloc() or vcalloc() is passed a size_t of '0'
 *               - vsizeof() is passed an invalid pointer
 */

#ifndef MEM_HEAP_H
#define MEM_HEAP_H

#define DEBUG // Comment out to remove debugging asserts

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

    void* mStartOfHeap; // Memory address of the start position of the heap (inclusive)
    void* mEndOfHeap; // Memory address of the end position of the heap (exclusive)
    int mHeaderSize; // The size in bytes of a Header struct

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