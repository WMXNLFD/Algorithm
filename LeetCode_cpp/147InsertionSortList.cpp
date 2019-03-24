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
    ListNode* swapPairs(ListNode* head)
    {
        ListNode* temp_head = new ListNode(-1);

        while(head)
        {
            //要在循环里面，每一次回到开头
            ListNode* pre = temp_head;
            while(pre->next && pre->next->val <= head->val)
            {
                //std::cout << pre->val;
                pre = pre->next;
            }

            ListNode* next = head->next;
            head->next = pre->next;
            pre->next = head;
            head = next;



        }
        return temp_head->next;
    }

};



int main()
{
    ListNode a1(-1);
    ListNode a2(5);
    ListNode b1(3);
    ListNode b2(4);
    ListNode b3(0);
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

    Solution solve;

    ListNode* head = solve.swapPairs(&a1);
    while(head)
    {
        std::cout << head->val;
        head = head->next;
    }


    //std::cout << result->val << result->left->val << result->right->val << std::endl;

}

