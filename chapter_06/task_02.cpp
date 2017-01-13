/*
    Write a program that reads up to 10 donation values into an array of double. (Or, if
    you prefer, use an array template object.) The program should terminate input on
    non-numeric input.It should report the average of the numbers and also report
    how many numbers in the array are larger than the average.
*/

#include <iostream>
using namespace std;

const int Size = 10;

int main()
{
    double arr[Size] = {0};
    int entries = 0;
    double sum = 0;

    cout << "Enter up to 10 donation values: " << endl;
    cout << "Write a non-numeric symbol to terminate" << endl;
    while (entries < Size && cin >> arr[entries])
    {
        sum += arr[entries];
        ++entries;
    }
    cout << "The avarage is " << sum / entries << endl;

    double average = (entries > 0) ? sum / entries : 0;
    int largerThanAverage = 0;
    for (int i = 0; i < entries; ++i)
    {
        if (arr[i] > average)
        {
            ++largerThanAverage;
        }
    }
    cout << "The average of the numbers is " << average << endl;
    cout << largerThanAverage << " numbers are larger than average" << endl;
}
