#include <iostream>
#include "linkedstack.hpp"
using namespace std;

void move(LinkedStack<int>& start, LinkedStack<int>& temp, LinkedStack<int>& end, int n)
{
    if(n == 1)
    {
        end.push(start.pop());
        return;
    }

    move(start, end, temp, n - 1);
    move(start, temp, end, 1);
    move(temp, start, end, n - 1);
}

void prytsOfHanoi(LinkedStack<int>& start, LinkedStack<int>& temp, LinkedStack<int>& end)
{
    if(start.getSize() == 0)
    {
        cout << "No input" << endl;
        return;
    }

    move(start, temp, end, start.getSize());
}

void printTowers(LinkedStack<int>& start, LinkedStack<int>& temp, LinkedStack<int>& end)
{
    cout << "First tower-> "; start.print(); cout << endl;
    cout << "Second tower-> "; temp.print(); cout << endl;
    cout << "Third tower-> "; end.print(); cout << endl;
}

int main()
{
    LinkedStack<int> pryt_01, pryt_02, pryt_03;

    for(int i=1; i<=10; i++)
        pryt_01.push(i);

    printTowers(pryt_01, pryt_02, pryt_03);
    prytsOfHanoi(pryt_01, pryt_02, pryt_03);
    printTowers(pryt_01, pryt_02, pryt_03);

    return 0;
}
