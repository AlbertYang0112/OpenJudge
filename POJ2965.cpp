#include<iostream>
#include<cstdio>
using namespace std;
void change(int pos, unsigned int &field,unsigned int &route)
{
    for(int i=pos%4;i<16;i+=4)
        field^=(1<<i);
    for(int i=0;i<4;i++)
        field^=(1<<(pos/4*4+i));
    field^=(1<<pos);
    route^=(1<<pos);
}
/*void print(const unsigned int field)
{
    for(int i=0;i<16;i++)
    {
        if((1<<i)&field)cout<<'1';
        else cout<<'0';
        if((i+1)%4==0)cout<<endl;
    }
}*/
bool dfs(int level,int depth,int &clicks,unsigned int &field,unsigned int &route)
{
    if(level==depth)
        return field==0;
    if(dfs(level+1,depth,clicks,field,route))
        return true;
    change(level,field,route);
    clicks++;
    if(dfs(level+1,depth,clicks,field,route))
        return true;
    change(level,field,route);
    clicks--;
    return false;
}
int main(void)
{
    unsigned int field=0,route=0;
    char temp[4];
    for(int i=0;i<4;i++)
    {
        scanf("%s",&temp);
        for(int j=0;j<4;j++)
        if(temp[j]=='+')field|=1<<(4*i+j);
    }
    //print(field);
    bool iscorrect=false;
    int clicks=0;
    for(int depth=1;depth<=16&&!iscorrect;depth++)
        iscorrect=dfs(0,depth,clicks,field,route);
    if(iscorrect)
    {
        printf("%d\n",clicks);
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
            if((1<<4*i+j)&route){printf("%d %d\n",i+1,j+1);}
    }
}
