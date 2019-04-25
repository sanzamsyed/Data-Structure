//Implementation of Postfix to Infix converter

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

string toString(char x)
{
    stringstream stringMaker;
    stringMaker << x;
    string stringTemp;
    stringMaker >> stringTemp;
    return stringTemp;
}

int main()
{
    cout << "Enter your input expression : " << endl;
    string input;
    cin >> input;
    stack<char> s;
    string ans = "";
    for (int i = 0; i < input.size(); ++i)
    {
        if (input[i] == '(')
        {
            s.push(input[i]);
        }
        
        else if (input[i] == '+' || input[i] == '-')
        {
            while (!s.empty())
            {
                char x = s.top();
                if (x == '+' || x == '-' || x == '*' || x == '/')
                {
                    s.pop();
                    ans += toString(x);
                }
                
                else
                {
                    break;
                }
            }
            
            s.push(input[i]);
        }
        
        else if (input[i] == '*' || input[i] == '/')
        {
            while (!s.empty())
            {
                char x = s.top();
                if (x == '*' || x == '/')
                {
                    s.pop();
                }
                else
                {
                    break;
                }
            }
            s.push(input[i]);
        }
        else if (input[i] == ')')
        {
            while (!s.empty())
            {
                char x = s.top();
                s.pop();
                if (x == '(')
                {
                    break;
                } else
                {
                    ans += toString(x);
                }
            }
            
        }
        else if (isalpha(input[i]))
        {
            ans += toString(input[i]);
        }
        
    }
    
    while (!s.empty())
    {
        ans += toString(s.top()); s.pop();
    }
    
    cout << ans << endl;
    
    
    return 0;
}
