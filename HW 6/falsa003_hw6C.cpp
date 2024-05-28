#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// Name : Danyal Falsafi
// Course : EE 1301
// x500 : falsa003
// Homework 6C

// Function prototype for binary search
int binarySearch(const int sortedArray[], int numVal, int leftBound, int rightBound);

int main() {
    // File stream for reading for an inputting of a file
    ifstream fin;

    // Array to store sorted values which is intialized
    int sortedArray[1000] = {0};
    
    // numberOfNumbers to kcount the number of elements read from the file inputted
    int numberOfNumbers = 0;
    
    // Number to search for in the array
    int numVal = 0;
    
    // File name
    string name_file;

    // Asks the user to provide the file name for the array they want to search
    cout << "What is the file with the array you want to search? ";
    cin >> name_file;

    // Prompt user for the number to find
    cout << "What is the number you want to find? Please provide an integer: ";
    cin >> numVal;

    // Open the file
    fin.open(name_file);

    // "If statement" will follow through then ending the code returning an integer if file is unsuccessfully opened
    if (!fin.is_open()) {
        cout << "Error in opening file";
        return 1;
    }

    // Reads values from  file to move into the array
    while (numberOfNumbers < 1000 && fin >> sortedArray[numberOfNumbers]) {
        numberOfNumbers = numberOfNumbers + 1;
    }

   //File Closed
    fin.close();

    // Length of the array
    int Length_Array = numberOfNumbers;

    // Perform binary search
    binarySearch(sortedArray, numVal, 0, numberOfNumbers - 1);

    return 0;
}

// Binary search function
int binarySearch(const int sortedArray[], int numVal, int leftBound, int rightBound) {
    // Check if the search interval is valid
    if (leftBound > rightBound) {
        cout << numVal << " is not in sortedArray" << endl;
        return -1;
    }

    // Calculate the middle index
    int midVal = (leftBound + rightBound) / 2;
    
    // Get the element at the middle index
    int foundElement = sortedArray[midVal];
    // Uncomment the line below to display the current index being examined
    // cout << "Looking at index: " << midVal << endl;

    // Check if the found element is equal to the desired value
    if (foundElement == numVal) {
        cout << numVal << " can be found at sortedArray[" << midVal << "]" << endl;
        return midVal;
    } else if (foundElement < numVal) {
        // If the found element is less than the desired value, search the upper half
        return binarySearch(sortedArray, numVal, midVal + 1, rightBound);
    } else {
        // If the found element is greater than the desired value, search the lower half
        return binarySearch(sortedArray, numVal, leftBound, midVal - 1);
    }
}