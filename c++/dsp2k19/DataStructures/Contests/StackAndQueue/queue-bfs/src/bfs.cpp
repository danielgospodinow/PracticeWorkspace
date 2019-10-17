#include <iostream>
#include <vector>
#include <queue>

typedef unsigned int uint;

void bfs(std::vector<std::vector<int>> graph, uint startVertex);
void processVertex(int vertex);

int main() {
	std::vector<std::vector<int>> graph;

	std::vector<int> firstVertex = { 2 };
	std::vector<int> secondVertex = { 3, 4, 0 };
	std::vector<int> thirdVertex = { 1 };
	std::vector<int> fourthVertex = { 1 };
	std::vector<int> fifthVertex = { 3 };

	graph.push_back(firstVertex);
	graph.push_back(secondVertex);
	graph.push_back(thirdVertex);
	graph.push_back(fourthVertex);
	graph.push_back(fifthVertex);

	bfs(graph, 3);

	return 0;
}

void processVertex(int vertex) {
	std::cout << "The current vertex is: " << vertex << std::endl;
}

void bfs(std::vector<std::vector<int>> graph, uint startVertex) {
	// Always protect yourself from an ebawka
	if(startVertex < 0 || startVertex >= graph.size()) {
		return;
	}

	// Get the number of vertices in the graph
	uint totalVertices = graph.size();

	// Watch which vertices are already visited, in order to prevent visiting them again,
	// thus avoiding infinite loops
	bool visited[totalVertices];

	// The current group of vertices which are being processed
	std::queue<int> verticesUnderProcess;

	// Start traversing the graph from the 'startVertex' vertex
	verticesUnderProcess.push(startVertex);

	// Process the current vertex and add its unprocessed children for future processing
	while(!verticesUnderProcess.empty()) {
		int currentVerticle = verticesUnderProcess.front();
		processVertex(currentVerticle);
		visited[currentVerticle] = true;
		verticesUnderProcess.pop();

		for(int child: graph.at(currentVerticle)) {
			if(!visited[child]) {
				verticesUnderProcess.push(child);
			}
		}
	}
}
