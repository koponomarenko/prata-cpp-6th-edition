/*
    Write a program that asks the user to enter his or her age.
    The program then should display the age in months:
        Enter your age: 29
        Your age in months is 384.
*/

#include <iostream>
using namespace std;

int main()
{
    cout << "Enter your age: ";
    int age = 0;
    cin >> age;
    cin.get(); // remove carriage return symbol from the stream

    cout << "Your age in months is " << age * 12 << "." << endl;
}
