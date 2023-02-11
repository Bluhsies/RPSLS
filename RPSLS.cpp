/*

This is the RPSLS game, in which the player will select different options to compete against the computer to win or lose by selecting Rock, Paper, Scissors, Lizard or Spock.
*/

/*
Reference List:

Angorro, W. (2018) C++ Data Structures and Algorithms. Birmingham, UK. Packt Publishing Ltd.
Dawson, M. (2010) Beginning C++ Through Game Programming. 3rd Edition. Course Technology.
Gregoire, M. (2014) Proefssional C++. 3rd Edition. Indianapolis, Indiana. John Wiley & Sons, Inc.
Grimes, R. (2017) Beginning C++ Programming. Birmingham, UK. Packt Publishing Ltd.
Horton, J. (2016) Beginning C++ Game Programming. Birmingham, UK. Packt Publishing Ltd.
Pupius, R. (2015) SFML Game Development by Example. Birmingham, UK. Packt Publishing Ltd.
Schlögl, E., Dempster, M.A.H., Madan, D.B. (2014) Quantative Finance: An Object-Orientated Approach in C++. Boca Raton, FL. CRC Press LLC.
Stroustrup, B. (2014) Programming Principles and Practice Using C++. 2nd Edition. Pearson Addison Wesley.

*/

/*
Below are the SFML headers which have been used for this program. (Pupius, 2015. p.3)
These have been included (#include) so that the files are included before the program is compiled.
iostream is used for the input and output operations of the program, such as 'cin' to allow the user to input a value into the console and 'cout' to output the result. (Stroustrup, 2014. p.347-349)
This also includes the endl; function to separate input and output on the console, as well as the use of << for the flow of the output statement and >> for the flow of the input statement. (Schlögl, 2014. p.2)
String is used to form words or full sentences. (Angorro, 2018. p.180-181) String has been included, as this serves as the main data type for my 2D array.
*/

#include <iostream>
#include <string>

/* Using namespace std; allows the program to access variables and functions from the Standard Library. (Dawson, 2010. p.36) */

using namespace std;

/* The const int iRowsAndCols is used to set the range of the 2D array and to make it a 5x5 grid of possible choices. */

const int iRowsAndCols = 5;

/* 
The integer (int) (Dawson, 2010. p.18) iUser has been defined as 0. This is the user input for the game, where the player will input a number from 0 - 4 which corresponds to the options in the array.
The integer iComputer has also been defined as 0. This is the computer's choice in the 2D array, which is compared against iUser to determine who has won.
*/

int iUser = 0;
int iComputer = 0;

/*
Below are a list of integers which are used for options which can be selected via the 2D array. For example, if iUser input is 1, this will indicate that the player has selected iPaper and print out a message to advise that paper was selected in the game.
The integer iError is used to compare any input which does not match the options available and provide an error message via a while loop. This has been defined as 5, as any user input which is 5 or equal is not a valid option in the array.
iRandom is used as part of the computer choice and has been defined as 5. This is used in conjunction with modulus and the rand() function to produce a random, computer generated number.
*/

int iRock = 0;
int iPaper = 1;
int iScissors = 2;
int iLizard = 3;
int iSpock = 4;
int iError = 5;
int iRandom = 5;

/*
The below integers are used to calculate the number of times the player beats the computer in the game and the number of turns / rounds which have been played. These have been set to 0 and will increase by an increment of +1 each time the player opts to continue playing.
*/

int iWinCounter = 0;
int iTurnCounter = 0;

/*
The below function prototypes (Grimes, R. 2017. p.34) have been defined as integers, as these will return values when the program is run. 
UserChoice() will return the value for iUser, which is used within GameCalculation() to determine what the user input is compared to the computer input.
Similarly, ComputerChoice() will return the value for iComputer to be used within GameCalculation() to determine what the computer input is compared to the user input.
Game() will return the value of 0 once the player has opted to finish playing the game and in conjunction with the boolean bGameActive, via a while loop, will quit the program. 
This also contains all of the required functions to run the main game: GameOptions(), UserChoice(), ComputerChoice(), GameCalculation() and QuitGame().
GameCalculation() will return the values for iWinCounter and iTurnCounter, as these are printed out once the player has confirmed that they no longer want to play the game.
This also contains a for loop which will compare iUser and iComputer via the 2D array and print out whether the player has won, tied or lost compared to the computer.
Additionally, as the function prototypes have been declared, the order in which your code can be presented can be in any order. For example, the main integer is at the top of the code but without declaring the prototypes, this would need to be at the bottom.
They can also be called to other functions within the code.
*/

int UserChoice();
int ComputerChoice();
int Game();
int GameCalculation();
int ProgramQuit();

/*
The below function prototypes have been defined as void functions, for they do not need to return a value. (Dawson, 2010. p.153)
Details on each of the void functions and their contents can be found above each void function.
The void functions can also be called to other functions in the code, as they have been declared.
*/

void GameRules();
void GameOptions();
void QuitGame();
void systemMenu();
void quitProgram();
void QuitRules();

/*
The below character variables (char) (Dawson, 2010. p.18) are used to define user input against a particular letter.
cMenuOption has been defined as the letter 'C' to confirm the user's choice to quit the program from the systemMenu().
cQuitOption has been defined as the letter 'Y' to confirm that when the user wants to quit the program altogether by selecting "Yes".
cGameQuitOption is defined as the letter 'Y' to confirm that when the player no longer wants to play the game and by selecting 'Y', this will quit the game and take them back to the main menu. 
cRulesQuitOptions is defined as the letter 'Y' to confirm that when the player no longer wants to review the rules for the game, after selecting option [B] in the main menu switch statement, that they want to quit the rules and return to the main menu.
*/

char cMenuOption = 'C';
char cQuitOption = 'Y';
char cGameQuitOption = 'Y';
char cRulesQuitOptions = 'Y';

/*
The below booleans will provide a true or false statement. (Dawson, 2010. p.18) In the event that the boolean remains true, the game, rules or program will remain active. In the event that the boolean is changed to false due to user input, it will quit the respective task.
*/

bool bProgramActive = true;
bool bGameActive = true;
bool bRulesActive = true;

/*
Below is the 2D array which I have used for the game. I have used a string array so that, depending on the outcome of iUser compared to iComputer, it will print out the corresponding message on whether the player has won, tied or lost.
I have declared the array as [iRowsAndCols][iRowsAndCols] which are each represented by the const int 5. (Horton, J. 2016. p.115 - 116)
Within the curly brackets, you will find the value which have been stored against each outcome when iUser is compared to iComputer. These have been done via string format, which will print out the desired outcome to the user when the calculation in GameCalculation() has been completed.
*/

																	/* Player Choice */

string sArray[iRowsAndCols][iRowsAndCols] = {       // Rock			  Paper		     Scissors		  Lizard		  Spock
									/*	Rock */     {"You Tied?",    "You Win!",     "You Lose...",  "You Lose...",  "You Win!"},
									/*	Paper */    {"You Lose...",  "You Tied?",    "You Win!",     "You Win!",     "You Lose..."},
			/* Computer Choice */	/*	Scissors */ {"You Win!",     "You Lose...",  "You Tied?",    "You Lose...",  "You Win!"},
									/*	Lizard */   {"You Win!",     "You Lose...",  "You Win!",     "You Tied?",    "You Lose..."},
									/*	Spock */    {"You Lose...",  "You Win!",     "You Lose...",  "You Win!",     "You Tied?"} };

/*
int main is the main function for the program and is where the main program is initialised. (Dawson, 2010. p.35)
The program will then return a value of 0, showing that it has ran successfully, once it has been completed.
*/

int main()
{
	ProgramQuit();
	return 0;
}


/*
Within the function Game() are the functions which are necessary to provide the games selection options (GameOptions()), allow user input (UserChoice()), allow for the computer to randomly generate a number for comparison (ComputerChoice())
and to complete the calculation in which iUser is compared to iComputer via the 2D array to provide a result (GameCalculation()).
The do while loop will run the code for the main game until the user opts to quit the game via the QuitGame() function, which changes the boolean bGameActive from true to false. (Gregoire, 2014. p.21)
This will then return a value of zero, to show that the game has successfully ran once it has been completed.
*/

int Game()
{
	GameOptions();

	UserChoice();
	cout << "*******************************" << endl;
	ComputerChoice();

	GameCalculation();

	do {
		QuitGame();
	} while (bGameActive);

	return 0;
}

/*
The below void function (systemMenu) is the main menu for the RPSLS game. In it, the user will be able to select from options A through C.
By using the switch statement, the user will be taken to the main game, game rules or can select the option to quit the game. 
A mixture of lower case and upper case letters can be used for the corresponding choice and will take the user to different branches of the code. (Dawson, 2010. p.51)
These are defined as cases, which represent a different aspect of the program.
For example, if the user were to input [b] or [B] they would be taken to the game rules.
The default has been used to confirm that if the user does not input A, B or C (or the lower case variants) then it is an error and further user input is required.
The system("CLS") at the beginning and end will clear the screen of any previous user input which was used in any of the functions contained within the switch statement.
*/

void systemMenu() 
{
	system("CLS"); 

	cout << "Welcome to the Rock, Paper, Scissors, Lizard, Spock game. Please select an option from A to C: " << endl;
	cout << "**********************************" << endl;
	cout << "[A] Play the game! " << endl;
	cout << "[B] Game Rules " << endl;
	cout << "[C] Exit the game. " << endl;
	cout << "**********************************" << endl;
	cin >> cMenuOption;

	switch (cMenuOption) {
	case 'a':
	case 'A':
		cout << "Welcome to Rock, Paper, Scissors, Lizard, Spock!" << endl;
		Game();
		break;

	case 'b':
	case 'B':
		GameRules();
		break;

	case 'c':
	case 'C':
		cout << "You have opted to quit the game. " << endl;
		quitProgram();
		break;

	default:
		cout << "That is an invalid option. Please select an option from A to C " << endl;
		system("pause");
		break;

		system("CLS");
	}
}

/*
The below void function GameOptions() will present the options which the player can select from each time they first start the game and each subsequent round.
This will be printed at the beginning of the Game() function.
*/

void GameOptions()
{
	cout << "Please select one of the following options from 0 to 4: " << endl;
	cout << "[0] Rock " << endl;
	cout << "[1] Paper " << endl;
	cout << "[2] Scissors " << endl;
	cout << "[3] Lizard " << endl;
	cout << "[4] Spock " << endl;
}

/*
In UserChoice(), the player will be asked to input a number from 0 - 4.
If the user inputs a number equal to or greater than iError (5) then the while loop will inform the user that it is an invalid option and to input a number between 0 - 4 again. (Horton, 2016. p.111)
The listed if (Dawson, 2010. p.40), else if (Dawson, 2010. p.45) and else (Dawson, 2010. p.48) statements will print out the corresponding phrase to advise what was selected by the user, if iUser is equal to the value stored in the respective integer. 
For example, if iUser is 1, this will print out the message for selecting paper.
iUser will then be returned as a value, which is used in the GameCalculation function.
*/

int UserChoice()
{
	cout << "*******************************" << endl;
	cout << "Please input your choice: " << endl;
	cout << "*******************************" << endl;
	cin >> iUser;

	while (iUser >= iError)
	{
		cout << "That is an invalid option. Please select a number between 0 and 4. " << endl;
		cin >> iUser;
	}

	if (iUser == iRock)
	{
		cout << "You have selected Rock. " << endl;
	}
	else if (iUser == iPaper)
	{
		cout << "You have selected Paper. " << endl;
	}
	else if (iUser == iScissors)
	{
		cout << "You have selected Scissors. " << endl;
	}
	else if (iUser == iLizard)
	{
		cout << "You have selected Lizard. " << endl;
	}
	else
	{
		cout << "You have selected Spock. " << endl;
	}

	return iUser;
}

/*
Within ComputerChoice, the integer iComputer is generated by calling the rand() function to generate a random number, where modulus is used to compare against the value stored for iRandom (5). (Dawson, M. 2010. p.70)
This will generate a random number between 0 - 4. Similarly, the if, else if and else statements will confirm the computer's choice and print out the message so the player knows what was selected.
The value iComputer is then returned to be used later in the GameCalculation function.
*/

int ComputerChoice()
{
	iComputer = rand() % iRandom;

	if (iComputer == iRock)
	{
		cout << "Computer has selected Rock. " << endl;
	}
	else if (iComputer == iPaper)
	{
		cout << "Computer has selected Paper. " << endl;
	}
	else if (iComputer == iScissors)
	{
		cout << "Computer has selected Scissors. " << endl;
	}
	else if (iComputer == iLizard)
	{
		cout << "Computer has selected Lizard. " << endl;
	}
	else
	{
		cout << "Computer has selected Spock. " << endl;
	}

	return iComputer;
}

/*
Within GameCalculation(), a nested for loop has been used to compare iUser with iComputer. In order to do so, two new integers (i & j) had to be declared within the loop to represent the user and computer input.
These are then set a rule to follow; in this case, if j is less than or equal to iComputer, j will increase by an increment of 1. This is the same for i. (Horton, J. 2016. p.114 - 115)
A nested if statement was then used to advise that if i is the same as iUser and j is the same as iComputer, then it will print out the result of the comparison for iUser and iComputer from the 2D array.
I have also added within the first nested if statement that iTurnCounter will equal iTurnCounter + 1, which will increase the number of turns counted by 1 each time the game is played.
Simiarly, the second nested if statement will count the number of times the result of the array is "You Win" and store these.
Both iTurnCounter and iWinCounter will then be returned for use later in the QuitGame function.
*/

int GameCalculation()
{
	for (int j = iComputer; j <= iComputer; j++)
	{
		for (int i = iUser; i <= iUser; i++)
		{
			if ((i == iUser) && (j == iComputer))
			{
				cout << "*******************************" << endl;
				cout << sArray[iComputer][iUser] << endl;
				cout << "*******************************" << endl;

				iTurnCounter = iTurnCounter + 1;

				if (sArray[iComputer][iUser] == "You Win!")
				{
					iWinCounter = iWinCounter + 1;
				}
			}
		}
	}

	return iTurnCounter;
	return iWinCounter;
}

/*
When the user selects to review the GameRules from the systemMenu switch statement, they will be provided with a brief overview of the game, information on the outcomes of each selection and the numbers which correspond to each choice.
When the user is finished reading, they can input a [Y] to leave the rules or an [N] to read them again. The option to quit via QuitRules is repeated until the player quits back to the main menu.
*/

void GameRules()
{
	system("CLS");

	cout << "**************************************************************************************************" << endl;
	cout << "Welcome to the rules section for the game Rock, Paper, Scissors, Lizard, Spock. " << endl;
	cout << "The player will select a number from 0 - 4, which correspond with a particular choice in the game. " << endl;
	cout << "The aim of the game is to pick one of the choices which defeats the computers choice. " << endl;
	cout << "However, the player does not know what the computer has selected and vice versa. " << endl;
	cout << "**************************************************************************************************" << endl;
	cout << "Below are the different outcomes: " << endl;
	cout << "Rock crushes Scissors and crushes Lizard " << endl;
	cout << "Paper covers Rock and disproves Spock " << endl;
	cout << "Scissors cuts Paper and decapitates Lizard " << endl;
	cout << "Lizard eats Paper and poisons Spock " << endl;
	cout << "Spock smashes Scissors and caporises Rock " << endl;
	cout << "**************************************************************************************************" << endl;
	cout << "Your choices are as follows: " << endl;
	cout << "[0] Rock " << endl;
	cout << "[1] Paper " << endl;
	cout << "[2] Scissors " << endl;
	cout << "[3] Lizard " << endl;
	cout << "[4] Spock " << endl;
	cout << "**************************************************************************************************" << endl;

	QuitRules();
}

/*
The function QuitGame is used to quit the main game in the Game() function.
The user will be asked if they would like to play again [Y] or quit the game [N].
If the user selects [n] or [N] the boolean bGameActive will change to false and quit the game, taking the user back to the main menu.
The else statement has been used to advise the player that any other input apart from [Y] or [N] is invalid and will loop back to the beginning asking for user input.
*/

void QuitGame()
{
	cout << "Would you like to play again? Please select [Y] to continue playing or [N] to quit back to the main menu. " << endl;
	cin >> cGameQuitOption;

	if (cGameQuitOption == 'n' || cGameQuitOption == 'N')
	{
		cout << "You have selected to quit the game. Taking you back to the main menu. " << endl;
		cout << "********************************************************************* " << endl;
		cout << "You have won " << iWinCounter << " out of " << iTurnCounter << " round(s). " << endl;
		cout << "********************************************************************* " << endl;
		bGameActive = false;
		system("pause");
	}
	else if (cGameQuitOption == 'y' || cGameQuitOption == 'Y')
	{
		cout << "You have selected to play again. " << endl;
		Game();
	}
	else
	{
		cout << "That is an invalid option. " << endl;
		QuitGame();
	}
}

/*
The function QuitRules is used to quit the game rules and take the user back to the main menu.
The user will be asked if they would like to go back to the main menu [Y] or review the rules again [N].
If the user selects [n] or [N] the boolean bRulesActive will change to false and quit the game, taking the user back to the main menu.
The else statement has been used to advise the player that any other input apart from [Y] or [N] is invalid and will loop back to the beginning asking for user input.
*/

void QuitRules()
{
	cout << "Would you like to go back to the main menu? Please input [Y] to quit or [N] to review again. " << endl;
	cin >> cRulesQuitOptions;

	if (cRulesQuitOptions == 'y' || cRulesQuitOptions == 'Y')
	{
		cout << "You have selected to go back to the main menu. " << endl;
		bRulesActive = false;
		system("pause");
	}
	else if (cRulesQuitOptions == 'n' || cRulesQuitOptions == 'N')
	{
		cout << "You have selected to review the rules. " << endl;
		system("pause");
		GameRules();
	}
	else
	{
		cout << "That is an invalid option. " << endl;
		QuitRules();
	}
}

/*
The quitProgram function is used to quit the program as a whole, when the option is selected from the main menu switch statement.
The user will be asked if they would like to stay in the program [Y] or quit the program [N].
If the user selects [n] or [N] the boolean bProgramActive will change to false and quit the program, returning the value of 0 and closing the program.
The else statement has been used to advise the player that any other input apart from [Y] or [N] is invalid and will loop back to the beginning asking for user input.
*/

void quitProgram()
{
	cout << "Please confirm that you would like to exit program by entering [Y] for yes or [N] for no. " << endl;
	cin >> cQuitOption;

	if (cQuitOption == 'y' || cQuitOption == 'Y')
	{
		cout << "You have selected to exit the program. " << endl;
		bProgramActive = false;
	}
	else if (cQuitOption == 'n' || cQuitOption == 'N')
	{
		cout << "You have opted to remain in the program. " << endl;
		bProgramActive = true;
		system("pause");
	}
	else
	{
		cout << "That is an invalid option. " << endl;
		quitProgram();
	}
}

/*
The function ProgramQuit is contains the code for when the user confirms that they want to quit the program altogether.
Whilst bProgramActive is true, the program will continue to run. Once changed to false via the quitProgram() function.
The do while loop will run the code and check to see if it is true or false after. 
A message will be printed out to thank the user for playing the game, via cout.
The system("pause") will pause the program until the user presses any key to continue.
*/

int ProgramQuit()
{
	bProgramActive = true;
	do {
		systemMenu();
	} while (bProgramActive);

	cout << "Thank you for playing! " << endl;

	return bProgramActive;

	system("pause");

}