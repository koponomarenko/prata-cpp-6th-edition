/*
    Do Programming Exercise 7, but use "new" to allocate a structure instead of declaring
    a structure variable. Also have the program request the pizza diameter before it
    requests the pizza company name.
*/

#include <iostream>
using namespace std;

struct Pizza {
    char name[80];
    int diameter;
    int weight;
};

int main()
{
    Pizza * pizza = new Pizza;

    cout << "Diameter (in cm): ";
    (cin >> pizza->diameter).get(); // cin.get() removes '\n' after "cin >>"

    cout << "Name: ";
    cin.getline(pizza->name, sizeof(pizza->name)); // also removes '\n' from the stream

    cout << "Weight (in grams): ";
    cin >> pizza->weight; // also leaves '\n' in the stream
    cin.get();

    cout << endl << "Let's see what we've got here ..." << endl;
    cout << "Pizza name: " << pizza->name << endl;
    cout << "Pizza diameter: " << pizza->diameter << " cm" << endl;
    cout << "Pizza weight: " << pizza->weight << " grams" << endl;

    delete pizza;
}
