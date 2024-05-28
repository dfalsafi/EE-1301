#include <iostream> // cout, etc.
#include <stdlib.h> // srand, rand
#include <cmath>    // pow
#include <iomanip>  // setprecision
#include <ctime>    // time

using namespace std;
int spin_the_wheels(int d, int w)
{
    int i;
    int target = rand() % d; // generate number from 0 to d-1
    for (i = 1; i < w; ++i) //creates an iterartion for as long as i is less than the number of wheels the i will be incremented each time 
    {
        int next = rand() % d; //a random number will be divided by d to get the remainder that will go from 0 to d-1 for the coomputer to cause the function to allow the int next to be based on the wheel spinning values it has
        if (next != target) //When the d-1 is not reached through the int next then the computer will return 0 ending the program 
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
     srand(time(NULL)); 
    int w; //wheels declared
    int d;// different values declared
    int n;//iteration till a million declared shown in line 38(vscode)
    int wins; //declared integer value of wins that the user successfully gets the same number for each wheel in a row
    wins = 0;  // loop with a value for w is resetted and initialized to zero
    for (w = 3; w <= 6; ++w) //we have an initial of 3 wheels that for every iteration within the loop there is a wheel added until the maximum of 6 wheels is reached
    {
			wins = 0; //once the loop resets the number of wins is initialized
        for (d = 9; d <= 27; d += 3) //indicates the number of wheels on wheel goes up to 9 and that each iteration d changes by a multiple of 3 going up to 27
        { // loop for different values of d
            for (int n = 1; n <= pow(10,6); ++n)
            { // do a million iterations for following values of d and w
                if (spin_the_wheels(d, w) == 1) //states that when the function spin_the_wheel for integer w and d returns a value of 1 the if statement will be executed
                {
                    wins++; //when if statement of the function is true then we have a win on spinning the same number on all the wheels.
                }
            
            }
           cout << "w=" << w << ", "; //outputs the number of wheels present for the user to know
         cout << "d=" << d << ":"; //outputs the number of possible values the spin can output 
         cout << "Simulated probability = m/n = "<< fixed << setprecision(4)  << (double)wins / pow(d, w)*100 << "%. ";
//line above is calculating the simulated probability by using the number of wins generated divided by pow(d,w) multiplied by a hundred to formulate the percentage
            cout << "Theoretical Probability = " << fixed << setprecision(5)<<  (double)d / pow(d, w)*100 << "%." << endl;
//line above demonstrates that the numbers generated once divided by pow(d,w) and multiplied by a hundred tend to give our theoretical probability since it is assumed by the number of d values that are potentially used for the user to win 
        }
       
    }

    return 0;
}