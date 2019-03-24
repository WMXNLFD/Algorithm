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
    int numComponents(ListNode* head, std::vector<int>& G)
    {
        std::set<int> set(G.begin(),G.end());
        int result = 0;
        while(head)
        {
            if(set.find(head->val) != set.end())
            {                                                //这里是恒等于，即找不到+1
                if(head->next == NULL || set.find(head->next->val) == set.end())
                    result ++;
            }
            head = head->next;
        }
        return result;
    }

};



int main()
{
    ListNode a1(0);
    ListNode a2(1);
    ListNode b1(2);
    ListNode b2(3);
    ListNode b3(4);
    //ListNode c1(6);
    //ListNode c2(7);
    //ListNode c3(8);

    a1.next = &a2;
    a2.next = &b1;
    b1.next = &b2;
    b2.next = &b3;
    //b3.next = &c1;
    //c1.next = &c2;
    //c1.next = &b2;

    std::vector<int> G = {0,1,3,4};

    Solution solve;

    int result = solve.numComponents(&a1,G);
    std::cout <<result;


    /*
    while(head)
    {
        std::cout << head->val;
        head = head->next;
    }
*/

    //std::cout << result->val << result->left->val << result->right->val << std::endl;

}

