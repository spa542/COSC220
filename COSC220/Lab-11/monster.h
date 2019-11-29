#ifndef _MONSTER_H_
#define _MONSTER_H_
#include <iostream>
#include "livingEntity.h"
#include <time.h>

class Monster : public LivingEntity {
	public:
		Monster();
		void printInfo() override;
		void takeDamage(int) override;
		int getHealth() {
			return health;
		};
		int getDamage() {
			return attackDamage;
		};
};

#endif
