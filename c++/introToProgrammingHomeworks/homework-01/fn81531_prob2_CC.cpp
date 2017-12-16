/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Daniel Gospodinow
 * @idnumber 81531
 * @task 2
 * @compiler GCC
 *
 */

#include <iostream>
using namespace std;

string charToStr(char c);
int charToInt(char c);

int main(int argc, char *argv[])
{
    string egn;
    cin >> egn;

    int expectedLastDigit = (charToInt(egn[0]) * 2 + charToInt(egn[1]) * 4 + charToInt(egn[2]) * 8 + charToInt(egn[3]) * 5 + charToInt(egn[4]) * 10 + charToInt(egn[5]) * 9 + charToInt(egn[6]) * 7 + charToInt(egn[7]) * 3 + charToInt(egn[8]) * 6) % 11;

    if((egn.length() != 10) || ((expectedLastDigit < 10) && (expectedLastDigit != charToInt(egn[9]))) || ((expectedLastDigit >= 10) && (charToInt(egn[9]) != 0)))
    {
            cout << "Bad input data!" << endl;
            return 0;
    }

    int monthNumber = stoi(charToStr(egn[2]) + charToStr(egn[3]));
    int dayNumber = stoi(charToStr(egn[4]) + charToStr(egn[5]));

    if((monthNumber > 12 + 40) || (dayNumber > 31))
    {
        cout << "Bad input data!" << endl;
        return 0;
    }

    string yearN = "19";
    string sex = (stoi(charToStr(egn[8])) % 2 == 0) ? "M" : "F";

    if(monthNumber - 40 > 0)
    {
        monthNumber -= 40;
        yearN = "20";
    }
    else if(monthNumber - 20 > 0)
    {
        monthNumber -= 20;
        yearN = "18";
    }

    if(monthNumber == 2)
    {
        if(stoi(yearN + charToStr(egn[0]) + charToStr(egn[1])) % 4 != 0 && stoi(charToStr(egn[4]) + charToStr(egn[5])) > 28)
        {
            cout << "Bad input data!" << endl;
            return 0;
        }
        else if(stoi(yearN + charToStr(egn[0]) + charToStr(egn[1])) % 4 == 0  && stoi(charToStr(egn[4]) + charToStr(egn[5])) > 29)
        {
            cout << "Bad input data!" << endl;
            return 0;
        }
    }
    if(monthNumber != 2)
    {
        if(monthNumber == 1 || monthNumber == 3 || monthNumber == 5 || monthNumber ==  7 || monthNumber == 8 || monthNumber == 10 || monthNumber == 12)
        {
            if(stoi(charToStr(egn[4]) + charToStr(egn[5])) > 31)
            {
                cout << "Bad input data!" << endl;
                return 0;
            }
        }
        else
        {
            if(stoi(charToStr(egn[4]) + charToStr(egn[5])) > 30)
            {
                cout << "Bad input data!" << endl;
                return 0;
            }
        }
    }

    string montNumberStr = (monthNumber > 9)?std::to_string(monthNumber):("0" + std::to_string(monthNumber));

    cout << charToStr(egn[4]) + charToStr(egn[5]) << "." << montNumberStr << "." << yearN + charToStr(egn[0]) + charToStr(egn[1]) << " " << sex << endl;

    return 0;
}

string charToStr(char c)
{
    return string(1, c);
}

int charToInt(char c)
{
    return stoi(charToStr(c));
}
