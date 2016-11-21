/*
    Write a program that uses an array of char and a loop to read one word at a time
    until the word done is entered. The program should then report the number of
    words entered (not counting done). A sample run could look like this:
        Enter words (to stop, type the word done):
        anteater birthday category dumpster
        envy finagle geometry done for sure
        You entered a total of 7 words.
    You should include the cstring header file and use the strcmp() function to
    make the comparison test.
*/

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    cout << "Enter words (to stop, type the word done):" << endl;
    char str[50] = {'\0'};
    int numberOfWords = 0;
    cin >> str;
    while (strcmp(str, "done"))
    {
        numberOfWords++;
        cin >> str;
    }
    // drop other words in cin if any
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "You entered a total of " << numberOfWords << " words." << endl;
}
