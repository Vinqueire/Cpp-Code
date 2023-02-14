#include <iostream>
#include <cstdlib>
#include <ctime>

void showMap(int boardMap[][3]);

void aiMove(int height, int width, int boardmap[3][3], bool characterX);

void rulesExplain();

void intro();

int characterChoice();

int finish(int boardMap[][3]);

int main()
{
	// Set a random seed in order for rand to work properly

	srand((unsigned int)time(0));

	// Intro / welcome the user
	
	intro();

	// Make the user choose a character
	// Return 1 for character X 
	// Return 0 for character O
	// Set either CharacterX or character0 to true depending on choice

	int checkChar = characterChoice();

	bool characterX{};
	bool characterO{};

	if (checkChar == 1)
	{
		characterX = true;
	}
	else if (checkChar == 0)
	{
		characterO = true;
	}
	else if (checkChar == 3)
	{
		return 1;
	}

	// Create a 2D array to represent the map and assign it to 0

	int boardMap[3][3];

	for (int height = 0; height < 3; ++height)
	{
		for (int width = 0; width < 3; ++width)
		{
			boardMap[height][width] = 0;
		}
	}

	// Explain the rules to the user and show the map

	rulesExplain();

	// Update the 2d array with according position and call Showmap to show
	// The updated Map

	for (int turn = 0; turn < 777; ++turn)
	{
		int mark{};
		int height{};
		int width{};

		std::cout << "Pick your mark by typing in the according number: 1-9\n";
		std::cout << std::endl;
		std::cin >> mark;
		std::cout << std::endl;

		for (int checkMark = 1; checkMark < 10; ++checkMark)
		{

			if (checkMark == 4)
			{
				height ++;
				width = 0;
			}

			if (checkMark == 7)
			{
				height ++;
				width = 0;
			}

			if (mark == checkMark && boardMap[height][width] != 0)
			{
				std::cout << "Place isn't empty, you lose for trying to cheat!"
					<< std::endl;
				return 0;
			}
			else if (mark == checkMark && characterX == true)
			{
				boardMap[height][width] = 1;
				std::cout << "Your move\n";
				showMap(boardMap);
				std::cout << std::endl;
				break;
			}
			else if (mark == checkMark && characterO == true)
			{
				boardMap[height][width] = 2;
				std::cout << "Your move\n";
				showMap(boardMap);
				std::cout << std::endl;
				break;
			}

			width++;
		}

		std::cout << "\n\n";

		width = 0;
		height = 0;

		// Ai turn

		aiMove(height, width, boardMap, characterX);

		// Check if anyone has won yet
		int finishYet = finish(boardMap);
		
		if (finishYet == 1)
		{
			std::cout << "X WON!\n";
			return 0;
		}
		else if (finishYet == 2)
		{
			std::cout << "0 WON!\n";
			return 0;
		}
		else if (finishYet == 4)
		{
			std::cout << "Tie!, no winners\n";
			return 0;
		}
		
	}
	return 0;
}

// Show the updated map

void showMap(int boardMap[3][3])
{
	char zeroZero{};
	char zeroOne{};
	char zeroTwo{};

	char oneZero{};
	char oneOne{};
	char oneTwo{};

	char twoZero{};
	char twoOne{};
	char twoTwo{};

	// Set zeroZero

	if (boardMap[0][0] == 0)
	{
		zeroZero = 0x20;
	}
	else if (boardMap[0][0] == 1)
	{
		zeroZero = 'X';
	}
	else if (boardMap[0][0] == 2)
	{
		zeroZero = 'O';
	}

	// set zeroOne

	if (boardMap[0][1] == 0)
	{
		zeroOne = 0x20;
	}
	else if (boardMap[0][1] == 1)
	{
		zeroOne = 'X';
	}
	else if (boardMap[0][1] == 2)
	{
		zeroOne = 'O';
	}

	// set ZeroTwo

	if (boardMap[0][2] == 0)
	{
		zeroTwo = 0x20;
	}
	else if (boardMap[0][2] == 1)
	{
		zeroTwo = 'X';
	}
	else if (boardMap[0][2] == 2)
	{
		zeroTwo = 'O';
	}
	
	// End of the first row


	// Set oneZero

	if (boardMap[1][0] == 0)
	{
		oneZero = 0x20;
	}
	else if (boardMap[1][0] == 1)
	{
		oneZero = 'X';
	}
	else if (boardMap[1][0] == 2)
	{
		oneZero = 'O';
	}

	// set oneOne

	if (boardMap[1][1] == 0)
	{
		oneOne = 0x20;
	}
	else if (boardMap[1][1] == 1)
	{
		oneOne = 'X';
	}
	else if (boardMap[1][1] == 2)
	{
		oneOne = 'O';
	}

	// set oneTwo

	if (boardMap[1][2] == 0)
	{
		oneTwo = 0x20;
	}
	else if (boardMap[1][2] == 1)
	{
		oneTwo = 'X';
	}
	else if (boardMap[1][2] == 2)
	{
		oneTwo = 'O';
	}

	// End of the second row

	// Set twoZero

	if (boardMap[2][0] == 0)
	{
		twoZero = 0x20;
	}
	else if (boardMap[2][0] == 1)
	{
		twoZero = 'X';
	}
	else if (boardMap[2][0] == 2)
	{
		twoZero = 'O';
	}

	// set twoOne

	if (boardMap[2][1] == 0)
	{
		twoOne = 0x20;
	}
	else if (boardMap[2][1] == 1)
	{
		twoOne = 'X';
	}
	else if (boardMap[2][1] == 2)
	{
		twoOne = 'O';
	}

	// set twoTwo

	if (boardMap[2][2] == 0)
	{
		twoTwo = 0x20;
	}
	else if (boardMap[2][2] == 1)
	{
		twoTwo = 'X';
	}
	else if (boardMap[2][2] == 2)
	{
		twoTwo = 'O';
	}

	std::cout << "-------------\n" << "| " << zeroZero << " | "
		<< zeroOne << " | " << zeroTwo << " |" << std::endl
		<< "-------------\n" << "| " << oneZero << " | "
		<< oneOne << " | " << oneTwo << " |" << std::endl
		<< "-------------\n" << "| " << twoZero << " | "
		<< twoOne << " | " << twoTwo << " |" << std::endl
		<< "-------------\n";
}


// Make the "Ai" oppenent and prompt it for the move

void aiMove(int height, int width, int boardMap[3][3], bool characterX)
{
	int aiNum = (rand() % 9) + 1;

	height = 0;
	width = 0;

	for (int checkAi = 1; checkAi < 10; ++checkAi)
	{

		if (checkAi == 4)
		{
			height++;
			width = 0;
		}

		if (checkAi == 7)
		{
			height++;
			width = 0;
		}

		if (aiNum == checkAi)
		{
			if (boardMap[height][width] == 1 || boardMap[height][width] == 2)
			{
				aiMove(height, width, boardMap, characterX);
			}
			else if (boardMap[height][width] == 0 && characterX == true)
			{
				boardMap[height][width] = 2;
				std::cout << "Openent's move\n";
				showMap(boardMap);
				std::cout << std::endl;
				break;
			}
			else if (boardMap[height][width] == 0 && characterX == false)
			{
				boardMap[height][width] = 1;
				std::cout << "Openent's move\n";
				showMap(boardMap);
				std::cout << std::endl;
				break;
			}
		}

		width++;
	}
}

// Instructions on how to play the game

void rulesExplain()
{
	std::cout << "Welcome to TicTacToe, your task is to pick the posistion "
		"on the map and place your shape.\n";

	std::cout << "The drawing bellow represents the "
		"position's in which you can place your mark.\n" << std::endl;

	std::cout << "-------------\n" << "| 1 | 2 | 3 |\n" << "-------------\n" <<
		"| 4 | 5 | 6 |\n" << "-------------\n" << "| 7 | 8 | 9 |\n" <<
		"-------------\n" << std::endl;

}

// Welcome the user

void intro()
{
	std::cout << "Welcome to TicTacToe, choose your character by inputing:\n\n"
		<< "0 to choose character: 0 \n\n" << "1 to choose character : X\n\n";
}

int characterChoice()
{
	// Variable for getting player's input

	char playerChoice{};

	std::cin >> playerChoice;
	std::cout << std::endl;

	// Prompts to inform user on choice and update char bool accordingly

	if (playerChoice == '0')
	{
		std::cout << "Your character is: 0\n" << std::endl;
		return 0;
	}
	else if (playerChoice == '1')
	{
		std::cout << "Your character is: X\n" << std::endl;
		return 1;
	}
	else
	{
		std::cout << "Bruh, you can't even choose a charater wtf\n";
		return 3;
	}

}

int finish(int boardMap[3][3])
{
	// Check for vertical lines for wins

	//
	// XXX
	//

	for (int height = 0; height < 3; ++height)
	{
		if (boardMap[height][0] == 1 && boardMap[height][1] == 1
			&& boardMap[height][2] == 1)
		{
			return 1;
		}
		else if (boardMap[height][0] == 2 && boardMap[height][1] == 2
			&& boardMap[height][2] == 2)
		{
			return 2;
		}
	}

	// Check for horizontal lines for wins

	//  X
	//  X
	//  X

	for (int width = 0; width < 3; ++width)
	{
		if (boardMap[0][width] == 1 && boardMap[1][width] == 1 &&
			boardMap[2][width] == 1)
		{
			return 1;
		}
		else if (boardMap[0][width] == 2 && boardMap[1][width] == 2 &&
			boardMap[2][width] == 2)
		{
			return 2;
		}
	}


	// Check for right line
 
	//   X
	//  X
	// X

	if (boardMap[0][2] == 1 && boardMap[1][2] == 1 && boardMap[2][2] == 1)
	{
		return 1;
	}
	else if (boardMap[0][2] == 2 && boardMap[1][2] == 2 && boardMap[2][2] == 2)
	{
		return 2;
	}


	// Check for left line

	// X
	//  X
	//   X

	if (boardMap[0][0] == 1 && boardMap[1][1] == 1 && boardMap[2][2] == 1)
	{
		return 1;
	}
	else if (boardMap[0][0] == 2 && boardMap[1][1] == 2 && boardMap[2][2] == 2)
	{
		return 2;
	}


	// Check for tie
	int tie{};

	for (int hgt = 0; hgt < 3; ++hgt)
	{
		for (int wdt = 0; wdt < 3; ++wdt)
		{
			if (boardMap[hgt][wdt] == 1 || boardMap[hgt][wdt] == 2)
			{
				tie++;

			}

			if (tie == 9)
			{
				return 4;
			}
		}
	}
	return false;
}

// Things to fix
// None it all works as intented :)