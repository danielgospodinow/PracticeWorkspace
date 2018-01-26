#include "graph.hpp"

int main()
{
    Graph graph(7);
    graph.addEdge(1, 3);
    graph.addEdge(1, 2);
    graph.addEdge(2, 4);
    graph.addEdge(2, 5);
    graph.addEdge(4, 3);
    graph.addEdge(6, 4);
    graph.addEdge(6, 5);

    std::cout << "DFS print: ";
    graph.printDFS(1);
    std::cout << "BFS print: ";
    graph.printBFS(1);
    std::cout << "Topological sort: ";
    graph.printTopologicalSort(1);

    std::cout << "Is there a path from 1 to 5 -> " << (graph.hasPath(1, 5) ? "true" : "false") << std::endl;
    std::cout << "There are " << graph.totalReachable(1) << " reachable vertices from " << 1 << std::endl;
    std::cout << "There are " << graph.getTotalPaths(1, 3) << " paths from 1 to 3" << std::endl;
    std::cout << (graph.isUnoriented()?"Is unordered":"Is not unordered") << std::endl;
    std::cout << (graph.hasPrimki()?"Has primki":"Doesnt have primki") << std::endl;
    graph.printMatrix();

    Graph fullGraph(3);
    fullGraph.addEdge(0, 1);
    fullGraph.addEdge(0, 2);
    fullGraph.addEdge(1, 0);
    fullGraph.addEdge(1, 2);
    fullGraph.addEdge(2, 0);
    fullGraph.addEdge(2, 1);

    std::cout << (fullGraph.isFull()?"The graph is full":"The graph is not full") << std::endl;
    std::cout << (fullGraph.isUnoriented()?"Is unordered":"Is not unordered") << std::endl;
    fullGraph.printMatrix();

    Graph emptyGraph = fullGraph.getOppositeGraph();
    std::cout << (emptyGraph.isFull()?"The graph is full":"The graph is not full") << std::endl;
    std::cout << (emptyGraph.isUnoriented()?"Is unordered":"Is not unordered") << std::endl;
    std::cout << (emptyGraph.hasPrimki()?"Has primki":"Doesnt have primki") << std::endl;
    emptyGraph.printMatrix();

    Graph lpGraph(5);
    lpGraph.addEdge(1, 0);
    lpGraph.addEdge(1, 2);
    lpGraph.addEdge(2, 0);
    lpGraph.addEdge(2, 3);
    lpGraph.addEdge(3, 0);
    lpGraph.addEdge(3, 4);
    lpGraph.addEdge(4, 0);

    lpGraph.addEdge(2, 4);
    lpGraph.addEdge(2, 1);

    std::cout << "Longest path from 1 to 0 is: ";
    std::vector<int> longestPath = lpGraph.getLongestPath(1, 0);
    for(int i=0; i<longestPath.size(); ++i)
        std::cout << longestPath[i] << " ";
    std::cout << std::endl;
    lpGraph.printMatrix();

    return 0;
}