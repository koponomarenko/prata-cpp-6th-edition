/*
    Redo Listing 7.15 without using the array class. Do two versions:

    a. Use an ordinary array of const char * for the strings representing the sea-
    son names, and use an ordinary array of double for the expenses.

    b. Use an ordinary array of const char * for the strings representing the sea-
    son names, and use a structure whose sole member is an ordinary array of
    double for the expenses. (This design is similar to the basic design of the
    array class.)
*/


#include <iostream>
#include <string>

using namespace std;

const int n_seasons = 4;
const char * season_names[n_seasons] =
    {"Spring", "Summer", "Fall", "Winter"};

struct Expenses {
    double expenses[n_seasons];
};


void fill(double * expenses);
void fill(Expenses * expenses);
void show(const double * expenses);
void show(const Expenses * expenses);

int main()
{
    cout << "Using an array" << endl; 
    double expenses[n_seasons] = {};
    fill(expenses);
    show(expenses);

    cout << "Using an array wrapped in a structure" << endl; 
    Expenses expenses_st = {};
    fill(&expenses_st);
    show(&expenses_st);
}

void fill(double * expenses)
{
    for (int i = 0; i < n_seasons; ++i)
    {
        cout << "Enter " << season_names[i] << " expenses: ";
        cin >> expenses[i];
    }
}

void fill(Expenses * expenses)
{
    for (int i = 0; i < n_seasons; ++i)
    {
        cout << "Enter " << season_names[i] << " expenses: ";
        cin >> expenses->expenses[i];
    }
}

void show(const double * expenses)
{
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0; i < n_seasons; ++i)
    {
        cout << season_names[i] << ": $" << expenses[i] << endl;
        total += expenses[i];
    }
    cout << "Total Expenses: $" << total << endl;
}

void show(const Expenses * expenses)
{
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0; i < n_seasons; ++i)
    {
        cout << season_names[i] << ": $" << expenses->expenses[i] << endl;
        total += expenses->expenses[i];
    }
    cout << "Total Expenses: $" << total << endl;
}
