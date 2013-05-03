#include "mem_heap.h"
#include <iostream>
#include <string>
#define TEST_HEAP_SIZE 2048

using namespace std;

bool testConstructor();

bool testVmallocSimple();
bool testVmallocFill();
bool testVmallocOverflow();

bool testVcallocSimple();
bool testVcallocFill();
bool testVcallocOverflow();

bool testVfreeSimple();

bool testVsizeof();
bool testVsizeofNULL();

bool testPrintHeapState();

bool testMassFunctCombo();

int main()
{
    string testResult;
    int tests = 0, passed = 0;

    tests++;
    cout << "======================================================================" << endl;
    cout << "-->> Running: testConstructor()" << endl;
    testResult = (testConstructor()) ? "Passed" : "Failed";
    cout << "-->> Result: " << testResult << endl;
    cout << "======================================================================" << endl << endl;
    if(testResult == "Passed")
        passed++;

    tests++;
    cout << "======================================================================" << endl;
    cout << "-->> Running: testVmallocSimple()" << endl;
    testResult = (testVmallocSimple()) ? "Passed" : "Failed";
    cout << "-->> Result: " << testResult << endl;
    cout << "======================================================================" << endl << endl;
    if(testResult == "Passed")
        passed++;

    tests++;
    cout << "======================================================================" << endl;
    cout << "-->>  Running: testVmallocFill()" << endl;
    testResult = (testVmallocFill()) ? "Passed" : "Failed";
    cout << "-->>  Result: " << testResult << endl;
    cout << "======================================================================" << endl << endl;
    if(testResult == "Passed")
        passed++;

    tests++;
    cout << "======================================================================" << endl;
    cout << "-->>  Running: testVmallocOverflow()" << endl;
    testResult = (testVmallocOverflow()) ? "Passed" : "Failed";
    cout << "-->>  Result: " << testResult << endl;
    cout << "======================================================================" << endl << endl;
    if(testResult == "Passed")
        passed++;

    tests++;
    cout << "======================================================================" << endl;
    cout << "-->> Running: testVcallocSimple()" << endl;
    testResult = (testVcallocSimple()) ? "Passed" : "Failed";
    cout << "-->> Result: " << testResult << endl;
    cout << "======================================================================" << endl << endl;
    if(testResult == "Passed")
        passed++;

    tests++;
    cout << "======================================================================" << endl;
    cout << "-->>  Running: testVcallocFill()" << endl;
    testResult = (testVcallocFill()) ? "Passed" : "Failed";
    cout << "-->>  Result: " << testResult << endl;
    cout << "======================================================================" << endl << endl;
    if(testResult == "Passed")
        passed++;

    tests++;
    cout << "======================================================================" << endl;
    cout << "-->>  Running: testVcallocOverflow()" << endl;
    testResult = (testVcallocOverflow()) ? "Passed" : "Failed";
    cout << "-->>  Result: " << testResult << endl;
    cout << "======================================================================" << endl << endl;
    if(testResult == "Passed")
        passed++;

    tests++;
    cout << "======================================================================" << endl;
    cout << "-->>  Running: testVfreeSimple()" << endl;
    testResult = (testVfreeSimple()) ? "Passed" : "Failed";
    cout << "-->>  Result: " << testResult << endl;
    cout << "======================================================================" << endl << endl;
    if(testResult == "Passed")
        passed++;

    tests++;
    cout << "======================================================================" << endl;
    cout << "-->>  Running: testVsizeof()" << endl;
    testResult = (testVsizeof()) ? "Passed" : "Failed";
    cout << "-->>  Result: " << testResult << endl;
    cout << "======================================================================" << endl << endl;
    if(testResult == "Passed")
        passed++;

    tests++;
    cout << "======================================================================" << endl;
    cout << "-->>  Running: testVsizeofNULL()" << endl;
    testResult = (testVsizeofNULL()) ? "Passed" : "Failed";
    cout << "-->>  Result: " << testResult << endl;
    cout << "======================================================================" << endl << endl;
    if(testResult == "Passed")
        passed++;

    tests++;
    cout << "======================================================================" << endl;
    cout << "-->>  Running: testPrintHeapState()" << endl;
    testResult = (testPrintHeapState()) ? "Passed" : "Failed";
    cout << "-->>  Result: " << testResult << endl;
    cout << "======================================================================" << endl << endl;
    if(testResult == "Passed")
        passed++;

    tests++;
    cout << "======================================================================" << endl;
    cout << "-->>  Running: testMassFunctCombo()" << endl;
    testResult = (testMassFunctCombo()) ? "Passed" : "Failed";
    cout << "-->>  Result: " << testResult << endl;
    cout << "======================================================================" << endl << endl;
    if(testResult == "Passed")
        passed++;

    cout << "======================================================================" << endl;
    cout << "-->>  Successful Tests: " << passed << "/" << tests << endl;
    cout << "======================================================================" << endl << endl;

    return 0;
}

bool testConstructor()
{
    MemHeap heapObj;
    return true;
}

bool testVmallocSimple()
{
    MemHeap heapObj;

    char *myNewChar = (char*)heapObj.vmalloc(sizeof(char));
    *myNewChar = 'a';
    cout << "Name: myNewChar  " << "   Value: " << *myNewChar << "         Address: " << (int*)myNewChar << "   Size: " << heapObj.vsizeof(myNewChar) << endl;

    int *myNewInt = (int*)heapObj.vmalloc(sizeof(int));
    *myNewInt = 123456;
    cout << "Name: myNewInt   " << "   Value: " << *myNewInt << "    Address: " << myNewInt << "   Size: " << heapObj.vsizeof(myNewInt) << endl;

    double *myNewDouble = (double*)heapObj.vmalloc(sizeof(double));
    *myNewDouble = 12.3456;
    cout << "Name: myNewDouble" << "   Value: " << *myNewDouble << "   Address: " << myNewDouble << "   Size: " << heapObj.vsizeof(myNewDouble) << endl;

    bool result = (*myNewChar == 'a' && *myNewInt == 123456 && *myNewDouble == 12.3456) ? true : false;
    return result;
}

bool testVmallocFill()
{
    struct forSizeStruct
    {
        int size;
        bool isSet;
        forSizeStruct *prev;
        forSizeStruct *next;
    };

    MemHeap heapObj;

    int numChars = TEST_HEAP_SIZE - sizeof(forSizeStruct);

    char *myNewCharArray = (char*)heapObj.vmalloc(sizeof(char) * (numChars));
    for(int i = 0; i < numChars; i += 2) {
        myNewCharArray[i] = 'a';
        myNewCharArray[i + 1] = 'b';
    }

    bool result = (myNewCharArray[0] == 'a' && myNewCharArray[numChars - 1] == 'b') ? true : false;
    return result;
}

bool testVmallocOverflow()
{
    bool result = false;
    MemHeap heapObj;

    try {
        int *myNewIntArray = (int*)heapObj.vmalloc(sizeof(int) * (TEST_HEAP_SIZE / sizeof(int)));
    } catch (const char* msg) {
        cout << msg << endl;
        result = true;
    }

    return result;
}

bool testVcallocSimple()
{
    return false;
    MemHeap heapObj;

    char *myNewChar = (char*)heapObj.vmalloc(sizeof(char));
    *myNewChar = 'a';
    cout << "Name: myNewChar  " << "   Value: " << *myNewChar << "         Address: " << (int*)myNewChar << "   Size: " << heapObj.vsizeof(myNewChar) << endl;

    int *myNewInt = (int*)heapObj.vmalloc(sizeof(int));
    *myNewInt = 123456;
    cout << "Name: myNewInt   " << "   Value: " << *myNewInt << "    Address: " << myNewInt << "   Size: " << heapObj.vsizeof(myNewInt) << endl;

    double *myNewDouble = (double*)heapObj.vmalloc(sizeof(double));
    *myNewDouble = 12.3456;
    cout << "Name: myNewDouble" << "   Value: " << *myNewDouble << "   Address: " << myNewDouble << "   Size: " << heapObj.vsizeof(myNewDouble) << endl;

    bool result = (*myNewChar == 'a' && *myNewInt == 123456 && *myNewDouble == 12.3456) ? true : false;
    return result;
}

bool testVcallocFill()
{
    return false;
    struct forSizeStruct
    {
        int size;
        bool isSet;
        forSizeStruct *prev;
        forSizeStruct *next;
    };

    MemHeap heapObj;

    int numChars = TEST_HEAP_SIZE - sizeof(forSizeStruct);
    
    char *myNewCharArray = (char*)heapObj.vmalloc(sizeof(char) * (numChars));
    for(int i = 0; i < numChars; i += 2) {
        myNewCharArray[i] = 'a';
        myNewCharArray[i + 1] = 'b';
    }

    bool result = (myNewCharArray[0] == 'a' && myNewCharArray[numChars - 1] == 'b') ? true : false;
    return result;
}

bool testVcallocOverflow()
{
    return false;
    bool result = false;
    MemHeap heapObj;

    try {
        int *myNewIntArray = (int*)heapObj.vcalloc(sizeof(int) * (TEST_HEAP_SIZE / sizeof(int)));
    } catch (const char* msg) {
        cout << msg << endl;
        result = true;
    }

    return result;
}

bool testVfreeSimple()
{
    MemHeap heapObj;

    int *myNewInt = (int*)heapObj.vmalloc(sizeof(int));
    *myNewInt = 123456;
    cout << "Name: myNewInt   " << "   Value: " << *myNewInt << "    Address: " << myNewInt << "   Size: " << heapObj.vsizeof(myNewInt) << endl;

    double *myNewDouble = (double*)heapObj.vmalloc(sizeof(double));
    *myNewDouble = 12.3456;
    cout << "Name: myNewDouble" << "   Value: " << *myNewDouble << "   Address: " << myNewDouble << "   Size: " << heapObj.vsizeof(myNewDouble) << endl;

    heapObj.printHeapState();

    cout << "Free.....myNewInt" << endl;
    heapObj.vfree(myNewInt);

    heapObj.printHeapState();

    cout << "Free.....myNewDouble" << endl;
    heapObj.vfree(myNewDouble);

    heapObj.printHeapState();

    return true;
}

bool testVsizeof()
{
    MemHeap heapObj;

    int *myNewInt = (int*)heapObj.vmalloc(sizeof(int));
    *myNewInt = 123456;
    cout << "Name: myNewInt   " << "   Value: " << *myNewInt << "    Address: " << myNewInt << "   Size: " << heapObj.vsizeof(myNewInt) << endl;

    bool result = (heapObj.vsizeof(myNewInt) == sizeof(int)) ? true : false;
    return result;
}

bool testVsizeofNULL()
{
    bool result = false;
    MemHeap heapObj;

    try {
        heapObj.vsizeof(NULL);
    } catch (const char* msg) {
        cout << msg << endl;
        result = true;
    }

    return result;
}

bool testPrintHeapState()
{
    MemHeap heapObj;

    int *myNewInt = (int*)heapObj.vmalloc(sizeof(int));
    *myNewInt = 123456;
    cout << "Name: myNewInt   " << "   Value: " << *myNewInt << "    Address: " << myNewInt << "   Size: " << heapObj.vsizeof(myNewInt) << endl;

    heapObj.printHeapState();

    return true;
}

bool testMassFunctCombo()
{
    MemHeap heapObj;

    int *myNewInt = (int*)heapObj.vmalloc(sizeof(int));
    *myNewInt = 123456;
    cout << "Name: myNewInt   " << "   Value: " << *myNewInt << "    Address: " << myNewInt << "   Size: " << heapObj.vsizeof(myNewInt) << endl;

    int *myNewInt2 = (int*)heapObj.vmalloc(sizeof(int));
    *myNewInt2 = 654321;
    cout << "Name: myNewInt2   " << "   Value: " << *myNewInt2 << "    Address: " << myNewInt2 << "   Size: " << heapObj.vsizeof(myNewInt2) << endl;

    int *myNewInt3 = (int*)heapObj.vmalloc(sizeof(int));
    *myNewInt3 = 332211;
    cout << "Name: myNewInt3   " << "   Value: " << *myNewInt3 << "    Address: " << myNewInt3 << "   Size: " << heapObj.vsizeof(myNewInt3) << endl;

    double *myNewDouble = (double*)heapObj.vmalloc(sizeof(double));
    *myNewDouble = 12.3456;
    cout << "Name: myNewDouble" << "   Value: " << *myNewDouble << "   Address: " << myNewDouble << "   Size: " << heapObj.vsizeof(myNewDouble) << endl;

    cout << endl;
    heapObj.printHeapState();
    cout << endl;

    cout << "Free.....myNewInt2" << endl;
    heapObj.vfree(myNewInt2);

    cout << endl;
    heapObj.printHeapState();
    cout << endl;

    char *myNewChar = (char*)heapObj.vmalloc(sizeof(char));
    *myNewChar = 'a';
    cout << "Name: myNewChar  " << "   Value: " << *myNewChar << "         Address: " << (int*)myNewChar << "   Size: " << heapObj.vsizeof(myNewChar) << endl;

    cout << endl;
    heapObj.printHeapState();
    cout << endl;

    cout << "Free.....myNewInt3" << endl;
    heapObj.vfree(myNewInt3);
    cout << endl;

    long * myLongArray = (long*)heapObj.vmalloc(sizeof(long) * 9);
    myLongArray[0] = 11111;
    myLongArray[1] = 22222;
    myLongArray[2] = 33333;
    myLongArray[3] = 44444;
    myLongArray[4] = 55555;
    myLongArray[5] = 66666;
    myLongArray[6] = 77777;
    myLongArray[7] = 88888;
    myLongArray[8] = 99999;
    cout << "Name: myLongArray  " << "   Address: " << (long*)myLongArray << "   Size: " << heapObj.vsizeof(myLongArray) << endl;
    for(int i = 0; i < 9; i++)
        cout << "Index " << i << " = " << myLongArray[i] << " @ address: " << &myLongArray[i] << endl;

    cout << endl;
    heapObj.printHeapState();
    cout << endl;
    return true;
}