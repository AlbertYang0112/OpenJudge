#include <iostream>
#include <queue>
#include <climits>
#include <cstring>

using namespace std;
// The position of nemo
int pos_x, pos_y;
const int MAX_N = 210;
// The map of labyrinth
// room[x][y][dir]    (x, y) the lower-left point of a grid
// dir:
//     3
//   1   2
//     0
char room[MAX_N + 1][MAX_N + 1][4];
// The minimum step it takes to visit the point (x, y)
int minSteps[MAX_N + 1][MAX_N + 1];
// The (dx, dy) for the given direction
const char DIR[4][2] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
// The direction to go back
const char RAW_DIR[4] = {3, 2, 1, 0};

// The structure containing grid
struct Point
{
    int x, y;
    int dir, step;
};

// Examine if the grid p is in the map
inline bool isValid(Point p)
{
    return p.x >= 0 && p.x <= MAX_N && p.y >= 0 && p.y <= MAX_N;
}
// BFS search
// return the minimum step
int bfs(void)
{
    queue<Point> bfsq;                       // Queue for BFS
    while(!bfsq.empty())bfsq.pop();         // Clear the queue
    Point nowPoint, nextPoint;
    nowPoint.x = pos_x;
    nowPoint.y = pos_y;
    nowPoint.dir = -1;
    nowPoint.step = 0;
    bfsq.push(nowPoint);                    // Set the position of nemo as the start point of BFS
    int minStep = INT_MAX;
    while(!bfsq.empty())
    {
        nowPoint = bfsq.front();
        bfsq.pop();
        if(nowPoint.x == 0 && nowPoint.y == 0)  // Reach the end point
        {
            if(nowPoint.step < minStep)
                minStep = nowPoint.step;
            continue;
        }
        for(int d = 0; d < 4; d++)          // Search for all directions
        {
            if(d == nowPoint.dir)           // No going back
                continue;
            if(room[nowPoint.x][nowPoint.y][d] == 1)    // No hitting the wall
                continue;
            nextPoint.x = nowPoint.x + DIR[d][0];       // Move to the next grid
            nextPoint.y = nowPoint.y + DIR[d][1];
            if(!isValid(nextPoint))                     // Examine if the next grid is in the map
                continue;
            nextPoint.dir = RAW_DIR[d];                 // Set the direction for the next grid, in case of going back
            if(room[nowPoint.x][nowPoint.y][d] == 2)
                nextPoint.step = nowPoint.step + 1;     // If go through a door, step++
            else
                nextPoint.step = nowPoint.step;
            if(nextPoint.step < minSteps[nextPoint.x][nextPoint.y] && nextPoint.step < minStep)
            {
                minSteps[nextPoint.x][nextPoint.y] = nextPoint.step;
                bfsq.push(nextPoint);
            }

        }
    }
    return minStep;
}

int main(void)
{
    int m, n;
    // m - the number of walls
    // n - the number of doors
    while(1)
    {
        cin >> m >> n;
        if(m == -1)
            break;
        /*if(m == 0 && n == 0)
        {
            cout << 0 << endl;
            continue;
        }*/
        int x, y, d, t;
        for (int i = 0; i < MAX_N + 1; i++)
            for (int j = 0; j < MAX_N + 1; j++)
                minSteps[i][j] = INT_MAX;
        memset(room, 0, sizeof(room));
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y >> d >> t;
            for (int j = 0; j < t; j++)
            {
                if (d == 0)
                {
                    room[x + j][y][0] = 1;
                    room[x + j][y - 1][3] = 1;
                }
                else
                {
                    room[x][y + j][1] = 1;
                    room[x - 1][y + j][2] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y >> d;
            if (d == 0)
            {
                room[x][y][0] = 2;
                room[x][y - 1][3] = 2;
            }
            else
            {
                room[x][y][1] = 2;
                room[x - 1][y][2] = 2;
            }
        }
        float tempX, tempY;
        cin >> tempX >> tempY;
        if (tempX < 1 || tempX >= 199 || tempY < 1 || tempY >= 199)
            cout << 0 << endl;
        else
        {
            pos_x = tempX;
            pos_y = tempY;
            int minStep = bfs();
            if (minStep == INT_MAX)
                cout << -1 << endl;
            else
                cout << minStep << endl;
        }
    }
    return 0;
}
