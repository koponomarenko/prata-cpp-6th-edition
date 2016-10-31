/*
    Write a program that asks the user to enter an hour value and a minute value.
    The main() function should then pass these two values to a type void function 
    that displays the two values in the format shown in the following sample run:
        Enter the number of hours: 9
        Enter the number of minutes: 28
        Time: 9:28
*/

#include <iostream>
using namespace std;

void display_time(int hours, int minutes);

int main()
{
    cout << "Enter the number of hours: ";
    int hours = 0;
    cin >> hours;
    cin.get(); // remove carriage return symbol from the stream

    cout << "Enter the munber of minutes: ";
    int minutes = 0;
    cin >> minutes;
    cin.get(); // remove carriage return symbol from the stream

    display_time(hours, minutes);
}

void display_time(int hours, int minutes)
{
    cout << "Time: " << hours << ":" << minutes << endl;
}
