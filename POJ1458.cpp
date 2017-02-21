#include <iostream>
#include <string>
#include <vector>
using namespace std;

int maxLen(int pl, int pr, const string &L, const string &R, vector<vector<int> > &data)
{
    if(pl < 0 || pr < 0)return 0;
    if(data[pl][pr] != -1 )return data[pl][pr];
    int result;
    if(L[pl] == R[pr])data[pl][pr] = maxLen(pl - 1, pr - 1, L, R, data) + 1;
    else data[pl][pr] = max(maxLen(pl, pr - 1, L, R, data), maxLen(pl - 1, pr, L, R, data));
    return data[pl][pr];
}

int main(void)
{
    string inA, inB;

    while(cin >> inA >> inB)
    {
        vector<vector<int> >data(inA.size(), vector<int>(inB.size(), -1));
        cout << maxLen(inA.size() - 1, inB.size() - 1, inA, inB, data) << endl;
    }
}
