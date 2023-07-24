# File input and output

## Opening and reading from a file

Sometimes a program should get input from a file rather than from a user typing on a keyboard. To read file input, a
programmer can create a new input stream that comes from a file, rather than the predefined input stream cin that comes
from the standard input (keyboard). An input stream can then be used just like cin.

The inFS.open(str) function has a string parameter str that specifies the name of the file to open. The filename
parameter can be a C++ string or a null-terminated C string. A program can also use a user-entered string as the
filename, such as using cin >> filename;.

```c++
#include <iostream>
#include <fstream>
using namespace std;

int main() {
   ifstream inFS;     // Input file stream
   int fileNum1;      // Data value from file
   int fileNum2;      // Data value from file

   // Try to open file
   cout << "Opening file numFile.txt." << endl;

   inFS.open("numFile.txt");
   if (!inFS.is_open()) {
      cout << "Could not open file numFile.txt." << endl;
      return 1; // 1 indicates error
   }

   // Can now use inFS stream like cin stream
   // numFile.txt should contain two integers, else problems
   cout << "Reading two integers." << endl;
   inFS >> fileNum1;
   inFS >> fileNum2;
   cout << "Closing file numFile.txt." << endl;
   inFS.close(); // Done with file, so close it

   // Output values read from file
   cout << "num1: " << fileNum1 << endl;
   cout << "num2: " << fileNum2 << endl;
   cout << "num1 + num2: " << (fileNum1 + fileNum2) << endl;

   return 0;
}

```

## Input stream errors

A **stream error** occurs when insertion or extraction fails, causing the stream to enter an error state. Ex: If a file
has the string two but the program attempts to extract an integer, the extraction will fail and the stream will enter an
error state.

An input stream may also enter an error state if a value extracted is too large (or small) to fit in the given variable.
While in an error state, an input stream may: skip extraction, set the given variable to 0, or set the given variable to
the maximum (or minimum) value of that variable's data type.

A stream internally uses several 1-bit error flags to track the state of the stream. A program can check a stream's
error state using several stream functions that return the current state. A stream's error state is cleared using
clear().

| Flag    | Meaning                                                                                                                             | Function                                                                                                           |
|---------|-------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------|
| goodbit | Indicates no error flags are set and the stream is good.                                                                            | **good()** returns true if no stream errors have occurred.                                                         |
| eofbit  | Indicates if end-of-file reached on extraction.                                                                                     | **eof()** returns value of eofbit, if end-of-file reached on extraction.                                           |
| failbit | Indicates a logical error for the previous extraction or insertion operation.                                                       | **fail()** returns true if either failbit or badbit is set, indicating an error for the previous stream operation. |
| badbit  | Indicates an error occurred while reading or writing the stream, and the stream is bad. Further operations on the stream will fail. | **bad()** returns true if badbit is set, indicating the stream is bad.                                             |
### Check for errors while reading a file.

```c++
inFS.open("Reviews.txt");

if (!inFS.is_open()) {
   cout << "Could not open file Reviews.txt."<< endl;
}

while (!inFS.eof() && inFS.good()) {
   inFS >> userName;
   inFS >> userRating;
  
   if (!inFS.fail()) {
      userNames.push_back(userName);
      userRatings.push_back(userRating);
   }
}

// If end-of-file not reached, then an error occurred
if (!inFS.eof()) {
   cout << "Error reading Reviews.txt." << endl;
   exit(EXIT_FAILURE);
}

```
