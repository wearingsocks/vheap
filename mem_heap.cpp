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

    //Testing
    cout << "  HeaderSize " << mHeaderSize << endl;
    cout << "   &VHEAP[0] " << (int*)&vheap[0] << endl;
    cout << "     &HStart " << mStartOfHeap << endl;
    cout << "       &HEnd " << mEndOfHeap << "\n" << endl;
    //EndTesting
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
        cout << "Not enough memory found." << endl;
    else
        newBlockAddress += mHeaderSize;

    return newBlockAddress;
}

void* MemHeap::vcalloc(size_t size)
{

}

void MemHeap::vfree(void* mem)
{
    Header *ptr = (Header*)mem;
    ptr--;
    ptr->isSet = false;
}

size_t MemHeap::vsizeof(void* mem)
{
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