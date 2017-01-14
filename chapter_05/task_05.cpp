/*
    You sell the book C++ for Fools. Write a program that has you enter a year’s worth
    of monthly sales (in terms of number of books, not of money). The program should
    use a loop to prompt you by month, using an array of char * (or an array of
    stringobjects, if you prefer) initialized to the month strings and storing the input
    data in an array of int. Then, the program should find the sum of the array contents
    and report the total sales for the year.
*/

#include <iostream>
using namespace std;

int main()
{
    const int Months = 12;
    const char * monthNames[Months] = { "January", "February", "March", "April", "May", 
        "June", "July", "August", "September", "October", "November", "December" };
    int soldBooks[Months] = {0};

    for (int i = 0; i < Months; ++i)
    {
        cout << "Enter a number of books sold in " << monthNames[i] << ": ";
        cin >> soldBooks[i];
    }

    int totalSales = 0;
    for (int i = 0; i < Months; ++i)
        totalSales += soldBooks[i];

    cout << "The total sales for the year: " << totalSales << endl;
}
