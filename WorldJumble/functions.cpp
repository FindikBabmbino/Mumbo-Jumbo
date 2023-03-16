#include"functions.h"

//This stores all the words the program is going to bring

std::string words[ARRAY_SIZE] = {
    "crown",
    "garlic",
    "chemistry",
    "perform",
    "employee",
    "banish",
    "duke",
    "straighten",
    "arrogant",
    "sensitivity",
    "quicksand",
    "jigsaw",
    "zigzag",
    "buzzsaw",
    "glitz",
    "jazz",
    "blitz",
    "pizza",
    "blizzard",
    "hazard",
    "quiz",
    "snazzy",
    "cozy",
    "fuzzy",
    "puzzle",
    "pizzazz",
    "frenzy",
    "frizzy",
    "spicy",
    "chintzy",
    "dizzy",
    "fizzle",
    "frizzle",
    "grizzly",
    "muzzle",
    "schmooze",
    "sneeze",
    "topaz",
    "wheezy",
    "wizard",
    "blazer",
    "brazen",
    "bronze",
    "craze",
    "dazzle",
    "embezzle",
    "frozen",
    "gazelle",
    "graze",
    "haze",
    "laze",
    "maize",
    "maze",
    "polarize",
    "prize",
    "raze",
    "scuzzy",
    "sizzle",
    "size",
    "stun",
    "unzip",
    "wizen",
    "ablaze",
    "amaze",
    "analyze",
    "appetizer",
    "authorize",
    "bamboo",
    "barbecue",
    "bathtub",
    "blueprint",
    "boycott",
    "buzzard",
    "breezy",
    "blizzard",
    "blaze",
    "bizarre",
    "chintz",
    "chutzpah",
    "crazy",
    "dizzying",
    "dazzling",
    "dazzlement",
    "doozy",
    "emblazon",
    "embellish",
    "fizz",
    "fuzzy",
    "frizz",
    "frizzy",
    "frazzled",
    "fizzle",
    "gizmo",
    "glazed",
    "glamorize",
    "grizzly",
    "hazelnut",
    "hazy",
    "horizon",
    "huzzle",
    "jazzed",
    "jazzy",
    "jinx",
    "klutz",
    "muzzle",
    "mezzanine",
    "puzzling",
    "pizza",
    "razz",
    "sizzle",
    "snazzy",
    "spaz",
    "swoozie",
    "tizzy",
    "topaz",
    "unfrozen",
    "voodoo",
    "whiz",
    "whizzing",
    "wheezy",
    "wizardry",
    "zebra",
    "zingy",
    "zippy",
    "zany",
    "zest",
    "zillion",
    "zodiac",
    "zombie",
    "zoom",
    "zucchini",
    "zinger",
    "zinc",
    "zonal",
    "zonked",
    "zoology",
};

//This is how we get the array 
std::string* GetWordArray()
{
	return words;
}

//This asks the player if they want to continue playing or not this is in the start after guessing and after the game over
bool ContinuePlaying()
{
	bool failure;
	char decision;
	do
	{
		failure = false;
		std::cout << "Do you wish to play the game? (y/n): ";
		std::cin >> decision;

		if(decision !='y'&& decision!='n')
		{
			std::cout << "Incorrect input. Try again" << std::endl;
			failure = true;
		}

	} while (failure);
    //We want to clear the screen so there is not that much clutter
	system("cls");
	if (decision == 'y') return true;
	else return false;
}

//This just explains the rules
void ExplainRulesOfTheGame()
{
	std::cout << "Welcome to Mumbo Jumbo!" << std::endl;

	std::cout << "In the game of Mumbo jumbo you will be given a random word. \n"
		"But this word will Mumbo Jumboed! (scrambled) your task is to find the word until your life counter reaches zero!" << std::endl;

    PressEnterToContinue();
}

//This is the main game loop

void GameLoop()
{
    //we create the life, score, currentword and answer just before the loop
	int life = 4;
	int highScore = 0;
	std::string currentWord = GetRandomWord();
	std::string answer = "";
	while (life > 0)
	{
		std::cout << "Current lives: " << life << std::endl;
		std::cout << "High Score: " << highScore << std::endl;
		std::cout << "Jumbled word: " << GenerateJumbledWord(currentWord) << std::endl;

		answer = GetAnswer();

		if(CheckAnswer(currentWord,answer))
		{
			std::cout << "Great you got it!" << std::endl;
			ContinuePlaying();
			std::cout << "Generating new word. Adding +1 health(if you are not already at max health)" << std::endl;
			if(life<4)
			{
				life++;
			}
			highScore++;
			currentWord = GetRandomWord();
		}
		else
		{
			std::cout << "Wrong guess, try again." << std::endl;
			std::cout << "Deducting life." << std::endl;
			life--;
		}

        PressEnterToContinue();
	}

	std::cout << "You lost :(" << std::endl;
    std::cout << "The word was: " << currentWord << std::endl;

    PressEnterToContinue();
}

//This just pulls a random word from the array and returns it back
std::string GetRandomWord()
{
	int randomWord = rand() % ARRAY_SIZE;
	return GetWordArray()[randomWord];
}

//This scrambles the current random word
std::string GenerateJumbledWord(std::string originalWord)
{
	std::string jumbledWord = originalWord;
	
	for (int i = 0; i < jumbledWord.length(); i++)
	{
        //we get the current character from the original word and swap it for another character in the same word
		if(!originalWord.empty())
		{
			int randomChar = rand() % originalWord.length();
			jumbledWord[i] = originalWord[randomChar];
            //we earese it so we don't have repeats
			originalWord.erase(randomChar,1);
		}
	}
	return jumbledWord;
}

//This gets the answer input from the player
std::string GetAnswer()
{
	std::string answer;

	std::cout << "Enter your guess: ";
	std::cin >> answer;
    //turns it to lower case so that the answer will be still correct if all caps were used
	for (int i = 0; i < answer.length(); i++)
	{
		answer[i] = tolower(answer[i]);
	}
	
	return answer;
}
//This does a quick check if the answer the player gave was correct
bool CheckAnswer(std::string compareWord, std::string answerToCheck)
{
	if(answerToCheck == compareWord)
        return true;
	else
		return false;
}

//This function makes it so that the code only moves forward if the player presses enter
void PressEnterToContinue()
{
    std::cout << "Press enter to continue.";
    std::cin.ignore();
    std::cin.get();
    system("cls");
}