#pragma once
#include "node.hpp"
#include "size.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <set>
using namespace sf;

RenderWindow window(VideoMode(860, 860), "Maze project", Style::Default);
vector<vector<RectangleShape>> grid;
vector<RectangleShape> walls;

void clearGrid()
{
    window.clear();

    RectangleShape big(Vector2f(860, 860));
    big.setPosition(Vector2f(0, 0));
    big.setFillColor(Color::White);

    window.draw(big);
}

void initializeSize()
{
    window.setPosition(Vector2i(1040, 80));
    cout << "please enter maze size between 2 and 50: ";

    while (cin >> SIZE)
    {
        if (SIZE >= 2 && SIZE <= 50) break;
        cout << "please enter maze size between 2 and 50: ";
    }

    grid.resize(SIZE, vector<RectangleShape>(SIZE));
    RECT_SIZE = 800.0 / SIZE;
    WALL_SIZE = 60.0 / (SIZE - 1);
}

void initializeGrid()
{
    clearGrid();

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            RectangleShape x(Vector2f(WALL_SIZE + RECT_SIZE, WALL_SIZE + RECT_SIZE));
            x.setPosition(j * (RECT_SIZE + WALL_SIZE), i * (WALL_SIZE + RECT_SIZE)); // i and j inverted
            x.setFillColor(Color::White);
            grid[i][j] = x;
        }
    }
}

void loadFont(Font &font)
{
    font.loadFromFile("JannaLT-Bold.ttf");
}

void writeText(Font font, int i, int j, int xShift, int yShift, string written)
{
    auto position = grid[i][j].getPosition();
    position.x += xShift;
    position.y += yShift;

    Text text;
    text.setFont(font);
    text.setString(written);
    text.setCharacterSize(round(RECT_SIZE / 3));
    text.setPosition(position);
    text.setFillColor(Color::Black);

    window.draw(text);
}

void displayAll()
{
    clearGrid();
    window.setPosition(Vector2i(1040, 80));

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            window.draw(grid[i][j]);
        }
    }

    for (auto &wall : walls)
    {
        window.draw(wall);
    }

    Font font;
    loadFont(font);
    writeText(font, 0, 0, WALL_SIZE, round(RECT_SIZE / 3), "Start");
    writeText(font, SIZE - 1, SIZE - 1, round(RECT_SIZE / 6), round(RECT_SIZE / 3), "End");

    window.display();
    Event event;
    window.pollEvent(event);
}

void slep()
{
    if (SIZE > 35) return;
    int time = round(400.0 / SIZE);
    sleep(milliseconds(time));
}

void slepAllat()
{
    sleep(milliseconds(200));
}

void colorNode(node x, Color c)
{
    grid[x.x][x.y].setFillColor(c);
    displayAll();
    slep();
}

void colorWall(node one, node two, Color c)
{
    if (two < one) // swap
    {
        node temp = one;
        one = two;
        two = temp;
    }

    auto next = grid[two.x][two.y];
    RectangleShape wall;

    if (one.x == two.x)
    {
        wall = RectangleShape(Vector2f(WALL_SIZE, RECT_SIZE + WALL_SIZE));
        wall.setPosition(next.getPosition().x - WALL_SIZE, next.getPosition().y);
    }

    if (one.y == two.y)
    {
        wall = RectangleShape(Vector2f(RECT_SIZE + WALL_SIZE, WALL_SIZE));
        wall.setPosition(next.getPosition().x, next.getPosition().y - WALL_SIZE);
    }

    wall.setFillColor(c);
    walls.push_back(wall);
    displayAll();
}

void removeDuplicateWalls()
{
    set<pair<int, int>> s;

    for (auto &wall : walls)
    {
        if (wall.getFillColor() != Color::Black)
        {
            auto vec = wall.getPosition();
            s.insert({vec.x, vec.y});
        }
    }

    for (int i = 0; i < walls.size(); i++)
    {
        auto vec = walls[i].getPosition();
        pair<int, int> temp = {vec.x, vec.y};

        if (s.find(temp) != s.end())
        {
            walls.erase(walls.begin() + i);
            i--;
        }
    }
}

void cleanUp()
{
    slepAllat();
    initializeGrid();
    removeDuplicateWalls();
    displayAll();
}