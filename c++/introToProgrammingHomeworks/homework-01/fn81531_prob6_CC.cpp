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
#include <math.h>
using namespace std;

int main(int argc, char *argv[])
{
    int rect01[4], rect02[4];
    cin >> rect01[0] >> rect01[1] >> rect01[2] >> rect01[3];
    cin >> rect02[0] >> rect02[1] >> rect02[2] >> rect02[3];

    int overlapW, overlapH;

    if(rect01[0] < rect02[0])
        overlapW = rect01[0] + rect01[3] - rect02[0];
    else
        overlapW = rect02[0] + rect02[3] - rect01[0];

    if(rect01[1] < rect02[1])
        overlapH = rect01[1] + rect01[2] - rect02[1];
    else
        overlapH = rect02[1] + rect02[2] - rect01[1];

    int overlapArea = overlapH * overlapW;

    (overlapArea >= 0)?cout<<overlapArea<<endl:cout<<"0"<<endl;

    return 0;
}
