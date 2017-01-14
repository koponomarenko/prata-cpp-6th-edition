/*
    Write a short program that asks for your height in feet and inches and your weight in pounds. 
    (Use three variables to store the information.) Have the program report your body mass index (BMI). 
    To calculate the BMI, first convert your height in feet and inches to your height in inches (1 foot = 12 inches).
    Then convert your height in inches to your height in meters by multiplying by 0.0254.
    Then convert your weight in pounds into your mass in kilograms by dividing by 2.2.
    Finally, compute your BMI by dividing your mass in kilograms by the square of your height in meters.
    Use symbolic constants to represent the various conversion factors.
*/

#include <iostream>
using namespace std;

int main()
{
    cout << "Enter your height" << endl;
    cout << "feet: ";
    int feetPart = 0;
    cin >> feetPart;
    cout << "inches: ";
    float inchesPart = 0;
    cin >> inchesPart;

    cout << "Enter your weight" << endl;
    cout << "pounds: ";
    int weight = 0;
    cin >> weight;

    const int InchesInFoot = 12;
    const float PoundsInKilogram = 2.2;

    float heightInInches = feetPart * InchesInFoot + inchesPart;

    float heightInMeters = heightInInches * 0.0254;
    int weightInKilograms = weight / PoundsInKilogram;

    cout << "Your height in meters: " << heightInMeters << endl;
    cout << "Your weight in kilograms: " << weightInKilograms << endl;
    int bmi = weightInKilograms / (heightInMeters * 2); // body mass index
    cout << "Your BMI: " << bmi << endl;
}
