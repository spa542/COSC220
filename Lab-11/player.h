#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <iostream>
#include "livingEntity.h"

class Player : public LivingEntity {
	private: 
		int healthRegen = 1;
	public:
		Player();
		void printInfo();
		void takeDamage(int);
		void heal() {
			health += healthRegen;
		};
		int getHealth() {
			return health;
		};
		int getDamage() {
			return attackDamage;
		};
};

#endif
