/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Daniel Gospodinow
 * @idnumber 81531
 * @task 4
 * @compiler GCC
 *
 */

#include <iostream>
#include <math.h>
using namespace std;

void scanElements(int num, int digits[]);

int main()
{
    int a, b, totalDigits = 10, aElements[totalDigits], bElements[totalDigits];
    cin >> a >> b;

    for(int i=0; i<totalDigits; i++)
    {
        aElements[i] = 0;
        bElements[i] = 0;
    }

    if(a<0)
        a = abs(a);
    if(b<0)
        b = abs(b);

    scanElements(a, aElements);
    scanElements(b, bElements);

    bool haveEqualElements = true;

    for(int i=0; i<totalDigits; i++)
        if(!((aElements[i] > 0 && bElements[i] > 0) || (aElements[i] == 0 && bElements[i] == 0)))
            haveEqualElements = false;

    haveEqualElements?cout << "Yes" << endl:cout << "No" << endl;

    return 0;
}

void scanElements(int num, int digits[])
{
    while(num >= 10)
    {
        int currentDigit = num % 10;
        digits[currentDigit] += 1;
        num /= 10;
    }
    digits[num] += 1;
}
