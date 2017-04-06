#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct robotStruct
{
    char dir;
    int posx, posy;
};

int main(void)
{
    const char moveadd[4][2] =
    {
       0, 1,
       1, 0,
       0, -1,
       -1, 0
    };
    int K;
    int A, B;       //Size
    int M, N;       //N robot M order
    cin >> K;
    while(K)
    {
        K--;
        cin >> A >> B;
        cin >> N >> M;

        vector<robotStruct>robot(N);
        for(int i = 0; i < N; i++)
        {
            cin >> robot[i].posx >> robot[i].posy >> robot[i].dir;
            switch(robot[i].dir)
            {
            case 'N':
                robot[i].dir = 0;
                break;
            case 'E':
                robot[i].dir = 1;
                break;
            case 'S':
                robot[i].dir = 2;
                break;
            case 'W':
                robot[i].dir = 3;
                break;
            }
        }

        char failure[3] = {0, 0, 0};
        int sel, repeat;
        char order;

        for(int i = 0; i < M; i++)
        {
            cin >> sel >> order >> repeat;
            if(failure[0] == 0)
            {
                switch(order)
                {
                case 'L':
                    for( ; repeat > 0; repeat--)
                    {
                        if(robot[sel - 1].dir != 0)
                            robot[sel - 1].dir--;
                        else
                            robot[sel - 1].dir = 3;
                    }
                    break;
                case 'R':
                    for( ; repeat > 0; repeat--)
                    {
                        if(robot[sel - 1].dir != 3)
                            robot[sel - 1].dir++;
                        else
                            robot[sel - 1].dir = 0;
                    }
                    break;
                case 'F':
                    for( ; repeat > 0; repeat--)
                    {
                        robot[sel - 1].posx += moveadd[robot[sel - 1].dir][0];
                        robot[sel - 1].posy += moveadd[robot[sel - 1].dir][1];
                        for(int i = 0; i < N; i++)
                            if(sel - 1 != i && robot[sel - 1].posx == robot[i].posx && robot[sel - 1].posy == robot[i].posy)
                            {
                                failure[0] = 2;
                                failure[1] = sel - 1;
                                failure[2] = i;
                                i = N;
                                repeat = 0;
                            }
                    }
                    break;
                }
                if(failure[0] == 0 && (robot[sel - 1].posx < 1 || robot[sel - 1].posx > A || robot[sel - 1].posy < 1 || robot[sel - 1].posy > B))
                {
                    failure[0] = 1;
                    failure[1] = sel - 1;
                }
            }
        }
        if(failure[0] == 0)
            cout << "OK" << endl;
        else if(failure[0] == 1)
            cout << "Robot " << failure[1] + 1 << " crashes into the wall" << endl;
        else
            cout << "Robot " << failure[1] + 1 << " crashes into robot " << failure[2] + 1 << endl;
    }
}
