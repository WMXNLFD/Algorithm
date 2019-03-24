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
    ListNode * deleteNode(ListNode *head,ListNode* node)
    {

        ListNode* new_head = head;

        node->val = node->next->val;
        ListNode* delNote = node ->next; // 1保存
        node->next = node->next->next;// 2删除
        delete delNote;// 3释放

        return new_head;
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
    std::cout << "删除后为:" << std::endl;
    head = solve.deleteNode(&a,&c);
    while(head)
    {
        std::cout << head->val;
        head = head->next;
    }


}



