/*
    Write a program that asks the user to enter the number of seconds 
    as an integer value (use type long,or,if available,long long) 
    and that then displays the equivalent time in days, hours, minutes, and seconds. 
    Use symbolic constants to represent the number of hours in the day, 
    the number of minutes in an hour, and the number of seconds in a minute.
    The output should look like this:
        Enter the number of seconds: 31600000
        31600000 seconds = 365 days, 17 hours, 46 minutes, 40 seconds
*/

#include <iostream>
using namespace std;

int main()
{
    cout << "Enter a number of seconds: ";
    long secondsTotal = 0;
    cin >> secondsTotal;

    const int SecInMin = 60;
    const int MinInHour = 60;
    const int HoursInDay = 24;

    long seconds = secondsTotal;
    long minutes = seconds / SecInMin;
    seconds = seconds % SecInMin;
    long hours = minutes / MinInHour;
    minutes = minutes % MinInHour;
    int days = hours / HoursInDay;
    hours = hours % HoursInDay;

    cout << secondsTotal << " seconds = " << days << " days, " << hours << " hours, " << minutes << " minutes , " << seconds << " seconds" << endl;
}
