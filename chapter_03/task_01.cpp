/*
    Write a short program that asks for your height in integer inches and then converts your height to feet and inches.
    Have the program use the underscore character to indicate where to type the response.
    Also use a "const" symbolic constant to represent the conversion factor.
*/

#include <iostream>
using namespace std;

int main()
{
    cout << "Enter your height in inches: _\b";
    int heightInInches = 0;
    cin >> heightInInches;

    const int inchesInFoot = 12;
    cout << "it is " << heightInInches / inchesInFoot << " foot and " << heightInInches % inchesInFoot << " inches" << endl;
}
