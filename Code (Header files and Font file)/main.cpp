#include "displayMaze.hpp"
#include "mazeGeneration.hpp"
#include "solve.hpp"
using namespace std;

int main()
{
    system("mode 70,30");
    initializeSize();
    initializeGrid();
    generate();
    solve();
}