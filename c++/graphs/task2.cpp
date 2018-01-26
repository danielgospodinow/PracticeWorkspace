#include <iostream>
#include <vector>
#include <set>

struct VertexList 
{
    int v; 
    VertexList* next; 
};

struct Vertex 
{
    int u; 
    VertexList* successors; 
    Vertex* next; 
};

std::vector<std::vector<int>> getMatrix(Vertex* const& graph)
{
    //Implement
    return std::vector<std::vector<int>>();
}

VertexList* getVertexList(std::vector<int> vec)
{
    //Implement
    if(vec.size() <= 0)
        return nullptr;

    return nullptr;
}

std::vector<std::vector<int>> matrix;

std::vector<int> getChildren(int vertex)
{
    if(matrix.size() <= 0)
        return std::vector<int>();

    std::vector<int> ret;

    for(int i=0; i<matrix.size(); ++i)
        if(matrix[vertex][i] == 1)
            ret.push_back(matrix[vertex][i]);

    return ret;
}

void findLongestPath(int start, int end, std::set<int>& visited, std::vector<int>& currentPath, std::vector<int>& longestPath)
{
    if(start == end)
    {
        currentPath.push_back(start);
        if(currentPath.size() > longestPath.size())
            longestPath = currentPath;
        currentPath.pop_back();
    }

    if(visited.count(start) != 0)
        return;

    visited.insert(start);
    currentPath.push_back(start);

    std::vector<int> children = getChildren(start);
    for(int i=0; i<children.size(); ++i)
        findLongestPath(children[i], end, visited, currentPath, longestPath);

    currentPath.pop_back();
    visited.erase(start);
}

VertexList* longestPath(Vertex* graph, int u, int v)
{
    matrix = getMatrix(graph);
    std::vector<int> longestPath, currentPath;
    std::set<int> visited;

    findLongestPath(u, v, visited, currentPath, longestPath);

    return getVertexList(longestPath);
}

int main()
{
    return 0;
}