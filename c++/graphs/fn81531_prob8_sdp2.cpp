/////////////////////////////////////////////////////////////
//
// Author: ������ ����������
// FN: 81531
// Date: 21.01.2018
//

#include <iostream>
#include <vector>
#include <set>

std::vector<int> getChildren(char G[100][100], int N, int vertex)
{
	std::vector<int> ret;

	for (int i = 0; i < N; ++i)
		if (G[vertex][i] != '\0')
			ret.push_back(i);

	return ret;
}

bool hasPath(char G[100][100], int N, int i, int j, std::set<int>& visited)
{
	if(i == j)
		return true;

	if(visited.count(i) != 0)
		return false;

	visited.insert(i);
	std::vector<int> children = getChildren(G, N, i);

	for(int i=0; i<children.size(); ++i)
		if(hasPath(G, N, children[i], j, visited))
			return true;

	return false;
}

void countUniqueUtil(char G[100][100], int N, int i, int j, int wantedSize, std::set<int>& visited, std::string& currentStr, std::set<std::string>& totalStrings)
{
	if (i == j)
	{
		std::cout << currentStr << std::endl;

		if(currentStr.length() == wantedSize)
			totalStrings.insert(currentStr);

		return;
	}

	visited.insert(i);
	std::vector<int> children = getChildren(G, N, i);

	for (int k = 0; k < children.size(); ++k)
	{
		std::set<int> visited2;
		if(!hasPath(G, N, children[k], j, visited2))
			continue;

		currentStr.push_back(G[i][children[k]]);
		countUniqueUtil(G, N, children[k], j, wantedSize, visited, currentStr, totalStrings);
		currentStr.pop_back();
	}

	visited.erase(i);
}

int countUnique(char G[100][100], int N, int k)
{
	std::set<std::string> totalStrings;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (i == j)
				continue;

			std::set<int> visited;
			std::string currentStr = "";

			countUniqueUtil(G, N, i, j, k, visited, currentStr, totalStrings);
		}
	}

	return totalStrings.size();
}

int main()
{
	char g[100][100];
	g[0][1] = 'b';
	g[0][4] = 'a';
	g[4][3] = 'a';
	g[1][3] = 'a';
	g[3][1] = 'b';
	g[2][3] = 'a';

	//Bug -> doesn't count paths with cycles;
	std::cout << countUnique(g, 5, 3) << std::endl;

	return 0;
}