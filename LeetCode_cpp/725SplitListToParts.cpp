#include <iostream>
#include <vector>
#include <set>
#include <list>

struct ListNode
{
    int val; //数据域
    ListNode *next; //指针域
    ListNode(int x) : val(x), next(NULL) {} //构造函数
};



class Solution {
public:
    std::vector<ListNode*> splitListToParts(ListNode* root, int k)
    {
        std::vector<ListNode*>res;
        ListNode* cur = root;
        int l = 0;
        while(cur)
        {
            cur = cur->next;
            l++;
        }
        std::vector<int>nums(k, l/k);
        for(int i = 0;i < (l % k); i++)
            nums[i]++;
        for(int num:nums)
        {
            ListNode* tmp = root;
            if(num == 0)
            {
                res.push_back(root);
                continue;
            }
            while(--num&&root)
                root = root->next;
            ListNode* nextroot = root->next;
            root->next = NULL;
            root = nextroot;
            res.push_back(tmp);

            //for(int i = 1; i < res.size();i++)
            //    std::cout << res[i]->val;
        }
        return res;
    }
};



int main()
{
    ListNode a1(1);
    ListNode a2(2);
    ListNode b1(3);
    //ListNode b2(3);
    //ListNode b3(4);
    //ListNode c1(6);
    //ListNode c2(7);
    //ListNode c3(8);

    a1.next = &a2;
    a2.next = &b1;
    //b1.next = &b2;
    //b2.next = &b3;
    //b3.next = &c1;
    //c1.next = &c2;
    //c1.next = &b2;

    Solution solve;

    std::vector<ListNode*> result = solve.splitListToParts(&a1,5);
    //vector的遍历
    for(int i = 0; i < result.size();i++)
    {
        if(result[i])
            std::cout << result[i]->val;
        else
            std::cout << NULL;
    }



/*
    while(result)
    {
        std::cout << result->val;
        result = result->next;
    }*/


    //std::cout << result->val << result->left->val << result->right->val << std::endl;

}

