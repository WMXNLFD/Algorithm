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
        //双指针，一次遍历
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fast = dummy,*slow = dummy;
        for(int i = 0;i < n;i++)
            fast = fast->next;
        while(fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
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
    ListNode *head = solve.removeNthFromEnd(&a,2);
    while(head)
    {
        std::cout << head->val;
        head = head->next;
    }

    return 0;
}



