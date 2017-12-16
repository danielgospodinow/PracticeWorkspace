/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Daniel Gospodinow
 * @idnumber 81531
 * @task 6
 * @compiler GCC
 *
 */

#include <iostream>
using namespace std;

void initFactorialStorage();
unsigned int getFactorial(unsigned int n);

const int FACTORIAL_STORAGE_SIZE = 50;
int factorialStorage[FACTORIAL_STORAGE_SIZE];

int main()
{
    initFactorialStorage();

    string result = "";
    unsigned int n;
    cin >> n;

    for(int k=0; k<=n; k++)
        result += to_string(getFactorial(n) / (getFactorial(k) * getFactorial(n - k))) + " ";

    result.pop_back();
    cout << result << endl;

    return 0;
}

unsigned int getFactorial(unsigned int n)
{
    if (n <= 0)
        return 1;

    if(n < FACTORIAL_STORAGE_SIZE && factorialStorage[n] != 0)
        return factorialStorage[n];

    return factorialStorage[n] = n * getFactorial(n-1);
}

void initFactorialStorage()
{
    for(int i=0; i<FACTORIAL_STORAGE_SIZE; i++)
        factorialStorage[i] = 0;
}
