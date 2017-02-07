#include <iostream>
#include <vector>
#include <set>
using namespace std;

void addon( vector<int>& src )
{
	int i;
	for( i = 0; i < src.size() - 1; i++ )
	{
		if( src[i] > 9 )
		{
			src[i + 1] += src[i] / 10; 
			src[i] %= 10;
		}
	}
	for( ; src[i] / 10 != 0; i++ )
	{
		src.push_back(src[i] / 10);
		src[i] %= 10;
	}
}

vector<int> multiply( const vector<int>& a, const vector<int>& b )
{
	vector<int> ans(a.size() + b.size());
	for(int i = 0; i < a.size(); i++ )
	  for(int j = 0; j < b.size(); j++ )
		  ans[i + j] += a[i] * b[j];
	addon(ans);
	return ans;
}

vector<int> add( const vector<int>& a, const vector<int>& b )
{
	vector<int> ans = a.size() > b.size() ? a : b;
	for( int i = 0; i < min( a.size(), b.size() ); i++)
	  ans[i] = a[i] + b[i];
	addon(ans);
	return ans;
}

vector<int> dfs( int level , vector<vector<int> >& rec, set<int>& visited )
{
	vector<int> temp;
	if( level == 1 )
	{
		temp.push_back(1);
		return temp;
	}
	if( level == 2 )
	{
		temp.push_back(3);
		return temp;
	}
	if( visited.find(level) != visited.end() )return rec[level];
	temp.push_back(2);
	rec[level] =add(multiply(temp, dfs( level - 2, rec, visited )), dfs( level -1, rec, visited ));
	visited.insert(level);
	return rec[level];
}
int main(void)
{
	int n;
	vector<vector<int> > rec;
	vector<int> ans;
	set<int> visited;
	while(cin >> n)
	{
		if(n == 0)
		{
			cout<<1<<endl;
			continue;
		}
		rec.resize(n+1);
		visited.clear();
		ans = dfs(n, rec, visited);
		bool isFirst = true;
		for( int i = ans.size() - 1; i >= 0; i-- )
		{
			if( ans[i] != 0 || !isFirst )
			{
				isFirst = false;
				cout << ans[i];
			}
		}
		cout<<endl;
	}
	return 0;
}
