/*
    Define a recursive function that takes an integer argument and returns the factorial
    of that argument. Recall that 3 factorial, written 3!, equals 3 × 2!, and so on,
    with 0! defined as 1. In general, if n is greater than zero, n! = n * (n - 1)!.
    Test your function in a program that uses a loop to allow the user to enter
    various values for which the program reports the factorial.
*/

#include <iostream>

using namespace std;

int get_factorial(int number);

int main()
{
    cout << "factorial: " << get_factorial(5) << endl;
}

int get_factorial(int number)
{
    if (number > 0)
    {
        return number * get_factorial(number - 1);
    }
    else
    {
        return 1;
    }
}
