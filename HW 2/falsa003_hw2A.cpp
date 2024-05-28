 #include <iostream>
 #include <ctime>
 #include <cstdlib>

 using namespace std;
//falsa003
//HW 2A
//Danyal Falsafi
//EE 1301
 int main(){
    char n;
    cout<<"Enter a single digit or an alphabetic character: "<<endl;
    //Request stated for the user to input something that is 0-9,a-z, or A-Z.
    cin>> n;
 //character claimed from user to input a value or single integer
     if(n>=48 && n<=57){
         cout<<"You entered "<<n<<", which is a number."<<endl;
     }
     //According to the ASCII table this allows the output to be stated when the user inputs any digit 0-9.
   

 else if(n>=97 && n<=122){
 cout<<"You entered "<<n<<", which is a lowercase letter."<<endl;
 }     //According to the ASCII table this allows the output to be stated when the user inputs any lowercase letter.

     else if( n>=65 && n<=90){
         cout<<"You entered "<<n<<", which is an uppercase letter."<<endl;
     }
          //According to the ASCII table this allows the output to be stated when the user inputs any uppercase letter
   else{
 cout<<"You entered "<<n<<", which is not a letter or a number."<<endl;
 //Anything that is negative,symbol, double digit, or anything that has no assigned output will let the user know that it is invalid
   }

 }
