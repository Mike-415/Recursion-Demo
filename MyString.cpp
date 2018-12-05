/*
 Name:       Michael Gonzalez
 Class:      cs110b
 Instructor: Dave Harden
 File:       MyString.cpp

 Class Invariant:

   The MyString class contains one data member: a char pointer named myString
   This data member stores c-strings and it's used
   in various operations such as relational operations.
 */
#include "MyString.h"
#include <cstring>
#include <iostream>
#include <fstream>

namespace cs_mystring{
    MyString::MyString(){
        myString = new char[1];
        strcpy(myString, "");
    }






    MyString::MyString(const char *inMyString) {
        myString = new char[strlen(inMyString) + 1];
        strcpy(myString, inMyString);
    }






    MyString::MyString(const MyString& otherString) {
        myString = new char[strlen(otherString.myString) + 1];
        strcpy(myString, otherString.myString);
    }






    MyString::~MyString() {
        delete [] myString;
    }






    int MyString::length() const {
        return strlen(myString);
    }






    void MyString::read(std::ifstream& inStream, const char delimiter){
        char tempString[MyString::MAX_INPUT_SIZE + 1];
        inStream.getline(tempString, MyString::MAX_INPUT_SIZE, delimiter);
        delete [] this->myString;
        this->myString = new char[ std::strlen(tempString) + 1 ];
        strcpy(this->myString, tempString);
    }






    std::ostream& operator<<(std::ostream& leftOS, const MyString& rightOperand) {
        leftOS << rightOperand.myString;
        return leftOS;
    }






    std::istream& operator>>(std::istream& leftIS, MyString& rightOperand) {
        char tempString[MyString::MAX_INPUT_SIZE + 1];
        leftIS >> tempString;
        delete [] rightOperand.myString;
        rightOperand.myString = new char[strlen(tempString) + 1];
        strcpy(rightOperand.myString, tempString);
        return  leftIS;
    }






    MyString MyString::operator=(const MyString& right) {
        if ( this != &right ) {
            delete [] myString;
            myString = new char[strlen(right.myString) + 1];
            strcpy(myString, right.myString);
        }
        return *this;
    }






    char MyString::operator[](int index) const {
        assert(index >= 0 && index < strlen(myString));
        return myString[index];
    }






    char& MyString::operator[](int index) {
        assert(index >= 0 && index < strlen(myString));
        return myString[index];
    }






    bool operator<(const MyString& leftOperand, const MyString& rightOperand) {
        return  strcmp(leftOperand.myString, rightOperand.myString) < 0;
    }






    bool operator>(const MyString& leftOperand, const MyString& rightOperand){
        return strcmp(leftOperand.myString, rightOperand.myString) > 0;
    }






    bool operator<=(const MyString& leftOperand, const MyString& rightOperand){
        return strcmp(leftOperand.myString, rightOperand.myString) <= 0;
    }






    bool operator>=(const MyString& leftOperand, const MyString& rightOperand){
        return strcmp(leftOperand.myString, rightOperand.myString) >= 0;
    }






    bool operator!=(const MyString& leftOperand, const MyString& rightOperand){
        return strcmp(leftOperand.myString, rightOperand.myString) != 0;
    }






    bool operator==(const MyString& leftOperand, const MyString& rightOperand){
        return strcmp(leftOperand.myString, rightOperand.myString) == 0;

    }






    MyString operator+(const MyString& leftOperand, const MyString& rightOperand){
        MyString combinedString;
        strcpy(combinedString.myString, leftOperand.myString);
        strcat(combinedString.myString, rightOperand.myString);
        return combinedString;
    }






    MyString MyString::operator+=(const MyString& rightOperand){
        *this = *this + rightOperand;
        return *this;
    }
}


