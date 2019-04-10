#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T)
    {
        vector<char> vs , vt;
        for(char c : S)
        {
            if(c != '#')
                vs.push_back(c);
            else if(! vs.empty())
                vs.pop_back();
        }
        for(char c : T)
        {
            if(c != '#')
                vt.push_back(c);
            else if(! vt.empty())//这里是判断vs，vt
                vt.pop_back();
        }
        return vs == vt;
    }
};


//测试函数

int main()
{
    string S = "a##c";
    string T = "#a#c";
    Solution solve;
    cout << solve.backspaceCompare(S,T);
    return 0;
}
