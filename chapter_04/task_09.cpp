/*
    Do Programming Exercise 6, but instead of declaring an array of three CandyBar
    structures, use new to allocate the array dynamically.
*/

#include <iostream>
#include <cstring>
using namespace std;

struct CandyBar {
    char brandName[80];
    float weight;
    int calories;
};

int main()
{
    int arraySize = 3;
    CandyBar * candies = new CandyBar[arraySize];
    memset(candies, 0, sizeof(candies[0]) * arraySize);

    // Fill up "candies" array
    strncpy(candies->brandName, "Mocha Munch 1", sizeof(candies->brandName) - 1);
    candies->weight = 1.1;
    candies->calories = 100;

    strncpy(candies[1].brandName, "Mocha Munch 2", sizeof(candies[1].brandName) - 1);
    candies[1].weight = 2.2;
    candies[1].calories = 200;

    strncpy((candies + 2)->brandName, "Mocha Munch 3", sizeof((candies + 2)->brandName) - 1);
    (candies + 2)->weight = 3.3;
    (candies + 2)->calories = 300;

    // Display "candies" array
    cout << "Candy bar #1" << endl;
    cout << "name: " << candies->brandName << endl;
    cout << "weight: " << candies->weight << endl;
    cout << "calories: " << candies->calories << endl;
    cout << endl;

    cout << "Candy bar #2" << endl;
    cout << "name: " << candies[1].brandName << endl;
    cout << "weight: " << candies[1].weight << endl;
    cout << "calories: " << candies[1].calories << endl;
    cout << endl;

    cout << "Candy bar #3" << endl;
    cout << "name: " << (candies + 2)->brandName << endl;
    cout << "weight: " << (candies + 2)->weight << endl;
    cout << "calories: " << (candies + 2)->calories << endl;

    delete [] candies;
}
