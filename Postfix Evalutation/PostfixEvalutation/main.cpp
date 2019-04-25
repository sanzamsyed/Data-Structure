//Implementation of Postfix Evaluation
#include <stdio.h>
#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

string toStringFromChar(char x)
{
    stringstream ss;
    ss << x;
    string xx;
    ss >> xx;
    return xx;
}

string toStringFromInt(int x)
{
    stringstream ss;
    ss << x;
    string xx;
    ss >> xx;
    return xx;
}


int toIntFromString(string x)
{
    stringstream ss;
    ss << x;
    int returnvalue;
    ss >> returnvalue;
    return returnvalue;
}


int main()
{
    //string input = "1 2 + 3 4 - 5 * 6 + *";
    string input;
    cout << "Enter your Infix expression : " << endl;
    cin >> input;
    stack<string> s;
    for (int i = 0; i < input.size(); ++i)
    {
        if (input[i] == ' ') continue;
        else if (isdigit(input[i]))
        {
            s.push(toStringFromChar(input[i]));
        }
        else if (input[i] == '+')
        {
            int second = toIntFromString(s.top());
            s.pop();
            int first = toIntFromString(s.top());
            s.pop();
            int ans = first + second;
            s.push(toStringFromInt(ans));
            // 1 -> 49
            // 0 -> 48
            // '1' - '0' = 1
        }
        else if (input[i] == '-')
        {
            int second = toIntFromString(s.top());
            s.pop();
            int first = toIntFromString(s.top());
            s.pop();
            int ans = first - second;
            s.push(toStringFromInt(ans));
            
        }
        
        else if (input[i] == '*')
        {
            int second = toIntFromString(s.top());
            s.pop();
            int first = toIntFromString(s.top());
            s.pop();
            int ans = first * second;
            s.push(toStringFromInt(ans));
            
        }
        else if (input[i] == '/')
        {
            int second = toIntFromString(s.top());
            s.pop();
            int first = toIntFromString(s.top());
            s.pop();
            int ans = first / second;
            s.push(toStringFromInt(ans));
        }
        
    }
    cout << s.top() << endl;
    
    
    return 0;
}
