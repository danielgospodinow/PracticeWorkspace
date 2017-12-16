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

const int MAX_TEXT_SIZE = 10001;
void swapWords(char *text, int swaps);
void cheatAppend(char *str);
void changeWord(char* str, int swaps);
int getStrLen(char* str);

int main()
{
    //!!! This works for single words and whole sentances.

    char text[MAX_TEXT_SIZE + 1];
    unsigned int swaps;

    cin.getline(text, MAX_TEXT_SIZE);
    cheatAppend(text);
    cin >> swaps;

    swapWords(text, swaps);
    cout << text << endl;

    return 0;
}

void swapWords(char* text, int swaps)
{
    char* pointer = text;
    bool onAWord = false;
    int space = 0;
    auto isAlphabetChar = [](char c) { return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')?true:false; };

    while(*text)
    {
        if(isAlphabetChar(*text) || (*text == '-' && isAlphabetChar(*(text - 1)) && isAlphabetChar(*(text + 1)) ))
        {
            if(!onAWord)
            {
                onAWord = true;
                pointer = text;
            }

            space += 1;
        }
        else
        {
            if(onAWord)
            {
                char* startPointer = pointer;
                char* currentWord = new char[space];
                for(int i=0; i<space; i++)
                    currentWord[i] = *(pointer++);

                changeWord(currentWord, swaps);
                //cout << currentWord << endl;

                for(int i=0; i<space; i++)
                    *(startPointer++) = currentWord[i];

                space = 0;
                delete currentWord;
            }

            onAWord = false;
        }

        text += 1;
    }
}

void changeWord(char* str, int swaps)
{
    for(int i=0; i<swaps; i++)
    {
        char lastC = str[getStrLen(str) - 1];
        char prevC = str[0];

        for(int j=1; j<getStrLen(str); j++)
        {
            char currC = str[j];
            str[j] = prevC;
            prevC = currC;

            if(j == getStrLen(str) - 1)
                str[0] = lastC;
        }
    }
}

int getStrLen(char* str)
{
    int size = 0;
    while(*(str++))
        size += 1;
    return size;
}

void cheatAppend(char* str)
{
    while(*str)
        str += 1;
    *str = ' ';
}
