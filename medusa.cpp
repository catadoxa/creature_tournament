/*********************************************************************
 ** Program Filename: medusa.cpp
 ** Author: Joshua Kluthe
 ** Date: 02.14.2016
 ** Description: Definition of Medusa creature, derived from the abstract Creature
 ** class. 
 ** Input:
 ** Output:
**********************************************************************/

#include "medusa.hpp"

/*********************************************************************
 ** Function: Medusa()
 ** Description: Constructs a Medusa with strength = 8, armor = 3;
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
Medusa::Medusa() {

	strength = 8;
	armor = 3;
	
}
	 
/*********************************************************************
 ** Function: void attack(Creature *attacked)
 ** Description: calls roll with 2 6 sided dice. If damage = 12, Calls take_damage() 
 ** on the attacked with fatal = true, else fatal = false.
 ** Parameters: Creature *attacked
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/	
void Medusa::attack(Creature *attacked) {

	int damage = 0;
	int die_sides = 6;
	int dice = 2;
	
	damage += roll(die_sides, dice);
	
	/*Activate Medusa Glare ability (turns opponent to stone)*/
	if(damage == 12) {
	
		std::cout << "Medusa attacks with a fatal stony Glare!" << std::endl;
		attacked->take_damage(damage, this, true);
		
	} else {
	
		std::cout << "Medusa attacks with " << damage << " damage!" << std::endl;
		attacked->take_damage(damage, this);
		
	}
}	 

/*********************************************************************
 ** Function: int defense()
 ** Description: This calls roll() with 1 6 sided die, adds armor, and returns.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/	
int Medusa::defense() {

	int defense = armor;
	int die_sides = 6;
	int dice = 1;
	
	defense += roll(die_sides, dice);
	
	std::cout << "Medusa total defense is " << defense << std::endl;
	
	return defense;
}