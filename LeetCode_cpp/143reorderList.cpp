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
    void reorderList(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
            return ;
        //1.快慢指针找中点，分成两部分
        ListNode* fast = head, *slow = head;
        //奇数为fast->next,偶数为fast,并不好用=。=
        /*while(fast)
        {
            slow = slow->next;
            fast = fast->next ? fast->next->next : fast->next;
        }*/
        //奇偶数通用
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            //std::cout << 1 ;
        }
        //std::cout << slow->val;
        //std::cout << slow->next->val;
        //std::cout << slow->next->next->val;

        //2.翻转后半部分,存进pre里面
        ListNode* pre = NULL;
        while(slow)
        {
            ListNode* next = slow->next;
            slow->next = pre;
            pre = slow;
            slow = next;
        }

        //3.两两插入
        ListNode* cur = head;
         //这里的终止条件时pre->next
        while(cur && pre->next)
        {
            ListNode* nextcur = cur->next;
            ListNode* nextpre = pre->next;
            cur->next = pre;
            pre->next = nextcur;
            cur = nextcur;
            pre = nextpre;
        }
        while(head)
        {
            std::cout << head->val;
            head = head->next;
        }

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

    solve.reorderList(&a1);

    //ListNode* head = solve.reorderList(&a1);
    //std::cout <<result;
/*
    while(head)
    {
        std::cout << head->val;
        head = head->next;
    }

*/
    //std::cout << result->val << result->left->val << result->right->val << std::endl;

}

