/*********************************************************************
 ** Program Filename: barbarian.hpp
 ** Author: Joshua Kluthe
 ** Date: 02.14.2016
 ** Description: Declaration of Barbarian creature, derived from the abstract Creature
 ** class. 
 ** Input:
 ** Output:
**********************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "creature.hpp"

class Barbarian : public Creature {
	
	private:
	
	public:
	
/*********************************************************************
 ** Function: Barbarian()
 ** Description: Constructs a Barbarian() with strength = 12, armor = 0
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
		Barbarian();

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
 ** Description: calls roll() with 2 6 sided dice, adds armor, returns.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/	
		int defense();

};

#endif