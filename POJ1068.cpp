#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void)
{
    int n, cas;
    int data[100];
    char par[100];
    int pos;
    cin >> cas;
    while(cas)
    {
        cin >> n;
        pos = 0;
        for(int i = 0; i < n; i++)
            cin >> data[i];
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            while(1)
            {
                if(cnt == data[i])
                    break;
                cnt++;
                par[pos] = '(';
                pos++;
            }
            par[pos] = ')';
            pos++;
        }
        /*for(int i = 0; i < par.size(); i++)
            cout << par[i];
            cout << endl;*/
/*        par.resize(n);
        for(int i = 0; i < n; i++)
            cin >> par[i];*/
        stack<int>par_L_pos;
        for(int i = 0; i < pos; i++)
        {
            if(par[i] == '(')
                par_L_pos.push(i);
            else
            {
                int cnt = 0;

                for(int j = i; j >= par_L_pos.top(); j--)
                    if(par[j] == '(')
                       cnt++;
                cout << cnt;
                if(i != pos - 1)
                    cout << ' ';
                par_L_pos.pop();
            }
        }
        cout << endl;
        cas--;
    }

}
