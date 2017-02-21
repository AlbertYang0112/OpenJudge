#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void arrange(const int s, const int e, vector<int> &elems, const int k)
{
    int pi = s, pj = e - 1;
    while(pi != pj)
    {
        while(pi < pj && elems[pi] < elems[pj])
            pj--;
        swap(elems[pi], elems[pj]);
        while(pi < pj && elems[pi] < elems[pj])
            pi++;
        swap(elems[pi], elems[pj]);
    }
    if(pi == e - k)return;
    if(pi > e - k)arrange(s, pi, elems, k - e + pi);
    if(pi < e - k)arrange(pi + 1, e, elems, k);
}
int main()
{
    int n, k;
    cin >> n;
    vector<int>elems(n);
    for(int i = 0; i < n; i++)
        cin >> elems[i];
    cin >> k;
    arrange(0, n, elems, k);
    sort(elems.end() - k, elems.end());
    for(int i = n - 1; i >= n - k; i--)
        cout<<elems[i]<<endl;
}
