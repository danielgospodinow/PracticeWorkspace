//
//  main.cpp
//  zad2
//
//  Created by Gospodinov, Daniel on 22.08.20.
//  Copyright © 2020 danielgospodinow. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

struct Tree {
public:
    Tree(map<int, vector<int>> const& treeVals, map<pair<int, int>, char> const& edges, int root) {
        this->treeVals = treeVals;
        this->edges = edges;
        this->root = root;
    }
    
    map<int, vector<int>> getTree() const { return treeVals; }
    map<pair<int, int>, char> getEdges() const { return edges; }
    int getRoot() const { return root; }
    
    vector<int> getChildrenOfVertex(int vertex) const { return (treeVals.find(vertex) != treeVals.end()) ? treeVals.at(vertex) : vector<int>(); }
    
private:
    map<int, vector<int>> treeVals;
    map<pair<int, int>, char> edges;
    int root;
    
};

void getAllBranchesFrom(int s, Tree const& t, vector<vector<int>>& branches, vector<int>& currentBranch) {
    if(t.getChildrenOfVertex(s).size() <= 0) {
        currentBranch.push_back(s);
        branches.push_back(currentBranch);
        currentBranch.pop_back();
        return;
    }
    
    currentBranch.push_back(s);
    for(int i=0; i<t.getChildrenOfVertex(s).size(); ++i) {
        getAllBranchesFrom(t.getChildrenOfVertex(s).at(i), t, branches, currentBranch);
    }
    currentBranch.pop_back();
}

void printBranches(vector<vector<int>> branches) {
    for (vector<int> branch : branches) {
        stringstream result;
        copy(branch.begin(), branch.end(), std::ostream_iterator<int>(result, " "));
        cout << "Branch: " << result.str().c_str() << endl;
    }
}

string branchWord(Tree const& t, vector<int> branch) {
    string ret = "";
    for(int i=0; i<branch.size() - 1; ++i) {
        ret += t.getEdges().at(pair<int, int>(branch.at(i), branch.at(i + 1)));
    }
    return ret;
}

int branchValue(vector<int> branch) {
    int ret = 0;
    
    for(int vertex : branch) {
        ret += vertex;
    }
    
    return ret;
}

void commonBranches(Tree const& t, int u, int v, int k) {
    vector<vector<int>> uBranches;
    vector<int> uTempBranch;
    
    vector<vector<int>> vBranches;
    vector<int> vTempBranch;
    
    getAllBranchesFrom(u, t, uBranches, uTempBranch);
    getAllBranchesFrom(v, t, vBranches, vTempBranch);
    
    for(vector<int> uBranch : uBranches) {
        string currentUWord = branchWord(t, uBranch);
        int currentUVal = branchValue(uBranch);
        
        for(vector<int> vBranch : vBranches) {
            string currentVWord = branchWord(t, vBranch);
            int currentVVal = branchValue(vBranch);
            
            if(currentUWord == currentVWord && currentUVal + currentVVal == k) {
                cout << currentUWord << endl;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    map<int, vector<int>> t;
    map<pair<int, int>, char> e;
    
    t[1] = vector<int>();
    t[1].push_back(2);
    t[1].push_back(3);
    t[1].push_back(4);
    
    t[2] = vector<int>();
    t[2].push_back(5);
    t[2].push_back(6);
    
    t[3] = vector<int>();
    t[3].push_back(7);
    
    t[4] = vector<int>();
    t[4].push_back(8);
    t[4].push_back(9);
    t[4].push_back(10);
    
    t[5] = vector<int>();
    t[5].push_back(36);
    
    t[8] = vector<int>();
    t[8].push_back(32);
    
    t[32] = vector<int>();
    t[32].push_back(60);
    
    t[36] = vector<int>();
    t[36].push_back(59);
    
    t[59] = vector<int>();
    t[59].push_back(19);
    
    t[60] = vector<int>();
    t[60].push_back(21);
    
    e[pair<int, int>(1, 2)] = 'a';
    e[pair<int, int>(1, 3)] = 'b';
    e[pair<int, int>(1, 4)] = 'c';
    e[pair<int, int>(2, 5)] = 'd';
    e[pair<int, int>(2, 6)] = 'e';
    e[pair<int, int>(3, 7)] = 'f';
    e[pair<int, int>(4, 8)] = 'g';
    e[pair<int, int>(4, 9)] = 'h';
    e[pair<int, int>(4, 10)] = 'i';
    e[pair<int, int>(5, 36)] = 'k';
    e[pair<int, int>(8, 32)] = 'k';
    e[pair<int, int>(32, 60)] = 'u';
    e[pair<int, int>(36, 59)] = 'u';
    e[pair<int, int>(59, 19)] = 'r';
    e[pair<int, int>(60, 21)] = 'r';
    
    Tree tree (t, e, 1);
    
    commonBranches(Tree(t, e, 1), 5, 8, 240);
    
    return 0;
}
