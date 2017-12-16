/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Daniel Gospodinow
 * @idnumber 81531
 * @task 9
 * @compiler GCC
 *
 */

#include <iostream>
using namespace std;

int cropDigit(int num, int pos);

int main()
{
    unsigned int numOne, numTwo, numOneLenght;
    cin >> numOne >> numTwo;

    numOneLenght = to_string(numOne).length();

    if(numOneLenght <= 1 || (numOneLenght <= to_string(numTwo).length()))
    {
        cout << "No" << endl;
        return 0;
    }

    bool fits = false;

    for(int i=0; i<numOneLenght; i++)
    {
        if(cropDigit(numOne, i) == numTwo)
        {
            fits = true;
            break;
        }
    }

    fits?cout << "Yes" << endl:cout << "No" << endl;

    return 0;
}

int cropDigit(int num, int pos)
{
    string numStr = to_string(num), ret = "";
    numStr[pos] = 'p';

    for(int i=0; i<numStr.length(); i++)
        if(numStr[i] != 'p')
            ret += numStr[i];

    return std::stoi(ret);
}
