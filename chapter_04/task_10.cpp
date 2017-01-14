/*
    Write a program that requests the user to enter three times for the 40-yd dash (or
    40-meter,if you prefer) and then displays the times and the average. Use an array
    object to hold the data. (Use a built-in array if array is not available.)
*/

#include <iostream>
using namespace std;

int main()
{
    const int ArrSize = 3;
    int dashes[ArrSize] = {0};

    cout << "Enter time for the 1st 40-meter dash (in seconds): ";
    cin >> dashes[0];

    cout << "Enter time for the 2nd 40-meter dash (in seconds): ";
    cin >> dashes[1];

    cout << "Enter time for the 3rd 40-meter dash (in seconds): ";
    cin >> dashes[2];

    int avarage = (dashes[0] + dashes[1] + dashes[2]) / ArrSize;
    cout << "Avarage time of 40-meter dash is " << avarage << " sec." << endl;
}
