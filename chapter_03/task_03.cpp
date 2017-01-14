/*
    Write a program that asks the user to enter a latitude in degrees, minutes,
    and seconds and that then displays the latitude in decimal format.
    There are 60 seconds of arc to a minute and 60 minutes of arc to a degree; 
    represent these values with symbolic constants.
    You should use a separate variable for each input value. A sample run should look like this:
        Enter a latitude in degrees, minutes, and seconds:
        First, enter the degrees: 37
        Next, enter the minutes of arc: 51
        Finally, enter the seconds of arc: 19
        37 degrees, 51 minutes, 19 seconds = 37.8553 degrees
*/

#include <iostream>
using namespace std;

int main()
{
    cout << "Enter a latitude in degrees, minutes, and seconds:" << endl;

    cout << "First, enter the degrees: ";
    int degrees = 0;
    cin >> degrees;

    cout << "Next, enter the minutes of arc: ";
    int minutes = 0;
    cin >> minutes;

    cout << "Finally, enter the seconds of arc: ";
    int seconds = 0;
    cin >> seconds;

    const int SecInMin = 60;
    const int MinInDegree = 60;

    double degreesTotal = (((double(seconds) / SecInMin) + minutes) / MinInDegree) + degrees;
    cout << degrees << " degrees, " << minutes << " minutes, " << seconds << " seconds = " << degreesTotal << " degrees" << endl;
}
