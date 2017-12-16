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
#include <iomanip>
using namespace std;

void initArray(int arr[], int size);
double findDistance(int n, double d, int accelerations[]);
double getCurrentAcceleration(int i, int accelerations[], double d);

int main()
{
    unsigned int n;
    double d;
    cin >> n >> d;

    if(n <= 0)
    {
        cout << "0" << endl;
        return 0;
    }

    int accelerations[n];
    initArray(accelerations, n);

    cout << std::fixed << setprecision(5) << findDistance(n, d, accelerations) << endl;

    return 0;
}

double findDistance(int n, double d, int accelerations[])
{
    double totalDistance = 0;

    for(int i=0; i<n; i++)
    {
        double currentAcc = getCurrentAcceleration(i - 1, accelerations, d) * d;
        if(currentAcc < 0) currentAcc = 0;
        double currentDistance = currentAcc + ((accelerations[i] * d * d) / 2);
        totalDistance += currentDistance;
    }

    return totalDistance;
}

double getCurrentAcceleration(int i, int accelerations[], double d)
{
    if(i <= -1)
        return 0;

    double prevAcc = getCurrentAcceleration(i - 1, accelerations, d);
    if(prevAcc < 0) prevAcc = 0;
    return prevAcc + accelerations[i] * d;
}

void initArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
        cin >> arr[i];
}
