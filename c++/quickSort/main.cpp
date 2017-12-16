#include <iostream>
using namespace std;

void quickSort(int* arr, int size);
void quickSort(int* arr, int left, int right);
int qsPartition(int* arr, int left, int right, int pivot);
void swap(int& a, int& b);
void printArr(int* arr, int size);

int main()
{
    const int SIZE = 6;
    int arr[SIZE] = {1, -8, 14, -5, 0, 9};
    printArr(arr, SIZE);

    quickSort(arr, SIZE);
    printArr(arr, SIZE);

    return 0;
}

void quickSort(int* arr, int size)
{
    quickSort(arr, 0, size - 1);
}

void quickSort(int* arr, int left, int right)
{
    if(left >= right)
        return;

    int pivot = (left + right) / 2;
    int divider = qsPartition(arr, left, right, arr[pivot]);

    quickSort(arr, left, divider - 1);
    quickSort(arr, divider, right);
}

int qsPartition(int* arr, int left, int right, int pivot)
{
    while(left <= right)
    {
        while(arr[left] < pivot)
            ++left;

        while(arr[right] > pivot)
            --right;

        if(left <= right)
        {
            swap(arr[left], arr[right]);
            ++left;
            --right;
        }
    }

    return left;
}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void printArr(int* arr, int size)
{
    for(int i=0; i<size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
