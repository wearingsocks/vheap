#include "mem_heap.h"
#include <iostream>

using namespace std;

MemHeap::MemHeap()
{
    mStartOfHeap = vheap;
    mEndOfHeap = (char*)mStartOfHeap + HEAP_SIZE;
    mHeaderSize = sizeof(Header);

    Header *newBlock = (Header*)mStartOfHeap;
    newBlock->isSet = false;
    newBlock->size = HEAP_SIZE - mHeaderSize;
    newBlock->next = NULL;
    newBlock->prev = NULL;
}

void* MemHeap::vmalloc(size_t size)
{
    void *newBlockAddress = NULL;

    Header *newBlock = (Header*)mStartOfHeap;
    while(newBlock && !newBlockAddress) {
        if(!newBlock->isSet) {
            if(newBlock->size >= size) {

                if(newBlock->size >= size + mHeaderSize) {
                    Header *nextBlock = (Header*)((char*)newBlock + (size + mHeaderSize));
                    nextBlock->size = newBlock->size - (size + mHeaderSize);
                    nextBlock->isSet = false;
                    nextBlock->next = newBlock->next;
                    nextBlock->prev = newBlock;

                    newBlock->size = size;
                    newBlock->isSet = true;
                    newBlock->next = nextBlock;
                    newBlockAddress = newBlock;
                }
                else {
                    newBlock->size = size;
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
        newBlockAddress = (char*)newBlockAddress + mHeaderSize;

    return newBlockAddress;
}

void* MemHeap::vcalloc(size_t size)
{
    void *newBlockAddress = vmalloc(size);
    Header *newBlock = (Header*)newBlockAddress;
    newBlock--;
    char *newBlockByte = (char*)newBlockAddress;
    for(int i = 0; i < newBlock->size; i++) {
        *newBlockByte = '0';
        newBlockByte++;
    }
    return newBlockAddress;
}

void MemHeap::vfree(void* mem)
{
    if(!mem)
        return;
    Header *ptr = (Header*)mem;
    ptr--;

    void *nextAddress;
    if(ptr->next && !ptr->next->isSet) {
        if(ptr->next->next)
            nextAddress = ptr->next->next;
        else
            nextAddress = mEndOfHeap;
    }
    else if(ptr->next)
        nextAddress = ptr->next;
    else
        nextAddress = mEndOfHeap;

    void *prevAddress;
    if(ptr->prev && !ptr->prev->isSet) {
        if(ptr->prev->prev)
            prevAddress = ptr->prev->prev;
        else
            prevAddress = mStartOfHeap;
    }
    else if(ptr->prev)
        prevAddress = ptr->prev;
    else
        prevAddress = mStartOfHeap;

    Header *nextBlock = (Header*)nextAddress;
    Header *prevBlock = (Header*)prevAddress;

    Header *newBlock;
    if(prevBlock != mStartOfHeap || (prevBlock->isSet && prevBlock != ptr))
        newBlock = (Header*)((char*)prevBlock + prevBlock->size + mHeaderSize);
    else
        newBlock = (Header*)mStartOfHeap;

    newBlock->isSet = false;
    newBlock->size = ((char*)nextBlock - (char*)newBlock) - mHeaderSize;

    if(nextBlock != mEndOfHeap) {
        newBlock->next = nextBlock;
        nextBlock->prev = newBlock;
    }
    else
        newBlock->next = NULL;

    if(prevBlock != mStartOfHeap) {
        newBlock->prev = prevBlock;
        prevBlock->next = newBlock;
    }
    else
        newBlock->prev = NULL;
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
            for(int i = 0; i < printBlock->size; i++)
                cout << 'D';
            for(char* i = (char*)printBlock + printBlock->size + mHeaderSize; i < (void*)printBlock->next; i++)
                cout << 'F';
        }
        else {
            for(int i = 0; i < mHeaderSize; i++)
                cout << 'I';
            for(int i = 0; i < printBlock->size; i++)
                cout << 'F';
        }
        if(!printBlock->next) {
            for(char* i = (char*)printBlock + printBlock->size + mHeaderSize; i < mEndOfHeap; i++)
                cout << 'F';
        }
        printBlock = printBlock->next;
    }
    cout << endl;
}