/*
    Write a program that asks the user to type in numbers. After each entry, 
    the program should report the cumulative sum of the entries to date.
    The program should terminate when the user enters 0.
*/

#include <iostream>
using namespace std;

int main()
{
    int number = 0;
    int sum = 0;
    do
    {
        cout << "Enter a number: ";
        cin >> number;
        sum += number;
        cout << "Sum of numbers entered so far is " << sum << endl;
    } while (number != 0);
}
