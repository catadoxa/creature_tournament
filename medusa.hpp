/*********************************************************************
 ** Program Filename: medusa.hpp
 ** Author: Joshua Kluthe
 ** Date: 02.14.2016
 ** Description: Declaration of Medusa creature, derived from the abstract Creature
 ** class. 
 ** Input:
 ** Output:
**********************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "creature.hpp"

class Medusa : public Creature {
	
	private:
	
	public:
	
/*********************************************************************
 ** Function: Medusa()
 ** Description: Constructs a Medusa with strength = 8, armor = 3;
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
		Medusa();

/*********************************************************************
 ** Function: void attack(Creature *attacked)
 ** Description: calls roll with 2 6 sided dice. If damage = 12, Calls take_damage() 
 ** on the attacked with fatal = true, else fatal = false.
 ** Parameters: Creature *attacked
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/	
		void attack(Creature *attacked);

/*********************************************************************
 ** Function: void take_damage(int damage, Creature *attacker, bool fatal = false)
 ** Description: calls defense and Creature::take_damage as appropriate. The first time
 ** Harry Potter is slain, he rises again with strength = 20. Also counterattacks.
 ** Parameters: int damage, Creature *attacker, bool fatal = false
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/	
		int defense();

};

#endif