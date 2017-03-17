//  Rock, Paper, Scissors is a two-person game typically played using hand gestures.
//  Both players make a fist with one hand and hold the other open, palm upward. Together,
//  they tap their fists in their open palms once, twice, and on the third time form one
//  of three items: a rock (by keeping the hand in a fist), a sheet of paper (by holding
//  the hand flat, palm down), or a pair of scissors (by extending the first two fingers
//  and holding them apart in a “V”).
//
// There are only three possible outcomes other than a tie:
//  1) Rock cuts Scissors
//  2) Paper covers Rock
//  3) Scissors cuts Paper
//
// If both players throw the same shape, the game is tied and is usually replayed to break the tie.


#include <iostream>
#include <string>
#include<ctime>
#include<cstdlib>
using namespace std;

enum Selection {
    NONE,
    ROCK,
    PAPER,
    SCISSORS
};

enum Result {
    DRAW,
    WON,
    LOST,
    ERROR
};

// Declaring two global variable

int prevInput = 0; // To store previous input of user.
int currInput;     // To store current input of user.

// Figure out what the selection is from the specified integer
Selection GetSelectionForInteger(int inputInteger) {
   
    if(inputInteger == 1)
       {
           return ROCK;
       }
    else if(inputInteger == 2)
       {
           return PAPER;
       }
    else if(inputInteger == 3)
       {
           return SCISSORS;
       }
    else
       {
           return NONE;
       }

}

// Returns a random number between min and max, inclusive of both
int GetRandomNumber(int min, int max) {
    
    int seed = time(0); //gets system time
    srand(seed); //seed the random number

    min = 1 + rand() % max; //generate random number between 1 to 3.

    return min;
}

// Returns the selection for the AI according to a certain strategy
Selection GetAISelection() {

    int number;

    // Using strategy to predict according to user input.
    // If previous input of user is equal to current input then
    // our AI will predict according to it.

    if(prevInput == currInput)
    {
        if(currInput == 1)
        {
            return PAPER;
        }
        else if(currInput == 2)
        {
            return SCISSORS;
        }
        else
        {
            return ROCK;
        }
    }

    // For next round we have to initialize previous input
    // with current input obviously.
    prevInput = currInput;

    // If previous input is not equal to current input then
    // our AI will use the GetRandomNumber function.

    number = GetRandomNumber(1,3); // Calling GetRandomNumber function to get
                                   // random number between 1 to 3.
    if(number == 1)
       {
          return ROCK;
       }
    else if(number == 2)
       {
          return PAPER;
       }
    else
       {
          return SCISSORS;
       }

}

// Compares the user's selection to the AI's selection,
// and determines the result of the round. If the user beats
// the AI it is considered a WIN, etc.
Result GetResult(Selection userSelection, Selection aiSelection) {
   
    if (userSelection == aiSelection) // When User and AI selects same option.
    {
        return DRAW;
    }

    else if ( userSelection == 1 && aiSelection == 2) // When User selects Rock and
    {                                            // AI selects Paper.
        return LOST;
    }
    else if (userSelection == 1 && aiSelection == 3) // When User selects Rock and
    {                                                // AI selects Scissors.
        return WON;
    }

    else if (userSelection == 2 && aiSelection == 1) // When User selects Paper and
    {                                           // AI selects Rock.
        return WON;
    }
    else if ( userSelection == 2 && aiSelection == 3) // When User selects Paper and
    {                                                 // AI selects Scissors.
        return LOST;
    }

    else if ( userSelection == 3 && aiSelection == 1) // When User selects Scissors and
    {                                            // AI selects Rock.
        return LOST;
    }
    else if (userSelection == 3 && aiSelection == 2) // When User selects Scissors and
    {                                                // AI selects Paper
        return WON;
    }
    else
    {
        return ERROR;
    }

}

// Display the instructions of what number corresponds to which selection
void ShowInitalUI(int roundNum) {
    cout << "\nRound #" << roundNum << ":\n";
    cout << "\nEnter the number associated with the option below to select your move:";
    cout << "\n1. Rock";
    cout << "\n2. Paper";
    cout << "\n3. Scissors";
    cout << "\n\nQ. Quit the game";
    cout << "\n> ";
}

// Displays the appropriate string for each Selection
void DisplaySelection(Selection a_nSelection) {
   
     if(a_nSelection == 1)
      {
         cout<<"ROCK\n";
      }
      else if(a_nSelection == 2)
      {
         cout<<"PAPER\n";
      }
      else if(a_nSelection == 3)
      {
         cout<<"SCISSORS\n";
      }
      else
      {
          cout<<"NONE\n";
      }
}

// Displays an appropriate string for each Result
void DisplayResult(Result result) {
    if(result == WON) {
        cout<<"\n\n YOU have WON this round";

    } else if(result == LOST) {
        cout<<"\n\n The COMPUTER has WON this round";

    } else if(result == DRAW) {
        cout<<"\n\n This round is a DRAW";

    } else {
        cout<<"\n\nOops! Something has gone wrong!";
    }

}

int main(int argc, const char * argv[]) {

    // Init variables
    int roundNum = 1;

    Selection playerSelection = NONE;
    Selection aiSelection     = NONE;

    // Start game

    cout << "\nWelcome to a game of Rock, Paper, Scissors!\n";

    while(1){

    ShowInitalUI(roundNum);

    // Gets player input
    string input;
    getline(cin, input);
    if(input == "Q" || input == "q")
        exit(1);
  
    int playerInputInt = atoi( input.c_str() );

    // Saving current input of user.
    currInput = playerInputInt;

    playerSelection = GetSelectionForInteger(playerInputInt);
    // Show selected option
    cout<<"\nYou have Selected: ";
    DisplaySelection(playerSelection);

    // Let the AI make a selection
    aiSelection = GetAISelection();

    // Show option selected by AI
    cout<<"\nThe Computer has Selected: ";
    DisplaySelection(aiSelection);

    // Display final result
    Result result = GetResult(playerSelection, aiSelection);
    DisplayResult(result);

    cout<<"\n";

    cout << "\nThank you for playing!\n\n";
    roundNum++;
    cout<<"Would you like to have another round?\n";
    cout<<"Press 'y' for Yes and 'n' for No.\n";

    //To get user input whether to play the game again or not.
    string playGame;
    getline(cin,playGame);

    if(playGame == "y" || playGame == "Y")
       {
           continue;
       }
    else
       {
            break;
       }

 }
    return 0;
}




