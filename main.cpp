/**
 * Program Aim: To test the functionality of the MemHeap class (mem_heap.h & mem_heap.cpp)
 *
 * Author: Benjamin Martin
 * Email Address: benjamin.martin2@griffithuni.edu.au
 * Student ID: s2846492
 *
 * Note: Some test results also rely on testers discretion to view
 *       outputs for correct functionality.
 */

#include "mem_heap.h"
#include <iostream>
#include <string>
#define TEST_HEAP_SIZE 2048

using namespace std;

int menu();

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

/**
 * The "main" function of the program calls user selected tests and
 * displays the testing results until the user selects to Quit the program.
 *
 * It returns a whole number (int).
 * It takes no parameters.
 */
int main()
{
    string testResult;
    int totalNumTests = 0, totalNumPassed = 0;

    int selection = 0;
    while(selection != 8) {
        selection = menu();
        int numTests = 0, numPassed = 0;
        switch(selection) {
            case 1:
                numTests++;
                cout << "======================================================================" << endl;
                cout << "-->> Running: testConstructor()" << endl;
                testResult = (testConstructor()) ? "Passed" : "Failed";
                cout << "-->> Result: " << testResult << endl;
                cout << "======================================================================" << endl << endl << endl;
                if(testResult == "Passed")
                    numPassed++;

                totalNumTests += numTests;
                totalNumPassed += numPassed;
                cout << "======================================================================" << endl;
                cout << "-->>  Successful Tests: " << numPassed << "/" << numTests << endl;
                cout << "======================================================================" << endl << endl;
                break;
            case 2:
                numTests++;
                cout << "======================================================================" << endl;
                cout << "-->> Running: testVmallocSimple()" << endl;
                testResult = (testVmallocSimple()) ? "Passed" : "Failed";
                cout << "-->> Result: " << testResult << endl;
                cout << "======================================================================" << endl << endl << endl;
                if(testResult == "Passed")
                    numPassed++;

                numTests++;
                cout << "======================================================================" << endl;
                cout << "-->>  Running: testVmallocFill()" << endl;
                testResult = (testVmallocFill()) ? "Passed" : "Failed";
                cout << "-->>  Result: " << testResult << endl;
                cout << "======================================================================" << endl << endl << endl;
                if(testResult == "Passed")
                    numPassed++;

                numTests++;
                cout << "======================================================================" << endl;
                cout << "-->>  Running: testVmallocOverflow()" << endl;
                testResult = (testVmallocOverflow()) ? "Passed" : "Failed";
                cout << "-->>  Result: " << testResult << endl;
                cout << "======================================================================" << endl << endl << endl;
                if(testResult == "Passed")
                    numPassed++;

                totalNumTests += numTests;
                totalNumPassed += numPassed;
                cout << "======================================================================" << endl;
                cout << "-->>  Successful Tests: " << numPassed << "/" << numTests << endl;
                cout << "======================================================================" << endl << endl;
                break;
            case 3:
                numTests++;
                cout << "======================================================================" << endl;
                cout << "-->> Running: testVcallocSimple()" << endl;
                testResult = (testVcallocSimple()) ? "Passed" : "Failed";
                cout << "-->> Result: " << testResult << endl;
                cout << "======================================================================" << endl << endl << endl;
                if(testResult == "Passed")
                    numPassed++;

                numTests++;
                cout << "======================================================================" << endl;
                cout << "-->>  Running: testVcallocFill()" << endl;
                testResult = (testVcallocFill()) ? "Passed" : "Failed";
                cout << "-->>  Result: " << testResult << endl;
                cout << "======================================================================" << endl << endl << endl;
                if(testResult == "Passed")
                    numPassed++;

                numTests++;
                cout << "======================================================================" << endl;
                cout << "-->>  Running: testVcallocOverflow()" << endl;
                testResult = (testVcallocOverflow()) ? "Passed" : "Failed";
                cout << "-->>  Result: " << testResult << endl;
                cout << "======================================================================" << endl << endl << endl;
                if(testResult == "Passed")
                    numPassed++;

                totalNumTests += numTests;
                totalNumPassed += numPassed;
                cout << "======================================================================" << endl;
                cout << "-->>  Successful Tests: " << numPassed << "/" << numTests << endl;
                cout << "======================================================================" << endl << endl;
                break;
            case 4:
                numTests++;
                cout << "======================================================================" << endl;
                cout << "-->>  Running: testVfreeSimple()" << endl;
                testResult = (testVfreeSimple()) ? "Passed" : "Failed";
                cout << "-->>  Result: " << testResult << endl;
                cout << "======================================================================" << endl << endl << endl;
                if(testResult == "Passed")
                    numPassed++;

                totalNumTests += numTests;
                totalNumPassed += numPassed;
                cout << "======================================================================" << endl;
                cout << "-->>  Successful Tests: " << numPassed << "/" << numTests << endl;
                cout << "======================================================================" << endl << endl;
                break;
            case 5:
                numTests++;
                cout << "======================================================================" << endl;
                cout << "-->>  Running: testVsizeof()" << endl;
                testResult = (testVsizeof()) ? "Passed" : "Failed";
                cout << "-->>  Result: " << testResult << endl;
                cout << "======================================================================" << endl << endl << endl;
                if(testResult == "Passed")
                    numPassed++;

                numTests++;
                cout << "======================================================================" << endl;
                cout << "-->>  Running: testVsizeofNULL()" << endl;
                testResult = (testVsizeofNULL()) ? "Passed" : "Failed";
                cout << "-->>  Result: " << testResult << endl;
                cout << "======================================================================" << endl << endl << endl;
                if(testResult == "Passed")
                    numPassed++;

                totalNumTests += numTests;
                totalNumPassed += numPassed;
                cout << "======================================================================" << endl;
                cout << "-->>  Successful Tests: " << numPassed << "/" << numTests << endl;
                cout << "======================================================================" << endl << endl;
                break;
            case 6:
                numTests++;
                cout << "======================================================================" << endl;
                cout << "-->>  Running: testPrintHeapState()" << endl;
                testResult = (testPrintHeapState()) ? "Passed" : "Failed";
                cout << "-->>  Result: " << testResult << endl;
                cout << "======================================================================" << endl << endl << endl;
                if(testResult == "Passed")
                    numPassed++;

                totalNumTests += numTests;
                totalNumPassed += numPassed;
                cout << "======================================================================" << endl;
                cout << "-->>  Successful Tests: " << numPassed << "/" << numTests << endl;
                cout << "======================================================================" << endl << endl;
                break;
            case 7:
                numTests++;
                cout << "======================================================================" << endl;
                cout << "-->>  Running: testMassFunctCombo()" << endl;
                testResult = (testMassFunctCombo()) ? "Passed" : "Failed";
                cout << "-->>  Result: " << testResult << endl;
                cout << "======================================================================" << endl << endl << endl;
                if(testResult == "Passed")
                    numPassed++;

                totalNumTests += numTests;
                totalNumPassed += numPassed;
                cout << "======================================================================" << endl;
                cout << "-->>  Successful Tests: " << numPassed << "/" << numTests << endl;
                cout << "======================================================================" << endl << endl;
                break;
            default:
                break;
        }
    }

    cout << "======================================================================" << endl;
    cout << "-->>  Overall Successful Tests: " << totalNumPassed << "/" << totalNumTests << endl;
    cout << "======================================================================" << endl << endl;

    return 0;
}

/**
 * menu provides the user with a menu to select from via entering the
 * corresponding number.
 *
 * It returns a whole number (int).
 * It takes no parameters.
 */
int menu() {
    int selection;

    cout << " -Available Tests-" << endl;
    cout << " 1. Constructor" << endl;
    cout << " 2. vmalloc()" << endl;
    cout << " 3. vcalloc()" << endl;
    cout << " 4. vfree()" << endl;
    cout << " 5. vsizeof()" << endl;
    cout << " 6. printHeapState()" << endl;
    cout << " 7. MassFunctionCombo" << endl;
    cout << " 8. Quit" << endl;

    cout << " Enter a test number: ";
    cin >> selection;
    cout << endl << endl;

    if(!cin || selection < 1 || selection > 8)
        selection = 8;

    return selection;
}

/**
 * testConstructor creates an object of MemHeap.
 *
 * The test passes is an object is created.
 *
 * It returns a boolean value (true/false).
 * It takes no parameters.
 */
bool testConstructor()
{
    MemHeap heapObj;
    return true;
}

/**
 * testVmallocSimple creates a char, int, and double using vmalloc and assigns them values.
 * A second int is attempted with the size 0 to cause exception throw.
 *
 * The test passes by checking the char, int, and doubles values and whether an exception
 * was caught.
 *
 * It returns a boolean value (true/false).
 * It takes no parameters.
 */
bool testVmallocSimple()
{
    bool result = false;
    MemHeap heapObj;

    cout << "\nCreating char...." << endl;
    char *myNewChar = (char*)heapObj.vmalloc(sizeof(char));
    *myNewChar = 'a';
    cout << "Summary of char: Value = " << *myNewChar << ", Address = " << (int*)myNewChar << ", Size = " << heapObj.vsizeof(myNewChar) << endl;

    cout << "\nCreating int...." << endl;
    int *myNewInt = (int*)heapObj.vmalloc(sizeof(int));
    *myNewInt = 123456;
    cout << "Summary of int: Value = " << *myNewInt << ", Address = " << myNewInt << ", Size = " << heapObj.vsizeof(myNewInt) << endl;

    cout << "\nCreating double...." << endl;
    double *myNewDouble = (double*)heapObj.vmalloc(sizeof(double));
    *myNewDouble = 12.3456;
    cout << "Summary of double: Value = " << *myNewDouble << ", Address = " << myNewDouble << ", Size = " << heapObj.vsizeof(myNewDouble) << endl;

    try {
        int *myNewInt2 = (int*)heapObj.vmalloc(0)   ;
    } catch (const char* msg) {
        cout << msg << endl;
        result = true;
    }
    
    result = (*myNewChar == 'a' && *myNewInt == 123456 && *myNewDouble == 12.3456 && result) ? true : false;
    return result;
}

/**
 * testVmallocFill creates an array of chars using vmalloc to the exact size
 * of the allowed memory size.
 *
 * The test passes by checking the first and last assigned values of the array.
 *
 * It returns a boolean value (true/false).
 * It takes no parameters.
 */
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

    cout << "\nCreating char[" << numChars << "]...." << endl;
    char *myNewCharArray = (char*)heapObj.vmalloc(sizeof(char) * (numChars));
    for(int i = 0; i < numChars; i += 2) {
        myNewCharArray[i] = 'a';
        myNewCharArray[i + 1] = 'b';
    }
    cout << "Summary of char[]: Value @ [0] = " << myNewCharArray[0] << ", Address = " << (int*)myNewCharArray << ", Size = " << heapObj.vsizeof(myNewCharArray) << endl;

    bool result = (myNewCharArray[0] == 'a' && myNewCharArray[numChars - 1] == 'b') ? true : false;
    return result;
}

/**
 * testVmallocOverflow creates an array of ints using vmalloc to the size of
 * the total memory.
 *
 * The test passes if an exception is caught when attempting to create the array.
 *
 * It returns a boolean value (true/false).
 * It takes no parameters.
 */
bool testVmallocOverflow()
{
    bool result = false;
    MemHeap heapObj;

    cout << "\nCreating int[" << TEST_HEAP_SIZE / sizeof(int) << "]...." << endl;
    try {
        int *myNewIntArray = (int*)heapObj.vmalloc(sizeof(int) * (TEST_HEAP_SIZE / sizeof(int)));
    } catch (const char* msg) {
        cout << msg << endl;
        result = true;
    }

    return result;
}

/**
 * testVcallocSimple creates an int and double using vcalloc and assigns them values.
 *
 * The test passes by checking the int and doubles values.
 *
 * It returns a boolean value (true/false).
 * It takes no parameters.
 */
bool testVcallocSimple()
{
    MemHeap heapObj;

    cout << "\nCreating int...." << endl;
    int *myNewInt = (int*)heapObj.vcalloc(sizeof(int));
    cout << "Summary of int: Address = " << myNewInt << ", Size = " << heapObj.vsizeof(myNewInt) << endl;
    cout << "  Before assignment: Value = " << *myNewInt << ", Bits = ";
    char *blockByte = (char*)myNewInt;
    for(int i = 0; i < heapObj.vsizeof(myNewInt); i++, blockByte++)
        cout << *blockByte;
    cout << endl;
    *myNewInt = 123456;
    cout << "  After assignment: Value = " << *myNewInt << ", Bits = ";
    blockByte = (char*)myNewInt;
    for(int i = 0; i < heapObj.vsizeof(myNewInt); i++, blockByte++)
        cout << *blockByte;
    cout << endl;

    cout << "\nCreating double...." << endl;
    double *myNewDouble = (double*)heapObj.vcalloc(sizeof(double));
    cout << "Summary of double: Address = " << myNewDouble << ", Size = " << heapObj.vsizeof(myNewDouble) << endl;
    cout << "  Before assignment: Value = " << *myNewDouble << ", Bits = ";
    blockByte = (char*)myNewDouble;
    for(int i = 0; i < heapObj.vsizeof(myNewDouble); i++, blockByte++)
        cout << *blockByte;
    cout << endl;
    *myNewDouble = 12.3456;
    cout << "  After assignment: Value = " << *myNewDouble << ", Bits = ";
    blockByte = (char*)myNewDouble;
    for(int i = 0; i < heapObj.vsizeof(myNewDouble); i++, blockByte++)
        cout << *blockByte;
    cout << endl;

    bool result = (*myNewInt == 123456 && *myNewDouble == 12.3456) ? true : false;
    return result;
}

/**
 * testVcallocFill creates an array of chars using vcalloc to the exact size
 * of the allowed memory size.
 *
 * The test passes by checking the first and last assigned values of the array.
 *
 * It returns a boolean value (true/false).
 * It takes no parameters.
 */
bool testVcallocFill()
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

    cout << "\nCreating char[" << numChars << "]...." << endl;
    char *myNewCharArray = (char*)heapObj.vcalloc(sizeof(char) * (numChars));
    for(int i = 0; i < numChars; i += 2) {
        myNewCharArray[i] = 'a';
        myNewCharArray[i + 1] = 'b';
    }
    cout << "Summary of char[]: Value @ [0] = " << myNewCharArray[0] << ", Address = " << (int*)myNewCharArray << ", Size = " << heapObj.vsizeof(myNewCharArray) << endl;

    bool result = (myNewCharArray[0] == 'a' && myNewCharArray[numChars - 1] == 'b') ? true : false;
    return result;
}

/**
 * testVcallocOverflow creates an array of ints using vcalloc to the size of
 * the total memory.
 *
 * The test passes if an exception is caught when attempting to create the array.
 *
 * It returns a boolean value (true/false).
 * It takes no parameters.
 */
bool testVcallocOverflow()
{
    bool result = false;
    MemHeap heapObj;

    cout << "\nCreating int[" << TEST_HEAP_SIZE / sizeof(int) << "]...." << endl;
    try {
        int *myNewIntArray = (int*)heapObj.vcalloc(sizeof(int) * (TEST_HEAP_SIZE / sizeof(int)));
    } catch (const char* msg) {
        cout << msg << endl;
        result = true;
    }

    return result;
}

/**
 * testVfreeSimple creates an int and a double using vmalloc. The int and double are
 * then freed from use via vfree.
 *
 * The test passes if no errors occur however it is up to testers discretion to view
 * outputs for correct functionality.
 *
 * It returns a boolean value (true/false).
 * It takes no parameters.
 */
bool testVfreeSimple()
{
    MemHeap heapObj;

    cout << "\nCreating int...." << endl;
    int *myNewInt = (int*)heapObj.vmalloc(sizeof(int));
    *myNewInt = 123456;
    cout << "Summary of int: Value = " << *myNewInt << ", Address = " << myNewInt << ", Size = " << heapObj.vsizeof(myNewInt) << endl;

    cout << "\nCreating double...." << endl;
    double *myNewDouble = (double*)heapObj.vmalloc(sizeof(double));
    *myNewDouble = 12.3456;
    cout << "Summary of double: Value = " << *myNewDouble << ", Address = " << myNewDouble << ", Size = " << heapObj.vsizeof(myNewDouble) << endl;

    cout << "\nFreeing int" << endl;
    heapObj.vfree(myNewInt);

    cout << "\nFreeing.....double" << endl;
    heapObj.vfree(myNewDouble);

    cout << endl;
    heapObj.printHeapState();

    return true;
}

/**
 * testVsizeof creates an int using vmalloc and retrieves its size via vsizeof function.
 *
 * The test passes if the correct size is returned.
 *
 * It returns a boolean value (true/false).
 * It takes no parameters.
 */
bool testVsizeof()
{
    MemHeap heapObj;

    cout << "\nCreating int...." << endl;
    int *myNewInt = (int*)heapObj.vmalloc(sizeof(int));
    *myNewInt = 123456;
    cout << "Summary of int: Value = " << *myNewInt << ", Address = " << myNewInt << ", Size = " << heapObj.vsizeof(myNewInt) << endl;

    bool result = (heapObj.vsizeof(myNewInt) == sizeof(int)) ? true : false;
    return result;
}

/**
 * testVsizeofNULL attempts to pass NULL to the vsizeof function.
 *
 * The test passes if an exception is caught.
 *
 * It returns a boolean value (true/false).
 * It takes no parameters.
 */
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

/**
 * testPrintHeapState creates an int using vmalloc and then outputs the heap state
 * via printHeapState function.
 *
 * The test passes if no errors occur however it is up to testers discretion to view
 * outputs for correct functionality.
 *
 * It returns a boolean value (true/false).
 * It takes no parameters.
 */
bool testPrintHeapState()
{
    MemHeap heapObj;

    cout << "\nCreating int...." << endl;
    int *myNewInt = (int*)heapObj.vmalloc(sizeof(int));
    *myNewInt = 123456;
    cout << "Summary of int: Value = " << *myNewInt << ", Address = " << myNewInt << ", Size = " << heapObj.vsizeof(myNewInt) << endl;

    heapObj.printHeapState();

    return true;
}

/**
 * testMassFunctCombo combines vmalloc, vcalloc, vfree, vsizeof and printHeapState
 * function calls into one test where different size memory blocks are created and
 * freed from different locations of the memory heap.
 *
 * The test passes if no errors occur however it is up to testers discretion to view
 * outputs for correct functionality.
 *
 * It returns a boolean value (true/false).
 * It takes no parameters.
 */
bool testMassFunctCombo()
{
    MemHeap heapObj;
    
    cout << "\nCreating int...." << endl;
    int *myNewInt = (int*)heapObj.vmalloc(sizeof(int));
    *myNewInt = 123456;
    cout << "Summary of int: Value = " << *myNewInt << ", Address = " << myNewInt << ", Size = " << heapObj.vsizeof(myNewInt) << endl;

    cout << "\nCreating int2...." << endl;
    int *myNewInt2 = (int*)heapObj.vmalloc(sizeof(int));
    *myNewInt2 = 654321;
    cout << "Summary of int2: Value = " << *myNewInt2 << ", Address = " << myNewInt2 << ", Size = " << heapObj.vsizeof(myNewInt2) << endl;

    cout << "\nCreating int3...." << endl;
    int *myNewInt3 = (int*)heapObj.vmalloc(sizeof(int));
    *myNewInt3 = 112233;
    cout << "Summary of int3: Value = " << *myNewInt3 << ", Address = " << myNewInt3 << ", Size = " << heapObj.vsizeof(myNewInt3) << endl;

    cout << "\nCreating double...." << endl;
    double *myNewDouble = (double*)heapObj.vcalloc(sizeof(double));
    *myNewDouble = 12.3456;
    cout << "Summary of double: Value = " << *myNewDouble << ", Address = " << myNewDouble << ", Size = " << heapObj.vsizeof(myNewDouble) << endl;

    cout << endl;
    heapObj.printHeapState();

    cout << "\nFreeing int2" << endl;
    heapObj.vfree(myNewInt2);

    cout << endl;
    heapObj.printHeapState();

    cout << "\nCreating char...." << endl;
    char *myNewChar = (char*)heapObj.vmalloc(sizeof(char));
    *myNewChar = 'a';
    cout << "Summary of char: Value = " << *myNewChar << ", Address = " << (int*)myNewChar << ", Size = " << heapObj.vsizeof(myNewChar) << endl;

    cout << endl;
    heapObj.printHeapState();

    cout << "\nFreeing int3" << endl;
    heapObj.vfree(myNewInt3);

    cout << endl;
    heapObj.printHeapState();

    cout << "\nCreating long[9]...." << endl;
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
    cout << "Summary of long[]: Address = " << (long*)myLongArray << ", Size = " << heapObj.vsizeof(myLongArray) << endl;
    for(int i = 0; i < 9; i++)
        cout << "long[" << i << "] = " << myLongArray[i] << " @ address: " << &myLongArray[i] << endl;

    cout << endl;
    heapObj.printHeapState();

    return true;
}