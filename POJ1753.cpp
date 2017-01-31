#include<iostream>
#include<cstring>
using namespace std;bool src[6][6],result[6][6];
int main(void)
{
    int minstep=1000;
    char temp;
    memset(src,false,sizeof(src));
    for(int i=1;i<5;i++)
    {
        for(int j=1;j<5;j++)
        {
            cin>>temp;
            if(temp=='b')src[i][j]=true;
            else {src[i][j]=false;}
        }
    }
    for(int sel=0;sel<2;sel++)
    for(int i=0;i<=0xF;i++)
    {
        int step=0;
        memcpy(result,src,sizeof(src));
        for(int pos=0;pos<4;pos++)
            if(i&(1<<pos))
            {
                step++;
                result[1][pos]=!result[1][pos];
                result[1][pos+1]=!result[1][pos+1];
                result[1][pos+2]=!result[1][pos+2];
                result[2][pos+1]=!result[2][pos+1];
            }
        for(int row=2;row<=4;row++)
            for(int col=1;col<=4;col++)
                if((result[row-1][col]&&sel==0)||(!result[row-1][col]&&sel==1))
                {
                    result[row-1][col]=!result[row-1][col];
                    result[row+1][col]=!result[row+1][col];
                    result[row][col+1]=!result[row][col+1];
                    result[row][col-1]=!result[row][col-1];
                    result[row][col]=!result[row][col];
                    step++;
                }
        bool iscorrect=true;
        for(int col=1;col<=4;col++)
            if((result[4][col]&&sel==0)||(!result[4][col]&&sel==1))
                iscorrect=false;
        if(iscorrect&&step<minstep)minstep=step;
    }
    if(minstep!=1000)cout<<minstep<<endl;
    else cout<<"Impossible"<<endl;
}
