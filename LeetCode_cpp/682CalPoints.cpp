#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops)
    {
        int sum = 0, i = -1;
        vector<int> sta;
        for(auto &x : ops)
        {
            if(x == "+")
            {
                sta.push_back(sta[i] + sta[i - 1]);
                i++;
            }
            else if(x == "D")
            {
                sta.push_back(2 * sta[i]);
                i++;
            }
            else if(x == "C")
            {
                sta.pop_back();
                i--;
            }
            else
            {
                i++;
                sta.push_back(atoi(x.c_str()));
            }
        }
        for(auto s : sta)
            sum += s;
        return sum;
    }
};



