#include "idlestate.h"

void IdleState::printOptions()  {
        std::cout << "You are sitting, looking " << currentDirection << std::endl;
      	for (auto i = choices.begin(); i != choices.end(); i++) {
                std::cout << i->first << ". " << i->second << std::endl;
     	}
}

GameState* IdleState::handleInput(std::string in) {
	int choice = std::stoi(in);
	
	GameState* rtn;

	switch (choice) {
	 case CONTINUE_OPTION:
		std::cout << "\nYou continue sitting...\n";
		rtn = new IdleState(currentDirection);
		break;
	 case LEAVE_OPTION:
		std::cout << "\nYou get your butt up and get moving again...\n" << std::endl;
		rtn = new TravelState(currentDirection);
		break;
	 default:
		std::cout << "Invalid option:\n";
		rtn = this;
		break;
	};
	
	return rtn;
}
