gofish: go_fish.o card.o deck.o player.o 
	g++  -std=gnu++0x -otest go_fish.o card.o deck.o player.o 
driver: go_fish.cpp card.h player.h deck.h
	g++ -std=gnu++0x -c go_fish.cpp
card.o: card.cpp card.h
	g++ -std=gnu++0x -c card.cpp
player.o: player.cpp player.h card.h
	g++ -std=gnu++0x -c player.cpp
deck.o: deck.cpp deck.h
	g++ -std=gnu++0x -c deck.cpp