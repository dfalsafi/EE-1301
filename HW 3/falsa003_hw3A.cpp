#include <iostream> // cout, etc.
#include <stdlib.h> // srand, rand
#include <cmath>    // pow
#include <iomanip>  // setprecision
#include <ctime>    // time

using namespace std;

int main()
{
    int input1;

    do
    {

        cout << "Enter an integer from -50 to 50: ";
        // Asks the user to select an integer ranging from 50 to -50
        cin >> input1;
        // Assigned variable "input1" to be the response of the user to the computer
        if (input1 == 0)
        { // if inputted value by the user is zero the code says "Goodbye."
            cout << "Goodbye." << endl;
            break; // stops the code at that point from moving forward executing none of the following instructions
        }
        else if (input1 < -50 || input1 > 50)
        {
            cout << "Sorry, you have entered an out of bounds input! Please enter a valid value."<<endl;
            /*When the input is less than -50 or greater than 50 the output will be invalid as th
             inputted values will be outside of the range the computer asked for the user to input*/
            continue;
        }
        else if (input1 > 0)
        {
            for (int i = 1; i <= input1; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    cout << i;
                }
                cout << endl;
            }
        }
        else
        {

            input1 = -input1; // allows the positive and negative integers to be outputting the same results from the computer
            for (int R = input1; R >= 1; R--)
            {
                for (int D = 0; D < R; D++)
                {
                    cout << R;
                }
                cout << endl;
            }
        }
    } while (true);
    return 0; // returns a 0 as the integer to the device for function int main()
}
