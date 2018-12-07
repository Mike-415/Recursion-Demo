#include <cstring>
#include <iostream>
#include "MyString.h"
using namespace cs_mystring;

void adjustCharacters(MyString &myString, int &lowerBound, int &upperBound);
bool isAPalindrome(MyString& myString, int lowerBound, int upperBound);
std::string isTrue(bool result);

int main(){
    char myString0[] = "Able was I, ere I saw Elba";
    int myStringSize = strlen(myString0);
    MyString myString(myString0);
    bool result = isAPalindrome(myString, 0, myStringSize-1);
    std::cout << "Palindrome?: " << isTrue(result) << std::endl;
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