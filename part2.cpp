#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
using namespace std;

//public variables
class myclass 
{
  public:
    static int playerinputset;
    char board[playerinputset][playerinputset];
    int playerX;
    int playerY;
};

//default board size is 15
//player can change the size
int boardsizing(int playerinput)
{
    myclass one;
    if (playerinput =! 15)
    {
        if (playerinput % 2 == 0)
        {
            cout << "Please enter an odd number for player to spawn in the middle. " <<endl;
        }
        else
        {
            one.playerinputset = playerinput;
        }
    }
    else
    {
        one.playerinputset = 15;
    }
    return 0;
}


int boardsizing2(int playerinput)
{
    myclass one;
    int playerinput2;
    playerinput2 = playerinput % 2;
    switch (playerinput2)
    {
        case 0:
            cout << "Please enter an odd number for player to spawn in the middle. " <<endl;
            break;
        case 1:
            one.playerinputset = playerinput2;
            break;
        default:
            one.playerinputset = 15;
            break;
    }
return 0;
}

//const int BOARD_SIZE = 15;

//char board[one.playerinputset][one.playerinputset];
//int playerX, playerY;


//where the player spawns
void initBoard() 
{
    myclass one;
    for (int i = 0; i < one.playerinputset; i++) {
        for (int j = 0; j < one.playerinputset; j++) 
        {
            one.board[i][j] = '.';
        }
    }

    one.playerX = one.playerinputset / 2;
    one.playerY = one.playerinputset / 2;
    one.board[one.playerX][one.playerY] = 'A';
}


//how the character moves
void movePlayer(char direction) 
{
    myclass one;
    one.board[one.playerX][one.playerY] = '.';
    if (direction == 'w' && one.playerX > 0) {
        one.playerX--;
    }
    else if (direction == 's' && one.playerX < one.playerinputset - 1) {
        one.playerX++;
    }
    else if (direction == 'a' && one.playerY > 0) {
        one.playerY--;
    }
    else if (direction == 'd' && one.playerY < one.playerinputset - 1) {
        one.playerY++;
    }
    else if (direction == 'q')
    {
        exit(0);
    }
    else
    {
        cout << "Invalid input, please enter the following input (q,w,a,s,d)" << endl;
    }
    one.board[one.playerX][one.playerY] = 'A';
}


//to print the board
void printBoard() 
{
    myclass one;
    for (int i = 0; i < one.playerinputset; i++) {
        for (int j = 0; j < one.playerinputset; j++) {
            cout << one.board[i][j] << " ";
        }
        cout << endl;
    }
}


//settings
int setting()
{ 
    myclass one;
    int sizing;
    cout << "Your board size is determined by AxA, where 'A' is your input" << endl;
    cout << "Enter your board size: ";
    cin >> sizing;
    boardsizing2(sizing);
    return 0;
}


//to start the game
int startgame()
{
    initBoard();
    printBoard();

    char direction;
    int directions;
    while (true) {
        cout << "Enter 'q' to exit the game" << endl;
        cout << "Enter direction (w, a, s, d): ";
        cin >> direction;
        cout << endl;
        movePlayer(direction);
        printBoard();
        //savemovement(direction);
    }

    return 0;
}

//to uppercase
string uppercase(const string& word)
{
    string newWord = word;
    for (int i = 0; i < newWord.size(); ++i)
    {
        newWord[i] = toupper(newWord[i]);
    }
    return newWord;
}

//the main menu
int mainmenu()
{
    cout << " ------------------------ " << endl;
    cout << " = Welcome to the game! = " << endl;
    cout << " -------------------------" << endl << endl;
    cout << " - Start   " << endl;
    cout << " - Load    " << endl;
    cout << " - Setting " << endl;
    cout << " - Quit    " << endl;

    string options;
    string option;
    cin >> options;
    option = uppercase(options);

    if (option == "START")
    {
        startgame();
    }
    else if (option == "LOAD") //soon to add
    {
        exit(0);
    }
    else if (option == "SETTINGS") //soon to add
    {
        exit(0);
    }
    else if (option == "QUIT")
    {
        exit(0);
    }
    else
    {
        exit(0);
    }
    return 0;
}


//main function
int main() 
{
    mainmenu();
    //initBoard();
    //printBoard();

    //char direction;
    //int directions;
    //while (true) {
    //    cout << "Enter direction (w, a, s, d): ";
    //    cin >> direction;
    //    cout << endl;
    //    movePlayer(direction);
    //    printBoard();
    //    savemovement(direction);
    //}

    //return 0;
}