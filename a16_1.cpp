/*
    Name:       Michael Gonzalez
    Class:      cs110b
    Instructor: Dave Harden
    File:       a16_1.cpp

    This file contains the following functions:

    char* reverseWithinBounds(char *cstring, int lowerBound, int upperBound);
       pre:  the lower and upper bounds are both higher than zero and less than
             the size of the c-string.  The lower bound also has to be lower than
             the upper bound.

       post: returns a pointer to a c-string that is sorted in reverse order
             from the lower bound to the upper bound

    char* reverseCstring(char *cstring);
       post: returns a pointer to a c-string that is completely sorted in
             reverse order.

 */
#include <iostream>
#include <cstring>

char* reverseWithinBounds(char *cstring, int lowerBound, int upperBound);
char* reverseCstring(char *cstring);

int main(){
    //PART 1: REVERSE THE STRING
    char word1[] = "12345678";
    char word2[] = "1234567";

    std::cout << "Reverse '12345678' from 2 to 7: " << reverseWithinBounds(word1, 2, 7) << std::endl;
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


/****************************************
OUTPUT:
Reverse '12345678' from 2 to 7: 12876543
****************************************/
