#include <iostream>
#include <vector>

struct ListNode
{
    int val; //数据域
    ListNode *next; //指针域
    ListNode(int x) : val(x), next(NULL) {} //构造函数
};


class Solution
{
public:
    ListNode* merageTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode temp_head(0);
        ListNode *pre = &temp_head;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                pre->next = l1;//*pre = l1->val;
                l1 = l1->next;
            }
            else
            {
                pre->next = l2;//*pre = l2->val;
                l2 = l2->next;
            }
            pre = pre->next;
        }
        if(l1)
        {
            pre->next = l1;
        }
        if(l2)
        {
            pre->next = l2;
        }
        return temp_head.next;
    }
};


int main()
{
    ListNode a(1);
    ListNode b(4);
    ListNode c(6);
    ListNode d(0);
    ListNode e(5);
    ListNode f(7);
    a.next = &b;
    b.next = &c;
    d.next = &e;
    e.next = &f;
    //e.next = NULL;
    Solution solve;
    ListNode *head = solve.merageTwoLists(&a,&d);
    while(head)
    {
        std::cout << head->val <<"\n";
        head = head->next;
    }

    return 0;
}



