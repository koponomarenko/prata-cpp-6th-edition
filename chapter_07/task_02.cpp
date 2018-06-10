/*
    Write a program that asks the user to enter up to 10 golf scores, 
    which are to be stored in an array. You should provide a means for the user
    to terminate input prior to entering 10 scores. The program should display
    all the scores on one line and report the average score. Handle input,
    display, and the average calculation with three separate array-processing functions.
*/

#include <iostream>
#include <limits>

using namespace std;

int input_scores(int scores[], const int max_scores_number);
void display_scores(const int scores[], const int scores_number);
int get_average_score(const int scores[], const int scores_number);

int main()
{
    const int max_scores_number = 10;
    int scores[max_scores_number] = {0};

    int filled_scores = input_scores(scores, max_scores_number);
    display_scores(scores, filled_scores);
    int average_score = get_average_score(scores, filled_scores);
    cout << "average score: " << average_score << endl;
}

int input_scores(int scores[], const int max_scores_number)
{
    int filled_scores = 0;
    cout << "Enter up to " << max_scores_number << " scores. ";
    cout << "Enter any non-digit symbol to terminate." << endl;
    for (int i = 0; i < max_scores_number; ++i)
    {
        cout << "Enter score (#" << i + 1 << "): ";
        // NOTE: assume correct data input from a user.
        cin >> scores[i];
        if (!cin)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        ++filled_scores;
    }
    return filled_scores;
}

void display_scores(const int scores[], const int scores_number)
{
    cout << "The scores are: ";
    for (int i = 0; i < scores_number; ++i)
    {
        cout << scores[i] << " ";
    }
    cout << endl;
}

int get_average_score(const int scores[], const int scores_number)
{
    int total = 0;
    for (int i = 0; i < scores_number; ++i)
    {
        total += scores[i];
    }
    return total / scores_number;
}
