#include "mem_heap.h"
#include <iostream>

using namespace std;

MemHeap::MemHeap()
{
    mStartOfHeap = vheap;
    mEndOfHeap = mStartOfHeap + HEAP_SIZE;
    mHeaderSize = sizeof(Header);

    Header *newBlock = (Header*)mStartOfHeap;
    newBlock->isSet = false;
    newBlock->size = HEAP_SIZE;
    newBlock->next = NULL;
    newBlock->prev = NULL;
}

void* MemHeap::vmalloc(size_t size)
{
    void *newBlockAddress = NULL;
    int newBlockSize = size + mHeaderSize;

    Header *newBlock = (Header*)mStartOfHeap;
    while(newBlock && !newBlockAddress) {
        if(!newBlock->isSet) {
            if(newBlock->size >= newBlockSize) {

                if(newBlock->size >= newBlockSize + mHeaderSize) {
                    Header *nextBlock = (Header*)((void*)newBlock + newBlockSize);
                    nextBlock->size = newBlock->size - newBlockSize;
                    nextBlock->isSet = false;
                    nextBlock->next = newBlock->next;
                    nextBlock->prev = newBlock;

                    newBlock->size = newBlockSize;
                    newBlock->isSet = true;
                    newBlock->next = nextBlock;
                    newBlockAddress = newBlock;
                }
                else {
                    newBlock->size = newBlockSize;
                    newBlock->isSet = true;
                    newBlockAddress = newBlock;
                }
            }
        }
        
        newBlock = newBlock->next;
    }

    if(!newBlockAddress)
        throw "Not enough memory found.";
    else
        newBlockAddress += mHeaderSize;

    return newBlockAddress;
}

void* MemHeap::vcalloc(size_t size)
{

}

void MemHeap::vfree(void* mem)
{
    if(!mem)
        return;
    Header *ptr = (Header*)mem;
    ptr--;
    ptr->isSet = false;

    if(ptr->next && !ptr->next->isSet) {
        ptr->size += ptr->next->size;
        ptr->next = ptr->next->next;
        if(ptr->next)
            ptr->next->prev = ptr;
    }
    if(ptr->prev && !ptr->prev->isSet) {
        ptr->prev->size += ptr->size;
        ptr->prev->next = ptr->next;
        if(ptr->prev->next)
            ptr->prev->next->prev = ptr->prev;
    }
}

size_t MemHeap::vsizeof(void* mem)
{
    if(!mem)
        throw "Invalid pointer (NULL).";
    Header *ptr = (Header*)mem;
    ptr--;
    return ptr->size;
}

void MemHeap::printHeapState()
{
    Header *printBlock = (Header*)mStartOfHeap;
    while(printBlock) {
        if(printBlock->isSet) {
            for(int i = 0; i < mHeaderSize; i++)
                cout << 'I';
            for(int i = 0; i < printBlock->size - mHeaderSize; i++)
                cout << 'D';
            for(char* i = (char*)printBlock + printBlock->size; i < (void*)printBlock->next; i++)
                cout << 'F';
        }
        else {
            for(int i = 0; i < mHeaderSize; i++)
                cout << 'I';
            for(int i = 0; i < printBlock->size - mHeaderSize; i++)
                cout << 'F';
        }
        if(!printBlock->next) {
            for(char* i = (char*)printBlock + printBlock->size; i < mEndOfHeap; i++)
                cout << 'F';
        }
        printBlock = printBlock->next;
    }
    cout << endl;
}