#include <iostream>
using namespace std;

void creation(char first[], int length_first, char second[], int length_second, char result[]){
  int k=0;
    for ( k=0; k<length_first-1;k++){
        result[k]=first[k];
    }
    for(int j=0; j<length_second;j++){
result [j+k]= second[j];
    }

    result[length_first+length_second]='\0';
}
int main(){
    char first[] = "I am ";
    char second[]{'i','r','o','n','m','a','n','\0'};
char result[100];
creation(first, 6, second, 8, result);
cout<<result;
return 0;
}
