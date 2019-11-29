#include "player.h"

Player::Player() {
	health = 10;
	type = "Human";
	attackDamage = 2;
}

void Player::printInfo() {
	std::cout << "Your Health: " << health << std::endl;
	std::cout << "Type: " << type << std::endl;
	std::cout << "Your damage: " << attackDamage << std::endl;
}

void Player::takeDamage(int inc) {
	health -= inc;
}
