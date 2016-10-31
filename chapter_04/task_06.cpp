/*
    The CandyBarstructure contains three members, as described in Programming
    Exercise 5. Write a program that creates an array of three CandyBar structures, ini-
    tializes them to values of your choice, and then displays the contents of each struc-
    ture.
*/

#include <iostream>
using namespace std;

struct CandyBar {
    char brandName[80];
    float weight;
    int calories;
};

int main()
{
    CandyBar candies[3] = {
        {"Mocha Munch 1", 1.1, 100},
        {"Mocha Munch 2", 2.2, 200},
        {"Mocha Munch 3", 3.3, 300}
    };

    cout << "Candy #1" << endl;
    cout << "name: " << candies[0].brandName << endl;
    cout << "weight: " << candies[0].weight << endl;
    cout << "calories: " << candies[0].calories << endl;
    cout << endl;

    cout << "Candy #2" << endl;
    cout << "name: " << candies[1].brandName << endl;
    cout << "weight: " << candies[1].weight << endl;
    cout << "calories: " << candies[1].calories << endl;
    cout << endl;

    cout << "Candy #3" << endl;
    cout << "name: " << candies[2].brandName << endl;
    cout << "weight: " << candies[2].weight << endl;
    cout << "calories: " << candies[2].calories << endl;
}
