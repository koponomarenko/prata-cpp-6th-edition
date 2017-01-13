/*
    Do Programming Exercise 6 but modify it to get information from a file. The first
    item in the file should be the number of contributors, and the rest of the file should
    consist of pairs of lines, with the first line of each pair being a contributor’s name
    and the second line being a contribution. That is, the file should look like this:
        4
        Sam Stone
        2000
        Freida Flass
        100500
        Tammy Tubbs
        5000
        Rich Raptor
        55000
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Contribution {
    string name;
    double amount;
};

int main()
{
    cout << "Enter a file name which has a list of contributors: ";
    string fileName;
    getline(cin, fileName);

    fstream inFile;
    inFile.open(fileName.c_str());
    if (!inFile)
    {
        cerr << "Error: No such file" << endl;
        return -1;
    }

    int contributors = 0;
    inFile >> contributors;
    inFile.get();
    Contribution * contributions = new Contribution[contributors];

    bool patrons = false;
    bool grandPatrons = false;
    for (int i = 0; i < contributors; ++i)
    {
        getline(inFile, contributions[i].name);
        inFile >> contributions[i].amount;
        inFile.get(); // removes a new line character

        if (!patrons && contributions[i].amount < 10000)
        {
            patrons = true;
        }
        if (!grandPatrons && contributions[i].amount >= 10000)
        {
            grandPatrons = true;
        }
    }
    inFile.close();

    if (grandPatrons)
    {
        cout << endl << "Grand Patrons:" << endl;
        for (int i = 0; i < contributors; ++i)
        {
            if (contributions[i].amount >= 10000)
            {
                cout << contributions[i].name << endl;
            }
        }
    }

    if (patrons)
    {
        cout << endl << "Patrons:" << endl;
        for (int i = 0; i < contributors; ++i)
        {
            if (contributions[i].amount < 10000)
            {
                cout << contributions[i].name << endl;
            }
        }
    }

    delete [] contributions;
}
