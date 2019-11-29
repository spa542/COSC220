GCC=g++
FLAGS=-std=c++11 -Wall

all: main

main: travelstate.o idlestate.o main.o combatstate.o monster.o player.o
	$(GCC) $(FLAGS) -o main travelstate.o idlestate.o main.o combatstate.o monster.o player.o

main.o: main.cpp
	$(GCC) $(FLAGS) -c main.cpp -o main.o

travelstate.o: travelstate.cpp gamestate.h travelstate.h
	$(GCC) $(FLAGS) -c travelstate.cpp -o travelstate.o

idlestate.o: idlestate.cpp gamestate.h idlestate.h
	$(GCC) $(FLAGS) -c idlestate.cpp -o idlestate.o

combatstate.o: combatstate.h combatstate.cpp gamestate.h
	$(GCC) $(FLAGS) -c combatstate.cpp -o combatstate.o

monster.o: monster.h monster.cpp livingEntity.h
	$(GCC) $(FLAGS) -c monster.cpp -o monster.o

player.o: player.h player.cpp livingEntity.h
	$(GCC) $(FLAGS) -c player.cpp -o player.o

clean:
	rm *.o main
