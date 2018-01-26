#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>

class Graph
{
public:
    Graph(int vertices):
        _size(vertices)
    {
        init();
    }

    void addEdge(int from, int to)
    {
        _arr[from][to] = 1;
    }

    void printMatrix()
    {
        for(int i=0; i<_size; ++i)
        {
            for(int j=0; j<_size; ++j)
                std::cout << _arr[i][j] << " ";
            std::cout << std::endl;
        }
    }

    std::vector<int> getChildren(int vertex)
    {
        std::vector<int> ret;

        for(int i=0; i<_size; ++i)
            if(_arr[vertex][i] == 1)
                ret.push_back(i);

        return ret;
    }    

    void printBFS(int start)
    {
        std::queue<int> q;
        std::set<int> v;
        q.push(start);

        while(!q.empty())
        {
            int currentNum = q.front();
            q.pop();
            v.insert(currentNum);

            std::cout << currentNum << " ";

            std::vector<int> children = getChildren(currentNum);
            for(int i=0; i<children.size(); ++i)
                if(v.count(children[i]) == 0)
                    q.push(children[i]);
        }

        std::cout << std::endl;
    }

    void printTopologicalSort(int start)
    {
        std::stack<int> temp;
        std::set<int> visited;
        printTopologicalSort(start, visited, temp);

        while(!temp.empty())
        {
            std::cout << temp.top() << " ";
            temp.pop();
        }
        std::cout << std::endl;
    }

    void printDFS(int start)
    {
        std::set<int> visited;
        printDFS(start, visited);

        std::cout << std::endl;
    }

    bool hasPrimki()
    {
        for(int i=0; i<_size; ++i)
            if(_arr[i][i] != 0)
                return true;

        return false;
    }

    bool isFull()
    {
        for(int i=0; i<_size; ++i)
        {
            std::vector<int> children = getChildren(i);
            
            bool hasSelf = std::find(children.begin(), children.end(), i) != children.end();
            if(! (hasSelf && children.size() == _size || !hasSelf && children.size() == _size - 1))
                return false;
        }

        return true;
    }

    bool hasEdge(int from, int to)
    {
        return (_arr[from][to] == 1);
    }

    bool isUnoriented()
    {
        for(int i=0; i<_size; ++i)
        {
            std::vector<int> children = getChildren(i);

            for(int j=0; j<children.size(); ++j)
                if(!hasEdge(children[j], i) && children[j] != i)
                    return false;
        }

        return true;
    }

    Graph getOppositeGraph()
    {
        Graph ret(_size);

        for(int i=0; i<_size; ++i)
            for(int j=0; j<_size; ++j)
                if(!hasEdge(i, j))
                    ret.addEdge(i,j);

        return ret;
    }

    bool hasPath(int from, int to)
    {
        std::set<int> visited;
        return hasPath(from, to, visited);
    }

    int totalReachable(int from)
    {
        int ret = 0;

        for(int i=0; i<_size; ++i)
        {
            if(i == from)
                continue;

            ret += (hasPath(from, i) ? 1 : 0);
        }

        return ret;
    }

    int getTotalPaths(int from, int to)
    {
        int totalPaths = 0;
        std::set<int> visited;
        getTotalPaths(from, to, totalPaths, visited);

        return totalPaths;
    }

    std::vector<int> getLongestPath(int start, int end)
    {
        std::vector<int> longestPath;
        std::vector<int> temp;
        std::set<int> visited;

        getLongestPath(start, end, visited, temp, longestPath);

        return longestPath;
    }

private:
    void init()
    {
        for(int i=0; i<_size; ++i)
            _arr.push_back(std::vector<int>(_size, 0));
    }

    void printDFS(int start, std::set<int>& visited)
    {
        if(visited.count(start) != 0)
            return;

        visited.insert(start);
        std::cout << start << " ";

        std::vector<int> children = getChildren(start);
        for(int i=0; i<children.size() ; ++i)
            printDFS(children[i], visited);
    }

    void printTopologicalSort(int start, std::set<int> & visited, std::stack<int> & st)
    {
        if (visited.count(start) != 0)
            return;

        visited.insert(start);

        std::vector<int> children = getChildren(start);
        for(int i=0; i<children.size(); ++i)
            printTopologicalSort(children[i], visited, st);

        st.push(start);
    }

    bool hasPath(int from, int to, std::set<int> & visited)
    {
        if(from == to)
            return true;
        if(visited.count(from) != 0)
            return false;

        visited.insert(from);
        std::vector<int> children = getChildren(from);

        for(int i=0; i<children.size(); ++i)
            if(hasPath(children[i], to, visited))
                return true;

        return false;
    }

    void getTotalPaths(int from, int to, int & totalPaths, std::set<int> & visited)
    {
        if(from == to)
        {
            totalPaths += 1;
            return;
        }

        visited.insert(from);
        std::vector<int> children = getChildren(from);

        for(int i=0; i<children.size(); ++i)
            if(visited.count(children[i]) == 0)
                getTotalPaths(children[i], to, totalPaths, visited);

        visited.erase(from);
    }
    
    void getLongestPath(int start, int end, std::set<int> & visited, std::vector<int> & currentPath, std::vector<int> & longestPath)
    {
        if(start == end)
        {
            currentPath.push_back(start);
            if(currentPath.size() > longestPath.size())
                longestPath = currentPath;
            currentPath.pop_back();

            return;
        }

        if(visited.count(start) != 0)
            return;

        visited.insert(start);
        currentPath.push_back(start);

        std::vector<int> children = getChildren(start);

        for(int i=0; i<children.size(); ++i)
            getLongestPath(children[i], end, visited, currentPath, longestPath);

        visited.erase(start);
        currentPath.pop_back();
    }

    std::vector<std::vector<int>> _arr;
    int _size;
};