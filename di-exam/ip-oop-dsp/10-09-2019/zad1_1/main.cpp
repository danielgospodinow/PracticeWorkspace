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
        return find(value, arr, mid);
    else
        return find(value, arr + mid + 1, size - (mid + 1));
}

int main() {
    int size = 8;
    int arr[] =  { 0, 10, 22, 45, 91, 220, 230, 240 };
    
    for(int i=0; i<size; ++i) {
        std::cout << "Find: " << (find(arr[i], arr, size) == 0 ? "no" : "yes") << std::endl;
    }
    
    std::cout << "Find: " << (find(17, arr, size) == 0 ? "no" : "yes") << std::endl;
    std::cout << "Find: " << (find(33, arr, size) == 0 ? "no" : "yes") << std::endl;
    std::cout << "Find: " << (find(69, arr, size) == 0 ? "no" : "yes") << std::endl;
    std::cout << "Find: " << (find(-1, arr, size) == 0 ? "no" : "yes") << std::endl;
    std::cout << "Find: " << (find(250, arr, size) == 0 ? "no" : "yes") << std::endl;
    
    return 0;
}
