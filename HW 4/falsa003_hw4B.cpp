#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
// Name : Danyal Falsafi
// Course : EE 1301
// x500 : falsa003
//Homework 4B
using namespace std;

int main() {
    ifstream inFS("statistics.csv");
    ofstream outFS("histogram.txt");
    
    if (!inFS.is_open() || !outFS.is_open()) {
        cout << "Could not open file." << endl;
        return 1;
    }
    
    string line;
    int max = 0;
    
    while (getline(inFS, line)) {
        stringstream ss(line);
        string grade;
        int exes;
        
        getline(ss, grade, ',');
        ss >> exes;
        
        if (exes > max) {
            max = exes;
        }
        
        outFS << exes << " X" << endl;
    }
    
    if (!inFS.eof()) {
        cout << "Input failure before reaching the end of the file." << endl;
    }
    
    inFS.close();
    
    int numEqualSigns = (1 + max) * 2;
    
    for (int i = 0; i < numEqualSigns; ++i) {
        outFS << "-";
    }

    outFS << endl;
    outFS << " ABCDF" << endl;
    
    outFS.close();
    
    cout << "Histogram has been written to histogram.txt" << endl;
    
    return 0;
}
