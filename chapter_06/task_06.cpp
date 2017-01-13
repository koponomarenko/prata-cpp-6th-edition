/*
    Put together a program that keeps track of monetary contributions to the Society
    for the Preservation of Rightful Influence. It should ask the user to enter the num-
    ber of contributors and then solicit the user to enter the name and contribution of
    each contributor. The information should be stored in a dynamically allocated array
    of structures. Each structure should have two members:a character array (or else a
    string object) to store the name and a double member to hold the amount of the
    contribution. After reading all the data, the program should display the names and
    amounts donated for all donors who contributed $10,000 or more. This list should
    be headed by the label Grand Patrons. After that, the program should list the
    remaining donors. That list should be headed Patrons. If there are no donors in one
    of the categories, the program should print the word “none.” Aside from displaying
    two categories, the program need do no sorting.
*/

#include <iostream>
#include <string>
using namespace std;

struct Contribution {
    string name;
    double amount;
};

int main()
{
    cout << "Enter a number of contributors: ";
    int contributors = 0;
    cin >> contributors;
    cin.get();
    Contribution * contributions = new Contribution[contributors];

    bool patrons = false;
    bool grandPatrons = false;
    for (int i = 0; i < contributors; ++i)
    {
        cout << "Name of " << i + 1 << " contributor: ";
        getline(cin, contributions[i].name);
        cout << "Amount of contribution: ";
        cin >> contributions[i].amount;
        cin.get(); // removes a new line character

        if (!patrons && contributions[i].amount < 10000)
        {
            patrons = true;
        }
        if (!grandPatrons && contributions[i].amount >= 10000)
        {
            grandPatrons = true;
        }
    }

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
