/*********************************************************************
 ** Program Filename: barbarian.cpp
 ** Author: Joshua Kluthe
 ** Date: 02.14.2016
 ** Description: Definition of Barbarian creature, derived from the abstract Creature
 ** class. 
 ** Input:
 ** Output:
**********************************************************************/

#include "barbarian.hpp"

/*********************************************************************
 ** Function: Barbarian()
 ** Description: Constructs a Barbarian() with strength = 12, armor = 0
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
Barbarian::Barbarian() {

	strength = 12;
	armor = 0;
	
}
	
/*********************************************************************
 ** Function: void attack(Creature *attacked)
 ** Description: calls roll with 2 6 sided dice. Calls take_damage() on the attacked
 ** Parameters: Creature *attacked
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/		
void Barbarian::attack(Creature *attacked) {

	int damage = 0;
	int die_sides = 6;
	int dice = 2;
	
	damage += roll(die_sides, dice);
	
	std::cout << "Barbarian attacks with " << damage << " damage!" << std::endl;
	
	attacked->take_damage(damage, this);
	
}	 

/*********************************************************************
 ** Function: int defense()
 ** Description: calls roll() with 2 6 sided dice, adds armor, returns.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/	
int Barbarian::defense() {

	int defense = armor;
	int die_sides = 6;
	int dice = 2;
	
	defense += roll(die_sides, dice);
	
	std::cout << "Barbarian total defense is " << defense << std::endl;
	
	return defense;
}
