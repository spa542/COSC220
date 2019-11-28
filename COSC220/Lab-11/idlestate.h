#ifndef IDLESTATE_H
#define IDLESTATE_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "gamestate.h"
#include "travelstate.h"

/*
 * For lab:
 * - implement the two override functions of GameState, printOptions and handleInput
 * - implement constructor to remember the status of the previous travel state
 */

class IdleState : public GameState {
  private:
	
    std::string currentDirection;
	
    enum Choices {
      CONTINUE_OPTION = 1,
      LEAVE_OPTION    = 2
    };

 public:
	IdleState(std::string dir) {
		currentDirection = dir;
		choices[CONTINUE_OPTION] = "Keep Sitting like a bum";
		choices[LEAVE_OPTION] = "Get on up";
	};

	void printOptions() override;
	
	GameState* handleInput(std::string) override;	

};

#endif
