/*********************************************************************
 ** Program Filename: utilities.cpp
 ** Authori: Joshua Kluthe
 ** Update: 02.14.2016
 ** Date: 01.16.2016
 ** Description: This declares various useful utilities, such as menu display functions
 ** Input:
 ** Output:
**********************************************************************/

#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <iostream>
#include <vector> 


/*********************************************************************
 ** Function: int menu(std::vector<std::string> menu)
 ** Description: This takes a vector of strings with menu options, outputs them, and asks
 ** the user to choose. It returns the int choice.
 ** Parameters: std::vector<std::string> menu
 ** Pre-Conditions: vector of strings exists
 ** Post-Conditions: returns the (vector_subscript + 1) as the choice.
**********************************************************************/
int menu(std::vector<std::string> menu);

/*********************************************************************
 ** Function: int choose_int(std::string prompt, int start, int end
 ** Description: This takes a string asking for the user to input some int value.
 ** Parameters: std::string prompt is the string asking for input, int start is the 
 ** beginning of the range, int end is the end (inclusive on both).
 ** Pre-Conditions:
 ** Post-Conditions: returns the int input by user
**********************************************************************/
int choose_int(std::string prompt, int start, int end);
 
/*********************************************************************
 ** Function: double any_double()
 ** Description: prompts user for aa double
 ** Pre-Conditions:
 ** Post-Conditions: returns the double input by user
**********************************************************************/
double any_double();

/*********************************************************************
 ** Function: unsigned positive_int()
 ** Description: prompts user for an unsigned int and returns
 ** Pre-Conditions:
 ** Post-Conditions: returns the unsigned int input by user
**********************************************************************/
int positive_int();

/*********************************************************************
 ** Function: std::string any_string(std::string prompt)
 ** Description: outputs prompt asking for a string
 ** Pre-Conditions:
 ** Post-Conditions: returns the string input by user
**********************************************************************/
std::string any_string(std::string prompt);

/*********************************************************************
 ** Function:
 ** Description:
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void enter_to_continue();
 
 #endif