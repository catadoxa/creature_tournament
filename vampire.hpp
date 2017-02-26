/*********************************************************************
 ** Program Filename: vampire.hpp
 ** Author: Joshua Kluthe
 ** Date: 02.14.2016
 ** Description: Declaration of Vampire creature, derived from the abstract Creature
 ** class. 
 ** Input:
 ** Output:
**********************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "creature.hpp"

class Vampire : public Creature {
	
	private:
	
	public:
	
/*********************************************************************
 ** Function: Vampire()
 ** Description: Constructs a Vampire() with strength = 18, armor = 1
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/	
		Vampire();
		
/*********************************************************************
 ** Function: void attack(Creature *attacked)
 ** Description: calls roll with 1 12 sided dice. Calls take_damage() on the attacked
 ** Parameters: Creature *attacked
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/	
		void attack(Creature *attacked);

/*********************************************************************
 ** Function: int defense()
 ** Description: calls roll() on a two sided die (AKA coinflip). One result leads to the 
 ** vampire charming its, and function returns -1 to indicate. The other result provides 
 ** defense as normal, with 1 6 sided die and armor added.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/	
		int defense();

/*********************************************************************
 ** Function: void take_damage(int damage, Creature *attacker, bool fatal = false)
 ** Description: calls defense and Creature::take_damage as appropriate. If defense
 ** returns a -1, vampire has charmed opponent and takes no damage. Counterattacks.
 ** Parameters: int damage, Creature *attacker, bool fatal = false
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/	
		void take_damage(int damage, Creature *attacker, bool fatal = false);

};

#endif