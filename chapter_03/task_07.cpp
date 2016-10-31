/*
    Write a program that asks you to enter an automobile gasoline consumption figure 
    in the European style (liters per 100 kilometers) and converts to the US style of miles per gallon. 
    Note that in addition to using different units of measurement, the US approach (distance / fuel)
    is the inverse of the European approach (fuel / dis-tance).
    Note that 100 kilometers is 62.14 miles, and 1 gallon is 3.875 liters. 
    Thus, 19 mpg is about 12.4 l/100 km, and 27 mpg is about 8.7 l/100 km.
*/

#include <iostream>
using namespace std;

int main()
{
    cout << "Enter liters per 100km: ";
    double litersPer100Km = 0;
    cin >> litersPer100Km;

    const double milesIn100Km = 62.14;
    const double literInGallon = 3.875;

    cout << "It is " << milesIn100Km / (litersPer100Km / literInGallon) << " miles per gallon." << endl;
}
