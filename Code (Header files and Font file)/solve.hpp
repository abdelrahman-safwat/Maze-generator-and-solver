#pragma once
#include "displayMaze.hpp"
#include "solveASTAR.hpp"
#include "solveBFS.hpp"
#include "solveDFS.hpp"
#include <iostream>
using namespace std;

void solve()
{
    string s = "y";

    while (s == "y" || s == "Y")
    {
        slepAllat();
        cleanUp();

        cout << "\nplease choose your solving algorithm:\n";
        cout << "1) DFS\n2) BFS\n3) A star\n";
        cout << "Input number: ";
        int x;
        cin >> x;

        if (x == 1) dfs(node(0, 0));
        else if (x == 2) bfs(node(0, 0));
        else if (x == 3) Astar(node(0, 0));

        cout << "Do you want to solve it again? (Y/N): ";
        cin >> s;
    }
}