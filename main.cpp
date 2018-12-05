#include <iostream>
#include <cstring>
#include "MyString.h"
using namespace cs_mystring;

char* reverseWithinBounds(char *cstring, int lowerBound, int upperBound);
char* reverseCstring(char *cstring);
void adjustCharacters(MyString &myString, int &lowerBound, int &upperBound);
bool isAPalindrome(MyString& myString, int lowerBound, int upperBound);
std::string isTrue(bool result);



int main() {
    char word1[] = "12345678";
    char word2[] = "1234567";
    //Used to test isAPalindrome
    char myString0[] = "Able was I, ere I saw Elna";
    int size = strlen(myString0);

    MyString myString(myString0);
    std::cout << reverseCstring(word1) << std::endl;
    std::cout << reverseCstring(word2) << std::endl;

    bool result = isAPalindrome(myString, 0, size-1);
    std::cout << "Palindrome?: " << isTrue(result) << std::endl;
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

std::string isTrue(bool result){
    if(result){
        return "true";
    }
    return "false";
}

/*
A palindrome is a string that reads the same forward and backward.
 Write a program that reads in any number of MyStrings of characters from the user
 and determines if each MyString is a palindrome.

 The user will terminate each MyString by pressing the return (or enter) button.
 The user will indicate that there are no more MyStrings by entering "quit".

To do this you must write a recursive function named isAPalindrome that takes a single MyString argument
 and two arguments that are bounds on array indices.
 The function must examine the part of the argument between the two bounds (including the bounds)
 and return true if this part of the argument is a palindrome, false if it is not a palindrome.
 The function must be recursive and must not call any other functions except
    ispunct(),
    isspace(), and
    toupper() (described below).

Do not make any changes to the MyString class (except, if necessary, to correct errors in your MyString class).
 In particular, note that the isAPalindrome() function is not part of the MyString class.
 You will be submitting only your client file containing your main() function and your isAPalindrome() function.
 Do not submit your MyString class. Do not use the C++ string class.

Follow this sample output closely:

Enter a string: Able was I, ere I saw Elba
Able was I, ere I saw Elba is a palindrome.
Enter a string: peanut butter
peanut butter is not a palindrome.
Enter a string: quit
In determining whether a string is a palindrome, this function must consider uppercase and lowercase letters to be the same and ignore punctuation characters and whitespace characters. You must not modify the argument in any way or make a copy of the argument to accomplish this. The simplest way to handle uppercase/lowercase issues is to make everything uppercase on the fly, right at the instant that you are comparing the two characters.

Hints:
You will want to use three functions that are in the cctype library (i.e. you must #include cctype to use them).
 They are
 ispunct(char), a bool function which returns true if its argument is a punctuation mark and false otherwise,
 isspace(char), which returns true if its argument is a whitespace character and false otherwise, and
 toupper(char), which returns the uppercase equivalent of its argument (without changing the argument itself).

I strongly suggest that you first write this program so that it works in the general case
 (i.e. assuming that all letters are uppercase and
 no characters are punctuation characters or whitespace characters),
 and then add code to handle the uppercase/lowercase and punctuation/whitespace issues.

Make sure you try a palindrome that starts and ends with the same letter but is not a palindrome.
 Returning a false positive in this case is one of the most common errors that students make.

Another common error is calling this value-returning function as if it was a void function.
 You can't say "isAPalindrome(str1, leftBound, highBound);" on a line by itself. It doesn't do anything.

Also, make sure that every case in your function has a return statement.
 Often students submit programs that worked perfectly for them, but they were just getting lucky,
 and the computer was returning the correct value by chance when there was no return statement.

 */