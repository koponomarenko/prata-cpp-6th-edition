/*
    Write a program that asks the user to enter his or her first name and then last
    name, and that then constructs, stores, and displays a third string, consisting of the
    user’s last name followed by a comma, a space, and first name. 

    Use "char arrays" and functions from the cstring header file. 
    A sample run could look like this:
        Enter your first name: Flip
        Enter your last name: Fleming
        Here is the information in a single string: Fleming, Flip
*/

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    cout << "Enter your first name: ";
    char firstName[80] = {'\0'};
    cin.getline(firstName, sizeof(firstName)); // also removes '\n' from the stream

    cout << "Enter your last name: ";
    char lastName[80] = {'\0'};
    cin.get(lastName, sizeof(lastName)); // also leaves '\n' in the stream
    cin.get();

    const char * separator = ", ";

    char * p = new char[strlen(firstName) + strlen(lastName) + strlen(separator) + 1];
    strcat(strcat(strcpy(p, lastName), separator), firstName);
    cout << "Here is the information in a single string: " << p << endl;
    delete [] p;
}
