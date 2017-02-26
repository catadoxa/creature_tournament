/*********************************************************************
 ** Program Filename: blue_men.hpp
 ** Author: Joshua Kluthe
 ** Date: 02.14.2016
 ** Description: Declaration of the Blue_men creature, derived from the abstract Creature
 ** class. 
 ** Input:
 ** Output:
**********************************************************************/
#ifndef BLUE_MEN_HPP
#define BLUE_MEN_HPP

#include "creature.hpp"

class Blue_Men : public Creature {
	
	private:
	
		int mob_member;
		
	public:
	
/*********************************************************************
 ** Function: Blue_Men()
 ** Description: sets armor = 3, strength = 12, mob_member = 4
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
		Blue_Men();

/*********************************************************************
 ** Function: virtual void attack(Creature *attacked) = 0
 ** Description: calls roll() with 2 10 sided dice.
 ** Parameters: Creature *attacked
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
		void attack(Creature *attacked);

/*********************************************************************
 ** Function: int defense()
 ** Description: This calls roll() with six-sided dice. The number of dice is given by
 ** dice = (strength + mob_member – 1)/mob_member. This gives the Nac Mac Feegle
 ** 3 dice for strength >= 9, 2 dice for 4 < strength < 9, and 1 die strength <= 4.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/	
		int defense();

};

#endif