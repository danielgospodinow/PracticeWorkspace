//
//  main.cpp
//  zad2
//
//  Created by Gospodinov, Daniel on 24.08.20.
//  Copyright © 2020 danielgospodinow. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

struct Node {
    Node(int num, Node* next, Node* fastNext)
        : num(num), next(next), fastNext(fastNext) {
    }
    
    int num;
    Node* next;
    Node* fastNext;
};

Node* readList(string filepath, int& listSize) {
    Node* list = nullptr;
    
    ifstream listFile(filepath);
    if(listFile.is_open()) {
        int prevNum;
        listFile >> prevNum;
        Node* prevItem = new Node(prevNum, nullptr, nullptr);
        list = prevItem;
        
        int size = 1;
        
        int num;
        while(listFile >> num) {
            Node* currentItem = new Node(num, nullptr, nullptr);
            prevItem->next = currentItem;
            prevItem = currentItem;
            ++size;
        }
        
        listFile.close();
        listSize = size;
        
        int jumpDistance = (int) sqrt((double) size);
        Node* prev = list;
        Node* current = list->next;
        for (int i=1; i<size; ++i) {
            if(i % jumpDistance == 0) {
                prev->fastNext = current;
                prev = current;
            }
            
            current = current->next;
        }
    }
    
    return list;
}

bool member(Node* listStart, int num) {
    Node* prev = listStart;
    Node* it = listStart->fastNext;
    while(it && it->num < num) {
        prev = it;
        it = it->fastNext;
    }
    
    if(it && it->num == num) {
        return true;
    }
    
    while(prev != it) {
        if(prev->num == num) {
            return true;
        } else {
            prev = prev->next;
        }
    }
    
    return false;
}

void print(Node* listHead) {
    cout << "List: ";
    
    Node* it = listHead;
    while(it) {
        cout << it->num << " ";
        it = it->next;
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    int listSize;
    Node* listStart = readList("list.txt", listSize);
    
    cout << "List size: " << listSize << endl;
    print(listStart);
    
    cout << (member(listStart, 32) == 0 ? "no" : "yes") << endl;
    cout << (member(listStart, 91) == 0 ? "no" : "yes") << endl;
    cout << (member(listStart, 111) == 0 ? "no" : "yes") << endl;
    cout << (member(listStart, 12) == 0 ? "no" : "yes") << endl;
    cout << (member(listStart, 404) == 0 ? "no" : "yes") << endl;
    cout << (member(listStart, 503) == 0 ? "no" : "yes") << endl;
    cout << (member(listStart, 1) == 0 ? "no" : "yes") << endl;
    
    cout << (member(listStart, 49) == 0 ? "no" : "yes") << endl;
    cout << (member(listStart, 50) == 0 ? "no" : "yes") << endl;
    cout << (member(listStart, 1110) == 0 ? "no" : "yes") << endl;
    cout << (member(listStart, 511) == 0 ? "no" : "yes") << endl;
    cout << (member(listStart, 504) == 0 ? "no" : "yes") << endl;
    cout << (member(listStart, -15) == 0 ? "no" : "yes") << endl;
    
    return 0;
}
