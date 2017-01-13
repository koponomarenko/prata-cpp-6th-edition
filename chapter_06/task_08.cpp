/*
    Write a program that opens a text file, reads it character-by-character to the end of
    the file, and reports the number of characters in the file.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    cout << "Enter a file name: ";
    string str;
    getline(cin, str);

    ifstream inFile;
    inFile.open(str.c_str());
    if (!inFile)
    {
        cerr << "Error: No such file" << endl;
        return -1;
    }

    long long characters = 0;
    while (inFile.get() && inFile.good())
    {
        ++characters;
    }
    inFile.close();
    cout << "\"" << str << "\" file has " << characters << " characters." << endl;
}
