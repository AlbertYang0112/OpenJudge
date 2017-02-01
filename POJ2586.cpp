#include <iostream>
using namespace std;

int main(void)
{
    int s,d,mind;
    bool rep[12];
    while(cin>>s>>d)
    {
        for( mind =0; s * (5 - mind) - d * mind>=0; mind++);
        for( int i = 0; i < 5- mind; i++ )
            rep[i]=true;
        for(int i = 5 - mind; i <5; i++ )
            rep[i]=false;
        for( int i = 1; i < 8; i++ )
        {
            if(!rep[i - 1])rep[4 + i]=false;
            else rep[4 + i]=true;
        }
        int total=0;
        for( int i = 0; i < 12; i++ )
        {
            if(rep[i])total+=s;
            else total-=d;
        }
        if(total>=0)cout<<total<<endl;
            else cout<<"Deficit"<<endl;
    }
}
