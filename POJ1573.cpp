#include <iostream>
#include <string>
#include <vector>
using namespace std;

const char movedir[4][2] =
{
    0, -1,
    1, 0,
    0, 1,
    -1, 0
};

int main(void)
{
    int A, B, P;
    while(1)
    {
        cin >> A >> B >> P;
        if(A == 0)break;
        vector<string>grid(A, string());
        vector<vector<int> >steps(A, vector<int>(B, 0));

        for(int i = 0; i < A; i++)
        {
            cin >> grid[i];
            for(int j = 0; j < B; j++)
            {
                switch(grid[i][j])
                {
                case 'N':
                    grid[i][j] = 0;
                    break;
                case 'E':
                    grid[i][j] = 1;
                    break;
                case 'S':
                    grid[i][j] = 2;
                    break;
                case 'W':
                    grid[i][j] = 3;
                    break;
                }
            }
        }

        /*for(int i = 0; i < A; i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
                cout << grid[i][j] + '0';
            cout << endl;
        }*/
        int posx = P - 1, posy = 0, nposx, nposy;
        steps[0][P - 1] = 1;
        while(1)
        {
            //cout << "POSITION:" << posx << ',' << posy << endl;
            nposx = movedir[grid[posy][posx]][0] + posx;
            nposy = movedir[grid[posy][posx]][1] + posy;
            //cout << "NPOSITION:" << nposx << ',' << nposy << endl;
            if(nposx < 0 || nposx >= B || nposy < 0 || nposy >= A)
            {
                cout << steps[posy][posx] << " step(s) to exit" << endl;
                break;
            }

            if(steps[nposy][nposx] != 0)
            {
                cout << steps[nposy][nposx]  - 1 << " step(s) before a loop of " << steps[posy][posx] - steps[nposy][nposx] + 1 << " step(s)" << endl;
                break;
            }

            steps[nposy][nposx] = steps[posy][posx] + 1;
            posx = nposx;
            posy = nposy;
        }
    }
}
