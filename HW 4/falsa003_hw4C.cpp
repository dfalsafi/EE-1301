#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
// Name : Danyal Falsafi
// Course : EE 1301
// x500 : falsa003
// Homework 4C
using namespace std;

int main()
{
    if (!filesystem::exists("output_files"))
    {
        filesystem::create_directory("output_files");
    }
    std::filesystem::path folderPath = "output_files";
    std::filesystem::path fileName = "election_results.txt";
    std::filesystem::path inputfolderPath = "input_files";
    std::filesystem::path inputfileName = "blahblah.txt";
    std::filesystem::path inputfilePath = inputfolderPath / inputfileName;
    std::filesystem::path filePath = folderPath / fileName;
    std::ofstream outFS(filePath);
    int a_count = 0;
    int e_count = 0;
    int i_count = 0;
    int o_count = 0;
    int u_count = 0;
    ifstream in(inputfilePath);
    if (!in)
    {
        cout << "Cannot open input file.\n";
        return 1;
    }
    string str;
    while (getline(in, str))
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == 'a' || str[i] == 'A')
            {
                a_count++;
            }
            else if (str[i] == 'e' || str[i] == 'E')
            {
                e_count++;
            }
            else if (str[i] == 'i' || str[i] == 'I')
            {
                i_count++;
            }
            else if (str[i] == 'o' || str[i] == 'O')
            {
                o_count++;
            }
            else if (str[i] == 'u' || str[i] == 'U')
            {
                u_count++;
            }
        }
    }
    in.close();
    int highest_count;
    string winner;
    if (a_count > e_count && a_count > i_count && a_count > o_count && a_count > u_count)
    {
        highest_count = a_count;
        winner = 'A';
    }
    else if (e_count > a_count && e_count > i_count && e_count > o_count && e_count > u_count)
    {
        highest_count = e_count;
        winner = 'E';
    }
    else if (i_count > a_count && i_count > e_count && i_count > o_count && i_count > u_count)
    {
        highest_count = i_count;
        winner = 'I';
    }
    else if (o_count > a_count && o_count > e_count && o_count > i_count && o_count > u_count)
    {
        highest_count = o_count;
        winner = 'O';
    }
    else if (u_count > a_count && u_count > e_count && u_count > i_count && u_count > o_count)
    {
        highest_count = u_count;
        winner = 'U';
    }
    cout << "The results are in!\n";
    cout << "A/a "
         << "received " << a_count << " votes\n";
    cout << "E/e "
         << "received " << e_count << " votes\n";
    cout << "I/i "
         << "received " << i_count << " votes\n";
    cout << "O/o "
         << "received " << o_count << " votes\n";
    cout << "U/u "
         << "received " << u_count << " votes\n";
    cout << "The winner is the letter \"" << winner << "\"!";
    outFS << "A," << a_count << endl;
    outFS << "E," << e_count << endl;
    outFS << "I," << i_count << endl;
    outFS << "O," << o_count << endl;
    outFS << "U," << u_count << endl;
    return 0;
}