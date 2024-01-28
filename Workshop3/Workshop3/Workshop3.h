#pragma once
#ifndef SENECA_WORKSHOP3_H
#define SENECA_WORKSHOP3_H

#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

namespace seneca {

    //Create a structure to store the information on the customer
    struct Customer {
        std::string firstname;
        std::string lastname;
        std::string address;
        std::string city;
        std::string province;
        std::string postalCode;
    };
    bool isAlpha(char c);

    bool isDigit(char c);

    void promptInput(const char* prompt, char* inputBuffer, int size);

    void removeNewLine(char* input);
    //Create a function to prompt the user to enter the customer information on the command line and store it in the structure.
    //This function will ensure that every field has a value and that the postal code is valid. If any are not valid, it will prompt the user until a valid value is entered.
    //This function will return a structure that is guaranteed to have values in each field and have a valid postal code.
    Customer getCustomerData();
    /*Create a function to test the validity of the postal code and return a Boolean true if the code is valid and a Boolean false if the code is invalid.
    It should accept postal code in upper or lower case and translate them all to upper case.
    It should also accept them with no spaces or several spaces between the groups of 3 characters.
    It will return the postal code in uppercase with one space between the groups of 3 characters.*/
    bool validPostalCode(std::string& postalCode);
}
#endif 

