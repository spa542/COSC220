#include "monster.h"

Monster::Monster() {
	health = rand() % 10 + 1;
	type = "Monster";
	attackDamage = rand() % 3 + 1;
}

void Monster::printInfo() {
	std::cout << "Type: " << type << std::endl;
	std::cout << "Health: " << health << std::endl;
	std::cout << "Attack: " << attackDamage << std::endl;
}

void Monster::takeDamage(int inc) {
	health -= inc;
}
