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
#include <stdlib.h>
using namespace std;

int validateNumber(int num);

int main(int argc, char *argv[])
{
    int a, b;
    char operation;

    cin >> a >> operation >> b;

    if(operation == '+')
        cout <<  validateNumber(validateNumber(a) + validateNumber(b)) << endl;
    else if(operation == '-')
        cout << validateNumber(validateNumber(validateNumber(a) - validateNumber(b))) << endl;
    else if(operation == '.')
        cout <<  validateNumber(validateNumber(a) * validateNumber(b)) << endl;
    else if(operation == '/' || operation == '%')
    {
        if(validateNumber(b) == 0)
        {
            cout << "Division by zero!" << endl;
            return 0;
        }

        if(operation == '/')
            cout << validateNumber(validateNumber(a) / validateNumber(b)) << endl;
        else if(operation == '%')
            cout << validateNumber(validateNumber(a) % validateNumber(b)) << endl;
    }

    return 0;
}

int validateNumber(int num)
{
    if(num <= 15 && num >= 0)
        return num;
    else if(num <= 0 && num >= -15)
        return num + 16;
    else
    	return num % ((abs(num) / 16) * 16);
}
