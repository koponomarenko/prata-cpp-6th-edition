/*
    Do Exercise 5 but use a two-dimensional array to store input for 3
    years of monthly sales. Report the total sales for each individual year
    and for the combined years.
*/

#include <iostream>
using namespace std;

int main()
{
    const int Months = 12;
    const int Years = 3;
    const char * monthNames[Months] = { "January", "February", "March", "April", "May", 
        "June", "July", "August", "September", "October", "November", "December" };
    int soldBooks[Years][Months] = {};

    for (int i = 0; i < Years; ++i)
    {
        for (int j = 0; j < Months; ++j)
        {
            cout << "Enter a number of books sold during " << i + 1 << " year in " << monthNames[j] << ": ";
            cin >> soldBooks[i][j];
        }
    }

    int totalSales = 0;
    for (int i = 0; i < Years; ++i)
    {
        int salesPerYear = 0;
        for (int j = 0; j < Months; ++j)
            salesPerYear += soldBooks[i][j];
        cout << "The total sales for the " << i + 1 << " year: " << salesPerYear << endl;
        totalSales += salesPerYear;
    }
    cout << "The total sales for " << Years << " years: " << totalSales << endl;
}
