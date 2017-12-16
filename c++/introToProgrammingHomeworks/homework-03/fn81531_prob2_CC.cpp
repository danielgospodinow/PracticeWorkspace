/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Daniel Gospodinow
 * @idnumber 81531
 * @task 2
 * @compiler GCC
 *
 */

#include <iostream>
using namespace std;

void printSums(int startNum, int currentSum, int neededSum, int depth, int *arr);
void printArr(int* arr, int size);

int main()
{
    unsigned int num;
    int* arr = new int [num];
    cin >> num;

    printSums(num, 0, num, 0, arr);

    delete arr;
    return 0;
}

void printSums(int startNum, int currentSum, int neededSum, int depth, int* arr)
{
    if(startNum <= 0 || currentSum > neededSum)
        return;

    for(int i=0; i<startNum; i++)
    {
        int currN = (startNum - i);

        if(currentSum + currN == neededSum)
        {
            arr[depth] = currN;
            printArr(arr, neededSum);
            continue;
        }
        else if(currentSum + currN < neededSum)
            arr[depth] = currN;

        printSums(currN, currentSum + currN, neededSum, depth + 1, arr);
        arr[depth] = 0;
    }
}

void printArr(int* arr, int size)
{
    cout << size << " = ";

    int nonZeroSize = 0;

    for(int i=0; i<size; i++)
        if(arr[i] != 0)
            nonZeroSize += 1;

    for(int i=0; i<nonZeroSize; i++)
    {
            if(i != 0)
                cout << "+ ";
            if(i != nonZeroSize - 1)
                cout << arr[i] << " ";
            else
                cout << arr[i];
    }

    cout << endl;
}
