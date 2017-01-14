/*
    Redo Listing 5.4 using a type array object instead of a built-in array and type
    long double instead of long long. Find the value of 100!
*/

#include <iostream>
#include <array>
using namespace std;

const int ArrSize = 101;

int main()
{
    array<long double, ArrSize> factorials;
    factorials[1] = factorials[0] = 1L;
    for (int i = 2; i < ArrSize; ++i)
        factorials[i] = i * factorials[i - 1];

    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.precision(0);
    for (int i = 0; i < ArrSize; ++i)
        cout << i << "! = " << factorials[i] << endl;

    cout << endl;
    cout << "CAUTION: The minimum number of significant digits for long double type: " << numeric_limits<long double>::digits10 << endl;
    cout << endl;
}
