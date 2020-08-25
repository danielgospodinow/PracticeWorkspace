//
//  main.cpp
//  zad1
//
//  Created by Gospodinov, Daniel on 25.08.20.
//  Copyright © 2020 danielgospodinow. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

bool isLexSmallerThan(int a, int b) {
    const char* aStr = to_string(a).c_str();
    const char* bStr = to_string(b).c_str();
    
    while(strcmp(aStr, "") != 0 && strcmp(bStr, "") != 0) {
        char aChar = aStr[0];
        char bChar = bStr[0];
        
        aStr++;
        bStr++;
        
        if(bChar <= aChar) {
            return false;
        }
    }
    
    return true;
}

void sortLex(int n, int* arr) {
    for(int i=0; i<n; ++i) {
        int smallestIndex = i;
        for(int j=i; j<n; ++j) {
            if(isLexSmallerThan(arr[j], arr[smallestIndex])) {
                smallestIndex = j;
            }
        }
        swap(arr[i], arr[smallestIndex]);
    }
}

void print(int n, int* arr) {
    for(int i=0; i<n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    const int n = 7;
    int arr[n] = { 7, 1, 91, 15, 56, 55, 123 };
    
    print(n, arr);
    sortLex(n, arr);
    print(n, arr);
    
    return 0;
}
