#include "Num.h"

#include<iostream>
#include<string>
#include<vector>

inline char Num::getBit(char pos) const
{
    return _num[pos];
}
istream& operator>>(istream& in, Num& rhs)
{
    string temp;
    in>>temp;
    int j;
    if(temp[0]=='-')rhs._minus = true;
    else rhs._minus=false;
    for( j = 0; (temp[j] <'1' || temp[j] > '9') && j < temp.size(); j++ );
    rhs._num.resize(temp.size() - j);
    for( int i = temp.size()-1; i >= j; i-- )
        rhs._num[temp.size() - 1 - i]=temp[i] - '0';
    if(rhs.length()==0){rhs._minus = false;rhs._num.push_back(0);}
    return in;
}
ostream& operator<<(ostream& out, Num& rhs)
{
    if(rhs._minus)out<<'-';
    for( int i = rhs.length() - 1; i >= 0 ; i-- )
        out << int(rhs._num[i]);
    return out;
}
inline int Num::length(void) const
{
    return _num.size();
}
Num Num::operator+(const Num& rhs) const
{
    vector<char> ans = length() > rhs.length() ? _num : rhs._num;
    for( unsigned int i=0; i < min(length(),rhs.length()); i++ )
        if(_minus^rhs._minus)ans[i]=_num[i]-rhs._num[i];
            else ans[i]=_num[i]+rhs._num[i];
    for(int i=0;i<ans.size();i++)cout<<int(ans[i]);
    cout<<endl;
    Num ans_num(ans);
    if(_minus)ans_num.inverse();
    return ans_num;
}
Num Num::operator-(const Num& rhs) const
{
    vector<char> ans = length() > rhs.length() ? _num : rhs._num;
    for( unsigned int i=0; i < min(length(),rhs.length()); i++ )
        if(_minus^rhs._minus)ans[i]=_num[i]+rhs._num[i];
            else ans[i]=_num[i]-rhs._num[i];
    Num ans_num(ans);
    if(_minus)ans_num.inverse();
    return ans_num;

}
Num Num::operator*(const Num& rhs) const
{
    vector<int> ans(length()+rhs.length(),0);
    for( unsigned int i = 0; i < length(); i++ )
        for( unsigned int j = 0; j < rhs.length(); j++ )
            ans[i + j] += _num[i] * rhs._num[j];

    unsigned int i;
    for( i = 0; i < ans.size() - 1; i++ )
    {
        if(ans[i]>9)
        {
            ans[i+1]+=ans[i]/10;
            ans[i]%=10;
        }
    }
    for( ; ans[i] / 10 != 0; i++ )
    {
        ans.push_back(ans[i]/10);
        ans[i]%=10;
    }
    Num ans_num(ans,_minus!=rhs._minus);
    return ans_num;
}
inline Num& Num::operator++()
{
    if(_minus)_num[0]--;
    else _num[0]++;
    carry();
    decomp();
    setMinus();
    return *this;
}
inline Num Num::operator++(int)
{
    Num tmp=*this;
    if(_minus)_num[0]--;
    else _num[0]++;
    carry();
    decomp();
    setMinus();
    return *this;
}
inline Num& Num::operator--()
{
    if(_minus)_num[0]++;
    else _num[0]--;
    carry();
    decomp();
    setMinus();
    return *this;
}
inline Num Num::operator--(int)
{
    Num tmp=*this;
    if(_minus)_num[0]++;
    else _num[0]--;
    carry();
    decomp();
    setMinus();
    return *this;
}
void Num::carry(void)
{
    unsigned int i;
    for( i = 0; i < length() - 1; i++ )
    {
        if(_num[i]>9)
        {
            _num[i+1]+=_num[i]/10;
            _num[i]%=10;
        }
    }
    for( ; _num[i] / 10 != 0; i++ )
    {
        _num.push_back(_num[i]/10);
        _num[i]%=10;
    }
    for( ; _num[i] == 0 && i != 0 ; i-- )
        _num.pop_back();
}
void Num::decomp(void)
{
    unsigned int i;
    for( i = 0; i < length()-1; i++)
        if(_num[i] < 0)
        {
            _num[i]+=10;
            _num[i+1]-=1;
        }
    if(_num[i]<0)inverse();
    for( ; _num[i] / 10 != 0; i++ )
    {
        _num.push_back(_num[i] / 10);
        _num[i] %= 10;
    }
    for( ; _num[i] == 0 && i != 0; i-- )
        _num.pop_back();

}
inline void Num::setMinus(void)
{
    if(_num[_num.size()-1]<0)
    {
        inverse();
        for( int i = 0; i < _num.size(); i++)
            _num[i]*=-1;
    }
    if(length() == 0)_minus=false;
}
