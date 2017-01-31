#ifndef NUM_H
#define NUM_H

#include<string>
#include<vector>

using namespace std;

class Num
{
private:
    vector<char> _num;
    bool _minus;
    void carry(void);
    void decomp(void);
    inline void setMinus(void);
public:
    Num(vector<char>& num,bool isMinus=false): _num(num),_minus(isMinus){setMinus();carry();decomp();}
    Num(vector<int>& num,bool isMinus=false): _minus(isMinus){_num.insert(_num.begin(),num.begin(),num.end());setMinus();carry();decomp();}
    Num(){_minus=false;}
    inline int length(void) const;
    inline char getBit(char) const;
    inline void inverse(void){_minus=!_minus;}
    inline bool isMinus(void)const {return _minus;}
    Num operator+(const Num&) const;
    Num operator-(const Num&) const;
    Num operator*(const Num&) const;
    inline Num& operator++();
    inline Num operator++(int);
    inline Num& operator--();
    inline Num operator--(int);
    inline const vector<char> getnum(void) const;
    friend istream& operator>>(istream& , Num&);
    friend ostream& operator<<(ostream& , Num&);
};

#endif // NUM_H
