/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Daniel Gospodinow
 * @idnumber 81531
 * @task 10
 * @compiler GCC
 *
 */

#include <iostream>
#include <math.h>
using namespace std;

bool isStupidNumber(int num);
void printResult(unsigned int *arr, int size);
int getPAdicNum(int p, int n);

int main()
{
    const unsigned int MAX_NQ = 1000000, MAX_P = 100000007;
    const unsigned long long int MAX_N = MAX_P * MAX_P;
    unsigned int nq, results[nq], p1, n, p2;

    cin >> nq;

    if(nq > MAX_NQ)
        return 0;

    for(int i=0; i<nq; i++)
    {
        cin >> p1 >> n >> p2;

        if(n == 0)
        {
            results[i] = -1;
            continue;
        }
        if(p1 > MAX_P || p2 > MAX_P || n > MAX_N || n < 0 || p1 <= 1 || p2 <= 1 || !isStupidNumber(p1) || !isStupidNumber(p2))
            return 0;

        results[i] = max(getPAdicNum(p1, n), getPAdicNum(p2, n));
    }

    printResult(results, nq);
}

int getPAdicNum(int p, int n)
{
    if(n % p != 0)
        return 0;

    int currentP = p * p, currentResult = 1;

    while(n % currentP == 0)
    {
        currentP *= p;
        currentResult += 1;
    }

    return currentResult;
}

bool isStupidNumber(int num)
{
    for(int i=2; i<=sqrt(num); i++)
        if(num % i == 0)
            return false;

    return true;
}

void printResult(unsigned int* arr, int size)
{
    for(int i=0; i<size; i++)
    {
        if(arr[i] == -1)
            cout << "infinity" << endl;
        else
            cout << arr[i] << endl;
    }
}
