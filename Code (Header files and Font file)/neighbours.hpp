#pragma once
#include "maze.hpp"
#include "node.hpp"
#include <vector>
#include "size.hpp"
using namespace std;

vector<node> surrounding(node n)
{
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    vector<node> v;
    const int x = n.x;
    const int y = n.y;

    for (int c = 0; c < 4; c++)
    {
        int xNeighbour = x + dx[c];
        int yNeighbour = y + dy[c];

        if (xNeighbour > -1 && xNeighbour < SIZE && yNeighbour > -1 && yNeighbour < SIZE)
        {
            node neighbour = node(xNeighbour, yNeighbour);
            v.push_back(neighbour);
        }
    }

    return v;
}

vector<node> neighbours(node n)
{
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    vector<node> v;
    const int x = n.x;
    const int y = n.y;

    for (int c = 0; c < 4; c++)
    {
        int xNeighbour = x + dx[c];
        int yNeighbour = y + dy[c];

        if (xNeighbour > -1 && xNeighbour < SIZE && yNeighbour > -1 && yNeighbour < SIZE)
        {
            node neighbour = node(xNeighbour, yNeighbour);

            if (isConnected(n, neighbour))
            {
                v.push_back(neighbour);
            }
        }
    }

    return v;
}