#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    /* File Handling with C++ using ifstream & ofstream class object*/
    /* To write the Content in File*/
    /* Then to read the content of file*/

    // Creation of ofstream class object
    std::ofstream fileOut;
    std::string content;

    /*
     * by default ios::out mode, automatically deletes
     * the content of file. To append the content, open in ios:app
     * fout.open("sample.txt", ios::app)
     */

    fileOut.open("file/sample.txt");

    // Execute a loop If file successfully opened
    while (fileOut)
    {
        // Read a Line from standard input
        getline(std::cin, content);

        // Press -1 to exit
        if (content == "-1")
            break;

        // Write line in file
        fileOut << content << std::endl;
    }
    // Close the File
    fileOut.close();

    // Creation of ifstream class object to read the file
    std::ifstream fileIn;

    // by default open mode = ios::in mode
    fileIn.open("file/sample.txt");

    // Execute a loop until EOF (End of File)
    while (std::getline(fileIn, content))
    {
        // Print line (read from file) in Console
        std::cout << content << std::endl;
    }

    // Close the file
    fileOut.close();
}
