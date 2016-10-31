/*
    Write a program that asks how many miles you have driven and how many gallons of gasoline you have used 
    and then reports the miles per gallon your car has gotten. 
    Or, if you prefer,the program can request distance in kilometers and petrol in liters 
    and then report the result European style, in liters per 100 kilometers.
*/

#include <iostream>
using namespace std;

int main()
{
    cout << "Enter driven miles: ";
    int miles = 0;
    cin >> miles;

    cout << "How much gas did it take in gallons: ";
    double gas = 0;
    cin >> gas;

    streamsize prevPrecis = cout.precision(4);
    //cout << "Prev precision: " << prevPrecis << endl;
    cout << "It is " << miles / gas << " miles per gallon." << endl;
}
