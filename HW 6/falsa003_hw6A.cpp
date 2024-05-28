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
// Homework 6A

class Dice
{
private:
    int min; // delcare minimum roll values
    int max; // declare maximum roll values

public:
    Dice();                         // Default Constructor named after class
    Dice(int minimum, int maximum); // Constructor taking in arguments of min and max rolls that will execute in the Dice function
    void roll();
};

Dice::Dice()
{
    min = 1; // Lowest roll value is initialized as '1'
    max = 6; // Highest roll value is initialized as '6'
}
Dice::Dice(int minimum, int maximum)
{
    min = minimum;//The inputted minimum integer to be assigned to min
    max = maximum; // The inputted maximum integer to be assigned to max
}

void Dice::roll()
{
    srand(time(0)); //Random Number generator
    for (int i = 1; i < 11; i++) //Create a for loop with completing up to 10 iterations for generating a random value by "rolling" the dice each time when for loop is executed
    {
        cout << "Roll #" << i << " was: " << (rand() % (max - min + 1)) + min << endl; 
    }
    return;
}

int main()
{
    int givenmin;
    int givenmax;
    cout << "Let's set up a die to roll. What are the minimum and maximum values for this die?" <<endl;
   
    cout << "Minimum Value: ";
    cin >> givenmin; //user's minimum value for the dice when rolled
    cout << "Maximum Value: ";
    cin >> givenmax; //user's maximum value for the dice when rolled
    cout << endl;
    cout << "The die is rolled 10 times. The results of those rolls are: " << endl;
    Dice diceage(givenmin, givenmax); //the dice class is called that the struct function in the Dice class will be executed replacing the following maximum=givenmax  and  minimum=givenmin
    diceage.roll(); //rolls the dice iterating 10 times for 10 rolls with the random generated values within the range of max and min.
    return 0;
}
