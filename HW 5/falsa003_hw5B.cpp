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
// Homework 5B

int main(int argint, char *argchar[])
{
    if (argint != 4)
    { //
        cout << "Please provide exactly 3 integer values as command line arguments." << endl;
        cout << "Correct usage: " << argchar[0] << " <numRows> <numColumns> <arrayMax>" << endl;
        return 1;
    }
    int numRows = atoi(argchar[1]);
    int numColumns = atoi(argchar[2]);
    int arrayLarge = atoi(argchar[3]);

    // Open output file
    ofstream outputFile("randArray.txt"); //
    if (!outputFile)
    {
        cerr << "Unable to create output file" << endl; // If the file is unable to be created the will return an integer and disregarding the rest of the code in the function
        return 1;
    }

    srand(time(0)); // Generates random number

    outputFile << numRows << " " << numColumns << endl;
    // Write number of rows and columns to the "randArray.txt" file

    for (int i = 0; i < numRows; ++i)
    { // create a forloop iterating over number of rows
        for (int j = 0; j < numColumns; ++j)
        {                                                                 // within the forloop for every row every column will generate a random number in thee array's range [-arrayLarge,arraylarge]
            int randomValue = rand() % (2 * arrayLarge + 1) - arrayLarge; // Generates some random integer in bounds of -arrayMax and +arrayLarge
            outputFile << randomValue;
            if (j != numColumns - 1)
                outputFile << " "; // Space is added betweeen each value besides the last column of each row
        }
        // Once every column for the row is filled up with content, end line to go through the forloop once more starting at i=0 again till the one before the last row has been reached.
        outputFile << endl;
    }

    outputFile.close(); // closes "randArray.txt" file

    cout << "Matrix generated and stored in randArray.txt" << endl;

    return 0;
}