#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int (*p1)[5] = (int (*)[5]) new int[5];
    // size of the whole array
    cout << "sizeof(*p1) = " << sizeof(*p1) << endl;

    int * p2 = new int[5];
    // size of the first element
    cout << "sizeof(*p2) = " << sizeof(*p2) << endl;

    memset(*p1, 0, sizeof(*p1));
    cout << "p1[0] = " << (*p1)[0] << endl;

    memset(p2, 0, sizeof(*p2) * 5);
    cout << "p2[0] = " << p2[0] << endl;
}
