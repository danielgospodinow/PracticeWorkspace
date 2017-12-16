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
#include <math.h>
using namespace std;

bool isNumValid(int num, int numSys);
int sumInNumSys(int numOne, int numTwo, int numSys);
int convertToDec(int num, int numSys);
string reverseString(string str);

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    if(!(isNumValid(n, k) && isNumValid(m, k) && k >= 2 && k <= 10 && m >= 0 && n >= 0 && m <= 500000 && n <= 500000))
    {
        cout << "Bad input data!" << endl;
        return 0;
    }

    cout << sumInNumSys(n, m, k) << endl;

    return 0;
}

int sumInNumSys(int numOne, int numTwo, int numSys)
{
    int decSum = convertToDec(numOne, numSys) + convertToDec(numTwo, numSys);
    string result = "";

    while(decSum > 0)
    {
        int currentDigit = decSum % numSys;
        result += to_string(currentDigit);
        decSum /= numSys;
    }

    return stoi(reverseString(result));
}

string reverseString(string str)
{
    string temp = "";
    for(int i=str.length()-1; i >= 0; i--)
        temp += str[i];

    return temp;
}

int convertToDec(int num, int numSys)
{
    int ret = 0;
    string numStr = to_string(num);

    for(int i=0; i<numStr.length(); i++)
        ret += (int)(numStr[i] - '0') * pow(numSys, numStr.length() - (i + 1));

    return ret;
}

bool isNumValid(int num, int numSys)
{
    while(num > 0)
    {
        int currentDigit = num % 10;
        if(currentDigit >= numSys)
            return false;
        num /= 10;
    }

    return true;
}
