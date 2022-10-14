#include <iostream>
#include <ctime>

void drawBoard(char* spaces, char player, char bot);
void playerMove(char* spaces, char player, char bot);
void botMove(char* spaces, char bot);
bool checkWinner(char* spaces, char player, char bot);
bool checkTie(char* spaces);

int main() {

	bool running = true;
	char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	char player = 'X';
	char bot = 'O';

	while (running) {

		drawBoard(spaces, player, bot);
		playerMove(spaces, player, bot);

		if (checkTie(spaces)) {

			std::cout << "TIE!" << std::endl; // DOESN'T WORK XDD
			running = false;

		}
		else if (checkWinner(spaces, player, bot)) {

			running = false;
			
		}
	}
}
void drawBoard(char* spaces, char player, char bot) {

	system("cls");
	std::cout << std::endl;
	std::cout << "     |     |     " << std::endl;
	std::cout << "  " << spaces[0] << "  " << "|" << "  " << spaces[1] << "  " << "|" << "  " << spaces[2] << std::endl;
	std::cout << "_____|_____|_____" << std::endl;
	std::cout << "     |     |     " << std::endl;
	std::cout << "  " << spaces[3] << "  " << "|" << "  " << spaces[4] << "  " << "|" << "  " << spaces[5] << std::endl;
	std::cout << "_____|_____|_____" << std::endl;
	std::cout << "     |     |     " << std::endl;
	std::cout << "  " << spaces[6] << "  " << "|" << "  " << spaces[7] << "  " << "|" << "  " << spaces[8] << std::endl;
	std::cout << "     |     |     " << std::endl;
	std::cout << std::endl;

}
void playerMove(char* spaces, char player, char bot) {

	int number;
	
	std::cout << "Enter a number to set the X to (1-9): ";
	std::cin >> number;

	if (spaces[number - 1] == ' ') {

		spaces[number - 1] = player;
		botMove(spaces, bot);
	}
	else {
		std::cout << "Enter a number to set the X to (1-9): ";
	}
}
void botMove(char* spaces, char bot) {

	srand(time(NULL));

	int number;

	while (true) {
		number = (rand() % 9) + 1;
		if (spaces[number - 1] == ' ') {
			spaces[number - 1] = bot;
			break;
		}
	}
}
bool checkWinner(char* spaces, char player, char bot) {

	// HORIZONTAL
	if ((spaces[0] != ' ') && (spaces[0] == spaces[1] && spaces[1] == spaces[2])) {
		spaces[0] == player ? std::cout << "YOU WIN" << std::endl : std::cout << "YOU LOSE" << std::endl;
	}
	else if ((spaces[3] != ' ') && (spaces[3] == spaces[4] && spaces[4] == spaces[5])) {
		spaces[3] == player ? std::cout << "YOU WIN" << std::endl : std::cout << "YOU LOSE" << std::endl;
	}
	else if ((spaces[6] != ' ') && (spaces[6] == spaces[7] && spaces[7] == spaces[8])) {
		spaces[6] == player ? std::cout << "YOU WIN" << std::endl : std::cout << "YOU LOSE" << std::endl;
	}
	// VERTICAL
	else if ((spaces[0] != ' ') && (spaces[0] == spaces[3] && spaces[3] == spaces[6])) {
		spaces[0] == player ? std::cout << "YOU WIN" << std::endl : std::cout << "YOU LOSE" << std::endl;
	}
	else if ((spaces[1] != ' ') && (spaces[1] == spaces[4] && spaces[4] == spaces[7])) {
		spaces[1] == player ? std::cout << "YOU WIN" << std::endl : std::cout << "YOU LOSE" << std::endl;
	}
	else if ((spaces[2] != ' ') && (spaces[2] == spaces[5] && spaces[5] == spaces[8])) {
		spaces[2] == player ? std::cout << "YOU WIN" << std::endl : std::cout << "YOU LOSE" << std::endl;
	}
	// DIAGONAL
	else if ((spaces[0] != ' ') && (spaces[0] == spaces[4] && spaces[4] == spaces[8])) {
		spaces[0] == player ? std::cout << "YOU WIN" << std::endl : std::cout << "YOU LOSE" << std::endl;
	}
	else if ((spaces[2] != ' ') && (spaces[2] == spaces[4] && spaces[4] == spaces[6])) {
		spaces[2] == player ? std::cout << "YOU WIN" << std::endl : std::cout << "YOU LOSE" << std::endl;
	}
	else {
		return false;
	}

	return true;
}
bool checkTie(char* spaces) {

	for (int i = 0; i < 9; i++) {
		if (spaces[i] == ' ') {
			return false;
			
		}
	}

	return true;
}