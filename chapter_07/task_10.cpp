/*
    Design a function calculate() that takes two type double values and a pointer to
    a function that takes two double arguments and returns a double. The
    calculate() function should also be type double, and it should return the value
    that the pointed-to function calculates, using the double arguments to
    calculate().

    For example, suppose you have this definition for the add() function:

    double add(double x, double y)
    {
        return x + y;
    }

    Then, the function call in the following would cause calculate() to pass the val-
    ues 2.5 and 10.4 to the add() function and then return the add() return value
    ( 12.9 ):

    double q = calculate(2.5, 10.4, add);

    Use these functions and at least one additional function in the add() mold in a
    program.

    The program should use a loop that allows the user to enter pairs of num-
    bers. For each pair, use calculate() to invoke add() and at least one other func-
    tion.

    If you are feeling adventurous, try creating an array of pointers to add()-style
    functions and use a loop to successively apply calculate() to a series of functions
    by using these pointers.

    Hint: Here’s how to declare such an array of three pointers:
        double (*pf[3])(double, double);
    You can initialize such an array by using the usual array initialization syntax and
    function names as addresses.
*/

#include <iostream>
#include <limits>

using namespace std;

double calculate(double n1, double n2, double (*foo)(double, double));
double add(double n1, double n2);
double subtract(double n1, double n2);
double divide(double n1, double n2);
double multiply(double n1, double n2);

// NOTE: assume correct input from a user.

int main()
{
    const int arr_size = 4;
    double (*arr[arr_size])(double, double) = {add, subtract, divide, multiply};

    while (true)
    {
        cout << "first number: ";
        double n1 = 0;
        cin >> n1;
        cout << "second number: ";
        double n2 = 0;
        cin >> n2;
        cin.get(); // getting '\n' after cin >> number;

        for (int i = 0; i < arr_size; ++i)
        {
            cout << calculate(n1, n2, arr[i]) << endl;
        }

        cout << "'q' for exit, anything else to continue: ";
        if (cin.get() == 'q')
        {
            break;
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

double calculate(double n1, double n2, double (*foo)(double, double))
{
    return foo(n1, n2);
}

double add(double n1, double n2)
{
    cout << n1 << " + " << n2 << " = ";
    return n1 + n2;
}

double subtract(double n1, double n2)
{
    cout << n1 << " - " << n2 << " = ";
    return n1 - n2;
}

double divide(double n1, double n2)
{
    cout << n1 << " / " << n2 << " = ";
    return (n2 == 0) ? 0 : n1 / n2;
}

double multiply(double n1, double n2)
{
    cout << n1 << " * " << n2 << " = ";
    return n1 * n2;
}
