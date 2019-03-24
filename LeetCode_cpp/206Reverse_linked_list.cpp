#include <iostream>

struct ListNode
{
    int val; //数据域
    ListNode *next; //指针域
    ListNode(int x) : val(x), next(NULL) {} //构造函数
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *new_head = NULL; //指向新链表头结点的指针
        while(head)
            {
                ListNode *next = head->next; //备份head->next
                head->next = new_head; //更新head->next
                new_head = head; //移动new_head
                head = next; //遍历链表
            }
            return new_head; //返回新链表头结点
    }
};

int main()
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    //e.next = NULL;
    Solution solve;
    ListNode *head = &a;
    std::cout << "before reverse: \n";
    while(head)
    {
        std::cout << head->val  << std::endl;
        head = head->next;
    }
    head = solve.reverseList(&a);
    std::cout << "after revese: \n";
    while(head)
    {
        std::cout << head->val << std::endl;
        head = head->next;
    }
    return 0;
}
