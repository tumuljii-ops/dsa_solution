#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    int applyOp(int a, int b, char op) {
        if (op == '+') return a + b;
        if (op == '-') return a - b;
        if (op == '*') return a * b;
        if (op == '/') return a / b;  
        return 0;
    }

    int calculate(string s) {
        stack<int> values;      
        stack<char> ops;       
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (c == ' ') continue;  

            if (isdigit(c)) {
                int val = 0;
                while (i < n && isdigit(s[i])) {
                    val = val * 10 + (s[i] - '0');
                    i++;
                }
                i--;  
                values.push(val);
            }
            else if (c == '(') {
                ops.push(c);
            }
            else if (c == ')') {
                while (!ops.empty() && ops.top() != '(') {
                    int b = values.top(); values.pop();
                    int a = values.top(); values.pop();
                    char op = ops.top(); ops.pop();
                    values.push(applyOp(a, b, op));
                }
                ops.pop(); 
            }
            else {
                while (!ops.empty() && precedence(ops.top()) >= precedence(c)) {
                    int b = values.top(); values.pop();
                    int a = values.top(); values.pop();
                    char op = ops.top(); ops.pop();
                    values.push(applyOp(a, b, op));
                }
                ops.push(c);
            }
        }

        while (!ops.empty()) {
            int b = values.top(); values.pop();
            int a = values.top(); values.pop();
            char op = ops.top(); ops.pop();
            values.push(applyOp(a, b, op));
        }

        return values.top();
    }
};
