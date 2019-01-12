#include "AStar.h"

int main()
{
    //1是路 0是墙
    int _map[MAP_ROW][MAP_COLUMN] =
    {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1 }
    };

    //构造地图
    a_node node[MAP_ROW][MAP_COLUMN] = { 0 };
    for (int i = 0; i < MAP_ROW; i++)
    {
        for (int j = 0; j < MAP_COLUMN; j++)
        {
            node[i][j].x = i;
            node[i][j].y = j;
            if (_map[i][j] == 0)
            {
                node[i][j].attr = ATTR_FORBID;
            }
        }
    }
    find_destination(&node[6][4], &node[0][4], node);
    return 0;
}
