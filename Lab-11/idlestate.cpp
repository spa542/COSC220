#include "idlestate.h"

void IdleState::printOptions()  {
        std::cout << "You are sitting, looking " << currentDirection << std::endl;
	std::cout << "Current Info: " << std::endl;
	p.printInfo();
      	for (auto i = choices.begin(); i != choices.end(); i++) {
                std::cout << i->first << ". " << i->second << std::endl;
     	}
}

GameState* IdleState::handleInput(std::string in) {
	int choice = std::stoi(in);
	
	GameState* rtn = nullptr;

	switch (choice) {
	 case CONTINUE_OPTION:
		std::cout << "\nYou continue sitting...\n";
		if (p.getHealth() < 10) {
		std::cout << "You start to feel better! (Health Regen++)" << std::endl;
			p.heal();
		} else {
			std::cout << "You feel about as good as you possible can. " << std::endl;
		}
		rtn = new IdleState(currentDirection, p);
		break;
	 case LEAVE_OPTION:
		std::cout << "\nYou get your butt up and get moving again...\n" << std::endl;
		rtn = new TravelState(currentDirection, p);
		break;
	 default:
		std::cout << "Invalid option:\n";
		rtn = this;
		break;
	};
	
	return rtn;
}
