/*
    Write a program that reads input a word at a time until a lone q is entered. The
    program should then report the number of words that began with vowels, the num-
    ber that began with consonants, and the number that fit neither of those categories.
    One approach is to use isalpha() to discriminate between words beginning with
    letters and those that don’t and then use an if or switch statement to further iden-
    tify those passing the isalpha() test that begin with vowels. A sample run might
    look like this:
        Enter words (q to quit):
        The 12 awesome oxen ambled
        quietly across 15 meters of lawn. q
        5 words beginning with vowels
        4 words beginning with consonants
        2 others
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int vowels = 0;
    int consonants = 0;
    int neither = 0;
    cout << "Enter words (q to quit):" << endl;
    string word;
    while (cin >> word && word != "q")
    {
        if (isalpha(word[0]))
        {
            // These letters are vowels in English: A, E, I, O, U
            switch (word[0])
            {
                case 'a':
                case 'A':
                case 'e':
                case 'E':
                case 'i':
                case 'I':
                case 'o':
                case 'O':
                case 'u':
                case 'U':
                    ++vowels;
                    break;
                default:
                    ++consonants;
            }
        }
        else
        {
            ++neither;
        }
    }

    cout << vowels << " words beginning with vowels" << endl;
    cout << consonants << " words beginning with consonants" << endl;
    cout << neither << " others" << endl;
}
