#ifndef _LIVINGENTITY_H_
#define _LIVINGENTITY_H_
#include <iostream>
#include <stdio.h>
#include <string.h>

class LivingEntity {
	protected: 
		int health;
		std::string type;
		int attackDamage;
	public:
		virtual void printInfo() = 0;
		virtual void takeDamage(int) = 0;
};

#endif
