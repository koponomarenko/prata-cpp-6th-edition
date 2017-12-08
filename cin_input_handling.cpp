#include <iostream>
#include <limits>

using namespace std;

int main()
{
    cout << "Enter a number: ";
    int number = 0;
    cin >> number;
    // cin >> int; leaves '\n' in cin buffer
    cin.get();
    cout << "Your number: " << number << endl;

    cout << "Enter some words: ";
    char str[20] = {'\0'};
    cin.getline(str, sizeof(str));
    // if a string from cin buffer doesn't fit into the array, failbit is set
    if (!cin)
    {
        // set cin buffer back to normal state
        cin.clear();
        // discard all chars from cin buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Not all your words fit into the destination array ... " << endl;
    }
    cout << "Your words:" << endl;
    cout << str << endl;

    cout << "Enter another number: ";
    int anotherNumber = 0;
    (cin >> anotherNumber).get();
    cout << "Your another number: " << anotherNumber << endl;
}
