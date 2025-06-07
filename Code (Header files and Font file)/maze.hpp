#pragma once
#include "node.hpp"
#include "displayMaze.hpp"
#include <map>

map<node, map<node, bool>> edges;

bool isConnected(node one, node two)
{
    if (edges.find(one) == edges.end()) return false;
    if (edges.find(two) == edges.end()) return false;
    if (edges[one].find(two) == edges[one].end()) return false;
    return true;
}

void makeEdge(node one, node two)
{
    edges[one][two] = true;
    edges[two][one] = true;
}