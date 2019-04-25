#include <stdio.h>
#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

string toString(char x) {
    stringstream ss;
    ss << x;
    string xx;
    ss >> xx;
    return xx;
}


int main() {
    string input = "AB+CD-E*F+*";
    stack<string> s;
    
    for (int i = 0; i < input[i]; ++i) {
        
        if (input[i] == ' ') continue;
        else if (isalpha(input[i])) {
            s.push(toString(input[i]));
        } else {
            char sign = input[i];
            // a sign b
            string second = s.top();
            s.pop();
            string first = s.top();
            s.pop();
            
            if (first.size() > 1 && !(first[0] == '(' && first[first.size() - 1] == ')')) {
                first = "(" + first + ")";
            }
            if (second.size() > 1 && !(second[0] == '(' && second[second.size() - 1] == ')')) {
                second = "(" + second + ")";
            }
            string forpush = first + toString(sign) + second;
            s.push(forpush);
            //cout << "ans: " << forpush << endl;
        }
        //cout << s.top() << endl;
    }
    
    cout << s.top() << endl;
    
    return 0;
}
