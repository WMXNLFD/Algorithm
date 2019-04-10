#include <iostream>
#include <vector>
#include <stack>

struct ListNode
{
    int val; //数据域
    ListNode *next; //指针域
    ListNode(int x) : val(x), next(NULL) {} //构造函数
};


class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* cur = head;
        ListNode dummy(0);
        ListNode* p = &dummy;
        p->next =head;
        int len = 1;
        while(cur->next)
        {
            cur = cur->next;
            len++;
        }
        //std::cout << len;
        for(int i = 0;i < len - n;i++)
            p = p->next;
        p->next = p->next->next;
        return dummy.next;
    }
};


int main()
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    //ListNode f(4);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;

    //e.next = &f;
    //e.next = NULL;
    Solution solve;
    ListNode *head = solve.removeNthFromEnd(&a,5);
    while(head)
    {
        std::cout << head->val;
        head = head->next;
    }

    return 0;
}



