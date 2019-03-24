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
        /*自己的方法，有点小问题，没找出来
        ListNode temp_head(0);
        ListNode* pre = &temp_head;

        while(head)
        {
            if(pre->val != head->val)
            {
                //std::cout << "if"<<std::endl;
                pre->next = head;
                head = head->next;
                pre = pre->next;
            }
            else
            {
                head = head->next;
            }
        }
        return temp_head.next;*/
        /*直接法
        ListNode* current = head;
        while(current != NULL && current->next != NULL)
        {
            if(current->next->val != current->val)
                current = current->next;
            else
                current->next = current->next->next;
        }
        return head;*/

        //递归法
        if(head == NULL || head->next == NULL)
            return head;
        head->next = deleteDuplicates(head->next);
        if(head->val == head->next->val)
        {
            head = head->next;
        }
        return head;

    }
};


int main()
{
    ListNode a(1);
    ListNode b(1);
    ListNode c(2);
    ListNode d(2);
    ListNode e(3);
    ListNode f(3);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    //e.next = NULL;
    Solution solve;
    //ListNode *head = &a;
    // m = solve.middleNode(&a)
    ListNode* head = solve.deleteDuplicates(&a);

    std::cout << "删除重复元素后的结果为:" << std::endl;
    while(head)
    {
        std::cout << head->val << "\n";
        head = head->next;
    }




}



