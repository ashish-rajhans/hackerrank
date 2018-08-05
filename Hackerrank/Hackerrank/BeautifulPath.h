#pragma once

#include "AdjacencyGraph.h"
#include <vector>
#include <memory>

class BeautifulPath
{
public:
	BeautifulPath();
	~BeautifulPath();

	int getShortestPath(int n, std::vector<std::vector<int>> edges, int A, int B);

	void createGraph(std::vector<std::vector<int>> & edges);
private:

	std::shared_ptr<AdjacencyGraph> graph;
};

