//
//  main.cpp
//  zad1_2
//
//  Created by Gospodinov, Daniel on 22.08.20.
//  Copyright © 2020 danielgospodinow. All rights reserved.
//

#include <iostream>

template <typename ReturnType, typename InputType, typename OpType>
ReturnType fold_left(InputType* arr, size_t size, OpType op, ReturnType nil) {
    ReturnType result = nil;
    
    for (size_t i = 0; i < size; ++i)
        result = op(arr[i], result);
    
    return result;
}

int op(char Digit, int Result) {
    return (Result * 10) + (Digit - '0');
}

// Преобразува символен низ от десетични цифри до величина от тип int
int str_to_int(const char * str) {
    return (str == nullptr)
        ? 0
        : fold_left(str, strlen(str), op, 0);
}

int main(int argc, const char * argv[]) {
    int strInt = str_to_int("1234");
    int randomInt = 1111;
    
    std::cout << strInt + randomInt << std::endl;
    
    return 0;
}
