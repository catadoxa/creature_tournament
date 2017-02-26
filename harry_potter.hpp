/*********************************************************************
 ** Program Filename: harry_potter.hpp
 ** Author: Joshua Kluthe
 ** Date: 02.14.2016
 ** Description: Declaration of harry_potter creature, derived from the abstract Creature
 ** class. 
 ** Input:
 ** Output:
**********************************************************************/
#ifndef HARRY_POTTER_HPP
#define HARRY_POTTER_HPP

#include "creature.hpp"

class Harry_Potter : public Creature {
	
	private:
	
		bool hogwarts;
		
	public:
	
/*********************************************************************
 ** Function: Harry_Potter()
 ** Description: Constructs a Harry_Potter with strength = 10, armor = 0; hogwarts = false
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/	
		Harry_Potter();

/*********************************************************************
 ** Function: void attack(Creature *attacked)
 ** Description: calls roll with 2 6 sided dice. Calls take_damage() on the attacked
 ** Parameters: Creature *attacked
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/			
		void attack(Creature *attacked);

/*********************************************************************
 ** Function: int defense()
 ** Description: This calls roll() with 2 6 sided dice, adds armor, and returns.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/	
		int defense();

/*********************************************************************
 ** Function: void take_damage(int damage, Creature *attacker, bool fatal = false)
 ** Description: calls defense and Creature::take_damage as appropriate. The first time
 ** Harry Potter is slain, he rises again with strength = 20. Also counterattacks.
 ** Parameters: int damage, Creature *attacker, bool fatal = false
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/				 
		void take_damage(int damage, Creature *attacker, bool fatal = false);

};

#endif