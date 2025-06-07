#pragma once
#include "displayMaze.hpp"
#include "maze.hpp"
#include "neighbours.hpp"
#include "node.hpp"
#include <set>
#include <time.h>
#include <vector>
using namespace std;

set<node> visited;

void randomizedDfs(node x)
{
    visited.insert(x);
    colorNode(x, Color::Cyan);

    vector<node> neighbours = surrounding(x);
    vector<node> otherNeighbours = surrounding(x);

    while (!neighbours.empty())
    {
        int index = rand() % neighbours.size(); // randomization !
        node neighbour = neighbours[index];

        if (visited.find(neighbour) == visited.end())
        {
            for (auto &otherNeighbour : otherNeighbours)
            {
                if (otherNeighbour == neighbour) continue;

                if (visited.find(otherNeighbour) == visited.end())
                {
                    colorWall(x, otherNeighbour, Color::Black);
                }
            }
            
            colorWall(x, neighbour, Color::Cyan);

            makeEdge(x, neighbour);
            randomizedDfs(neighbour);

            colorWall(x, neighbour, Color::White);
        }

        neighbours.erase(neighbours.begin() + index);
    }

    colorNode(x, Color::White);
}

void generate()
{
    cout << "Generating...\n";
    srand(time(NULL));
    randomizedDfs(node(0, 0));
}