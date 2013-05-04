/**
 * Function implementations for mem_heap.h
 *
 * Author: Benjamin Martin
 * Email Address: benjamin.martin2@griffithuni.edu.au
 * Student ID: s2846492
 */

#include "mem_heap.h"
#include <iostream>

using namespace std;

/**
 * The constructor initialises all data members and creates
 * a Header block to hold the size of the free memory.
 *
 * It returns nothing.
 * It takes no parameters.
 */
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

    #ifdef DEBUG
        cout << "|---------DEBUG Mode----------|" << endl;
        cout << "|-----MemHeap Constructor-----|" << endl;
        cout << "|=============================|" << endl;
        cout << "|         What | Where        |" << endl;
        cout << "|=============================|" << endl;
        cout << "|  Header Size | " << mHeaderSize << "           |" << endl;
        cout << "|    &VHEAP[0] | " << (int*)&vheap[0] << "    |" << endl;
        cout << "|Start Of Heap | " << mStartOfHeap << "    |" << endl;
        cout << "|  End Of Heap | " << (int*)((char*)mEndOfHeap - 1) << "    |" << endl;
        cout << "|=============================|" << endl;
        cout << "| All addresses are inclusive |" << endl;
        cout << "|=============================|" << endl;
    #endif
}

/**
 * vmalloc searches through a linked list of Header structs for a section
 * of memory which is big enough to satisty the requested amount. If a
 * section of memory is not found an exception is thrown.
 *
 * It returns a memory address to the allocated memory (void*).
 * It takes one parameter of size_t which is used for the size of
 * allocated memory.
 */
void* MemHeap::vmalloc(size_t size)
{
    if(size == 0)
        throw "Invalid size: 0";
    void *newBlockAddress = NULL;

    Header *newBlock = (Header*)mStartOfHeap;
    while(newBlock && !newBlockAddress) {
        if(!newBlock->isSet && newBlock->size >= size) {
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
        
        newBlock = newBlock->next;
    }

    if(!newBlockAddress)
        throw "Not enough memory found.";
    else
        newBlockAddress = (char*)newBlockAddress + mHeaderSize;

    #ifdef DEBUG
        Header *testBlock = (Header*)newBlockAddress;
        testBlock--;
        cout << "|---------DEBUG Mode----------|" << endl;
        cout << "|------newBlockAddresses------|" << endl;
        cout << "|=============================|" << endl;
        cout << "|         What | Where        |" << endl;
        cout << "|=============================|" << endl;
        cout << "|  Block Start | " << testBlock << "    |" << endl;
        cout << "|   Head Start | " << testBlock << "    |" << endl;
        cout << "|     Head End | " << (int*)((char*)testBlock + mHeaderSize - 1) << "    |" << endl;
        cout << "|   Data Start | " << newBlockAddress << "    |" << endl;
        cout << "|     Data End | " << (int*)((char*)newBlockAddress + size - 1) << "    |" << endl;
        cout << "|    Block End | " << (int*)((char*)testBlock + mHeaderSize + size - 1) << "    |" << endl;
        cout << "|=============================|" << endl;
        cout << "| All addresses are inclusive |" << endl;
        cout << "|=============================|" << endl;
    #endif

    return newBlockAddress;
}

/**
 * vcalloc calls vmalloc to find a suitable section of memory. The section
 * of memory is then cycled through byte by byte and filled with 0's.
 *
 * It returns a memory address to the allocated memory (void*).
 * It takes one parameter of size_t which is used for the size of
 * allocated memory.
 */
void* MemHeap::vcalloc(size_t size)
{
    void *newBlockAddress = vmalloc(size);
    char *newBlockByte = (char*)newBlockAddress;
    for(int i = 0; i < size; i++) {
        *newBlockByte = '0';
        newBlockByte++;
    }
    return newBlockAddress;
}

/**
 * vfree marks the specified memory address block as unused so it may be
 * reused. It also check for unused adjacent memory blocks and bytes to
 * merge into a single unused memory block.
 *
 * It returns nothing.
 * It takes one parameter which is a memory address (void*).
 */
void MemHeap::vfree(void* mem)
{
    if(!mem)
        return;
    Header *block = (Header*)mem;
    block--;

    void *nextAddress;
    if(block->next && !block->next->isSet)
        nextAddress = (block->next->next) ? block->next->next : mEndOfHeap;
    else if(block->next)
        nextAddress = block->next;
    else
        nextAddress = mEndOfHeap;

    void *prevAddress;
    if(block->prev && !block->prev->isSet)
        prevAddress = (block->prev->prev) ? block->prev->prev : mStartOfHeap;
    else if(block->prev)
        prevAddress = block->prev;
    else
        prevAddress = mStartOfHeap;

    Header *nextBlock = (Header*)nextAddress;
    Header *prevBlock = (Header*)prevAddress;

    Header *newBlock;
    if(prevBlock != mStartOfHeap || (prevBlock->isSet && prevBlock != block))
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

    #ifdef DEBUG
        cout << "|---------DEBUG Mode----------|" << endl;
        cout << "|-----freedBlockAddresses-----|" << endl;
        cout << "|=============================|" << endl;
        cout << "|         What | Where        |" << endl;
        cout << "|=============================|" << endl;
        cout << "|  Block Start | " << newBlock << "    |" << endl;
        cout << "|   Head Start | " << newBlock << "    |" << endl;
        cout << "|     Head End | " << (int*)((char*)newBlock + mHeaderSize - 1) << "    |" << endl;
        cout << "|   Data Start | " << (int*)((char*)newBlock + mHeaderSize) << "    |" << endl;
        cout << "|     Data End | " << (int*)((char*)newBlock + mHeaderSize + newBlock->size - 1) << "    |" << endl;
        cout << "|    Block End | " << (int*)((char*)newBlock + mHeaderSize + newBlock->size - 1) << "    |" << endl;
        cout << "|=============================|" << endl;
        cout << "| All addresses are inclusive |" << endl;
        cout << "|=============================|" << endl;
    #endif
}

/**
 * vsizeof provides the size, in bytes, of memory allocated for a given pointer.
 *
 * It returns a non negitive whole number of size_t.
 * It takes one parameter which is a memory address (void*).
 */
size_t MemHeap::vsizeof(void* mem)
{
    if(!mem)
        throw "Invalid pointer.";
    Header *block = (Header*)mem;
    block--;
    return block->size;
}

/**
 * printHeapState outputs a specific character to the console for each byte of the
 * entire memory heap. The characters are: I = Header Information, D = Used Memory (Data),
 * and F = Unused Memory (Free).
 *
 * It returns nothing.
 * It takes no parameters.
 */
void MemHeap::printHeapState()
{
    Header *block = (Header*)mStartOfHeap;
    while(block) {
        if(block->isSet) {
            for(int i = 0; i < mHeaderSize; i++)
                cout << 'I';
            for(int i = 0; i < block->size; i++)
                cout << 'D';
            for(char* i = (char*)block + block->size + mHeaderSize; i < (void*)block->next; i++)
                cout << 'F';
        }
        else {
            for(int i = 0; i < mHeaderSize; i++)
                cout << 'I';
            for(int i = 0; i < block->size; i++)
                cout << 'F';
        }
        if(!block->next) {
            for(char* i = (char*)block + block->size + mHeaderSize; i < mEndOfHeap; i++)
                cout << 'F';
        }
        block = block->next;
    }
    cout << endl;
}