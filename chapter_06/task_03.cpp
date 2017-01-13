/*
    Write a precursor to a menu-driven program. The program should display a menu
    offering four choices, each labeled with a letter. If the user responds with a letter
    other than one of the four valid choices, the program should prompt the user to
    enter a valid response until the user complies. Then the program should use a
    switch to select a simple action based on the user’s selection. A program run could
    look something like this:
        Please enter one of the following choices:
        c) carnivore p) pianist
        t) tree g) game
        f
        Please enter a c, p, t, or g: q
        Please enter a c, p, t, or g: t
        A maple is a tree.
*/

#include <iostream>
#include <limits>
using namespace std;

int main()
{

    cout << "Please enter one of the following choices:" << endl;
    cout << "c) carnivore       p) pianist" << endl;
    cout << "t) tree            g) game" << endl;

    string input;
    string choices = "cCpPtTgG";
    getline(cin, input);
    while (input.size() != 1 || choices.find(input) == string::npos)
    {
        cout << "Please enter 'c', 'p', 't', or 'g': ";
        getline(cin, input);
    }

    switch (input[0])
    {
    case 'c':
    case 'C':
        cout << "carnivore" << endl;
        break;
    case 't':
    case 'T':
        cout << "tree" << endl;
        break;
    case 'p':
    case 'P':
        cout << "pianist" << endl;
        break;
    case 'g':
    case 'G':
        cout << "game" << endl;
        break;
    }
}
