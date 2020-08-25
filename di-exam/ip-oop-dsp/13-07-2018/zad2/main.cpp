//
//  main.cpp
//  zad2
//
//  Created by Gospodinov, Daniel on 25.08.20.
//  Copyright © 2020 danielgospodinow. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

struct Node {
    Node(char ch, Node* left = nullptr, Node* mid = nullptr, Node* right = nullptr):
        ch(ch), left(left), mid(mid), right(right) {
    }
    
    char ch;
    Node* left;
    Node* mid;
    Node* right;
};

void readLastHelperRec(Node* vertex, map<int, string>& depthWords, int currentDepth, int& maxDepth) {
    if(!vertex) {
        return;
    }
    
    if(currentDepth > maxDepth) {
        maxDepth = currentDepth;
    }
    
    depthWords[currentDepth] += vertex->ch;
    
    readLastHelperRec(vertex->left, depthWords, currentDepth + 1, maxDepth);
    readLastHelperRec(vertex->mid, depthWords, currentDepth + 1, maxDepth);
    readLastHelperRec(vertex->right, depthWords, currentDepth + 1, maxDepth);
}

string readLast(Node* treeRoot) {
    map<int, string> depthWords;
    int maxDepth;
    readLastHelperRec(treeRoot, depthWords, 0, maxDepth);
    
    return depthWords.at(maxDepth);
}

int main() {
    Node h('h');
    Node u('u');
    Node i('i');
    Node p('p');
    Node q('q');
    Node r('r', &h, &u, nullptr);
    Node s('s', nullptr, &i, nullptr);
    Node x('x', &p, &q, &r);
    Node y('y', nullptr, nullptr, &s);
    Node root('b', &x, &y, nullptr);
    
    cout << readLast(&root) << endl;
    
    return 0;
}
