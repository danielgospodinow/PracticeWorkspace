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
using namespace std;

void initDataBase(float **& dataBase, int rows, int cols);
void sortDataBase(float**& dataBase, int rows, int cols);
void printDataBase(float**& dataBase, int rows, int cols);
void releaseDataBase(float**& dataBase, int rows, int cols);
void swapRows(float *rowOne, float *rowTwo, int rowSize);

int main()
{
    const int COLS = 3;
    int rows;
    float **dataBase = NULL;

    cin >> rows;

    initDataBase(dataBase, rows, COLS);
    sortDataBase(dataBase, rows, COLS);
    printDataBase(dataBase, rows, COLS);

    releaseDataBase(dataBase, rows, COLS);
    return 0;
}

void sortDataBase(float **&dataBase, int rows, int cols)
{
    for(int i=0; i<rows; i++)
    {
        int minIndex = i;

        for(int j=i + 1; j < rows; j++)
        {
            if(dataBase[j][0] == dataBase[i][0] && dataBase[j][1] < dataBase[i][1])
                swapRows(dataBase[j], dataBase[i], cols);
            if(dataBase[j][0] < dataBase[minIndex][0])
                minIndex = j;
        }

        if(dataBase[i][0] != dataBase[minIndex][0])
            swapRows(dataBase[i], dataBase[minIndex], cols);
    }
}

void printDataBase(float **&dataBase, int rows, int cols)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(j != cols - 1)
                cout << dataBase[i][j] << " ";
            else
                cout << dataBase[i][j];
        }
        cout << endl;
    }
}

void initDataBase(float **&dataBase, int rows, int cols)
{
    dataBase = new float*[rows];
    for(int i=0; i<rows; i++)
    {
        dataBase[i] = new float[cols];

        for(int j=0; j<cols; j++)
            cin >> dataBase[i][j];
    }
}

void releaseDataBase(float **&dataBase, int rows, int cols)
{
    for(int i=0; i<rows; i++)
        delete [] dataBase[i];
    delete [] dataBase;
}

void swapRows(float *rowOne, float *rowTwo, int rowSize)
{
    float* temp = new float[rowSize];

    for(int i=0; i<rowSize; i++)
    {
        temp[i] = rowOne[i];
        rowOne[i] = rowTwo[i];
        rowTwo[i] = temp[i];
    }

    delete temp;
}
