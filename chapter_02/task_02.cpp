/*
    Write a C++ program that asks for a distance in furlongs and converts it to yards.
    (One furlong is 220 yards.)
*/

#include <iostream>
using namespace std;

int main()
{
    cout << "Enter a distance in furlongs: ";
    int distance = 0;
    cin >> distance;
    cin.get(); // remove carriage return symbol from the stream

    cout << "It is " << distance * 220 << " yards (1 furlong = 220 yards)" << endl;
}
