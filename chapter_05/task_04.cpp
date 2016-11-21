/*
    Daphne invests $100 at 10% simple interest. That is, every year, the investment earns
    10% of the original investment, or $10 each and every year:
        interest = 0.10 x original balance
    At the same time, Cleo invests $100 at 5% compound interest. That is, interest is 5%
    of the current balance, including previous additions of interest:
        interest = 0.05 x current balance
    Cleo earns 5% of $100 the first year, giving her $105. The next year she earns 5% of
    $105, or $5.25, and so on. Write a program that finds how many years it takes for
    the value of Cleo’s investment to exceed the value of Daphne’s investment and then
    displays the value of both investments at that time.
*/

#include <iostream>
using namespace std;

int main()
{
    double investment_A = 100;
    double investment_B = 100;

    double profit_A = 0;
    double profit_B = 0;

    int years = 0;
    do
    {
        years++;

        // 10% simple interest
        profit_A += 0.10 * investment_A;

        // 5% compound interest
        profit_B += 0.05 * (investment_B + profit_B);
    } while (profit_A > profit_B);

    cout << "After " << years << " years" << endl;
    cout << "profit from " << investment_A <<  "$ investment at 10\% simple interest is " << profit_A << endl;
    cout << "profit from " << investment_B <<  "$ investment at 5\% compound interest is " << profit_B << endl;
}
