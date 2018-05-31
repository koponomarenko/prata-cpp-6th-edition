/*
    Write a program that repeatedly asks the user to enter pairs of numbers
    until at least one of the pair is 0. For each pair, the program should
    use a function to calculate the harmonic mean of the numbers.
    The function should return the answer to main(), which should report the result.
    The harmonic mean of the numbers is the inverse of the average of the inverses
    and can be calculated as follows:
        harmonic mean = 2.0 × x × y / (x + y)
*/

#include <iostream>
#include <limits>

using namespace std;

double get_harmonic_mean(int, int);

int main()
{
    int number1 = 0;
    int number2 = 0;

    // NOTE: assume correct data input from a user.
    while (true)
    {
        cout << "Enter 1st number: ";
        cin >> number1;
        cout << "Enter 2nd number: ";
        cin >> number2;
        if (number1 == 0 || number2 == 0)
        {
            break;
        }
        cout << "harmonic mean: " << get_harmonic_mean(number1, number2) << endl;
    }
}

double get_harmonic_mean(int n1, int n2)
{
    return 2.0 * n1 * n2 / (n1 + n2);
}
