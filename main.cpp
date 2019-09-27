#include <iostream>
#include "Game.h"
#include "BoardGame.h"
#include "VideoGame.h"

//loops until valid input is given
void getInput(int& number) {
	while (1) {
		std::cout << "Press 1 for an instance of game.\n"
			<< "Press 2 for an instance of board game.\n"
			<< "Press 3 for an instance of video game.\n"
			<< "Press 4 for an instance of a board game declared as a game\n"
			<< "Press 5 for an instance of a video game declared as a game\n";
		std::cin >> number;
		if (number > 0 && number < 6)
			return;
	}
}
//function that calls play() and winner() methods
void test(Game *g) {
	(*g).play();
	(*g).winner();
}

int main() {
	char input;
	do {
		int i;
		getInput(i);
		if (i == 1) {
			Game *g = new Game;
			(*g).play();
			(*g).winner();
			test(g);
			delete g;
		}
		else if (i == 2) {
			BoardGame *g = new BoardGame;
			(*g).play();
			(*g).winner();
			test(g);
			delete g;
		}
		else if (i == 3) {
			VideoGame *g = new VideoGame;
			(*g).play();
			(*g).winner();
			test(g);
			delete g;
		}
		else if (i == 4) {
			Game *g = new BoardGame;
			(*g).play();
			(*g).winner();
			test(g);
			delete g;
		}
		else /*(i == 5)*/ {
			Game *g = new VideoGame;
			(*g).play();
			(*g).winner();
			test(g);
			delete g;
		}
		std::cout << "Would you like to continue (y/n)?\n";
		std::cin >> input;
	} while (input == 'Y' || input == 'y');
	return 0;
}