#pragma once
#include <utility>
using namespace std;

struct node
{
    int x;
    int y;

    node()
    {
    }

    node(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    node operator=(node other)
    {
        this->x = other.x;
        this->y = other.y;
        return node(x, y);
    }

    bool operator==(node other)
    {
        return x == other.x && y == other.y;
    }

    bool operator<(const node &other) const
    {
        pair<int, int> disNode = {x, y};
        pair<int, int> daOtherNode = {other.x, other.y};

        return disNode < daOtherNode;
    }
};