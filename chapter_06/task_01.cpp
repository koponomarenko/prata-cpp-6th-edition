/*
    Write a program that reads keyboard input to the @ symbol and that echoes the
    input except for digits, converting each uppercase character to lowercase, and vice
    versa. (Don’t forget the cctype family.)
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    cout << "Write something. Type '@' to terminate." << endl;
    string str;
    char ch;
    while (cin.get(ch) && ch != '@')
    {
        if (isdigit(ch))
        {
            continue;
        }
        if (isalpha(ch))
        {
            ch = isupper(ch) ? tolower(ch) : toupper(ch);
        }
        str.push_back(ch);
    }
    cout << "After convertion: " << endl;
    cout << str << endl;
}
