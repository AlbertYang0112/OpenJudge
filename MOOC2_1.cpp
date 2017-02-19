#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void foo(const string &input, vector<bool> &visited, vector<char> &output)
{
    bool allVisited = true;
    for(int i = 0; i < input.size();i++)
    {
        if(visited[i])continue;
        visited[i] = true;
        output.push_back(input[i]);
        foo(input, visited, output);
        visited[i] = false;
        output.pop_back();
        allVisited = false;
    }
    if(allVisited)
    {
        for(int i = 0; i < output.size(); i++)
            cout<<output[i];
        cout<<endl;
    }
}
int main(void)
{
    string input;
    cin>>input;
    sort(input.begin(), input.end());
    vector<bool> visited(input.size(), false);
    vector<char> output;
    foo(input, visited, output);
}
