/*
    Modify Listing 8.14 so that it uses two template functions called SumArray()
    to return the sum of the array contents instead of displaying the contents.
    The program now should report the total number of things and the sum of all the debts.
*/

#include <iostream>

template <typename T> // template A
void ShowArray(T arr[], int n);

template <typename T> // template B
void ShowArray(T* arr[], int n);

template <typename T> // template Sum A
T SumArray(T arr[], int n);

template <typename T> // template Sum B
T SumArray(T* arr[], int n);

struct debts
{
    char name[50];
    double amount;
};

int main()
{
    const int things_size = 6;
    int things[things_size] = {13, 31, 103, 301, 310, 130};

    const int mr_e_size = 3;
    struct debts mr_E[mr_e_size] =
    {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };
    double* pd[mr_e_size];

    // set pointers to the amount members of the structures in mr_E
    for (int i = 0; i < mr_e_size; ++i)
    {
        pd[i] = &mr_E[i].amount;
    }

    std::cout << "Listing Mr. E's counts of things:\n";
    // things is an array of int
    ShowArray(things, things_size); // uses template A

    std::cout << "Listing Mr. E's debts:\n";
    // pd is an array of pointers to double
    ShowArray(pd, mr_e_size); // uses template B (more specialized)

    std::cout << "Total number of things: " << std::endl;
    std::cout << SumArray(things, things_size) << std::endl;
    std::cout << "Sum of all the debts: " << std::endl;
    std::cout << SumArray(pd, mr_e_size) << std::endl;
}

template <typename T>
void ShowArray(T arr[], int n)
{
    std::cout << "template A\n";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

template <typename T>
void ShowArray(T* arr[], int n)
{
    std::cout << "template B\n";
    for (int i = 0; i < n; i++)
    {
        std::cout << *arr[i] << ' ';
    }
    std::cout << std::endl;
}

template <typename T>
T SumArray(T arr[], int n)
{
    T sum = 0;
    std::cout << "template Sum A\n";
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

template <typename T>
T SumArray(T* arr[], int n)
{
    T sum = 0;
    std::cout << "template Sum B\n";
    for (int i = 0; i < n; i++)
    {
        sum += *arr[i];
    }
    return sum;
}
