#include <iostream>
using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;
    int *W = new int[n], *D = new int[n];
    for(int i = 0; i < n; i++)
        cin >> W[i] >> D[i];
    int *temp = new int[m + 1];
    for(int i = 0; i < W[0]; i++)
        temp[i] = 0;
    for(int i = W[0]; i < m + 1; i++)
        temp[i] = D[0];
    //cout << 'A';
    for(int i = 1; i < n; i++)
    {
        //cout << i;
        for(int j = m; j > 0; j--)
            if(j - W[i] >= 0 && temp[j - W[i]] + D[i] > temp[j])
                temp[j] = temp[j - W[i]] + D[i];
    }
    int maxD = 0;
    for(int i = 0; i < m + 1; i++)
        if(temp[i] > maxD)maxD = temp[i];
    cout << maxD << endl;
    delete []D;
    delete []W;
    delete []temp;
}
