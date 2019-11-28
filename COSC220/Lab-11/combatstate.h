#ifndef _COMBATSTATE_H_
#define _COMBATSTATE_H_
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "gamestate.h"
#include "travelstate.h"

class CombatState : public GameState {
	private:
		std::string currentDirection;

	enum Choices {
		ATTACK_OPTION = 1,
		FLEE_OPTION = 2
	};

	public:
		CombatState(std::string dir) {
			currentDirection = dir;
			choices[ATTACK_OPTION] = "Attack that mofo";
			choices[FLEE_OPTION] = "Run away panzy";
		};
		
		void printOptions() override;

		GameState* handleInput(std::string) override;

};

#endif
