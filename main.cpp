/*
    Name:       Michael Gonzalez
    Class:      cs110b
    Instructor: Dave Harden
    File:       MyString.h

    The MyString class is used to make working with sequences of characters a little more
    convenient and less error-prone than handling raw c-strings.

    The following functions are available:

    MyString();
      post: constructs a MyString object with an empty string for the myString data member.


    MyString(const char *inMyString);
      post: constructs a MyString object with a c-string argument for the myString data member.

    MyString(const MyString& otherString);
      post: constructs a hard copy of a MyString object with another MyString object
            that provides the myString data member

    MyString();
      post: deallocates any object within the stack, usually when
            execution reaches the end of the function body.

    int length() const;
      post: returns the number of characters contained within the myString data member.

    void read(std::ifstream& inStream, const char delimiter);
      pre:  the stream reads characters below the maximum of 127
      post: the data member myString receives it's value from the file input stream

    friend std::ostream& operator<<(std::ostream& leftOS, const MyString& rightOperand);
      post: returns an output stream that contains the myString data member.

    friend std::istream& operator>>(std::istream& leftIS, MyString& rightOperand);
      post: replaces the data member myString in the right operand and returns an input stream

    MyString operator=(const MyString& right);
      post: returns a hard copy of the right MyString object


    char operator[](int index) const;
      post: returns the character within the index of the myString char array.

    char& operator[](int index);
      post: returns a reference to the left-side operand in order to assign
            it a value.

    friend bool operator<(const MyString& leftOperand, const MyString& rightOperand);
      post: Returns true if the left operand is less than to the right operand.

    friend bool operator>(const MyString& leftOperand, const MyString& rightOperand);
      post: Returns true if the left operand is greater than to the right operand.

    friend bool operator<=(const MyString& leftOperand, const MyString& rightOperand);
      post: Returns true if the left operand is less than or equal to the right operand.

    friend bool operator>=(const MyString& leftOperand, const MyString& rightOperand);
      post: Returns true if the left operand is greater than or equal to the right operand.

    friend bool operator!=(const MyString& leftOperand, const MyString& rightOperand);
      post: Returns true if the left operand is not equal to the right operand.

    friend bool operator==(const MyString& leftOperand, const MyString& rightOperand);
      post: Returns true if the left operand is equal to the right operand.

    friend MyString operator+(const MyString& leftOperand, const MyString& rightOperand);
      pre:  the left operand is a MyString object and the right operand is either a MyString object
            or a C-string
      post: returns a MyString object that contains a concatenated string from both operands

    MyString operator+=(const MyString& rightOperand);
      pre:  the left operand is a MyString and the right operand is either a MyString object or
            a C-string.
      post: the calling object will concatenate it's myString data member with that of the right
            operand
*/

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
int findSmallestIndex(int *array, int originalIndex, int size );



int main() {
    //PART 1: REVERSE THE STRING
    char word1[] = "12345678";
    char word2[] = "1234567";
    //PART 2: PALINDROME
    char myString0[] = "Able was I, ere I saw Elba";
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
    std::cout << "[ ";
    for(int i = 0; i < INT_ARR_SIZE; i++){
        std::cout << arrayPtr[i] << ((i == INT_ARR_SIZE - 1)? "": ", ");
    }
    std::cout << " ]" << std::endl;
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
        if(myString[lowerBound] != myString[upperBound]){
            return false;
        }
        return isAPalindrome(myString, ++lowerBound, --upperBound); //NOTE the function's return type vs the return function call
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

