/*********************************************************************
 ** Program Filename: utilities.cpp
 ** Author: Joshua Kluthe
 ** Update: 02.14.2016
 ** Date: 01.16.2016
 ** Description: This contains various useful utilities, such as menu display functions
 ** Input:
 ** Output:
 *********************************************************************/
 
#include "utilities.hpp"

#include <iomanip>
#include <limits>
#include <cstdio>
 
/*********************************************************************
 ** Function: int menu(std::vector<std::string> menu)
 ** Description: This takes a vector of strings with menu options, outputs them, and asks
 ** the user to choose. It returns the int choice - 1 (the vector subscript).
 ** Parameters: std::vector<std::string> menu
 ** Pre-Conditions: vector of strings exists
 ** Post-Conditions: returns the vector_subscript as the choice.
 *********************************************************************/
int menu(std::vector<std::string> menu) {
	
	/*stores the return value, which is one of the vector subscripts + 1*/
	unsigned choice;
	
	std::cout << "\n\tYour menu options are:\n\n";
	
	//repeat menu option 0
	std::cout << "\t" << std::setw(3) << 0 << ")\t" << "Repeat this menu." << std::endl;
	
	/*display the contents of menu, numbered with subscript + 1*/
	for(unsigned i = 0; i < menu.size(); i++)
		std::cout << "\t" << std::setw(3) << i + 1 << ")\t" << menu[i] << std::endl;
	
	std::cout << "\n\tEnter the number next to your choice: ";
	
	/*while loop guards against bad input*/
	while(!(std::cin >> choice)||(choice > menu.size())) {
		std::cout << "That is not a valid option.\nEnter a menu option: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	/*skip the hanging newline in the buffer*/
	std::cin.ignore();
	
	//added 1 in the out loop to make it start at 1 instead of 0, so subtract it now
	return choice - 1;

}

/*********************************************************************
 ** Function: int choose_int(std::string prompt, int start, int end
 ** Description: This takes a string asking for the user to input some int value.
 ** Parameters: std::string prompt is the string asking for input, int start is the 
 ** beginning of the range, int end is the end.
 ** Pre-Conditions:
 ** Post-Conditions: returns the int input by user
 *********************************************************************/
 int choose_int(std::string prompt, int start, int end) {
	
	/*stores the user input. Must be within range*/
	int choice;
	
	std::cout << prompt << std::endl;
	std::printf("\nEnter an integer from %d to %d: ", start, end);
	
	/*while loop guards against bad input*/
	while(!(std::cin >> choice)||(choice < start)||(choice > end)) {
		std::cout << "That is not within the range. Enter another value: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	/*skip the hanging newline in the buffer*/
	std::cin.ignore();
	return choice;
 
 }
 
/*********************************************************************
 ** Function: unsigned positive_int()
 ** Description: prompts user for an unsigned int and returns as regular int
 ** Pre-Conditions:
 ** Post-Conditions: returns the unsigned int as a regular int
**********************************************************************/
int positive_int() {
	
	/*stores the user input. Must be within range*/
	unsigned choice;
	
	std::cout << "\nEnter an integer greater than or equal to zero: ";
	
	/*while loop guards against bad input*/
	while(!(std::cin >> choice)) {
		std::cout << "That is not within the range. Enter another value: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	/*skip the hanging newline in the buffer*/
	std::cin.ignore();
	return static_cast<int>(choice);
 
}

/*********************************************************************
 ** Function: double any_double()
 ** Description: prompts user for aa double
 ** Pre-Conditions:
 ** Post-Conditions: returns the double input by user
**********************************************************************/
double any_double() {
	
	/*stores the user input. Must be within range*/
	double choice;
	
	std::cout << "\nEnter a double value: ";
	
	/*while loop guards against bad input*/
	while(!(std::cin >> choice)) {
		std::cout << "That is not a valid input. Enter another value: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	
	/*skip the hanging newline in the buffer*/
	std::cin.ignore();
	return choice;
 
}

/*********************************************************************
 ** Function: std::string any_string(std::string prompt)
 ** Description: outputs prompt asking for a string
 ** Pre-Conditions:
 ** Post-Conditions: returns the string input by user
**********************************************************************/
std::string any_string(std::string prompt) {
	
	/*stores the user input.*/
	std::string input;
	
	std::cout << "\n\t" << prompt << std::endl;
	
	/*while loop guards against bad input*/
	while(!(std::cin >> input)) {
		std::cout << "That is not a valid input. Enter another value: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	
	/*I think I need this? requires testing. skip the hanging newline in the buffer*/
	//std::cin.ignore();
	
	return input;
 
}

/*********************************************************************
 ** Function:
 ** Description:
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void enter_to_continue() {
	std::cout << "\n\tPress enter to continue.";
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}