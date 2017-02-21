#include <iostream>
#include <vector>
using namespace std;

void mergeIn(int s, int m, int e, vector<int> &elems)
{
    int wp = 0, rpa = s, rpb = m + 1;
    vector<int> temp(e - s + 1);
    while(rpa <= m && rpb <= e)
    {
        if(elems[rpa] > elems[rpb])
            temp[wp++] = elems[rpa++];
        else
            temp[wp++] = elems[rpb++];
    }
    while(rpa <= m)
        temp[wp++] = elems[rpa++];
    while(rpb <= e)
        temp[wp++] = elems[rpb++];
    for(int i = 0; i < e - s + 1; i++)
        elems[i + s] = temp[i];
}
long long mergeSortAndCount(int s, int e, vector<int> &elems)
{
    if(s >= e)return 0;
    //cout<<s<<' '<<e<<endl;
    int flag = (s + e) / 2;
    long long cnt;
    cnt = mergeSortAndCount(s, flag, elems);
    cnt += mergeSortAndCount(flag + 1, e, elems);
    int i = s, j = flag + 1;
    while(i <= flag && j <= e)
    {
        if(elems[i] > elems[j])
        {
            cnt += e - j + 1;
            i++;
        }
        else j++;
    }
    mergeIn(s, flag, e, elems);
    return cnt;
}

int main(void)
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin>>a[i];
    cout<<mergeSortAndCount(0, n - 1, a) << endl;
    /*for(int i = 0; i < n; i++)
        cout<<a[i];*/
}
