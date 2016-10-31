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

    const int secInMin = 60;
    const int minInHour = 60;
    const int hoursInDay = 24;

    long seconds = secondsTotal;
    long minutes = seconds / secInMin;
    seconds = seconds % secInMin;
    long hours = minutes / minInHour;
    minutes = minutes % minInHour;
    int days = hours / hoursInDay;
    hours = hours % hoursInDay;

    cout << secondsTotal << " seconds = " << days << " days, " << hours << " hours, " << minutes << " minutes , " << seconds << " seconds" << endl;
}
