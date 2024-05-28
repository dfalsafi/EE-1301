#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

// Name : Danyal Falsafi
// Course : EE 1301
// x500 : falsa003
// Homework 5A

const char BLANK = '-';
const char ROBOT = 'X';
const char GOAL = 'O';           // This character 'O' is constant character
const char WALL = 'W';           // new char for wall to appear as 'W' on the maze
const int screen_num_lines = 25; // The output is supposed to have a total of 25 lines
const int lengthX = 10;          // There are 10 rows for the board that is being used for this code's dimensions
const int lengthY = 10;          // There are 10 columns for the board that is being used for this code's dimensions

void initBoard(char board[lengthX][lengthY], int &xPos, int &yPos);
void newBoard(char board[lengthX][lengthY], int &xPos, int &yPos); // Function for rearranging everything to make a new board

void clearScreen();
void showGrid(char board[lengthX][lengthY]);

bool hasChar(char board[lengthX][lengthY], char findMe);
void updateGrid(char board[lengthX][lengthY], int &xPos, int &yPos, char action);

int main()
{
    char board[lengthX][lengthY] = {0};
    int xPos = 0, yPos = 0;
    ifstream inFS;
    inFS.open("maze.txt"); // Opens the file called "maze.txt"
    if (inFS.is_open())    // Following will be executed once file is opened
    {
        newBoard(board, xPos, yPos); // A new board will be formed consisting of multiple parameters embedded in the paranthesis
        inFS.close();                // closes the file
    }
    else
    {
        initBoard(board, xPos, yPos); // Initialized the board
    }

    while (hasChar(board, GOAL))
    {
        char action;
        clearScreen();
        showGrid(board);
        cout << "Where would you like to go? (l, r, u, d) " << endl;
        cin >> action;
        // Asks user directions they would want to move the robot that whatever inputted will be inputted in the character "action"

        updateGrid(board, xPos, yPos, action); // updates parameters of the grid based on what is inputted
    }

    clearScreen();
    showGrid(board);
    cout << "You found the cookie!  Congratulations!\n";

    return 0;
}

/*
Description: Initializes game board. Sets all characters in board as blanks,
then sets position of goal, and then sets position of robot.
Inputs:
    char board[][] - 2D array used to represent game board
    int xPos - saved x position of robot
    int yPos - saved y position of robot
Outputs: NA
*/
void initBoard(char board[lengthX][lengthY], int &xPos, int &yPos)
{
    for (int curRow = 0; curRow < lengthY; curRow++)
    {
        for (int curCol = 0; curCol < lengthX; curCol++)
        {
            board[curCol][curRow] = BLANK;
        }
    }

    board[2][9] = GOAL; // These maze's default walls that is programmed onto the board
    board[3][3] = WALL;
    board[3][4] = WALL;
    board[5][9] = WALL;
    board[9][2] = WALL;
    board[1][1] = WALL;
    board[2][1] = WALL;
    board[lengthX / 2][lengthY / 2] = ROBOT;

    xPos = lengthX / 2;
    yPos = lengthY / 2;
}
void newBoard(char board[lengthX][lengthY], int &xPos, int &yPos)
{ // Makes a character array board representing a maze from using x and y as reference for moving the robot

    ifstream inFS;         // Reads the data from the file
    inFS.open("maze.txt"); // opens maze.txt file
    char fileChars;        // delcaration of character to store contents from the file
    for (int curRow = 0; curRow < lengthY; curRow++)
    {
        for (int curCol = 0; curCol < lengthX; curCol++)
        {
            inFS >> fileChars;                 // reads character from file maze.txt as a variable called "fileChars"
            board[curCol][curRow] = fileChars; // sets the character of the board to that
            if (board[curCol][curRow] == ROBOT)
            { // sets the initial position of the robot within the maze
                xPos = curCol;
                yPos = curRow;
            }
        }
    }
    inFS.close(); // closing file
}

/*
Description: Loops through given game board to determine if it contains given char findMe.
Inputs:
    char board[][] - 2D array used to represent game board
    char findMe - character to look for in game board
Outputs:
    bool - returns true if board contains findMe, else returns false
*/
bool hasChar(char board[lengthX][lengthY], char findMe)
{
    for (int curRow = 0; curRow < lengthY; curRow++)
    {
        for (int curCol = 0; curCol < lengthX; curCol++)
        {
            if (board[curCol][curRow] == findMe)
            {
                return true;
            }
        } // end curCol loop
    }     // end curRow loop

    return false;
}

/*
Description: Prints out screen_num_lines amount of end lines to terminal so
that old board is no longer visible.
Inputs: NA
Outputs: NA
*/
void clearScreen()
{
    for (int i = 0; i < screen_num_lines; i++)
    {
        cout << endl; // Starting at the first line to the one before the last line there will be a new line once each line's content is presented
    }
}

/*
Description: Prints out input game board to the terminal.
Inputs:
    char board[][] - 2D array used to represent game board
Outputs: NA
*/
void showGrid(char board[lengthX][lengthY])
{
    for (int curRow = 0; curRow < lengthY; curRow++)
    {
        for (int curCol = 0; curCol < lengthX; curCol++)
        {
            cout << board[curCol][curRow];
        } // end curCol loop
        cout << endl;
    } // end curRow loop
}

/*
Description: Updates saved grid position of robot based on input action.
Inputs:
    char board[][] - 2D array used to represent game board
    int xPos - saved x position of robot
    int yPos - saved y position of robot
    char action - desired direction for robot to move, i.e. 'l', 'r', 'u', or 'd'
Outputs: NA
*/
void updateGrid(char board[lengthX][lengthY], int &xPos, int &yPos, char action)
{
    int new_xPos = xPos;
    int new_yPos = yPos;

    board[xPos][yPos] = BLANK;
    if (action == 'l' && xPos > 0) //
    {
        if (board[xPos - 1][yPos] != WALL)
        /*The robot moves accordingly to the direction asked of the user as
        long as there is no wall to interfere */
        {
            xPos--;
        }
        else
        {
            /*Puts the robot back to its original place any time it hits a wall
           so it stays in put*/
            board[xPos][yPos] = ROBOT;
        }
    }
    else if (action == 'r' && xPos < lengthX - 1)
    {
        if (board[xPos + 1][yPos] != WALL)
        {
            /*The robot moves accordingly to the direction asked of the user as
       long as there is no wall to interfere */
            xPos++;
        }
        else
        {
            /*Puts the robot back to its original place any time it hits a wall
           so it stays in put*/
            board[xPos][yPos] = ROBOT;
        }
    }
    else if (action == 'u' && yPos > 0)
    {
        if (board[xPos][yPos - 1] != WALL)
        {
            /*The robot moves accordingly to the direction asked of the user as
       long as there is no wall to interfere */
            yPos--;
        }
        else
        {
            /*Puts the robot back to its original place any time it hits a wall
           so it stays in put*/
            board[xPos][yPos] = ROBOT;
        }
    }
    else if (action == 'd' && yPos < lengthY - 1)
    {
        if (board[xPos][yPos + 1] != WALL)
        {
            /*The robot moves accordingly to the direction asked of the user as
       long as there is no wall to interfere */
            yPos++;
        }
        else
        {
            board[xPos][yPos] = ROBOT;
            /*Puts the robot back to its original place any time it hits a wall
            so it stays in put*/
        }
    }

    board[xPos][yPos] = ROBOT;
}
