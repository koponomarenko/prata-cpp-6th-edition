/*
    Redo Listing 7.7, modifying the three array-handling functions to each use two
    pointer parameters to represent a range. The fill_array() function, instead of
    returning the actual number of items read, should return a pointer to the location
    after the last location filled; the other functions can use this pointer as the second
    argument to identify the end of the data.
*/

#include <iostream>
#include <limits>

using namespace std;

double * fill_array(double * begin, double * end);
void show_array(const double * begin, const double * end);
void revalue(double r, double * begin, double * end);

int main()
{
    const int max_properties = 5;
    double properties[max_properties];

    double * properties_end = fill_array(properties, properties + max_properties);
    show_array(properties, properties_end);
    if (properties_end != properties)
    {
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Bad input; Please enter a number: ";
        }
        revalue(factor, properties, properties_end);
        show_array(properties, properties_end);
    }
    cout << "Done.\n";
    return 0;
}

double * fill_array(double * begin, double * end)
{
    double temp;
    int i = 0;
    double * pt = begin;
    while (pt != end)
    {
        cout << "Enter value #" << (i++ + 1) << ": ";
        cin >> temp;
        if (!cin)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Bad input; input process terminated.\n";
            break;
        }
        else if (temp < 0)
        {
            break;
        }
        *pt++ = temp;
    }
    return pt;
}

void show_array(const double * begin, const double * end)
{
    int i = 0;
    for (const double * pt = begin; pt != end; ++pt)
    {
        cout << "Property #" << (i++ + 1) << ": $";
        cout << *pt << endl;
    }
}

void revalue(double r, double * begin, double * end)
{
    for (double * pt = begin; pt != end; ++pt)
    {
        *pt *= r;
    }
}
