//
//  main.cpp
//  zad1
//
//  Created by Gospodinov, Daniel on 22.08.20.
//  Copyright © 2020 danielgospodinow. All rights reserved.
//

#include <iostream>

bool find(int value, int* arr, size_t size)
{
    if (size == 0)
        return false;
    
    size_t mid = size / 2;
    if (value == arr[mid])
        return true;
    
    if (value < arr[mid])
        return find(value, arr, size/2);
    else
        return find(value, arr + size/2 + 1, size/2);
}

int main() {
    int size = 6;
    int arr[] =  { 0, 10, 22, 45, 91, 220 };
    std::cout << "Find: " << (find(45, arr, size) == 0 ? "no" : "yes") << std::endl;
    
    return 0;
}
