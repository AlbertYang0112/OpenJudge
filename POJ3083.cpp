#include <iostream>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

// The maze is upside-down
// Direction 0 is actually downward
//      0
//    1   2
//      3

struct Pos      // Structure for position
{
    unsigned char x;
    unsigned char y;
    char dir;       // Direction towards the previous position
    unsigned int step;      // Total steps it takes to get to the current position
};
int sizeX, sizeY;       // The size of maze
Pos entryPoint, exitPoint;      // The position of maze-entry and maze-exit
const int MAX_MAZE_SIZE = 40;
char maze[MAX_MAZE_SIZE][MAX_MAZE_SIZE];    // The map of maze
int minSteps[MAX_MAZE_SIZE][MAX_MAZE_SIZE]; // The minimum steps it takes to the position in maze
char moveDelta[4][2] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};  // The change of position when moving towards 4 directions
char prevDir[4] = {3, 2, 1, 0};     // Get the direction towards the previous position according to the moving direction
char moveLeftDir[4] = {1, 3, 0, 2};     // The direction to the left of moving direction
char moveRightDir[4] = {2, 0, 3, 1};    // The direction to the right of moving direction

int searchMinStep(void)       //BFS
{
    queue<Pos> bfsq;        // The queue used for BFS
    while(!bfsq.empty())bfsq.pop();     // Clear the queue
    bfsq.push(entryPoint);
    Pos nowPoint, nextPoint;
    nowPoint.x = entryPoint.x;
    nowPoint.y = entryPoint.y;
    nowPoint.dir = entryPoint.dir;
    nowPoint.step = entryPoint.step;
    int minStep = INT_MAX;
    while(!bfsq.empty())
    {
        nowPoint = bfsq.front();
        bfsq.pop();
        if(nowPoint.x == exitPoint.x && nowPoint.y == exitPoint.y)
        {
            if(nowPoint.step < minStep)
                minStep = nowPoint.step;
            continue;
        }
        for(int dir = 0; dir < 4; dir++)    // Search in 4 directions
        {
            if(dir == nowPoint.dir)     // No moving back
                continue;
            nextPoint.x = nowPoint.x + moveDelta[dir][0];   // Get the position after moving in direction of "dir"
            nextPoint.y = nowPoint.y + moveDelta[dir][1];
            if(nextPoint.x >= sizeX || nextPoint.y >= sizeY)
                continue;
            if(maze[nextPoint.x][nextPoint.y] == '#')   // No hitting the wall
                continue;
            nextPoint.dir = prevDir[dir];
            nextPoint.step = nowPoint.step + 1;
            if(nextPoint.step < minSteps[nextPoint.x][nextPoint.y] && nextPoint.step < minStep)
            {
                minSteps[nextPoint.x][nextPoint.y] = nextPoint.step;
                bfsq.push(nextPoint);
            }
        }
    }
    return minStep;
}

Pos moveAlongLeft(Pos prev)
{
    Pos next;
    next.step = 0;
    Pos wallPos;
    int dir;
    dir = prevDir[prev.dir];    // Try to continue to move in the previous direction
    next.x = prev.x + moveDelta[dir][0];
    next.y = prev.y + moveDelta[dir][1];
    next.dir = prev.dir;
    next.step = prev.step + 1;
    if(maze[next.x][next.y] == '#' || maze[next.x][next.y] == 'S')  // If hit the wall or the start point
    {
        next.x = prev.x + moveDelta[moveRightDir[dir]][0];      // Try to moving rightward
        next.y = prev.y + moveDelta[moveRightDir[dir]][1];
        next.dir = moveLeftDir[dir];
        if(maze[next.x][next.y] == '#' || maze[next.x][next.y] == 'S')  // If still failed to move
        {
            next.x = prev.x + moveDelta[prev.dir][0];   // It is a dead corner. Move back
            next.y = prev.y + moveDelta[prev.dir][1];
            next.dir = dir;
            dir = prev.dir;
        }
        else
            dir = moveRightDir[dir];
        //return next;
    }
    wallPos.x = next.x + moveDelta[moveLeftDir[dir]][0];    // Get the position of wall which it moves along with
    wallPos.y = next.y + moveDelta[moveLeftDir[dir]][1];
    if(maze[wallPos.x][wallPos.y] == '.' || maze[wallPos.x][wallPos.y] == 'E')  // If lose the wall
    {
        next.x = wallPos.x;     // Move to get the wall
        next.y = wallPos.y;
        next.dir = moveRightDir[dir];
        next.step++;
    }
    return next;
}

Pos moveAlongRight(Pos prev)        // The same as the Pos moveAlongLeft()
{
    Pos next;
    next.step = 0;
    Pos wallPos;
    int dir;
    dir = prevDir[prev.dir];
    next.x = prev.x + moveDelta[dir][0];
    next.y = prev.y + moveDelta[dir][1];
    next.dir = prev.dir;
    next.step = prev.step + 1;
    if (maze[next.x][next.y] == '#' || maze[next.x][next.y] == 'S')
    {
        next.x = prev.x + moveDelta[moveLeftDir[dir]][0];
        next.y = prev.y + moveDelta[moveLeftDir[dir]][1];
        next.dir = moveRightDir[dir];
        if (maze[next.x][next.y] == '#' || maze[next.x][next.y] == 'S')
        {
            next.x = prev.x + moveDelta[prev.dir][0];
            next.y = prev.y + moveDelta[prev.dir][1];
            next.dir = dir;
            dir = prev.dir;
        }
        else
            dir = moveLeftDir[dir];
        //return next;
    }
    wallPos.x = next.x + moveDelta[moveRightDir[dir]][0];
    wallPos.y = next.y + moveDelta[moveRightDir[dir]][1];
    if (maze[wallPos.x][wallPos.y] == '.' || maze[wallPos.x][wallPos.y] == 'E')
    {
        next.x = wallPos.x;
        next.y = wallPos.y;
        next.dir = moveLeftDir[dir];
        next.step++;
    }
    return next;
}


int main(void)
{
    int n;
    cin >> n;
    while(n)
    {
        n--;
        cin >> sizeX >> sizeY;
        char tempIn;
        memset(maze, -1, sizeof(maze));     // Initialize
        memset(minSteps, 1000000, sizeof(minSteps));
        for (int i = 0; i < sizeY; i++)
            for (int j = 0; j < sizeX; j++) {
                cin >> tempIn;
                maze[j][i] = tempIn;
                if (tempIn == 'S') {
                    entryPoint.x = j;
                    entryPoint.y = i;
                    entryPoint.step = 0;
                    if (i == 0)
                        entryPoint.dir = 0;
                    else if (i == sizeY - 1)
                        entryPoint.dir = 3;
                    else if (j == 0)
                        entryPoint.dir = 1;
                    else
                        entryPoint.dir = 2;
                } else if (tempIn == 'E') {
                    exitPoint.x = j;
                    exitPoint.y = i;
                }
            }
        int leftStep, rightStep;
        Pos nowPos = entryPoint;
        while (maze[nowPos.x][nowPos.y] != 'E' && nowPos.step < 10000) // Move until reaching the exit point
            nowPos = moveAlongLeft(nowPos);
        //cout << "Alone Left: " << nowPos.step + 1 << endl;
        cout << nowPos.step + 1 << ' ';
        nowPos = entryPoint;
        while (maze[nowPos.x][nowPos.y] != 'E' && nowPos.step < 10000)
            nowPos = moveAlongRight(nowPos);
        //cout << "Alone Right: " << nowPos.step + 1 << endl;
        cout << nowPos.step + 1 << ' ';
        //cout << "Min Step: " << searchMinStep() + 1 << endl;
        cout << searchMinStep() + 1 << endl;
    }
}
