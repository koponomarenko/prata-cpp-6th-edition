/*
    This exercise provides practice in writing functions dealing with arrays and struc-
    tures. The following is a program skeleton. Complete it by providing the described
    functions:

    #include <iostream>
    using namespace std;

    const int SLEN = 30;
    struct student {
        char fullname[SLEN];
        char hobby[SLEN];
        int ooplevel;
    };

    // getinfo() has two arguments: a pointer to the first element of
    // an array of student structures and an int representing the
    // number of elements of the array. The function solicits and
    // stores data about students. It terminates input upon filling
    // the array or upon encountering a blank line for the student
    // name. The function returns the actual number of array elements
    // filled.
    int getinfo(student pa[], int n);

    // display1() takes a student structure as an argument
    // and displays its contents
    void display1(student st);

    // display2() takes the address of student structure as an
    // argument and displays the structure’s contents
    void display2(const student * ps);

    // display3() takes the address of the first element of an array
    // of student structures and the number of array elements as
    // arguments and displays the contents of the structures
    void display3(const student pa[], int n);

    int main()
    {
        cout << "Enter class size: ";
        int class_size;
        cin >> class_size;
        while (cin.get() != '\n')
            continue;

        student * ptr_stu = new student[class_size];
        int entered = getinfo(ptr_stu, class_size);
        for (int i = 0; i < entered; i++)
        {
            display1(ptr_stu[i]);
            display2(&ptr_stu[i]);
        }
        display3(ptr_stu, entered);
        delete [] ptr_stu;
        cout << "Done\n";
        return 0;
    }
*/

#include <iostream>
#include <limits>
#include <cstring>

using namespace std;

const int SLEN = 30;
struct student {
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

// getinfo() has two arguments: a pointer to the first element of
// an array of student structures and an int representing the
// number of elements of the array. The function solicits and
// stores data about students. It terminates input upon filling
// the array or upon encountering a blank line for the student
// name. The function returns the actual number of array elements
// filled.
int getinfo(student pa[], int n);

// display1() takes a student structure as an argument
// and displays its contents
void display1(student st);

// display2() takes the address of student structure as an
// argument and displays the structure’s contents
void display2(const student * ps);

// display3() takes the address of the first element of an array
// of student structures and the number of array elements as
// arguments and displays the contents of the structures
void display3(const student pa[], int n);

// NOTE: assume correct input from a user.

int main()
{
    cout << "Enter class size: ";
    int class_size;
    cin >> class_size;
    while (cin.get() != '\n')
        continue;

    student * ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    for (int i = 0; i < entered; i++)
    {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete [] ptr_stu;
    cout << "Done\n";
    return 0;
}

int getinfo(student pa[], int n)
{
    int filled_students = 0;
    for (int i = 0; i < n; ++i)
    {
        cout << "Enter info for student #" << i + 1 << endl;
        cout << "full name: ";
        cin.getline(pa[i].fullname, SLEN);
        if (!cin)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (strlen(pa[i].fullname) == 0)
        {
            break;
        }
        cout << "hobby: ";
        cin.getline(pa[i].hobby, SLEN);
        if (!cin)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "ooplevel (digit): ";
        cin >> pa[i].ooplevel;
        cin.get();
        ++filled_students;
    }
    return filled_students;
}

void display1(student st)
{
    cout << "Student info (passed by value)" << endl;
    cout << "full name: " << st.fullname << endl;
    cout << "hobby: " << st.hobby << endl;
    cout << "ooplevel: " << st.ooplevel << endl;
}

void display2(const student * ps)
{
    cout << "Student info (passed by pointer)" << endl;
    cout << "full name: " << ps->fullname << endl;
    cout << "hobby: " << ps->hobby << endl;
    cout << "ooplevel: " << ps->ooplevel << endl;
}

void display3(const student pa[], int n)
{
    cout << "Student info (passed by pointer, full array)" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << "full name: " << pa[i].fullname << endl;
        cout << "hobby: " << pa[i].hobby << endl;
        cout << "ooplevel: " << pa[i].ooplevel << endl;
    }
}
