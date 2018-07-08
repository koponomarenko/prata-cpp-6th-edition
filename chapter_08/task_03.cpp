/*
    Write a function that takes a reference to a string object as its parameter
    and that converts the contents of the string to uppercase.
    Use the toupper() function described in Table 6.4 of Chapter 6.

    Write a program that uses a loop which allows you to test the function
    with different input.

    A sample run might look like this:

    Enter a string (q to quit): go away
    GO AWAY
    Next string (q to quit): good grief!
    GOOD GRIEF!
    Next string (q to quit): q
    Bye.
*/

#include <iostream>
#include <cctype>


void my_toupper(std::string& str);

int main()
{
    std::string str;
    std::cout << "Enter a string (q to quit): ";
    std::getline(std::cin, str);
    while (str != "q")
    {
        my_toupper(str);
        std::cout << str << std::endl;
        std::cout << "Next string (q to quit): ";
        std::getline(std::cin, str);
    }
    std::cout << "Bye." << std::endl;
}

void my_toupper(std::string& str)
{
    for (int i = 0; i < str.size(); ++i)
    {
        str[i] = std::toupper(str[i]);
    }
}
