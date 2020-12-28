#include "travelstate.h"

void TravelState::printOptions() {
  std::cout << "You are walking " << direction << std::endl;
  std::cout << "Current loadout: " << std::endl;
  p.printInfo();
  if (hasCrossroad){
    std::cout << "You see a fork in the road, headed " << newDirection << std::endl;
  }

  /* Classic way
  for(int i = 1; i<choices.size() + 1; i++){
    std::cout << i << ". " << choices[i] << std::endl;
  }
  */

  /* More modern way to iterate a std::map */
  for(auto i = choices.begin(); i != choices.end(); i++){
    /*
     * i holds an iterator, which is a pointer to a std::pair<int, string>
     * i->first is the int
     * i->second is the string
     */
    std::cout << i->first << ". " << i->second << std::endl;
  }
};

GameState* TravelState::handleInput(std::string in) {
  // cast the string to an int to be interpreted as a choice
  int choice = std::stoi(in);

  // Temp variable to hold the new game state
  GameState* rtn = nullptr;

  switch (choice){
    case CONTINUE_OPTION:
      std::cout << "\nYou continue walking...\n";
	if (rand()%10 + 1 > 6) { // 40% chance of an enemy appearing
	   Monster mon;
           rtn = new CombatState(direction, mon, p); 
        } else {
      	   rtn = new TravelState(direction, p);
	}
      break;
    case SIT_OPTION:
      // construct and return a new idlestate
      // currently this will cause a segfault if the user
      // tries to sit down!
      rtn = new IdleState(direction, p);
      break;
    case FORK_OPTION:
      std::cout << "\nYou take the fork...\n";
      rtn = new TravelState(newDirection, p);
      break;
    default:
      std::cout << "Invalid option.\n";
      rtn = this;
      break;
  };

  return rtn;
};
