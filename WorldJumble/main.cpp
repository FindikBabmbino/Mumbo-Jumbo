#include "functions.h"

/*
----------------------------MADE BY Sinan Berk Karaagac----------------------------
							Date(DD / MM / YY) : 16 / 12 / 2023
------------------------------------------------------------------------------------
*/

int main()
{
	srand(time(NULL));
	while (ContinuePlaying())
	{
		ExplainRulesOfTheGame();
		GameLoop();
	}
}