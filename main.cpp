#include "mem_heap.h"
#include <iostream>

using namespace std;

int main()
{
    MemHeap heapObj;
/*
    //myNewInt
    int *myNewInt = (int*)heapObj.vmalloc(sizeof(int));
    *myNewInt = 12345678;
    cout << "    myNewInt " << myNewInt << "     " << *myNewInt << "     " << heapObj.vsizeof(myNewInt) << endl;

    //myNewInt2
    int *myNewInt2 = (int*)heapObj.vmalloc(sizeof(int));
    *myNewInt2 = 87654321;
    cout << "   myNewInt2 " << myNewInt2 << "     " << *myNewInt2 << "     " << heapObj.vsizeof(myNewInt2) << endl;

    //myNewInt3
    int *myNewInt3 = (int*)heapObj.vmalloc(sizeof(int));
    *myNewInt3 = 33333333;
    cout << "   myNewInt3 " << myNewInt3 << "     " << *myNewInt3 << "     " << heapObj.vsizeof(myNewInt3) << endl;

    //myNewDouble
    double *myNewDouble = (double*)heapObj.vmalloc(sizeof(double));
    *myNewDouble = 12.345678;
    cout << " myNewDouble " << myNewDouble << "     " << *myNewDouble << "      " << heapObj.vsizeof(myNewDouble) << endl;

    cout << endl;
    heapObj.printHeapState();
    cout << endl;

    heapObj.vfree(myNewInt2);
    cout << " vfree(myNewInt2)" << endl;

    cout << endl;
    heapObj.printHeapState();
    cout << endl;

    //myNewChar
    char *myNewChar = (char*)heapObj.vmalloc(sizeof(char));
    *myNewChar = 'a';
    cout << "   myNewChar " << (int*)myNewChar << "     " << *myNewChar << "     " << heapObj.vsizeof(myNewChar) << endl;

    cout << endl;
    heapObj.printHeapState();
    cout << endl;

    //Array Long
    long * myLongArr = (long*)heapObj.vmalloc(sizeof(long) * 9);
    myLongArr[0] = 11111;
    myLongArr[1] = 22222;
    myLongArr[2] = 33333;
    myLongArr[3] = 44444;
    myLongArr[4] = 55555;
    myLongArr[5] = 66666;
    myLongArr[6] = 77777;
    myLongArr[7] = 88888;
    myLongArr[8] = 99999;

    cout << "myLongArr:" << endl;
    for(int i = 0; i < 9; i++)
        cout << "Index " << i << " = " << myLongArr[i] << " - @ address: " << &myLongArr[i] << endl;

    cout << endl;
    heapObj.printHeapState();
    cout << endl;
*/
    cout << " Loop x20: vmalloc(sizeof(long) * 9)" << endl;
    long *fill;
    for(int i = 0; i < 21; i++)
        fill = (long*)heapObj.vmalloc(sizeof(long) * 9);

    //myNewChar
    char *myNewChar = (char*)heapObj.vmalloc(sizeof(char));
    if(myNewChar) {
        *myNewChar = 'a';
        cout << "   myNewChar " << (int*)myNewChar << "     " << *myNewChar << "     " << heapObj.vsizeof(myNewChar) << endl;
    }
    else
        cout << " ---myNewChar is NULL---" << endl;

    //myNewDouble
    double *myNewDouble = (double*)heapObj.vmalloc(sizeof(double));
    if(myNewDouble) {
        *myNewDouble = 12.345678;
        cout << " myNewDouble " << myNewDouble << "     " << *myNewDouble << "      " << heapObj.vsizeof(myNewDouble) << endl;
    }
    else
        cout << " ---myNewDouble is NULL---" << endl;

    cout << endl;
    heapObj.printHeapState();
    cout << endl;

    return 0;
}