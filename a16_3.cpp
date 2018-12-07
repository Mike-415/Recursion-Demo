/*
    Name:       Michael Gonzalez
    Class:      cs110b
    Instructor: Dave Harden
    File:       a16_3.cpp

    This file contains the following functions:

    int* selectionSort(int *array, int position, int size);
       pre: the position argument is greater than zero and
            less than the size of the array
       post: the return type is an int pointer which references an sorted integer array

    int findSmallestIndex(int *array, int originalIndex, int size );
       post: returns an integer that represents the index of the smallest index
             from the subset of values that range from the original index to the
             last element of the array

    void printArray(const int *array,const char *message);
        post: displays a message followed by all the elements within an array
 */

#include <iostream>
#include <cstring>
#include "MyString.h"
using namespace cs_mystring;

int* selectionSort(int *array, int position, int size);
int findSmallestIndex(int *array, int originalIndex, int size );
void printArray(const int *array,const char *message);
const int SIZE  = 13;
const char ORIGINAL_ARRAY[] = "Original array: ";
const char SORTED_ARRAY[] = "Sorted array:   ";

int main(){
    int intArr[] = {9,9,2,8,3,7,4,6,5,1,0,-1, -2};
    int *arrayPtr;
    printArray(intArr, ORIGINAL_ARRAY);
    arrayPtr = selectionSort(intArr, 0, SIZE);
    printArray(intArr, SORTED_ARRAY);
}

int* selectionSort(int *array, int position, int size){
    if(position == size){
        return array;
    }else{
        int smallestIndex = findSmallestIndex(array, position, size);
        int temp = array[position];
        array[position] = array[smallestIndex];
        array[smallestIndex] = temp;
        return selectionSort(array, ++position, size);
    }
}

int findSmallestIndex(int *array, int originalIndex, int size ){
    int smallestIndex = originalIndex;
    for(int i = originalIndex+1; i < size; i++){
        if(array[i] < array[smallestIndex]){
            smallestIndex = i;
        }
    }
    return smallestIndex;
}

void printArray(const int *array,const char *message){
    std::cout << message;
    std::cout << "[ ";
    for(int i = 0; i < SIZE; i++){
        std::cout << array[i] << ((i == SIZE - 1)? "": ", ");
    }
    std::cout << " ]" << std::endl;
}



