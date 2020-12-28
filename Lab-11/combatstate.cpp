#include "combatstate.h"

void CombatState::printOptions() {
	std::cout << "You are fighting an enemy from the " << currentDirection << std::endl;
	std::cout << "Enemy: " << std::endl;
	m.printInfo();
	std::cout << "You: " << std::endl;
	p.printInfo();
	for (auto i = choices.begin(); i != choices.end(); i++) {
		std::cout << i->first << ". " << i->second << std::endl;
	}
}

GameState* CombatState::handleInput(std::string in) {
	int choice = std::stoi(in);

	GameState* rtn = nullptr;

	switch (choice) {
	 case ATTACK_OPTION:
		std::cout << "\nYou attacked the enemy...\n";
		m.takeDamage(p.getDamage());
		if (m.getHealth() > 0 ) {
			std::cout << "Counter attack!" << std::endl;
			p.takeDamage(m.getDamage());
			if (p.getHealth() > 0) {
				rtn = new CombatState(currentDirection, m, p);
			} else {
				std::cout << "NOOOOO! Your long fought journey is over! :( " << std::endl;
				exit(0);
			}
		} else {
			std::cout << "Nice Job! You got that SOB :)" << std::endl;
			rtn = new TravelState(currentDirection, p);
		}
		break;
	 case FLEE_OPTION:
		std::cout << "\nYou run like a wimp...\n" << std::endl;
		rtn = new TravelState(currentDirection, p);
		break;
	 default:
		std::cout << "Invalid option:\n";
		rtn = this;
		break;
	};
	
	return rtn;
}
