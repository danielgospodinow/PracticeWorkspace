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

int main(int argc, char *argv[])
{
    float point[2], r1 = 1, r2 = 3, r3 = 6;
    cin >> point[0] >> point[1];

    if(point[1] > 0)
    {
        if(sqrt(pow((0 - point[0]), 2) + pow((3 - point[1]), 2)) < r1)
            cout << "Evil" << endl;
        else if(sqrt(pow((0 - point[0]), 2) + pow((3 - point[1]), 2)) == r1)
            cout << "Neutral" << endl;
        else
        {
            if(point[0] < 0 && sqrt(pow((0 - point[0]), 2) + pow((0 - point[1]), 2)) <= r3)
                cout << "Good" << endl;
            else
            {
                if(sqrt(pow((0 - point[0]), 2) + pow((3 - point[1]), 2)) < r2)
                    cout << "Good" << endl;
                else if(sqrt(pow((0 - point[0]), 2) + pow((3 - point[1]), 2)) == r2)
                    cout << "Neutral" << endl;
                else
                {
                    if(sqrt(pow((0 - point[0]), 2) + pow((0 - point[1]), 2)) <= r3)
                        cout << "Evil" << endl;
                    else
                        cout << "Neutral" << endl;
                }
            }
        }
    }
    else if(point [1] < 0)
    {
        if(sqrt(pow((0 - point[0]), 2) + pow((-3 - point[1]), 2)) < r1)
            cout << "Good" << endl;
        else if(sqrt(pow((0 - point[0]), 2) + pow((-3 - point[1]), 2)) == r1)
            cout << "Neutral" << endl;
        else
        {
            if(point[0] > 0 && sqrt(pow((0 - point[0]), 2) + pow((0 - point[1]), 2)) <= r3)
                cout << "Evil" << endl;
            else
            {
                if(sqrt(pow((0 - point[0]), 2) + pow((-3 - point[1]), 2)) < r2)
                    cout << "Evil" << endl;
                else if(sqrt(pow((0 - point[0]), 2) + pow((-3 - point[1]), 2)) == r2)
                    cout << "Neutral" << endl;
                else
                {
                    if(sqrt(pow((0 - point[0]), 2) + pow((0 - point[1]), 2)) <= r3)
                        cout << "Good" << endl;
                    else
                        cout << "Neutral" << endl;
                }
            }
        }
    }
    else
    {
        if(point[0] > 0)
            cout <<"Evil" << endl;
        else if(point[0] < 0)
            cout << "Good" << endl;
        else
            cout << "Neutral" << endl;
    }

    return 0;
}
