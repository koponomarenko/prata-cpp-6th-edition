/*
    When you join the Benevolent Order of Programmers, you can be known at BOP
    meetings by your real name, your job title, or your secret BOP name. Write a pro-
    gram that can list members by real name, by job title,by secret name, or by a mem-
    ber’s preference. Base the program on the following structure:
        // Benevolent Order of Programmers name structure
        struct bop {
            char fullname[strsize]; // real name
            char title[strsize]; // job title
            char bopname[strsize]; // secret BOP name
            int preference; // 0 = fullname, 1 = title, 2 = bopname
        };
    In the program,create a small array of such structures and initialize it to suitable
    values.Have the program run a loop that lets the user select from different alterna-
    tives:
    a. display by name    b. display by title
    c. display by bopname d. display by preference
    q. quit
    Note that “display by preference”does not mean display the preference member;it
    means display the member corresponding to the preference number.For instance,if
    preference is 1,choice dwould display the programmer’s job title. 
    A sample run may look something like the following:
        Benevolent Order of Programmers Report
        a. display by name    b. display by title
        c. display by bopname d. display by preference
        q. quit
        Enter your choice: a
        Wimp Macho
        Raki Rhodes
        Celia Laiter
        Hoppy Hipman
        Pat Hand
        Next choice: d
        Wimp Macho
        Junior Programmer
        MIPS
        Analyst Trainee
        LOOPY
        Next choice: q
        Bye!
*/

#include <iostream>
using namespace std;

const int StrSize = 50;
// Benevolent Order of Programmers name structure
struct Bop {
    char fullName[StrSize]; // real name
    char title[StrSize]; // job title
    char bopName[StrSize]; // secret BOP name
    int preference; // 0 = fullname, 1 = title, 2 = bopname
};

int main()
{
    const int ArrSize = 5;
    Bop arr[ArrSize] = {
        {"Wimp Macho", "Junior Programmer", "001", 0},
        {"Raki Rhodes", "Middle Programmer", "002", 1},
        {"Celia Laiter", "Senior Programmer", "003", 0},
        {"Hoppy Hipman", "Senior Programmer", "004", 2},
        {"Pat Hand", "Junior Programmer", "005", 2}
    };

    cout << "Benevolent Order of Programmers Report" << endl;
    cout << "a. display by name      b. display by title" << endl;
    cout << "c. display by bopname   d. display by preference" << endl;
    cout << "q. quit" << endl;

    cout << "Enter your choice: ";
    char ch;
    cin >> ch;
    while (ch != 'q')
    {
        switch (ch)
        {
            case 'a':
                for (int i = 0; i < ArrSize; ++i)
                {
                    cout << arr[i].fullName << endl;
                }
                break;
            case 'b':
                for (int i = 0; i < ArrSize; ++i)
                {
                    cout << arr[i].title << endl;
                }
                break;
            case 'c':
                for (int i = 0; i < ArrSize; ++i)
                {
                    cout << arr[i].bopName << endl;
                }
                break;
            case 'd':
                for (int i = 0; i < ArrSize; ++i)
                {
                    if (arr[i].preference == 0)
                    {
                        cout << arr[i].fullName << endl;
                    }
                    else if (arr[i].preference == 1)
                    {
                        cout << arr[i].title << endl;
                    }
                    else if (arr[i].preference == 2)
                    {
                        cout << arr[i].bopName << endl;
                    }
                }
                break;
            default:
                cout << "Please choose a valid option!" << endl;
        }

        cout << "Next choice: ";
        cin >> ch;
    }
}
