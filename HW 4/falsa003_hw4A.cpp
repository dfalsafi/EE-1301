#include <iostream>
#include <fstream>
#include <string>
// Name : Danyal Falsafi
// Course : EE 1301
// x500 : falsa003
//Homework 4A
using namespace std;

int main()
{
    ifstream inFS("grades.txt"); // says the object name is "inFS" that is making an ifstream for accessing the file grade.txt
    string name1;
    string name2;
    double grade; // Allows the grade to be identified as either a double in case if the file is specific with demicals

    int count_A = 0; // initializes the  integer value of numbert of studens recieving an A grade
    int count_B = 0; // initializes the  integer value of numbert of studens recieving an B grade
    int count_C = 0; // initializes the  integer value of numbert of studens recieving an C grade
    int count_D = 0; // initializes the  integer value of numbert of studens recieving an D grade
    int count_F = 0; // initializes the  integer value of numbert of studens recieving an F grade

    if (!inFS.is_open()) /*When the file is not open the following will be executed within the brackets.
    This command is from fstream library with using an if statement*/
    {
        cerr << "Failed to open file grades.txt" << endl; // Couts to the user that the file grades.txt that is trying to be opened has failed to do so apparently.
        return 1;
    }
    int count = 0; // This is the value integer percent the computer reads from teh given file grade.txt initializing the count value to start at 0.
    while (inFS >> name1 >> name2 >> grade)
    {
        count++;         //
        if (grade >= 90) // The grade read from the file being greater than 90 would add an increment of one to our count_A integer for the number of students who recieved an A
        {
            count_A++;
        }
        else if (grade >= 80) // The grade read from the file being greater than 80 would add an increment of one to our count_B integer for the number of students who recieved a B
        {
            count_B++;
        }
        else if (grade >= 70) // The grade read from the file being greater than 70 would add an increment of one to our count_C integer for the number of students who recieved a C
        {
            count_C++;
        }
        else if (grade >= 60) // The grade read from the file being greater than 60 would add an increment of one to our count_D integer for the number of students who recieved a D
        {
            count_D++;
        }
        else // The grade read from the file being less than 60 would add an increment of one to our count_F integer for the number of students who recieved an F
        {
            count_F++;
        }
    }
    if (inFS.eof())
    {
    }
    inFS.close(); // closes the grade.txt file for the following on the next line to be executed
    cout << count_A << " A" << endl; //Number of students from the file that have recieved an A
    cout << count_B << " B" << endl;//Number of students from the file that have recieved a B
    cout << count_C << " C" << endl;//Number of students from the file that have recieved a C
    cout << count_D << " D" << endl;//Number of students from the file that have recieved a D
    cout << count_F << " F" << endl;//Number of students from the file that have recieved an F

    ofstream outFS("statistics.csv", ios::app); // the following below is meant to execute the "statistics.csv" file's output for the computer to read the letter grade then the number of students
    outFS << "Grade,NumStudents" << endl;
    outFS << "A," << count_A << endl; // read out "A, " and then the number of students who recieved an A according to the file
    outFS << "B," << count_B << endl; // read out "B, " and then the number of students who recieved an B according to the file
    outFS << "C," << count_C << endl; // read out "C, " and then the number of students who recieved an C according to the file
    outFS << "D," << count_D << endl; // read out "D, " and then the number of students who recieved an D according to the file
    outFS << "F," << count_F << endl; // read out "F, " and then the number of students who recieved an F according to the file
        outFS.close();

    return 0;
}
