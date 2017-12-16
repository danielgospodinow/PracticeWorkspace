/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Daniel Gospodinow
 * @idnumber 81531
 * @task 7
 * @compiler GCC
 *
 */

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    unsigned int n, m, y, maxRange = 100000;
    string result = "";
    cin >> n >> m >> y;

    if((n <= 0 || n > maxRange) || (m <= 1 || m > maxRange) || (y < 0 || y >= m))
        return 0;

    for(int i=1; i<m; i++)
        if((int)(pow(i, n))%m == y)
            result += std::to_string(i) + " ";

    if(result != "")
        result.pop_back();
    else
        result = "-1";

    cout << result << endl;

    return 0;
}
