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
#include <math.h>
using namespace std;

bool isStupidNumber(int num);

int main()
{
    int n, maxRange = 100000, i =5, totalNumbers = 0;
    cin >> n;

    if(n > maxRange)
        return 0;

    while(totalNumbers < n)
    {
        if(isStupidNumber(i) && isStupidNumber(i - 2))
        {
            totalNumbers += 1;
            cout << i-2 << " " << i << endl;
        }

        i++;
    }

    return 0;
}

bool isStupidNumber(int num)
{
    bool isStupid = true;

    for(int i=2; i<=sqrt(num); i++)
        if(num % i == 0)
            isStupid = false;

    return isStupid;
}

