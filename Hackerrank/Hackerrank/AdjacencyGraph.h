#pragma once

#include <vector>
#include <list>

class AdjacencyGraph
{
public:
	AdjacencyGraph(int n);
	~AdjacencyGraph();

	void insertEdge(int u, int v, int weight);
	//void deleteEdge();
	int getWeight(int u, int v);

	std::list<std::pair<int, int>> & getNeighbours(int u);

private:
	std::vector < std::list<std::pair<int, int>>> graph;
};

