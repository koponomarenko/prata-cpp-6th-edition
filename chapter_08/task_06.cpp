/*
    Write a template function maxn() that takes as its arguments an array of items
    of type T and an integer representing the number of elements in the array and
    that returns the largest item in the array. Test it in a program that uses
    the function template with an array of six int value and an array of four double
    values.

    The program should also include a specialization that takes an array of
    pointers-to-char as an argument and the number of pointers as a second argument
    and that returns the address of the longest string. If multiple strings are tied
    for having the longest length, the function should return the address of the first
    one tied for longest. Test the specialization with an array of five string pointers.
*/

#include <iostream>

template <typename T>
T maxn(T arr[], int size);

template <>
const char* maxn(const char* arr[], int size);

template <typename T>
void shown(T arr[], int size);

template <>
void shown(const char* arr[], int size);

int main()
{
    const int arr1_size = 6;
    int arr1[arr1_size] = {1, 2, 8, 5, 16, -3};
    std::cout << "arr1: ";
    shown(arr1, sizeof(arr1) / sizeof(arr1[0]));
    std::cout << std::endl;
    int max1 = maxn(arr1, sizeof(arr1) / sizeof(arr1[0]));
    std::cout << "Max1: " << max1 << std::endl;

    const int arr2_size = 4;
    double arr2[arr2_size] = {0.3, 1.1, 17.0, -20.1};
    std::cout << "arr2: ";
    shown(arr2, sizeof(arr2) / sizeof(arr2[0]));
    std::cout << std::endl;
    double max2 = maxn(arr2, sizeof(arr2) / sizeof(arr2[0]));
    std::cout << "Max2: " << max2 << std::endl;

    const int str_arr_size = 5;
    const char* str_arr[str_arr_size] = {
        "Hi there!",
        "This is the second string.",
        "The third one.",
        "This is the longest string among them.",
        "This is the fifth string."
    };
    std::cout << "str arr: " << std::endl;
    shown(str_arr, str_arr_size);
    const char* str_max = maxn(str_arr, str_arr_size);
    std::cout << "Max str: " << str_max << std::endl;
}

template <typename T>
T maxn(T arr[], int size)
{
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

template <>
const char* maxn(const char* arr[], int size)
{
    int max = 0;
    for (int i = 0; i < size; ++i)
    {
        if (strlen(arr[i]) > strlen(arr[max]))
        {
            max = i;
        }
    }
    return arr[max];
}

template <typename T>
void shown(T arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i];
        if (i + 1 < size)
        {
            std::cout << ", ";
        }
    }
}

template <>
void shown(const char* arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << std::endl;
    }
}
