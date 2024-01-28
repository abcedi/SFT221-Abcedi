#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

#include "Workshop3.h"

using namespace std;
using namespace seneca;

namespace seneca
{
	bool isAlpha(char c) {
		return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
	}

	bool isDigit(char c) {
		return c >= '0' && c <= '9';
	}

	void promptInput(const char* prompt, char* inputBuffer, int size) {
		do {
			cout << prompt;
			fgets(inputBuffer, size, stdin);
			if (inputBuffer[0] == '\n') {
				cout << "Invalid Entry: ";
			}
		} while (inputBuffer[0] == '\n');
	}
	void removeNewLine(char* input) {
		size_t len = strlen(input);
		if (len > 0 && input[len - 1] == '\n') {
			input[len - 1] = '\0';
		}
	}
	/*Create a function to prompt the user to enter the customer information on the command line and store it in the structure.
	This function will ensure that every field has a value and that the postal code is valid. If any are not valid, it will prompt the user until a valid value is entered.
	This function will return a structure that is guaranteed to have values in each field and have a valid postal code.*/
	Customer getCustomerData() {
		Customer customer;
		char input[100];
		cout << "Please enter the following customer information:" << endl;
		promptInput("Enter your first name: ", input, 100);
		removeNewLine(input);
		customer.firstname = input;

		promptInput("Enter your last name: ", input, 100);
		removeNewLine(input);
		customer.lastname = input;

		promptInput("Enter your address: ", input, 100);
		removeNewLine(input);
		customer.address = input;

		promptInput("Enter your city: ", input, 100);
		removeNewLine(input);
		customer.city = input;

		promptInput("Enter your province: ", input, 100);
		removeNewLine(input);
		customer.province = input;

		do {
			cout << "Enter your postal code: ";
			fgets(input, 100, stdin);
			removeNewLine(input);
			customer.postalCode = input;
		} while (!validPostalCode(customer.postalCode));

		return customer;
	
	}


	/*Create a function to test the validity of the postal code and return a Boolean true if the code is valid and a Boolean false if the code is invalid.
	It should accept postal code in upper or lower case and translate them all to upper case.
	It should also accept them with no spaces or several spaces between the groups of 3 characters.
	It will return the postal code in uppercase with one space between the groups of 3 characters.*/
	bool validPostalCode(std::string& postalCode) {
		int i = 0;
		string cleanCode;
		for (char c : postalCode) {
			if (isAlpha(c) || isDigit(c)) {
				if (c >= 'a' && c <= 'z') {
					c = c - 'a' + 'A';
				}	
				cleanCode += c;
				
			}
		}

		if (cleanCode.length() != 6) {
			return false;
		}

		for (i = 0; i < 6; i++) {
			if (i % 2 == 0) {
				if (!isAlpha(cleanCode[i])) {
					return false;
				}
			}
			else {
				if (!isDigit(cleanCode[i])) {
					return false;
				}
			}
		}
		postalCode = cleanCode.substr(0, 3) + " " + cleanCode.substr(3, 3);
		return true;
	}

}

//Create a main that invokes the function to get the data into the structure and then prints out the contents of the structure.
int main() {
	Customer customer = getCustomerData();
	cout << "You entered:" << endl;
	cout << "Name: " << customer.firstname << " " << customer.lastname << endl;
	cout << "Address: " << customer.address << endl;
	cout << "City: " << customer.city << endl;
	cout << "Province: " << customer.province << endl;
	cout << "Postal Code: " << customer.postalCode << endl;

	return 0;
}