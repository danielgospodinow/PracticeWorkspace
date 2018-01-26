#include <iostream>

struct Elem 
{
    Elem(int _x, Elem* _next = nullptr):
        x(_x), next(_next)
    {
    }

    int x; 
    Elem *next;
};

int getIElem(Elem* start, int i)
{
    while(i-- > 0 && start)
        start = start->next;

    return (start ? start->x : 0);
}

void clearList(Elem*& list)
{
    if(!list)
        return;

    clearList(list->next);
    delete list;
    list = nullptr;
}

void addElemToList(Elem* list, int elem)
{
    if(!list)
    {
        list = new Elem(elem);
        return;
    }

    while(list->next)
        list = list->next;

    list->next = new Elem(elem);
}

void combineSum(Elem** const lists, int n, Elem*& L)
{
    clearList(L);
    int k = 0;

    while(true)
    {
        int currentSum = 0;
        for(int i=0; i<n; ++i)
            currentSum += getIElem(lists[i], k);

        if(currentSum == 0)
            break;
        else
            addElemToList(L, currentSum);

        ++k;
    }
}

int main()
{
    return 0;
}