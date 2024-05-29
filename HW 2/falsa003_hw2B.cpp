#include <iostream>
#include <fstream>
#include <string>
using namespace std;


double power(double base, unsigned int exp)
{ // Creates a function that declares double type for "base" and an int named "exp" that can only be positive
    // double result = 0;
    if (exp == 0)
    {
        return 1;
    }
    else if (exp == 1) //When the exponent is 1 whatever the base is to the power of 1 results with returning a base
    {
        return base;
    }
    else
    {
        return base * power(base, exp - 1);
    }
}
int main(){
    //Question 1
    double y = 3;                //these are the practice runs for the power function to be executed correctly
    unsigned int x = 3;
    cout << power(y, x);

}