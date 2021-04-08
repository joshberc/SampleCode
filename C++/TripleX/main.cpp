#include<iostream>
#include<ctime>

//Player needs to guess the correct code.
//Josh Berc - 2020

bool playGame(int difficulty)
{
	//Variables
	int CodeA = rand() % difficulty + difficulty;
	int CodeB = rand() % difficulty + difficulty;
	int CodeC = rand() % difficulty + difficulty;
	int CodeSum		= CodeA + CodeB + CodeC;
	int CodeProduct = CodeA * CodeB * CodeC;
	int GuessA, GuessB, GuessC, GuessSum, GuessProduct;

	//Print rules
	std::cout << "You are a secret agent breaking into a level " << difficulty << " safe." << std::endl;
	std::cout << "Enter the code to continue...." << std::endl;
	std::cout <<  std::endl;
	std::cout << " - There are 3 numbers in the code." << std::endl;
	std::cout << " - The codes sum is: " << CodeSum << std::endl;
	std::cout << " - The codes product is: " << CodeProduct << std::endl;

	//Get Player input
	std::cin >> GuessA;
	std::cin >> GuessB;
	std::cin >> GuessC;
	std::cout << "You guessed " << GuessA << " - " << GuessB << " - " << GuessC << "." << std::endl;

	//Calculates guess values
	GuessSum = GuessA + GuessB + GuessC;
	GuessProduct = GuessA * GuessB * GuessC;

	//Checks answer
	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{
		std::cout << "You win!" << std::endl;
		return true;
	}
	else
	{
		std::cout << "You lose..." << std::endl;
		return false;
	}
}

int main()
{
	//Resets random
	srand(time(NULL));

	//Variables
	int Difficulty = 1;
	const int MaxDifficulty = 5;

	while (Difficulty <= MaxDifficulty) 
	{
		bool BeatLevel = playGame(Difficulty);
		std::cin.clear(); //Clears errors
		std::cin.ignore(); //Discards buffer

		if (BeatLevel)
		{
			++Difficulty;
		}
	}

	std::cout << "You beat the game!" << std::endl;
	return 0;
}

