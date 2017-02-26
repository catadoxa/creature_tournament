/*********************************************************************
 ** Program Filename: blue_men.cpp
 ** Author: Joshua Kluthe
 ** Date: 02.14.2016
 ** Description: Definition of the Blue_men creature, derived from the abstract Creature
 ** class. 
 ** Input:
 ** Output:
**********************************************************************/

#include "blue_men.hpp"

/*********************************************************************
 ** Function: Blue_Men()
 ** Description: sets armor = 3, strength = 12, mob_member = 4
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
Blue_Men::Blue_Men() {

	strength = 12;
	armor = 3;
	mob_member = 4;
	
}
	
/*********************************************************************
 ** Function: virtual void attack(Creature *attacked) = 0
 ** Description: calls roll() with 2 10 sided dice.
 ** Parameters: Creature *attacked
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/	
void Blue_Men::attack(Creature *attacked) {

	int damage = 0;
	int die_sides = 10;
	int dice = 2;
	
	damage += roll(die_sides, dice);
	
	std::cout << "Blue Men attacks with " << damage << " damage!" << std::endl;
	
	attacked->take_damage(damage, this);
	
}	 

/*********************************************************************
 ** Function: int defense()
 ** Description: This calls roll() with six-sided dice. The number of dice is given by
 ** dice = (strength + mob_member – 1)/mob_member. This gives the Nac Mac Feegle
 ** 3 dice for strength >= 9, 2 dice for 4 < strength < 9, and 1 die strength <= 4.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/	
int Blue_Men::defense() {

	int defense = armor;
	int die_sides = 6;
	int dice = (strength + mob_member - 1)/mob_member;
	
	defense += roll(die_sides, dice);
	std::cout << "Blue Men total defense is " << defense << std::endl;
	
	return defense;
}