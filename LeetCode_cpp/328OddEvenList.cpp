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
    ListNode* oddEvenList(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* o = head;
        ListNode* p = head->next;
        ListNode* e = p;
        while(o->next && e->next)
        {
            o->next = e->next;
            o = o->next;
            e->next = o->next;
            e = e->next;
        }
        o->next = p;
        return head;
    }

};



int main()
{
    ListNode a1(1);
    ListNode a2(2);
    ListNode b1(3);
    ListNode b2(4);
    ListNode b3(5);
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

    ListNode* head = solve.oddEvenList(&a1);
    while(head)
    {
        std::cout << head->val;
        head = head->next;
    }


    //std::cout << result->val << result->left->val << result->right->val << std::endl;

}

