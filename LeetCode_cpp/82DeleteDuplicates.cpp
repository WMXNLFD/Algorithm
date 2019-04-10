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
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode dummy(0);
        ListNode* p = &dummy;
        p->next = head;
        ListNode* left,*right;
        while(p->next)
        {
            left = p->next;
            right = left;
            while(right->next && right->next->val == left->val)
                right = right->next;
            if(left == right)
                p = p->next;
            else
                p->next = right->next;
        }
        return dummy.next;
    }
};


int main()
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(3);
    ListNode e(4);
    ListNode f(4);
    ListNode g(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;
    //e.next = NULL;
    Solution solve;
    ListNode *head = solve.deleteDuplicates(&a);
    while(head)
    {
        std::cout << head->val <<"\n";
        head = head->next;
    }

    return 0;
}



