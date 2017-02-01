#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
    int r,n;
    vector<int> pos;
    set<int> visited;
    while(( cin >> r >> n ) && r != -1)
    {
        visited.clear();
        pos.resize(n);
        for( int i = 0; i < n; i++ )
            cin >> pos[i];
        sort(pos.begin(),pos.end());
        int tempmax = -1, cnt = 0;
        for( int i = 0; i < n; i++ )
        {
            if(visited.find(i)==visited.end())
            {
                if(pos[i] <= tempmax)
                {
                    visited.insert(i);
                }
                else
                {
                    cnt++;
                    tempmax = pos[i] + r;
                    //cout<<"Pos:"<<pos[i]<<endl;

                    for(int j = 1 ; i + j < n; j++ )
                    {
                        if(pos[i + j] - r <= pos[i])
                        {
                            visited.insert(i + j);
                            tempmax = pos[i + j] + r;
                            //cout<<"Move to:"<<pos[i + j]<<endl;
                            //cout<<"Max:"<<tempmax<<endl;
                        }
                        else j = n;
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }
}
