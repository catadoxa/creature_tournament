/*********************************************************************
 ** Program Filename: harry_potter.cpp
 ** Author: Joshua Kluthe
 ** Date: 02.14.2016
 ** Description: Definition of harry_potter creature, derived from the abstract Creature
 ** class. 
 ** Input:
 ** Output:
**********************************************************************/

#include "harry_potter.hpp"

/*********************************************************************
 ** Function: Harry_Potter()
 ** Description: Constructs a Harry_Potter with strength = 10, armor = 0; hogwarts = false
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
Harry_Potter::Harry_Potter() {
	
	strength = 10;
	armor = 0;
	hogwarts = false;
	
}
	
/*********************************************************************
 ** Function: void attack(Creature *attacked)
 ** Description: calls roll with 2 6 sided dice. Calls take_damage() on the attacked
 ** Parameters: Creature *attacked
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/	
void Harry_Potter::attack(Creature *attacked) {

	int damage = 0;
	int die_sides = 6;
	int dice = 2;
	
	damage += roll(die_sides, dice);
	
	std::cout << "Harry_Potter attacks with " << damage << " damage!" << std::endl;
	
	attacked->take_damage(damage, this);
	
}	

/*********************************************************************
 ** Function: int defense()
 ** Description: This calls roll() with 2 6 sided dice, adds armor, and returns.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/	
int Harry_Potter::defense() {

	int defense = armor;
	int die_sides = 6;
	int dice = 2;
	
	defense += roll(die_sides, dice);
	
	std::cout << "Harry Potter's total defense is " << defense << std::endl;
	
	return defense;
	
} 

/*********************************************************************
 ** Function: void take_damage(int damage, Creature *attacker, bool fatal = false)
 ** Description: calls defense and Creature::take_damage as appropriate. The first time
 ** Harry Potter is slain, he rises again with strength = 20. Also counterattacks.
 ** Parameters: int damage, Creature *attacker, bool fatal = false
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/	
void Harry_Potter::take_damage(int damage, Creature *attacker, bool fatal) {

	if(strength <= 0)
	
		dead();
		
	else {
	
	/*take damage as appropriate*/
		int defend = defense();
		
		if(defend >= 0)
			damage -= defend;
		else
			damage = 0;
			
		if(damage >= 0)
			Creature::take_damage(damage, fatal);
		else
			std::cout << "The creature takes no damage!" << std::endl;
		
		/*Harry Potter rises from the dead the first time he dies*/
		if(strength <= 0 && hogwarts == false) {
		
			dead("Harry Potter is slain!");
			dead("Harry Potter rises again with the power of Hogwarts!");
			hogwarts = true;
			strength = 20;
			
		}
		
		if(strength > 0) {
		
			/*counterattack*/
			std::cout << "Defending creature has " << strength << " strength "
					<< "and will now attack.\n" << std::endl;
					
			wait();
			attack(attacker);
			
		} else
			dead("Harry Potter is slain!");
	}

}