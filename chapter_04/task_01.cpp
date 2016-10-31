/*
    Write a C++ program that requests and displays information as shown in the fol-
    lowing example of output:
        What is your first name? Betty Sue
        What is your last name? Yewe
        What letter grade do you deserve? B
        What is your age? 22
        Name: Yewe, Betty Sue
        Grade: C
        Age: 22
    Note that the program should be able to accept first names that comprise more
    than one word. Also note that the program adjusts the grade downward—that is,up
    one letter. Assume that the user requests an A,a B,or a C so that you don’t have to
    worry about the gap between a D and an F.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "What is your first name? ";
    string name;
    getline(cin, name); // also removes '\n' from the stream

    cout << "What is your last name? ";
    char lastName[80] = {'\0'};
    cin.get(lastName, sizeof(lastName)); // also leaves '\n' in the stream
    cin.get();

    cout << "What letter grade do you deserve? ";
    char grade = '\0';
    cin.get(grade);
    grade++; // lowering the grade e.g. A -> B

    cout << "What is your age? ";
    int age = 0;
    cin >> age;
    
    cout << "Name: " << lastName << ", " << name << endl;
    cout << "Grade: " << grade << endl;
    cout << "Age: " << age << endl;
}
