#include "stdafx.h"
#include "Graph.h"
#include <algorithm>

using namespace std;

Graph::Graph()
{
}

Graph::~Graph()
{
}

void Graph::insertEdge(int u, int v, int weight)
{
	//graphEdges[pair<int, int>(u, v)] = weight;
}

void Graph::deleteEdge(int u, int v)
{
	/*auto edgeItr = graphEdges.find(pair<int, int>(u, v));

	if (edgeItr != graphEdges.end())
	{
		graphEdges.erase(edgeItr);
	}*/
}

void Graph::setNodeCount(int n)
{
	nodeCount = n;
}

int Graph::getNodeCount()
{
	return nodeCount;
}
