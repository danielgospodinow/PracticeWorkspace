/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Daniel Gospodinow
 * @idnumber 81531
 * @task 8
 * @compiler GCC
 *
 */

#include <iostream>
#include <math.h>
using namespace std;

void sortByModul3(int* arr, int size);
void initArr(int* arr, int size);
void swapNums(int &a, int &b);
void printArr(int* arr, int size);

int main()
{
    int n, *arr = NULL;
    cin >> n;

    arr = new int[n];

    initArr(arr, n);
    sortByModul3(arr, n);
    printArr(arr, n);

    delete arr;
    return 0;
}

void printArr(int* arr, int size)
{
  for(int i=0; i<size; i++)
  {
    if(i == size-1)
      cout << arr[i];
    else
      cout << arr[i] << " ";
  }
  cout << endl;
}

void sortByModul3(int* arr, int size)
{
    for(int i=0; i<size - 1; i++)
    {
        int minIndex= i;

        for(int j=i + 1; j < size; j++)
            if((arr[j] % 3) < (arr[minIndex] % 3))
                minIndex = j;

        swapNums(arr[i], arr[minIndex]);
    }
}

void swapNums(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void initArr(int* arr, int size)
{
    for(int i=0; i<size; i++)
        cin >> arr[i];
}
