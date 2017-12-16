#include <iostream>
#include <math.h>
using namespace std;

struct Box
{
    Box(int n, Box* next):
        nextBox(next), num(n)
    {
    }

    Box* nextBox;
    int num;
};

void print (Box* first)
{
    if(!first)
        cout << "None";

    while(first)
    {
        cout << first->num << " ";
        first = first->nextBox;
    }
    cout << endl;
}

int count (Box* first, int searchedData)
{
    int totalFound = 0;

    while(first)
    {
        if(first->num == searchedData)
            ++totalFound;

        first = first->nextBox;
    }

    return totalFound;
}

Box* range (int start, int end)
{
    Box* startIter = new Box(start, nullptr);
    Box* ret = startIter;

    for(int i=start + 1; i<=end; i++)
    {
        startIter->nextBox = new Box(i, nullptr);
        startIter = startIter->nextBox;
    }

    return ret;
}

void removeAll (Box*& first, int num)
{
    Box* tempFirst = first;
    Box* prev = nullptr;

    while(tempFirst)
    {
        if(tempFirst->num == num)
        {
            if(prev)
            {
                prev->nextBox = tempFirst->nextBox;
                delete tempFirst;
                tempFirst = prev->nextBox;
                continue;
            }

            else
            {
                prev = first;
                first = first->nextBox;
                delete prev;
                continue;
            }
        }

        prev = tempFirst;
        tempFirst = tempFirst->nextBox;
    }
}

void append (Box*& first, Box* second)
{
    if(!first || !second)
        return;

    Box* lastBoxFirst = first;
    while(lastBoxFirst->nextBox)
        lastBoxFirst = lastBoxFirst->nextBox;

    while(second->nextBox)
    {
        lastBoxFirst->nextBox = second;
        lastBoxFirst = second;
        second = second->nextBox;
    }
}

Box* concat (Box* first, Box* second) // Fix
{
    Box* last = nullptr;

    while(second)
    {
        last = new Box(second->num, last);
        second = second->nextBox;
    }

    while(first)
    {
        last = new Box(first->num, last);
        second = second->nextBox;
    }

    return last;
}

void reverse (Box*& first)
{
    Box* last = nullptr;

    while(first)
    {
        last = new Box(first->num, last);

        Box* tempDel = first;
        first = first->nextBox;
        delete tempDel;
    }

    first = last;
}

void map (Box*& first, int (*func) (int))
{
    Box* iter = first;

    while(iter)
    {
        iter->num = func(iter->num);

        iter = iter->nextBox;
    }
}

int doubler (int x)
{
    return x * 2;
}

int main ()
{
    Box* first = new Box(10, new Box(1, new Box(7, new Box(7, new Box(7, new Box(1, new Box(4, nullptr)))))));
    print(first);

    cout << count(first, 1) << endl;

    Box* first2 = range(5, 10);
    print(first2);

    removeAll(first, 7);
    print(first);

    append(first, first2);
    print(first);

    Box* first3 = concat(first, first2);
    print(first3);

    //map(first2, &doubler);
    map(first2, [] (int num) -> int {return pow(num, 2);});
    print(first2);

    reverse(first2);
    print(first2);

    return 0;
}
