/*
    Write a function that normally takes one argument, the address of a string,
    and prints that string once. However, if a second, type int, argument is provided
    and is nonzero, the function should print the string a number of times
    equal to the number of times that function has been called at that point.

    (Note that the number of times the string is printed is not equal to the value
    of the second argument; it is equal to the number of times the function
    has been called.)

    Yes, this is a silly function, but it makes you use some of the techniques
    discussed in this chapter.

    Use the function in a simple program that demonstrates how the function works.
*/

#include <iostream>

using namespace std;

void print_str(const char * str, int n = 0);

int main()
{
    print_str("hello");
    print_str("it's me");
    print_str("I am not repeating", 1);
}

void print_str(const char * str, int n)
{
    static int count = 0;
    ++count;

    int max = n == 0 ? 1 : count;
    for (int i = 0; i < max; ++i)
    {
        cout << str << endl;
    }
}
