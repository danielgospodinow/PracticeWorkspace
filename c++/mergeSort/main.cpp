#include <iostream>
using namespace std;

void print(int* arr, int n)
{
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void fillArr(int* toFill, int* source, int start, int end)
{
    for(int i=start; i<=end; i++)
        toFill[i - start] = source[i];
}

void merge(int* left, int* right, int* arr, int leftN, int rightN)
{
    int i = 0, j = 0, k = 0;

    while(i<leftN && j<rightN)
    {
        if(left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while(i<leftN)
        arr[k++] = left[i++];

    while(j<rightN)
        arr[k++] = right[j++];
}

void mergeSort(int* arr, int start, int end)
{
    if(end - start == 0)
        return;

    int mid = (start + end) / 2;

    int leftArr[mid], rightArr[end - (mid + 1)];

    fillArr(leftArr, arr, start, mid);
    fillArr(rightArr, arr, mid + 1, end);

    mergeSort(leftArr, 0, mid);
    mergeSort(rightArr, 0, end - (mid + 1));

    merge(leftArr, rightArr, arr, mid - start + 1, end - mid);
}

int main()
{
    int arr[] = {1, 6, -3, 5, 16, 18, -14, -2, 11};
    int size = 9;
    print(arr, size);

    mergeSort(arr, 0, size - 1);

    print(arr, size);

    return 0;
}
