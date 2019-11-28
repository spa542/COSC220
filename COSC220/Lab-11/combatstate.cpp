#include "combatstate.h"

void CombatState::printOptions() {
	std::cout << "You are fighting an enemy from the " << currentDirection << std::endl;
	for (auto i = choices.begin(); i != choices.end(); i++) {
		std::cout << i->first << ". " << i->second << std::endl;
	}
}

GameState* CombatState::handleInput(std::string in) {
	int choice = std::stoi(in);

	GameState* rtn;

	switch (choice) {
	 case ATTACK_OPTION:
		std::cout << "\nYou attacked the enemy...\n";
		rtn = new CombatState(currentDirection);
		break;
	 case FLEE_OPTION:
		std::cout << "\nYou run like a wimp...\n" << std::endl;
		rtn = new TravelState(currentDirection);
		break;
	 default:
		std::cout << "Invalid option:\n";
		rtn = this;
		break;
	};
	
	return rtn;
}
