#include "stdafx.h"
#include "AdjacencyGraph.h"
#include <algorithm>

using namespace std;

AdjacencyGraph::AdjacencyGraph(int n)
{
	graph.resize(n);
}


AdjacencyGraph::~AdjacencyGraph()
{
}

void AdjacencyGraph::insertEdge(int u, int v, int weight)
{
	graph[u].push_back(pair<int, int>(v, weight));
	graph[v].push_back(pair<int, int>(u, weight));
}

int AdjacencyGraph::getWeight(int u, int v)
{
	auto edgeItr = find_if(graph[u].begin(), graph[u].end(), [v](pair<int, int> & edge)
	{
		return v == edge.first;
	});

	if (edgeItr != graph[u].end())
	{
		return edgeItr->second;
	}
	else
	{
		return -1;
	}
}

std::list<pair<int, int>>& AdjacencyGraph::getNeighbours(int u)
{
	return graph[u];
}
