/*
    Write a template function max5() that takes as its argument an array of
    five items of type T and returns the largest item in the array.
    (Because the size is fixed, it can be hard-coded into the loop instead of being
    passed as an argument.)

    Test it in a program that uses the function with an array of five int value and
    an array of five double values.
*/

#include <iostream>

template <typename T>
T max5(T arr[]);

template <typename T>
void show5(T arr[]);

int main()
{
    const int arr_size = 5;

    int arr1[arr_size] = {1, 2, 8, 5, -3};
    std::cout << "arr1: ";
    show5(arr1);
    std::cout << std::endl;
    int max1 = max5(arr1);
    std::cout << "Max1: " << max1 << std::endl;

    double arr2[arr_size] = {0.3, 1.1, 4.7, 17.0, -20.1};
    std::cout << "arr2: ";
    show5(arr2);
    std::cout << std::endl;
    double max2 = max5(arr2);
    std::cout << "Max2: " << max2 << std::endl;
}

template <typename T>
T max5(T arr[])
{
    const int size = 5;
    T max = arr[0];
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

template <typename T>
void show5(T arr[])
{
    const int size = 5;
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i];
        if (i + 1 < size)
        {
            std::cout << ", ";
        }
    }
}
