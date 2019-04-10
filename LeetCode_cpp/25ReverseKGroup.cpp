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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* next = NULL;
        //必须检查链表长度是不是符合翻转，不然最后一个也会翻转
        //题目要求：如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序。
        ListNode* check = head;
        int len = 0;
        int count = 0;
        while(len < k && check)
        {
            check = check->next;
            len++;
        }
        if(len == k)
        {
            while(count < k && cur)
            {
                next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
                count++;
            }
            if(next)
                head->next = reverseKGroup(next,k);
            return pre;
        }
        else
            return head;
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
    ListNode *head = solve.reverseKGroup(&a,3);
    while(head)
    {
        std::cout << head->val;
        head = head->next;
    }

    return 0;
}



