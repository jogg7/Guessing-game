#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>


void game();  //function that runs game


int main()
{
	//Generate new seed for pc
	srand(time(NULL));

	int answer; //users answer to play or quit
	std::string quit; //confirms user wants to quit game

	// loop to ask user to play or quit
	do
	{
		std::cout << "Press 1 to play game" << std::endl;  //User Presses 1 to play
		std::cout << "Press 0 to quit" << std::endl;       //0 ends the game
		std::cin >> answer;

		switch (answer)
		{
		case 0:
			std::cout << "You quit the game!" << std::endl;
			std::cout << "Are you sure you want to quit?\n";
			std::cin >> quit;
			if (quit == "Yes" || quit == "yes")                //confirm user wants to quit
			{
				std::cout << "Thanks for Playing. Good Bye.";
				return 0;
			}
			break;
		case 1:
			std::cout << "Let's play the game!" << std::endl;  //user wants to play game
			game();                                            //function call
		}
	} 
	while (answer != 1);
	
	

}


//guessing game for user vs computer
void game()
{
	//array to hold users answers
	int total_guesses_array[11];
	int guess_count = 0;


	int random_number;              //generate random number
	random_number = rand() % 11;    

	while (true)                    //Have user keep guessing until they are correct
	{
		int guess_answer;
		std::cout << "Guess a number 0 to 10\t";       //get guess from user
		std::cin >> guess_answer;

		total_guesses_array[guess_count] = guess_answer;  //hold users answer's
		guess_count++;


		if (guess_answer == random_number)             //Compare user's guess to computer's answer
		{
			std::cout << "The computer guessed: " << random_number << "\n";
			std::cout << "Your guess was: " << guess_answer << "\n";
			std::cout << "COngratulations, You Win!!\n";

			//Display users previous guesses from array total guesses 
			for (int i = 0; i < guess_count; i++)
			{
				std::cout << total_guesses_array[i] << "\t" << std::endl;
			}

			break;
		
		}
	
	}
}