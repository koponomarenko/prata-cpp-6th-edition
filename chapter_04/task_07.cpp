/*
    William Wingate runs a pizza-analysis service. For each pizza, he needs to record
    the following information:
        The name of the pizza company, which can consist of more than one word
        The diameter of the pizza
        The weight of the pizza
    Devise a structure that can hold this information and write a program that uses a
    structure variable of that type. The program should ask the user to enter each of the
    preceding items of information, and then the program should display that informa-
    tion. Use cin (or its methods) and cout.
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
    Pizza pizza;

    cout << "Name: ";
    cin.getline(pizza.name, sizeof(pizza.name)); // also removes '\n' from the stream

    cout << "Diameter (in cm): ";
    cin >> pizza.diameter; // also leaves '\n' in the stream
    cin.get();

    cout << "Weight (in grams): ";
    cin >> pizza.weight; // also leaves '\n' in the stream
    cin.get();

    cout << endl << "Let's see what we've got here ..." << endl;
    cout << "Pizza name: " << pizza.name << endl;
    cout << "Pizza diameter: " << pizza.diameter << " cm" << endl;
    cout << "Pizza weight: " << pizza.weight << " grams" << endl;
}
