#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iomanip>
using namespace std;

// Name : Danyal Falsafi
// Course : EE 1301
// x500 : falsa003
// Homework 5C

ifstream Array;

int main(int argument1, char *argument2[])
{ // comand line arguments
    if (argument1 != 2)
    {
        // makes sure for there to be the correct number of arguments
        cout << "Incorrect number of arguments!" << endl
             << "Correct usage: ./HW5C <filename>" << endl;
        return 1;
    }
    string ArrayName = argument2[1]; // There is a string type array for the array "argument2" at the first index

    ifstream fin(ArrayName); // creates input File streamn
    if (!fin.is_open())
    { // The following will execute returning an integer in the function skipping the rest of the code if file is opened incorrectly
        cout << "Cannot find specified text file." << endl;
        return 1;
    }

    int temp;
    fin >> temp;
    const int ySize = temp;
    fin >> temp;
    // From the file the first two characters are taken out setting to both x and y seperately
    const int xSize = temp;
    double original[xSize][ySize]; // Based on our original file we collect the information(data) to form an array
    while (true)
    {
        for (int yPos = 0; yPos < ySize; yPos++) // Iterates over this orginal's file's ySize
        {
            for (int xPos = 0; xPos < xSize; xPos++) // Iterates over this orginal's file's xSize
            {
                fin >> temp;
                original[xPos][yPos] = temp; // Assigns the value of the "temp" integer to the array specifically at xPos & yPos
            }
        }
        if (!fin.eof())
            break; // End of file indicator
    }
    fin.close();                             // Closes file
    double output[xSize][ySize];             // This is the output file that is being created
    int total = 0, iteration = 0;            // initializes
    for (int yPos = 0; yPos < ySize; yPos++) // For loop iterating from yPos to (yPos-1) by increments
    {
        for (int xPos = 0; xPos < xSize; xPos++) // For loop iterating from xPos to (xPos-1) by increments
        {
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    if ((yPos + y) >= 0 && (xPos + x) >= 0 && (yPos + y) < ySize && (xPos + x) < xSize) // Verifies that the x and y values would result in applicable xPos and yPos values
                    {
                        total = total + original[xPos + x][yPos + y];
                        iteration++;
                    }
                }
            }
            output[xPos][yPos] = round(total / iteration);
            total = 0; // initializes for when regoing through forloop
            iteration = 0;
        }
    }
    // The rest is outputting the new array
    for (int yPos = 0; yPos < ySize; yPos++) // For loop iterating from yPos to (yPos-1) by increments
    {
        for (int xPos = 0; xPos < xSize; xPos++) // For loop iterating from xPos to (xPos-1) by increments
        {
            cout << output[xPos][yPos]; // Simply outputs the value of the array
            if (xPos < xSize)
            {
                cout << " "; // Every column needs a space after it besides the last one
            }
        }
        cout << endl;
    }
    return 0;
}