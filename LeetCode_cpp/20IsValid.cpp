#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(string s)
    {
        stack<char> stk;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == ')' || s[i] == ']' || s[i] == '}')
            {
                if(stk.size() == 0) return false;
                if(stk.top() == '(' && s[i] != ')') return false;
                if(stk.top() == '[' && s[i] != ']') return false;
                if(stk.top() == '{' && s[i] != '}') return false;
                stk.pop();
            }
            else
                stk.push(s[i]);
        }
        return stk.empty();
    }
};


//²âÊÔº¯Êý

int main()
{
    string S = "()[]{}";
    Solution solve;
    cout << solve.isValid(S);
    return 0;
}
