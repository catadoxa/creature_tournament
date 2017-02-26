/*********************************************************************
 ** Program Filename: creature.hpp
 ** Author: Joshua Kluthe
 ** Date: 02.14.2016
 ** Description: Declaration of the abstract Creature class. Objects derived from Creature
 ** can attack, defend, and take damage in a Dungeons and Dragons kind of way.
 ** Input:
 ** Output:
**********************************************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>

/*********************************************************************
 ** Function:
 ** Description:
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/

class Creature {

	protected:
		int strength;
		int armor;
		
	public:

/*********************************************************************
 ** Function: Creature()
 ** Description: Constructs a creature with a seed for the random nature of the roll()
 ** function.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
		Creature();
	
/*********************************************************************
 ** Function: virtual void attack(Creature *attacked) = 0
 ** Description: calls roll() with the appropriate attack dice for each Derived Creature.
 ** Also checks for any special abilities, and then calls take_damage on the attacked
 ** creature.
 ** Parameters: Creature *attacked
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
		virtual void attack(Creature *attacked) = 0;

/*********************************************************************
 ** Function: virtual int defense() = 0
 ** Description: This calls roll() with the appropriate dice for each derived creature.
 ** must be overridden due to different dice. Also checks special abilities, adds armor.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/			 
		virtual int defense() = 0;

/*********************************************************************
 ** Function: void take_damage(int damage, bool fatal = false)
 ** Description: subtracts damage from the creature strength. If fatal == true, sets
 ** strength = 0
 ** Parameters: int damage, bool fatal = false
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/			 
		void take_damage(int damage, bool fatal = false);

/*********************************************************************
 ** Function: virtual void take_damage(int damage, Creature *attacker, bool fatal = false)
 ** Description: This allows the creature to counterattack and perform other actions
 ** if it takes damage from another creature.
 ** Parameters: int damage, Creature *attacker, bool fatal = false
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/			 
		virtual void take_damage(int damage, Creature *attacker, bool fatal = false);

/*********************************************************************
 ** Function: int roll(int sides, int dice)
 ** Description: returns the added total of a simulated dice roll.
 ** Parameters: int sides, int dice
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/			 
		int roll(int sides, int dice);

/*********************************************************************
 ** Function: void dead(std::string s = "The creature is already dead!")
 ** Description: Simply prints out a message for a creature with strength <= 0
 ** Parameters: std::string s = "The creature is already dead!"
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
		void dead(std::string s = "The creature is already dead!");
			
/*********************************************************************
 ** Function: void wait(double n = 4)
 ** Description: sleeps the program for n*(one quarter second)
 ** Parameters: double n = 4
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
		void wait(double n = 4);
};

#endif