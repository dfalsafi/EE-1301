#include <iostream>
#include <ctime>
 #include <cstdlib>

 using namespace std;
 int main(){
    srand(time(nullptr));
    //allows us to use the random operator on-1

    int values;
    while(true){
    cout<<"How many values do you want on each wheel? "<<endl;
    //asks user a question for an integer input
    cin>> values;
    if(values <= 0){
        // prevents the inputted value from being negative
        cout<<"Ok, goodbye."<<endl;
break;
    }
    
int max= values;
    int wheel1 = rand()% max +1;
    int wheel2 = rand()% max +1;
    int wheel3 = rand()%max+1;
    int wheel4 =rand()%max+1;
    //allows the integer values for each wheel to be random numbers that would be valid based on it having a remainder that would be valid if conditions are met
    cout<<"The wheels spin to give: "<<wheel1<<" "<<wheel2<<" "<<wheel3<<" "<<wheel4<<". ";
    //Once the user inputs a valid positive in range number the computer outputes three random numbers generated
if(wheel1 == wheel2 && wheel2 == wheel3 && wheel3 == wheel4){
    cout<<"Eureka!"<<endl;
}
//Once all the randomnumbers generated are the same for each assigned wheel, the computer outputs Eureka as a sign of victory
else{
    cout<<"You lose."<<endl;
    //If the wheels spinned are not the same then the user would have lost, which is a shame. 
} 
    }

return 0;

 }