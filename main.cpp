#include <iostream>
#include <cstring>
#include "MyString.h"
using namespace cs_mystring;

char* reverseWithinBounds(char *cstring, int lowerBound, int upperBound);
char* reverseCstring(char *cstring);
void adjustCharacters(MyString &myString, int &lowerBound, int &upperBound);
bool isAPalindrome(MyString& myString, int lowerBound, int upperBound);
std::string isTrue(bool result);
int* selectionSort(int *array, int position, int size);
int findSmallestIndex(int *array, int orginalIndex, int size );



int main() {
    //PART 1: REVERSE THE STRING
    char word1[] = "12345678";
    char word2[] = "1234567";
    //PART 2: PALINDROME
    char myString0[] = "Able was I, ere I saw Elna";
    int myStringSize = strlen(myString0);
    //PART 3: SELECTION SORT

    int intArr[] = {9,9,2,8,3,7,4,6,5,1,0,-1, -2};
    int INT_ARR_SIZE  = 13; //size - 1

    MyString myString(myString0);
    std::cout << reverseCstring(word1) << std::endl;
    std::cout << reverseCstring(word2) << std::endl;

    bool result = isAPalindrome(myString, 0, myStringSize-1);
    std::cout << "Palindrome?: " << isTrue(result) << std::endl;

    int *arrayPtr;
    arrayPtr = selectionSort(intArr, 0, INT_ARR_SIZE);
    for(int i = 0; i < INT_ARR_SIZE; i++){
        std::cout << arrayPtr[i];
    }
    std::cout << std::endl;
    return 0;
}

char* reverseCstring(char *cstring ) {
    int upperBound = strlen(cstring) - 1;
    return reverseWithinBounds(cstring, 0, upperBound);
}

char* reverseWithinBounds(char *cstring, int lowerBound, int upperBound){
    if(upperBound - lowerBound < 0){
        return cstring;
    }else{
        char temp = cstring[upperBound];
        cstring[upperBound] = cstring[lowerBound];
        cstring[lowerBound] = temp;
        return reverseWithinBounds(cstring, lowerBound + 1, upperBound -1);
    }
}

void adjustCharacters(MyString &myString, int &lowerBound, int &upperBound) {
    while(ispunct(myString[lowerBound]) || isspace(myString[lowerBound]) ){
        lowerBound++;
    }
    while(ispunct(myString[upperBound]) || isspace(myString[upperBound])) {
        upperBound--;
    }
    myString[lowerBound] = toupper(myString[lowerBound]);
    myString[upperBound] = toupper(myString[upperBound]);
}

bool isAPalindrome(MyString& myString, int lowerBound, int upperBound){
    if(upperBound - lowerBound <= 1){
        return true;
    }else{
        adjustCharacters(myString, lowerBound, upperBound);
        //std::cout << "lowerBound: " << myString[lowerBound] << " upperBound: " << myString[upperBound] << std::endl;
        if(myString[lowerBound] != myString[upperBound]){
            return false;
        }
        return isAPalindrome(myString, ++lowerBound, --upperBound);
    }
}

int findSmallestIndex(int *array, int orginalIndex, int size ){
    int smallestIndex = orginalIndex;
    for(int i = orginalIndex+1; i < size; i++){
        if(array[i] < array[smallestIndex]){
            smallestIndex = i;
        }
    }

    return smallestIndex;
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

std::string isTrue(bool result){
    if(result){
        return "true";
    }
    return "false";
}

/*

 */