#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.precision(0);

    stringstream ss;

    cout << "Convert \"string\" to \"float\"" << endl;
    cout << "The minimum number of significant digits for \"float\": " << numeric_limits<float>::digits10 << endl;
    // Create a number
    for (int i = 0; i < numeric_limits<float>::digits10; ++i)
        ss << (i + 1) % 10;
    // Overflow this number intentionally
    ss << "100";
    float floatNumber = 0.0f;
    ss >> floatNumber;
    cout << "string: " << ss.str() << endl;
    cout << " float: " << floatNumber << endl;
    cout << "        " << ss.str().substr(0, numeric_limits<float>::digits10) << endl;
    cout << endl;

    ss.clear();
    ss.str("");
    cout << "Convert \"string\" to \"double\"" << endl;
    cout << "The minimum number of significant digits for \"double\": " << numeric_limits<double>::digits10 << endl;
    // Create a number
    for (int i = 0; i < numeric_limits<double>::digits10; ++i)
        ss << (i + 1) % 10;
    // Overflow this number intentionally
    ss << "100";
    double doubleNumber = 0.0;
    ss >> doubleNumber;
    cout << "string: " << ss.str() << endl;
    cout << "double: " << doubleNumber << endl;
    cout << "        " << ss.str().substr(0, numeric_limits<double>::digits10) << endl;
    cout << endl;
    
    ss.clear();
    ss.str("");
    cout << "Convert \"string\" to \"long double\"" << endl;
    cout << "The minimum number of significant digits for \"long double\": " << numeric_limits<long double>::digits10 << endl;
    // Create a number
    for (int i = 0; i < numeric_limits<long double>::digits10; ++i)
        ss << (i + 1) % 10;
    // Overflow this number intentionally
    ss << "100";
    long double longDoubleNumber = 0.0L;
    ss >> longDoubleNumber;
    cout << "     string: " << ss.str() << endl;
    cout << "long double: " << longDoubleNumber << endl;
    cout << "             " << ss.str().substr(0, numeric_limits<long double>::digits10) << endl;
}
