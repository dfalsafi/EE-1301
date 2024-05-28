#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_NUM_DICE=50; //Number of Dice Formats

void userInputParser(string s, int dice[], int maxNumDie) ; //declares void function
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
int main() {
    int pairs[2 * MAX_NUM_DICE + 1] = {0};
    srand(time(0)); // DO NOT WRITE THIS LINE AGAIN OR ANYWHERE ELSE
    cout << "What die do you want to roll? (e.g. 4d3+2) ";
    string s;
    getline(cin, s);
    // populate the pairs array based on the input string s
    userInputParser(s, pairs, MAX_NUM_DICE);  

    // pairs[] is an array with the following format:
    // {array_size,
    //  first_die_min,
    //  first_die_max,
    //  second_die_min,
    //  ... }

    // == Replace the code below this line with your own code. == 

    // This example code will display the array of dice information 
    // retrieved from user.
    cout << "Number of Die Detected: " << pairs[0]/2 << endl;
    for(int i=1; i < pairs[0]; i=i+2) {
        cout << "Die #" << (i+1)/2 << ", ";
        cout << "min value: " << pairs[i] << ", ";
        cout << "max value: " << pairs[i+1] << "." << endl;
    }
    // == Replace the code above this line with your code. ==
    
}


void userInputParser(string s, int dice[], int maxNumDie) {
    // static int dice[2*MAX_NUM_DICE+1] = {}; // array format:
    // {array_size,
    //  first_die_min,
    //  first_die_max,
    //  second_die_min,
    //  ... }
    // maximum of MAX_NUM_DICE dice supported

    string data[4*maxNumDie];  // Intermediate storage for parsing input string

    // count how many '+'s or 'd's there are...
    int parts = 0;
    for(int i=0; i < s.length(); i++)
    {
        if(s[i] == 'd' || s[i] == '+')
        {
            parts++;
        }
    }
    // ... so we know the number of times to decode values

    int index=0;
    unsigned d = s.find('d');
    unsigned p = s.find('+');
    while(d != static_cast<unsigned>(-1) || p != static_cast<unsigned>(-1))
    {
        bool dFirst = d < p;
        if(dFirst)
        {
            string before = s.substr(0,d); // part before the 'd' (should be just one number)
            // figure out what number is after 'd'
            int count = 0;
            bool foundDigit=false;
            for(int i=0; i< static_cast<signed>(s.length()-d-1); i++)
            {
                if(isdigit(s[count+d+1]))
                {
                    foundDigit=true;
                }
                if(!isdigit(s[count+d+1]) && foundDigit)
                {
                    break;
                }
                count++;
            }
            string after = s.substr(d+1,count); //should be just the number after 'd'

            // store these two parts
            data[index] = before;
            data[index+1] = after;
            index+=2;


            // remove this part from the string s
            s = s.substr(d+count+1); // discard these two parts
        }
        else // same idea for the '+'
        {
            // figure out what number is after '+'
            int count = 0;
            bool foundDigit=false;
            for(int i=0; i< static_cast<signed>(s.length()-p-1); i++)
            {
                if(isdigit(s[count+p+1]))
                {
                    foundDigit=true;
                }
                if(!isdigit(s[count+p+1]) && foundDigit)
                {
                    break;
                }
                count++;
            }
            string after = s.substr(p+1,count); //should be just the number after '+'

            // store this part
            data[index] = "+";
            data[index+1] = after;
            index+=2;


            // remove this part from the string s
            s = s.substr(p+count+1); // discard these two parts
        }

        // update d and p for next loop interation
        d = s.find('d');
        p = s.find('+');

    }

    // now we need to figure out how many dice there are (as 2d4 is 2 dice)
    // we will treat "+2" as a die that rolls [2,2]
    int diceCount = 0;
    for(int i=0; i < parts*2; i+=2)
    {
        if(data[i][0] == '+')
        {
            diceCount++;
        }
        else
        {
            diceCount+=atoi(data[i].c_str());
        }
    }

    dice[0] = diceCount*2+1; // put size in first index

    int ind=1; // index for the "dice" array (as not same as data array)
    for(int i=0; i < parts*2; i+=2)
    {
        // if we have a +, add a "Dice" that has a range of 0
        if(data[i][0] == '+')
        {
            dice[ind] = atoi(data[i+1].c_str());
            dice[ind+1] = atoi(data[i+1].c_str());

            ind+=2;
        }
        else // otherwise add however many of the dice requested
        {
            for(int j=0; j < atoi(data[i].c_str()); j++)
            {
                dice[ind] = 1;
                dice[ind+1] = atoi(data[i+1].c_str());

                ind += 2;
            }
        }
    }

}
