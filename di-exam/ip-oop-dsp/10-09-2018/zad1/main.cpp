//
//  main.cpp
//  zad1
//
//  Created by Gospodinov, Daniel on 24.08.20.
//  Copyright © 2020 danielgospodinow. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

string revealPassword(string** a, int m, int n) {
    string password = " ";
    
    for(int i=0; i<m; ++i) {
        vector<string> currentRowOfBooks;
        for(int j=0; j<n; ++j) {
            if(a[i][j] != "") {
                currentRowOfBooks.push_back(a[i][j]);
            }
        }
        
        bool rowSorted = true;
        for(int j=0; j<(int)currentRowOfBooks.size() - 1; ++j) {
            if(!(currentRowOfBooks.at(j) <= currentRowOfBooks.at(j + 1))) {
                rowSorted = false;
                break;
            }
        }
        
        if(rowSorted && currentRowOfBooks.size() > 0) {
            string middleBook = currentRowOfBooks.at(currentRowOfBooks.size() / 2);
            middleBook += ' ';
            
            int tempSize = 0;
            for(int j=0; j<middleBook.size(); ++j) {
                if(middleBook.at(j) == ' ') {
                    password += (to_string(tempSize) + " ");
                    tempSize = 0;
                } else {
                    ++tempSize;
                }
            }
        }
    }
    password.pop_back();
    
    return password;
}

int main(int argc, const char * argv[]) {
    const int rows = 20;
    const int cols = 30;
    string** library = new string*[rows];
    for(int i=0; i<rows; ++i) {
        library[i] = new string[cols];
    }
    
    library[0][5] = "Algebra";
    library[0][13] = "Analiti4na geometriq";
    library[0][25] = "Matemati4eski analiz";
    
    library[5][0] = "Увод в програмирането";
    library[5][28] = "Обектно-ориентирано програмиране";
    library[5][29] = "Структури от данни и програмиране";
    
    library[17][0] = "Bazi ot danni";
    library[17][1] = "Funkcionalno programirane";
    library[17][2] = "Izkustwen intelekt";
    
    cout << "Password: " << revealPassword(library, rows, cols) << endl;
    
    for(int i=0; i<rows; ++i) {
        delete[] library[i];
    }
    delete[] library;
    
    return 0;
}
