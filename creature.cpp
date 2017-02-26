/*********************************************************************
 ** Program Filename: creature.cpp
 ** Author: Joshua Kluthe
 ** Date: 02.14.2016
 ** Description: Definition of the abstract Creature class. Objects derived from Creature
 ** can attack, defend, and take damage in a Dungeons and Dragons kind of way.
 ** Input:
 ** Output:
**********************************************************************/
#include "creature.hpp"

/*unistd.h is included for usleep()*/
#include <unistd.h>

/*********************************************************************
 ** Function: Creature()
 ** Description: Constructs a creature with a seed for the random nature of the roll()
 ** function.
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
Creature::Creature() {
	
	/*wait so that each seed is different for each creature. Not a great solution*/
	wait(4);
	
	/*create a seed*/
	unsigned seed = time(0);
	srand(seed);
	
}
	 
/*********************************************************************
 ** Function: void take_damage(int damage, bool fatal = false)
 ** Description: subtracts damage from the creature strength. If fatal == true, sets
 ** strength = 0
 ** Parameters: int damage, bool fatal = false
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/	
void Creature::take_damage(int damage, bool fatal) {
	
	if(fatal) {
	
		strength = 0;
		std::cout << "The creature takes fatal damage!" << std::endl;
		
	} else {
	
		strength -= damage;
		std::cout << "The creature takes " << damage << " damage!" << std::endl;
		
	}
}

/*********************************************************************
 ** Function: virtual void take_damage(int damage, Creature *attacker, bool fatal = false)
 ** Description: This allows the creature to counterattack and perform other actions
 ** if it takes damage from another creature.
 ** Parameters: int damage, Creature *attacker, bool fatal = false
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/	
void Creature::take_damage(int damage, Creature *attacker, bool fatal) {
	
	if(strength <= 0)
		
		/*print out that the creature is dead*/
		dead();
		
	else {
		
		/*take damage and counterattack if still alive*/
		damage -= defense();
		
		if(damage >= 0)
			take_damage(damage, fatal);
			
		else
			std::cout << "The creature takes no damage!" << std::endl;
			
		if(strength > 0) {
		
			std::cout << "Defending creature has " << strength << " strength "
					<< "and will now attack.\n" << std::endl;
			
			/*wait between each round*/
			wait();
			attack(attacker);
			
		} else
		
			/*if damage turned out to be fatal*/
			dead("The creature is slain!");
	}

		
}

/*********************************************************************
 ** Function: int roll(int sides, int dice)
 ** Description: returns the added total of a simulated dice roll.
 ** Parameters: int sides, int dice
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/	
int Creature::roll(int sides, int dice) {
	
	int total_roll = 0;

	for(int i = 0; i < dice; i++)
		total_roll += 1 + rand()%sides;
		
	return total_roll;
}

/*********************************************************************
 ** Function: void dead(std::string s = "The creature is already dead!")
 ** Description: Simply prints out a message for a creature with strength <= 0
 ** Parameters: std::string s = "The creature is already dead!"
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void Creature::dead(std::string s) {

	std::cout << s << std::endl;
	
}

/*********************************************************************
 ** Function: void wait(double n = 4)
 ** Description: sleeps the program for n*(one quarter second)
 ** Parameters: double n = 4
 ** Pre-Conditions:
 ** Post-Conditions:
**********************************************************************/
void Creature::wait(double n) {

	/*waits for * quarter seconds.*/
	double time = n*250000;
	usleep(time);

}