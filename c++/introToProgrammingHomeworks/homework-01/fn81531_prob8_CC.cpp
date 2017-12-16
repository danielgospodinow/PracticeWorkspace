/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Daniel Gospodinow
 * @idnumber 81531
 * @task 8
 * @compiler GCC
 *
 */

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int cash;
    cin >> cash;

    if(cash == 0)
    {
        cout << "0 = 0*0" << endl;
        return 0;
    }
    else if(cash < 0)
    {
        cout << "Bad input!" << endl;
        return 0;
    }

    int initCash = cash;

    int ft = cash / 50;
    (cash >= 50)?cash-=(ft * 50):cash = cash;
    int tw = cash / 20;
    (cash >= 20)?cash-=(tw * 20):cash = cash;
    int tt = cash / 10;
    (cash >= 10)?cash-=(tt * 10):cash = cash;
    int f = cash / 5;
    (cash >= 5)?cash-=(f * 5):cash = cash;
    int t = cash / 2;
    (cash >= 2)?cash-=(t * 2):cash = cash;
    int o = cash / 1;

    string result = std::to_string(initCash) + " = ";

    if(ft != 0)
        result += std::to_string(ft) + "*50 ";
    if(tw != 0 && ft != 0)
        result += "+ " + std::to_string(tw) + "*20 ";
    else if(tw != 0)
        result += std::to_string(tw) + "*20 ";
    if(tt != 0 && (tw != 0 || ft != 0))
        result += "+ " + std::to_string(tt) + "*10 ";
    else if(tt != 0)
        result += std::to_string(tt) + "*10 ";
    if(f != 0 && (tw != 0 || ft != 0 || tt != 0))
        result += "+ " + std::to_string(f) + "*5 ";
    else if(f != 0)
        result += std::to_string(f) + "*5 ";
    if(t != 0 && (tw != 0 || ft != 0 || tt != 0 || f != 0))
        result += "+ " + std::to_string(t) + "*2 ";
    else if(t != 0)
        result += std::to_string(t) + "*2 ";
    if(o != 0 && (tw != 0 || ft != 0 || tt != 0 || f != 0 || t != 0))
        result += "+ " + std::to_string(o) + "*1";
    else if(o != 0)
        result += std::to_string(o) + "*1";

    cout << result << endl;

    return 0;
}
