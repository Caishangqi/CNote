#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream inFS; // Input file stream        
    string userWord;
    int wordFreq = 0;
    string currWord;

    // Open file
    cout << "Opening file wordFile.txt." << endl;
    inFS.open("wordFile.txt");

    if (!inFS.is_open())
    {
        cout << "Could not open file wordFile.txt." << endl;
        return 1;
    }

    // Word to be found
    cout << "Enter a word: ";
    cin >> userWord;

    // Identify when a word matches the userWord 
    // and increase wordFreq
    while (!inFS.eof())
    {
        inFS >> currWord;
        if (!inFS.fail())
        {
            if (currWord == userWord)
            {
                ++wordFreq;
            }
        }
    }

    cout << userWord << " appears in the file "
        << wordFreq << " times." << endl;

    // Done with file, so close it
    inFS.close();

    return 0;
}
