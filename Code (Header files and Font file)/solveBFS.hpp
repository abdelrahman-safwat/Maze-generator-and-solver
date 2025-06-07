#pragma once
#include "displayMaze.hpp"
#include "neighbours.hpp"
#include "node.hpp"
#include <map>
#include <queue>
#include <set>
#include <utility>
using namespace std;

void bfs(node S)
{
    set<node> visited; // a set of visited nodes
    queue<node> Q;     // queue of nodes for the BFS traversal
    map<node, node> parent;
    node X;
    visited.insert(S); // mark starting node as visited
    Q.push(S);         // push first node to the queue

    while (!Q.empty())
    {
        node temp = Q.front();
        Q.pop();
        colorNode(temp, Color::Cyan);

        if (temp.y == SIZE - 1 && temp.x == SIZE - 1)
        {
            X = temp;
            break;
        }

        vector<node> N = neighbours(temp);

        for (auto neighbour : N)
        {
            if (visited.find(neighbour) == visited.end())
            {
                parent[neighbour] = temp;
                Q.push(neighbour);
                visited.insert(neighbour);
            }
        }
    }

    initializeGrid();

    while (!(X == S))
    {
        colorNode(X, Color(160, 32, 240));
        X = parent[X];
    }

    colorNode(X, Color(160, 32, 240));
}