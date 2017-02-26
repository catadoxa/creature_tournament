/*********************************************************************
 ** Program Filename: main_creature.cpp
 ** Author: Joshua Kluthe
 ** Date: 02.14.2016
 ** Description: Prints out menu options to allow the user to have two Creature derived
 ** objects fight, or to test the roll funciton of the Creature class. Uses utilities.hpp
 ** functions as well as Creature derived objects.
 ** Input:
 ** Output:
**********************************************************************/

#include "creature.hpp"
#include "barbarian.hpp"
#include "medusa.hpp"
#include "vampire.hpp"
#include "blue_men.hpp"
#include "harry_potter.hpp"


#include "utilities.hpp"
#include <string>
#include <cstdio>

/*declare functions defined below main*/
Creature * make_creature(int n);
void roll_test();
void do_battle();

/*********************************************************************
 ** Function: int main()
 ** Description: Displays user options, calls the appropriate functions.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
int main() {
		
	int choice = 0;
	
	do {
	
		choice = choose_int("\nEnter 1 to perform a roll test, 2 to do battle,"
			" or 3 to exit.", 1, 3);
	
		if(choice == 1)
			roll_test();
		else if(choice == 2)
			do_battle();
			
	} while(choice != 3);
	
	return 0;
}

/*********************************************************************
 ** Function: Creature * make_creature(int n)
 ** Description: Creates a creature of the specified type.
 ** Parameters: int n
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
Creature * make_creature(int n) {

	Creature *creature;
	
	switch(n) {
	
		case 0:
			creature = new Barbarian();
			break;
		case 1:
			creature = new Medusa();
			break;
		case 2:
			creature = new Vampire();
			break;
		case 3:
			creature = new Blue_Men();
			break;
		case 4:
			creature = new Harry_Potter();
			break;
	
	}
	return creature;

}

/*********************************************************************
 ** Function: void roll_test()
 ** Description: simulates a number of results and compares actual roll results to
 ** expected roll results.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void roll_test() {
	
	int sides, rolls;
	
	/*get user input*/
	std::cout << "\nEnter the number of sides on the die: " << std::endl;
	sides = positive_int();
	
	std::cout << "\nEnter the number of rolls to make. Larger numbers "
			<< "will get more accurate results: " << std::endl;
	rolls = positive_int();
	
	/*add up the sides on the die*/
	double sides_total = 0;
	for(int i = 1; i <= sides; i++) {
		sides_total += i;
	}
	
	/*average the sides to find the average roll value*/
	double ave_roll = sides_total/sides;
	
	/*output expected results*/
	std::printf("A die with %d sides rolls a %.1f on average, so after %d rolls the running"
			" roll total should be around %.1f.", sides, ave_roll, rolls, rolls*ave_roll);
	
	/*roll the die*/
	Creature *roller = new Barbarian();
	int total = roller->roll(sides, rolls);
	
	/*output actual results*/
	std::cout << "\n\nThe running roll total is: " << total << std::endl;
	

}

/*********************************************************************
 ** Function: void do_battle()
 ** Description: Allows user to create two creatures and have them battle to the death.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void do_battle() {

	Creature *fighter1, *fighter2;
	
	/*menu options*/
	std::vector<std::string> options(5);
	{
		options[0] = "Barbarian";
		options[1] = "Medusa";
		options[2] = "Vampire";
		options[3] = "Nac Mac Feegle";
		options[4] = "Harry Potter";
	}
	
	std::cout << "Choose the warrior that will attack first!" << std::endl;
	
	/*create attacker*/
	int first = menu(options);
	fighter1 = make_creature(first);
	
	std::cout << "\nChoose your second warrior!" << std::endl;
	
	/*create second creature, defends first*/
	int second = menu(options);
	fighter2 = make_creature(second);
	
	std::cout << "\nThe battle begins!\n" << std::endl;
	
	/*Creatures fight to the death*/
	fighter1->attack(fighter2);
}