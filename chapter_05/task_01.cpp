/*
    Write a program that requests the user to enter two integers. The program should
    then calculate and report the sum of all the integers between and including the two
    integers. At this point, assume that the smaller integer is entered first. For example, if
    the user enters 2 and 9, the program should report that the sum of all the integers
    from 2 through 9 is 44.
*/

#include <iostream>
using namespace std;

int main()
{
    cout << "Enter first number: ";
    int number_1 = 0;
    cin >> number_1;

    cout << "Enter second number: ";
    int number_2 = 0;
    cin >> number_2;

    int sum = 0;
    for (int i = number_1; i <= number_2; i++)
        sum += i;

    cout << "The sum of all numbers between " << number_1 << " and " << number_2 << " is " << sum << endl;
}
