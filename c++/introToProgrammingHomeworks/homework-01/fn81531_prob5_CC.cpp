/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Daniel Gospodinow
 * @idnumber 81531
 * @task 5
 * @compiler GCC
 *
 */

#include <iostream>
#include <math.h>
using namespace std;

double roundToDigits(double value, int digits);

int main(int argc, char *argv[])
{
    double targetPoint[2], deviation[2];
    double radius01 = 8, radius02 = 3, radius03 = 1;
    int rad01Val = 10, rad02Val = 20, rad03Val = 2 * (rad01Val + rad02Val);
    int score = 0;

    cin >> targetPoint[0] >> targetPoint[1] >> deviation[0] >> deviation[1];

    targetPoint[0] += deviation[0];
    targetPoint[1] += deviation[1];

	double distance = roundToDigits(sqrt(pow(targetPoint[0], 2) + pow(targetPoint[1], 2)), 3);

	if(distance == radius03 || distance == radius02 || distance == radius01)
		score += 0;
    else if(distance < radius03)
        score += rad03Val;
    else if(distance < radius02)
        score += rad02Val;
    else if(distance < radius01)
        score += rad01Val;

    cout << score << endl;

    return 0;
}

double roundToDigits(double value, int digits)
{
    if (value == 0.0)
        return 0.0;

    double factor = pow(10.0, digits - ceil(log10(fabs(value))));
    return round(value * factor) / factor;
}
