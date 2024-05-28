#include <iostream> // cout, etc.
#include <stdlib.h> // srand, rand
#include <cmath>    // pow
#include <iomanip>  // setprecision
#include <ctime>    // time

using namespace std;

int randWalk(int oldValue, int updateSize) // A new function named randWalk with parameters: int oldValue and in updateSize
{
    int newrange = -updateSize + rand() % (2 * updateSize + 1);
    return oldValue + newrange; /*this function when used is using the inputted oldValue from the user then adding it to a
     new integer that is created between -updateSize and +updateSize which will be the result by adding the new value of int new range to the oldValue originally*/
}

int main()
{
    srand(time(0));                                                         // Gives a starting point to the random function such as a new seed for the function to be initial at 0
    int updateSize;                                                         // Declaring integer updateSize
    int oldValue;                                                           // declaring initial value [0,255], integer
    int numIterations;                                                      // declaring the integer of iterations user inputs
    cout << "Please enter an initial integer value in the range [0,255]: "; // Asks user to select a value between 0 & 255
    do
    {   
            cin >> oldValue;                                      // Integer inputted by user
        if ((oldValue < 0 || oldValue > 255)) // The following statement will go through if the integer inputted is not between or equal to 0 and 255
        {
            cout << "Value must be between 0 and 255. Please enter an initial value in the range [0,255]: "; // Computer reminds user the range of the integer that could be inputted is [0,255] and the cin of the oldValue will be asked for again

            continue;
        }
        cout << "Please enter the desired number of iterations: ";                    // Asks for the number of iterations the user wants to be outputted
        cin >> numIterations;                                                         // User input of how many iterations they want for the computer to output
        cout << "Please enter the size of each possible update for each iteration: "; // Asking the user to choose how long they want the iteration to be in terms of size
        cin >> updateSize;                                                            // Users input of the size they want for the iterations to be

        for (int i = 1; i <= numIterations; i++) /*Using a continuous for loop with allowing out int i to start at one that the loop will keep running as long as the i value is
        less than number of Iterations then i++ increments 1 to i each time*/
        {
            oldValue = randWalk(oldValue, updateSize);                          // Usesd the function of randWalk to operate creating a new value between updatedSize and -updatedSize by adding to the oldValue, that sum is assigned to a new "oldValue" integer
            cout << "Value at iteration # " << i << " is: " << oldValue << endl; // For each iteration with from 1-i(number of iterations) as well as the new oldValue from what the function randWalk created based on the users input between [0,255]
        }
        break;
    } while (true);

    return 0;
}
