/*
    The CandyBar structure contains three members. The first member holds
    the brand name of a candy bar. The second member holds the weight
    (which may have a fractional part) of the candy bar,
    and the third member holds the number of calories (an integer value)
    in the candy bar. Write a program that uses a function that takes
    as arguments a reference to CandyBar, a pointer-to-char, a double,
    and an int and uses the last three values to set the corresponding members
    of the structure.

    The last three arguments should have default values of "Millennium Munch",
    2.85, and 350.

    Also the program should use a function that takes a reference
    to a CandyBar as an argument and displays the contents of the structure.
    Use const where appropriate.
*/

#include <iostream>
#include <string>

using namespace std;

struct Candy_bar {
    std::string brand_name;
    double weight;
    int calories;
};

void set(Candy_bar& candy_bar,
        const char* brand_name = "Millennium Munch",
        double weight = 2.85,
        int calories = 350);

void show(const Candy_bar& candy_bar);

int main()
{
    Candy_bar tasty_candy;
    set(tasty_candy, "Tasty Candy", 45.5, 110);

    Candy_bar sweet_bar;
    set(sweet_bar);

    show(tasty_candy);
    show(sweet_bar);
}

void set(Candy_bar& candy_bar, const char* brand_name, double weight, int calories)
{
    candy_bar.brand_name = brand_name;
    candy_bar.weight = weight;
    candy_bar.calories = calories;
}

void show(const Candy_bar& candy_bar)
{
    cout << "Candy bar info" << endl;
    cout << "brand name: " << candy_bar.brand_name << endl;
    cout << "weight: " << candy_bar.weight << endl;
    cout << "calories: " << candy_bar.calories << endl;
}
