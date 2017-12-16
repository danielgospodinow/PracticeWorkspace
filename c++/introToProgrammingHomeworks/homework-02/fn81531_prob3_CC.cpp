/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Daniel Gospodinow
 * @idnumber 81531
 * @task 3
 * @compiler GCC
 *
 */
#include <iostream>
using namespace std;

const int numLenght(int num);
void convertIntToStr(char str[], int num);

int main ()
{
    unsigned long wantedNum, searchFieldNum, maxRange = 4000000000;
    cin >> wantedNum >> searchFieldNum;

    if(wantedNum > searchFieldNum || searchFieldNum > maxRange)
        return 0;

    const int wantedNumStrLenght = numLenght(wantedNum), searchFieldNumStrLenght = numLenght(searchFieldNum);
    char wantedNumStr[wantedNumStrLenght + 1], searchFieldNumStr[searchFieldNumStrLenght + 1];

    convertIntToStr(wantedNumStr, wantedNum);
    convertIntToStr(searchFieldNumStr, searchFieldNum);

    int equalCounter = 0;

    for(int i=0; i < searchFieldNumStrLenght - wantedNumStrLenght + 1; i++)
    {
        bool areEqual = true;
        for(int k =0; k<wantedNumStrLenght; k++)
        {
            if(searchFieldNumStr[i + k] != wantedNumStr[k])
                areEqual = false;
        }
        (areEqual)?equalCounter+=1:equalCounter+=0;
    }

    cout << equalCounter << endl;

    return 0;
}

const int numLenght(int num)
{
    int lenght = 0;

    while (num > 0)
    {
        num /= 10;
        lenght += 1;
    }

    return lenght;
}

void convertIntToStr(char str[], int num)
{
    int i = 0;
    while (num > 0)
    {
        int lastDigit = num % 10;
        str[i] = '0' + lastDigit;
        num /= 10;

        i++;
    }
    str[i] = '\0';
}
