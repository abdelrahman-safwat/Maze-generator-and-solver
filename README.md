# Maze Generator and Solver

## Contributers:

- Abdelrahman Safwat

- Doha Bahaa eldin

- Kareem Abdelhameed

- Hamdi Awad

## Brief Description

**Check the documentation pdf for details about the GUI, block layout, color structure, generation, ...etc**

Breifly, the project generates a maze and solves it. Demo gif is shown below. The user first chooses the maze size (it is always a square maze), then the maze is generated. After that the user can pick the solving algorithm of his choice. The maze always starts at the top left corner and ends at the bottom right corner.

The project utilizes graph traversal and shortest path Algorithms, namely DFS, BFS, and A* with L1-norm heuristic. (Dijkstra was not used since it is an unweighted graph)
The project is fully coded in C++. All the graphics shown are basically done from scratch.
The library used for the graphics is SFML. Every single element drawn on screen is a rectangle, it is all rectangle manipulations in SFML.

![Demo](demo.gif)
