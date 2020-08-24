//
//  main.cpp
//  zad2
//
//  Created by Gospodinov, Daniel on 23.08.20.
//  Copyright © 2020 danielgospodinow. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Vertex {
    Vertex(int i, vector<Vertex> children, int num, char ch) :
        i(i), children(children), num(num), ch(ch) {
    }
    
    int i;
    vector<Vertex> children;
    
    int num;
    char ch;
};

char sym(Vertex const& vertex) {
    return vertex.ch;
}

int val(Vertex const& vertex) {
    return vertex.num;
}

int sumValRec(Vertex const& u, Vertex const& v, int sum) {
    if(u.children.size() == 0 && v.children.size() == 0) {
        if(u.ch == v.ch) {
            return sum + (u.num + v.num);
        } else {
            return 0;
        }
    }
    
    if(u.children.size() == 0 || v.children.size() == 0 || u.ch != v.ch) {
        return 0;
    }
    
    int result = 0;
    for(int i=0; i<u.children.size(); ++i) {
        for(int j=0; j<v.children.size(); ++j) {
            if(u.children.at(i).ch == v.children.at(j).ch) {
                result += sumValRec(u.children.at(i), v.children.at(j), sum + (u.num + v.num));
            }
        }
    }
    
    return result;
}

int sumVal(Vertex const& u, Vertex const& v) {
    return sumValRec(u, v, 0);
}

int main() {
    Vertex r1(11, vector<Vertex>(), 11, 'r');
    Vertex r2(12, vector<Vertex>(), 12, 'r');
    Vertex m(8, vector<Vertex>(), 8, 'm');
    Vertex z(9, vector<Vertex>(), 9, 'z');
    Vertex w(10, vector<Vertex>(), 10, 'w');
    Vertex a1(5, vector<Vertex>(), 5, 'a');
    Vertex a2(6, vector<Vertex>(), 6, 'a');
    
    vector<Vertex> u1Children;
    u1Children.push_back(m);
    u1Children.push_back(r1);
    Vertex u1(4, u1Children, 4, 'u');
    
    vector<Vertex> u2Children;
    u2Children.push_back(z);
    u2Children.push_back(r2);
    u2Children.push_back(w);
    Vertex u2(7, u2Children, 7, 'u');
    
    vector<Vertex> k1Children;
    k1Children.push_back(u1);
    k1Children.push_back(a1);
    Vertex k1(2, k1Children, 2, 'k');
    
    vector<Vertex> k2Children;
    k2Children.push_back(u2);
    k2Children.push_back(a2);
    Vertex k2(3, k2Children, 3, 'k');
    
    vector<Vertex> rootChildren;
    rootChildren.push_back(k1);
    rootChildren.push_back(k2);
    Vertex root(1, rootChildren, 1, 'y');
    
    cout << "SumVal: " << sumVal(k1, k2) << endl;
    
    return 0;
}
