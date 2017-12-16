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

string printNum(int n);

int main()
{
    int n;
    cin >> n;

    cout << printNum(n) << endl;
}

string printNum(int n)
{
    if(n == 1)
        return "1";

    string leftSide = printNum(n - 1);
    string rightSide = printNum(n - 1);
    return leftSide.append(to_string(n)).append(rightSide);
}
