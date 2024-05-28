#include <iostream>
using namespace std;
void time_conversion(int inp, int& hours, int& mins){
hours = inp/60;

mins=inp%(60);
return;
}

int main(){
    char yesNo = 'y';
    while(yesNo=='y'){
        int inp; 
        int hours;
        int mins;
        cout<<"Enter a number of minutes: ";
        cin>>inp;
        time_conversion(inp, hours, mins);
        cout<<"Hours:minutes is "<< hours<<":";
        if(mins<10){
            cout<<"0";
        }
        cout<<mins<<endl;
        cout<<"continue?";
        cin>>yesNo;
    }


}