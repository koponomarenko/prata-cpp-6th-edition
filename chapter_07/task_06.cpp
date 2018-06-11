/*
    Write a program that uses the following functions:

    "fill_array()" takes as arguments the name of an array of double values and an
    array size. It prompts the user to enter double values to be entered in the array. It
    ceases taking input when the array is full or when the user enters non-numeric
    input, and it returns the actual number of entries.

    "show_array()" takes as arguments the name of an array of double values and an
    array size and displays the contents of the array.

    "reverse_array()" takes as arguments the name of an array of double values and an
    array size and reverses the order of the values stored in the array.

    The program should use these functions to fill an array, show the array, reverse the
    array, show the array, reverse all but the first and last elements of the array, and then
    show the array.
*/

#include <iostream>
#include <limits>

using namespace std;

int fill_array(double arr[], int size);
void show_array(const double arr[], int size);
void reverse_array(double arr[], int size);

int main()
{
    const int size = 10;
    double arr[size] = {0};

    int filled_size = fill_array(arr, size);
    show_array(arr, filled_size);
    reverse_array(arr, filled_size);
    show_array(arr, filled_size);
    reverse_array(arr + 1, filled_size - 2);
    show_array(arr, filled_size);
}

int fill_array(double arr[], int size)
{
    int filled_numbers = 0;
    for (int i = 0; i < size; ++i)
    {
        cout << "Enter value of element #" << i + 1 << ": ";
        cin >> arr[i];
        if (!cin)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        ++filled_numbers;
    }
    return filled_numbers;
}

void show_array(const double arr[], int size)
{
    cout << "Array filled elements: ";
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverse_array(double arr[], int size)
{
    double * begin = arr;
    double * end = arr + size - 1;
    double tmp = 0;
    while (begin < end)
    {
        tmp = *begin;
        *begin++ = *end;
        *end-- = tmp;
    }
}
