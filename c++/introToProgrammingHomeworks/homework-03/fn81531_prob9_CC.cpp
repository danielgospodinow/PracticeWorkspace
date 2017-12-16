/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Daniel Gospodinow
 * @idnumber 81531
 * @task 9
 * @compiler GCC
 *
 */

#include <iostream>
using namespace std;

void initDataBase(int **& dataBase, int rows, int*& babaDat, int cols);
void printNiceOffers(int**& dataBase, int rows, int*& babaData);
void releaseDataBase(int**& dataBase, int rows, int*& babaData);

int main()
{
    int rows;
    const int COLS = 4;
    int **dataBase = NULL;
    int* babaData = NULL;

    cin >> rows;

    initDataBase(dataBase, rows, babaData, COLS);
    printNiceOffers(dataBase, rows, babaData);

    releaseDataBase(dataBase, rows, babaData);
    return 0;
}

void printNiceOffers(int **&dataBase, int rows, int *&babaData)
{
    bool atleastOne = false;

    for(int i=0; i<rows; i++)
    {
        if(dataBase[i][1] > babaData[0] && dataBase[i][2] > babaData[1] && dataBase[i][3] > babaData[2])
        {
            cout << dataBase[i][0] << " " << dataBase[i][1] << " " << dataBase[i][2] << " " << dataBase[i][3] << endl;
            atleastOne = true;
        }
     }

    if(!atleastOne)
        cout << "No solution" << endl;
}

void initDataBase(int **&dataBase, int rows, int *&babaDat, int cols)
{
    dataBase = new int*[rows];
    for(int i=0; i<rows; i++)
    {
        dataBase[i] = new int[cols];

        for(int j=0; j<cols; j++)
            cin >> dataBase[i][j];
    }

    babaDat = new int[3];
    for(int i=0; i<3; i++)
        cin >> babaDat[i];
}

void releaseDataBase(int **&dataBase, int rows, int *&babaData)
{
    for(int i=0; i<rows; i++)
        delete [] dataBase[i];
    delete [] dataBase;

    delete [] babaData;
}
