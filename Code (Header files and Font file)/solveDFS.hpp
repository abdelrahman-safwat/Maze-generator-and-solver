#pragma once
#include "neighbours.hpp"
#include "node.hpp"
#include "displayMaze.hpp"
#include <set>
using namespace std;

set<node> visitedDFS;

bool dfs(node S)
{
    colorNode(S, Color::Green);
    visitedDFS.insert(S);

    if (S.x == SIZE - 1 && S.y == SIZE - 1)
    {
        visitedDFS.clear();
        return true;
    }

    for (auto &i : neighbours(S))
    {
        if (visitedDFS.find(i) == visitedDFS.end())
        {
            if (dfs(i))
            {
                return true;
            }
        }
    }

    colorNode(S, Color::White);
    return false;
}