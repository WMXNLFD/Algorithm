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
    ListNode* middleNode(ListNode* head)
    {
       //快慢指针的方法，真的牛b
       ListNode* fast = head;
       ListNode* slow = head;
       while(fast != NULL && fast->next != NULL)
       {
           fast = fast->next->next;
           slow = slow->next;
       }
       return slow;
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
    //int m = solve.middleNode(&a)
    std::cout << "中间元素为为:" << solve.middleNode(&a)->val << std::endl;




}



