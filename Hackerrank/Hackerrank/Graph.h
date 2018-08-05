#pragma once

#include <list>
#include <unordered_map>

class Graph
{
public:
	Graph();
	~Graph();

	void insertEdge(int u, int v, int weight);
	void deleteEdge(int u, int v);

	void setNodeCount(int n);
	int getNodeCount();

protected:
	std::list<std::pair<int, int>> graphEdges;
	//std::unordered_map<std::pair<int, int>, int> graphEdges;
	int nodeCount;
};

