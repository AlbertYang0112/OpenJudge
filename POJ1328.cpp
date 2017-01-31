#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
using namespace std;
int cmp(const void *a,const void *b)
{
    if(((float*)a)[0]>((float*)b)[0])return 1;
    else return -1;
}
int main(void)
{
    int n,r,case_num=0;
    bool na;
    //ifstream in("in.txt");
    //ofstream out("out.txt");
    float loc[1000][2];
    while(1)
    {
        case_num++;
        cin>>n>>r;
        if(n==0)break;
        na=false;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            if(y>r||y<0||r<=0)na=true;
            else
            {
                loc[i][0]=x-sqrt(float(r*r-y*y));
                loc[i][1]=x+sqrt(float(r*r-y*y));
                //loc[i][2]=i;
            }
        }
        //getchar();
        //getchar();
        if(!na)
        {
            qsort(loc,n,sizeof(loc[0]),cmp);
            /*for(int i=0;i<n;i++)
                out<<"No."<<int(loc[i][2])<<'('<<loc[i][0]<<','<<loc[i][1]<<')'<<endl;*/
            int inc=1;
            float now_max=loc[0][1];
            float area_l=loc[0][0],area_r=loc[0][1];
            for(int i=0;i<n-1;i++)
            {
                if(loc[i+1][0]<=area_r)
                {
                    area_l=loc[i+1][0];
                    area_r=loc[i+1][1]>area_r?area_r:loc[i+1][1];
                }
                else
                {
                    inc++;
                    area_l=loc[i+1][0];
                    area_r=loc[i+1][1];
                }
            }
            cout<<"Case "<<case_num<<": "<<inc<<endl;
        }
        else cout<<"Case "<<case_num<<": "<<-1<<endl;
    }
    //in.close();
    //out.close();
    return 0;
}
