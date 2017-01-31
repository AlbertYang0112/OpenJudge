#include <iostream>
#include <cstring>
using namespace std;
bool lights[7][8];  //5*6

int main(void)
{
    int n,testcase = 1,temp;
    cin>>n;
    while(n--)
    {
        for(int i = 1;i <= 5;i++)
            for(int j = 1;j <= 6;j++)
            {
                cin>>temp;
                if(temp)lights[i][j] = true;
                else lights[i][j] = false;
            }
        bool iscorrect=false;
        bool result[7][8],click[7][8];
        for(int i=0;(i<=0x3F)&&!iscorrect;i++)
        {
            memcpy(result,lights,sizeof(lights));
            memset(click,false,sizeof(click));
            for(int j=0;j<6;j++)
                if((1<<j)&i)
                {
                    result[1][j]=!result[1][j];
                    result[1][j+1]=!result[1][j+1];
                    result[1][j+2]=!result[1][j+2];
                    result[2][j+1]=!result[2][j+1];
                    click[1][j+1]=true;
                }
                else click[1][j+1]=false;
            for(int raw=2;raw<=5;raw++)
            {
                for(int col=1;col<=6;col++)
                {
                    if(result[raw-1][col])
                    {
                        click[raw][col]=true;
                        result[raw][col-1]=!result[raw][col-1];
                        result[raw][col+1]=!result[raw][col+1];
                        result[raw-1][col]=!result[raw-1][col];
                        result[raw+1][col]=!result[raw+1][col];
                        result[raw][col]=!result[raw][col];
                    }
                    else click[raw][col]=false;
                }
            }
            iscorrect=true;
            for(int col=1;col<=6;col++)
                if(result[5][col])iscorrect=false;
        }
        cout<<"PUZZLE #"<<testcase<<endl;
        testcase++;
        for(int raw=1;raw<=5;raw++)
        {
            for(int col=1;col<=6;col++)
            {
                cout<<click[raw][col];
                if(col!=6)
                    cout<<' ';
            }
            cout<<endl;
        }
    }
}
