#include "stdafx.h"
#include "BeautifulPath.h"
#include <queue>
#include <iostream>

using namespace std;

BeautifulPath::BeautifulPath()
{
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> edges(m);

	for (size_t i = 0; i < m; i++)
	{
		vector<int> edge(3);
		cin >> edge[0] >> edge[1] >> edge[2];
		edges[i] = edge;
	}

	int a, b;
	cin >> a >> b;

	cout << "\n\n Shortest = " << getShortestPath(n, edges, a, b) << "\n\n";
}

BeautifulPath::~BeautifulPath()
{
}

int BeautifulPath::getShortestPath(int n, vector<vector<int>> edges, int A, int B)
{
	A -= 1;
	B -= 1;
	vector<bool> visited(n, false);
	graph = make_shared<AdjacencyGraph>(n);
	vector<vector<int>> cost(n);
	//cost[A] = 0;

	createGraph(edges);

	queue<int> pendingNodes;
	pendingNodes.push(A);

	while (!pendingNodes.empty())
	{
		auto currNode = pendingNodes.front();
		pendingNodes.pop();
		visited[currNode] = true;

		auto & neighbours = graph->getNeighbours(currNode);

		vector<bool> addedToQ(n, false);
		for (auto & neighbour : neighbours)
		{
			if (!visited[neighbour.first])
			{
				//int newCost = cost[currNode] | neighbour.second;
		/*		if (newCost < cost[neighbour.first])
				{
					cost[neighbour.first] = newCost;
				}*/

				if (cost[neighbour.first] < cost[B] && !addedToQ[neighbour.first])
				{
					addedToQ[neighbour.first] = true;
					pendingNodes.push(neighbour.first);
				}
			}
		}
	}

	return 1;//cost[B];
}

void BeautifulPath::createGraph(vector<vector<int>> & edges)
{
	for (auto & edge : edges)
	{
		graph->insertEdge(edge[0] - 1, edge[1] - 1, edge[2]);
	}	
}

