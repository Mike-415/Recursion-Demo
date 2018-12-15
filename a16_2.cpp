/*
    Name:       Michael Gonzalez
    Class:      cs110b
    Instructor: Dave Harden
    File:       a16_2.cpp

    This file contains the following functions:

    void adjustCharacters(MyString &myString, int &lowerBound, int &upperBound);
    bool isAPalindrome(MyString& myString, int lowerBound, int upperBound);
    void displayPalindromeResults(bool isPalindrome, const MyString& testString);



 */
#include <cstring>
#include <iostream>
#include "MyString.h"
using namespace cs_mystring;

void adjustCharacters(MyString &myString, int &lowerBound, int &upperBound);
bool isAPalindrome(MyString& myString, int lowerBound, int upperBound);
void displayPalindromeResults(bool isPalindrome, const char* originalString);

int main(){
    char initialCString[] = "Able was I, ere I saw Elba";
    int myStringSize = strlen(initialCString);
    MyString myString(initialCString);
    bool result = isAPalindrome(myString, 0, myStringSize-1);
    displayPalindromeResults(result, initialCString);
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







void displayPalindromeResults(bool isPalindrome, const char* originalString) {
    if(isPalindrome){
        std::cout << originalString << " is a palindrome" << std::endl;
    } else {
        std::cout << originalString << " is not a palindrome" << std::endl;
    }
}

/*****************************************
OUTPUT:
Able was I, ere I saw Elba is a palindrome
*****************************************/

