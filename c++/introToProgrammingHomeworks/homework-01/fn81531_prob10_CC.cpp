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

double roundToDigits(double value, int digits);

int main(int argc, char *argv[])
{
    double exp1[3], exp2[3];

    cin >> exp1[0] >> exp1[1] >> exp1[2];
    cin >> exp2[0] >> exp2[1] >> exp2[2];

    double y = (exp1[2] * exp2[0] - exp2[2] * exp1[0]) / (exp2[0] * exp1[1] - exp1[0] * exp2[1]),
            x = (exp2[2] - exp2[1] * y) / exp2[0];

    if(exp2[0] * exp1[1] - exp1[0] * exp2[1] == 0 && exp1[2] * exp2[0] - exp2[2] * exp1[0] == 0)
        cout << "Many solutions" << endl;
    else if(exp2[0] * exp1[1] - exp1[0] * exp2[1] == 0 && exp1[2] && exp1[2] * exp2[0] - exp2[2] * exp1[0] != 0)
        cout << "No solution" << endl;
    else
        cout << roundToDigits(x, 5) << " " << roundToDigits(y, 5) << endl;

    return 0;
}

double roundToDigits(double value, int digits)
{
    if (value == 0.0)
        return 0.0;

    double factor = pow(10.0, digits - ceil(log10(fabs(value))));
    return round(value * factor) / factor;
}
