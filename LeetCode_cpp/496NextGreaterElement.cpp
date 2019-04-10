#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> res;
        for(int i = 0; i < nums1.size(); i++)
        {
            auto r = find(nums2.begin(),nums2.end(),nums1[i]);
            while((++r) != nums2.end())
            {
                if(*r > nums1[i])
                {
                    res.push_back(*r);
                    break;
                }
            }
            if(r == nums2.end())
                res.push_back(-1);
        }
        return res;
    }
};



