/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Daniel Gospodinow
 * @idnumber 81531
 * @task 3
 * @compiler GCC
 *
 */

#include <iostream>
using namespace std;

string convToHex(int n);
bool isStrEqual(string str, int pos, int lenght);

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    string hexN = convToHex(n);
    cout << (isStrEqual(hexN, 0, hexN.length())?"Yes":"No") << endl;

    return 0;
}

bool isStrEqual(string str, int pos, int lenght)
{
    if(pos == lenght - 2)
        return str[pos] == str[pos + 1];

    if(isStrEqual(str, pos + 1, lenght) == false)
        return false;
    else
        return str[pos] == str[pos + 1];
}

string convToHex(int n)
{
    if(n != 0)
    {
        string ret = "";

        switch (n%16)
        {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9: ret = to_string(n % 16); break;
        case 10: ret = "A"; break;
        case 11 : ret = "B"; break;
        case 12 : ret = "C"; break;
        case 13: ret ="D"; break;
        case 14: ret = "E"; break;
        case 15: ret = "F"; break;
        default: break;
        }

        return convToHex(n / 16) + ret;
    }

    return "";
}
