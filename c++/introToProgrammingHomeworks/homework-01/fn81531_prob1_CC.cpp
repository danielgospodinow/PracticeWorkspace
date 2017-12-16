/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Daniel Gospodinow
 * @idnumber 81531
 * @task 1
 * @compiler GCC
 *
 */

#include <iostream>
using namespace std;
 
int main(int argc, char *argv[])
{
    int n, thousand, hundred, ten, one;
    cin >> n;
    if (n <= 0 || n > 3000)
    {
        cout << "Invalid number" << endl;
        return 0;
    }
    else
    {
        thousand = (n / 1000) * 1000;
        hundred = ((n / 100) % 10) * 100;
        ten = (((n / 10) % 100) % 10) * 10;
        one = (((n % 1000) % 100) % 10) * 1;
        if (thousand == 1000)
            cout << "M";
        else if (thousand == 2000)
            cout << "MM";
        else if (thousand == 3000)
            cout << "MMM";
        if (hundred == 100)
            cout << "C";
        else if (hundred == 200)
            cout << "CC";
        else if (hundred == 300)
            cout << "CCC";
        else if (hundred == 400)
            cout << "CD";
        else if (hundred == 500)
            cout << "D";
        else if (hundred == 600)
            cout << "DX";
        else if (hundred == 700)
            cout << "DXX";
        else if (hundred == 800)
            cout << "DXXX";
        else if (hundred == 900)
            cout << "CM";
        if (ten == 10)
            cout << "X";
        else if (ten == 20)
            cout << "XX";
        else if (ten == 30)
            cout << "XXX";
        else if (ten == 40)
            cout << "XL";
        else if (ten == 50)
            cout << "L";
        else if (ten == 60)
            cout << "LX";
        else if (ten == 70)
            cout << "LXX";
        else if (ten == 80)
            cout << "LXXX";
        else if (ten == 90)
            cout << "XC";
        if (one == 1)
            cout << "I";
        else if (one == 2)
            cout << "II";
        else if (one == 3)
            cout << "III";
        else if (one == 4)
            cout << "IV";
        else if (one == 5)
            cout << "V";
        else if (one == 6)
            cout << "VI";
        else if (one == 7)
            cout << "VII";
        else if (one == 8)
            cout << "VIII";
        else if (one == 9)
            cout << "IX";
    }

    cout << endl;

    return 0;
}