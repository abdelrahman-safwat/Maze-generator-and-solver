#pragma once
#include "displayMaze.hpp"
#include "neighbours.hpp"
#include "node.hpp"
#include <map>
#include <queue>
#include <set>
#include <utility>
#include "size.hpp"

using namespace std;

void Astar(node source)
{
    map<node, int> dis;
    set<node> visited;
    map<node, node> parent;
    node X;

    for (int i = 0; i < SIZE; i++)
    {
        for (int z = 0; z < SIZE; z++)
        {
            node x(i, z);
            dis[x] = INT_MAX;
        }
    }

    dis[source] = 0;
    visited.insert(source);
    priority_queue<pair<pair<int, int>, node>, vector<pair<pair<int, int>, node>>, greater<pair<pair<int, int>, node>>> q;

    q.push({{0, 0}, source});

    while (!q.empty())
    {
        pair<pair<int, int>, node> temp = q.top();
        q.pop();
        visited.insert(temp.second);
        colorNode(temp.second, Color::Cyan);

        if (temp.second.y == SIZE - 1 && temp.second.x == SIZE - 1)
        {
            X = temp.second;
            break;
        }

        for (auto neighbor : neighbours(temp.second))
        {
            if (dis[temp.second] + 1 < dis[neighbor] && visited.find(neighbor) == visited.end())
            {
                dis[neighbor] = dis[temp.second] + 1;
                int manhaten = SIZE - 1 - neighbor.x + SIZE - 1 - neighbor.y;
                q.push({{dis[neighbor] + manhaten, dis[neighbor]}, neighbor});
                parent[neighbor] = temp.second;
            }
        }
    }

    initializeGrid();

    while (!(X == source))
    {
        colorNode(X, Color::Red);
        X = parent[X];
    }

    colorNode(X, Color::Red);
}