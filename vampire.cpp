/*********************************************************************
 ** Program Filename: vampire.cpp
 ** Author: Joshua Kluthe
 ** Date: 02.14.2016
 ** Description: Definition of Vampire creature, derived from the abstract Creature
 ** class. 
 ** Input:
 ** Output:
**********************************************************************/

#include "vampire.hpp"

/*********************************************************************
 ** Function: Vampire()
 ** Description: Constructs a Vampire() with strength = 18, armor = 1
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/	
Vampire::Vampire() {

	strength = 18;
	armor = 1;
	
}

/*********************************************************************
 ** Function: void attack(Creature *attacked)
 ** Description: calls roll with 1 12 sided dice. Calls take_damage() on the attacked
 ** Parameters: Creature *attacked
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/	
void Vampire::attack(Creature *attacked) {

	int damage = 0;
	int die_sides = 12;
	int dice = 1;
	
	damage += roll(die_sides, dice);
	
	std::cout << "Vampire attacks with " << damage << " damage!" << std::endl;
	
	attacked->take_damage(damage, this);
	
}	 

/*********************************************************************
 ** Function: void take_damage(int damage, Creature *attacker, bool fatal = false)
 ** Description: calls defense and Creature::take_damage as appropriate. If defense
 ** returns a -1, vampire has charmed opponent and takes no damage. Counterattacks.
 ** Parameters: int damage, Creature *attacker, bool fatal = false
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/	
void Vampire::take_damage(int damage, Creature *attacker, bool fatal) {
	
	if(strength <= 0)
	
		dead();
		
	else {
	
		int defend = defense();
		
		/*only called if vampire failed to charm opponent*/
		if(defend >= 0)
			damage -= defend;
			
		/*if charm succeeded, damage = 0*/
		else
			damage = 0;
			
		if(damage >= 0)
			Creature::take_damage(damage, fatal);
		else
			std::cout << "The creature takes no damage!" << std::endl;
		
		if(strength > 0) {
		
			std::cout << "Defending creature has " << strength << " strength "
					<< "and will now attack.\n" << std::endl;
					
			wait();
			attack(attacker);
			
		} else
			dead("The creature is slain!");
	}
	
}

/*********************************************************************
 ** Function: int defense()
 ** Description: calls roll() on a two sided die (AKA coinflip). One result leads to the 
 ** vampire charming its, and function returns -1 to indicate. The other result provides 
 ** defense as normal, with 1 6 sided die and armor added.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/	
int Vampire::defense() {

	int defense = armor;
	int die_sides = 6;
	int dice = 1;
	
	/*flip a coin to see if the vampire charms its opponent*/
	if(roll(2, 1) == 2) {
	
		std::cout << "Vampire charms its attacker!" << std::endl;
		defense = -1;
	
	/*else defend normally*/
	} else {
	
		defense += roll(die_sides, dice);
		std::cout << "Vampire total defense is " << defense << std::endl;
		
	}
	
	return defense;
}