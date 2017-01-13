/*
    The Kingdom of Neutronia, where the unit of currency is the tvarp, has the fol-
    lowing income tax code:
    First 5,000 tvarps:0% tax
    Next 10,000 tvarps:10% tax
    Next 20,000 tvarps:15% tax
    Tvarps after 35,000:20% tax
    For example, someone earning 38,000 tvarps would owe 5,000 * 0.00 + 10,000 * 0.10 + 20,000 * 0.15 + 3,000 * 0.20,
    or 4,600 tvarps. Write a program that uses a
    loop to solicit incomes and to report tax owed. The loop should terminate when
    the user enters a negative number or non-numeric input.
*/

#include <iostream>
#include <limits>
using namespace std;

struct TaxCategory {
    const long long moneyLimit;
    const double taxRate;
};

int main()
{
    const int ArrSize = 4;
    const TaxCategory taxCategories[ArrSize] = {
        {5000,  0.0,}, // first 5000
        {10000, 0.10}, // next 10000
        {20000, 0.15}, // next 20000
        {numeric_limits<long long>::max(), 0.20} // after 35000
    };

    cout << "Enter a negative number or non-numeric input for EXIT." << endl;
    cout << "Enter your income: ";
    long long income = 0;
    while (cin >> income && income >= 0)
    {
        long long tax = 0;
        long long slice = 0;

        for (int i = 0; i < ArrSize && income > 0; ++i)
        {
            slice = (income > taxCategories[i].moneyLimit) ? taxCategories[i].moneyLimit : income;
            income -= slice;
            tax += slice * taxCategories[i].taxRate;
        }

        cout << "tax = " << tax << endl;
    }
}
