#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool cal(string str, char var)      //Calculate the Prefix
{
    stack<bool> num;
    bool val_l, val_r;
    for(int i = str.size() - 1; i >= 0; i--)
    {
        if(str[i] >= 'p' && str[i] <= 't')
            num.push(var & (1 << (str[i] - 'p')));
        else
            switch(str[i])
            {
                case 'K':
                    val_r = num.top();
                    num.pop();
                    val_l = num.top();
                    num.pop();
                    num.push(val_l && val_r);
                    break;
                case 'A':
                    val_r = num.top();
                    num.pop();
                    val_l = num.top();
                    num.pop();
                    num.push(val_l || val_r);
                    break;
                case 'N':
                    val_r = num.top();
                    num.pop();
                    num.push(!val_r);
                    break;
                case 'C':
                    val_r = num.top();
                    num.pop();
                    val_l = num.top();
                    num.pop();
                    num.push(!val_l || (val_l && val_r));
                    break;
                case 'E':
                    val_r = num.top();
                    num.pop();
                    val_l = num.top();
                    num.pop();
                    num.push(val_l == val_r);
                    break;
            }
    }
    return num.top();
}

int main(void)
{
    string input;
    char var;   //Store the value of "p q r s t" in BIT0~4
    while(1)
    {
        cin >> input;
        if(input[0] == '0')
            break;
        for(var = 0; var < 1 << 6; var++)
            if(!cal(input, var))break;
        if(var == 1 << 6)
            cout << "tautology" << endl;
        else
            cout << "not" << endl;
    }
}
