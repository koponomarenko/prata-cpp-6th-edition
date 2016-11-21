/*
    Write a program that matches the description of the program in Exercise 8,
    but use a string class object instead of an array. Include the string
    header file and use a relational operator to make the comparison test.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Enter words (to stop, type the word done):" << endl;
    string str;
    int numberOfWords = 0;
    cin >> str;
    while (str != "done")
    {
        numberOfWords++;
        cin >> str;
    }
    // discard other words/chars from cin buffer if any
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "You entered a total of " << numberOfWords << " words." << endl;
}
