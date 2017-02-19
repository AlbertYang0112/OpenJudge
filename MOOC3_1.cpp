#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int main(void)
{
    string infix, postfix;
    int cnt = 0;
    //ifstream ifile("in.txt",ios_base::in);
    while(getline(cin, infix))
    {
        infix.insert(0, "V&");
        postfix.clear();
        if(infix.size() == 0)continue;
       // cout<<infix<<endl;
        ++cnt;
        stack<char> temp;
        string::iterator str_iter;
        for(str_iter = infix.begin(); ; )
        {
            str_iter = find(str_iter, infix.end(), ' ');

            if(str_iter == infix.end())break;
            infix.erase(str_iter);
        }
        for(str_iter = infix.begin(); ; )
        {
            str_iter = find(str_iter, infix.end(), '!');
            if(str_iter == infix.end())break;
            if(str_iter + 1 != infix.end() && *(str_iter + 1) == '!')
            {
                infix.erase(str_iter);
                infix.erase(str_iter);
            }
            else str_iter++;
        }

        for(str_iter = infix.begin(); str_iter != infix.end(); str_iter++)
        {
            if(*str_iter == 'V' || *str_iter == 'F')postfix.push_back(*str_iter);
            else if(*str_iter == ')')
                {
                    while(!temp.empty())
                    {
                        if(temp.top() == '(')
                        {
                            temp.pop();
                            break;
                        }
                        postfix.push_back(temp.top());
                        temp.pop();
                    }
                }
            else if(*str_iter == '|')
                {
                    while(!temp.empty() && temp.top() != '(')
                    {
                        postfix.push_back(temp.top());
                        temp.pop();
                    }
                    temp.push('|');
                }
            else if(*str_iter == '&')
                {
                    while(!temp.empty() && temp.top() != '(')
                    {
                        if(temp.top() == '|')
                        {
                            break;
                        }
                        postfix.push_back(temp.top());
                        temp.pop();
                    }
                    temp.push('&');
                }
            else if(*str_iter == '!')
                {
                    while(!temp.empty() && temp.top() != '(')
                    {
                        if(temp.top() == '|' || temp.top() == '&')
                        {
                            break;
                        }
                        postfix.push_back(temp.top());
                        temp.pop();
                    }
                    temp.push('!');

                }
            else if(*str_iter == '(')
                temp.push('(');
        }
        for(; !temp.empty(); )
        {
            postfix.push_back(temp.top());
            temp.pop();
        }
        //cout<<"POST:"<<postfix<<endl;
        for(str_iter = postfix.begin(); str_iter != postfix.end(); str_iter++)
        {
            if(*str_iter == 'V' || *str_iter == 'F')temp.push(*str_iter);
            else if(*str_iter == '!')
            {
                char a = temp.top();
                temp.pop();
                temp.push(a == 'V' ? 'F' : 'V');
            }
            else
            {
                bool a,b;
                a = temp.top() == 'V' ? true : false;
                temp.pop();
                b = temp.top() == 'V' ? true : false;
                temp.pop();
                switch(*str_iter)
                {
                    case '&': temp.push(a & b ? 'V' : 'F');break;
                    case '|': temp.push(a | b ? 'V' : 'F');break;
                }
            }
        }
        cout<<"Expression "<<cnt<<": "<<temp.top()<<endl;
    }
}
