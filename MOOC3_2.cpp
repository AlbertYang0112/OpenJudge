#include <iostream>
using namespace std;
int foo(int n, int m)
{
    if(m == 1 || n == 1) return 1;
    if(n < m)return foo(n, n);
    if(n == m)return 1 + foo(n, n - 1);
    if(n > m)return foo(n - m, m) + foo(n, m - 1);
}
int main(void)
{
    int N;
    while(cin >> N)
    {
        cout << foo(N, N)<<endl;
    }
}
