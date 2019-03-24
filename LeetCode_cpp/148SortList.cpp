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
    ListNode* sortList(ListNode* head)
    {
        return head == NULL ? NULL :mergeSort(head);
    }

    ListNode* mergeSort(ListNode* node)
    {
        if(node->next == NULL)
            return node;
        ListNode* fast = node, * slow = node;
        //很重要
        ListNode* breakN = node;
        while(fast != NULL && fast->next != NULL)
        {
            //std::cout << 1 ;
            breakN = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        breakN->next = NULL;
        ListNode* l = mergeSort(node);
        ListNode* r = mergeSort(slow);
        return mergeTwoLists(l,r);
    }
    ListNode* mergeTwoLists(ListNode* l1,ListNode* l2)
    {
        ListNode* temp_head = new ListNode(0);
        ListNode* pre = temp_head;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                pre->next = l1;
                l1 = l1->next;
            }
            else
            {
                pre->next = l2;
                l2 = l2->next;
            }
            pre = pre->next;
        }
        if(l1)
            pre->next = l1;
        if(l2)
            pre->next = l2;
        return temp_head->next;
    }

};



int main()
{
    ListNode a1(4);
    ListNode a2(2);
    ListNode b1(1);
    ListNode b2(3);
    //ListNode b3(9);
    //ListNode c1(6);
    //ListNode c2(7);
    //ListNode c3(8);

    a1.next = &a2;
    a2.next = &b1;
    b1.next = &b2;
    //b2.next = &b3;
    //b3.next = &c1;
    //c1.next = &c2;
    //c1.next = &b2;

    Solution solve;

    ListNode* head = solve.sortList(&a1);
    while(head)
    {
        std::cout << head->val;
        head = head->next;
    }


    //std::cout << result->val << result->left->val << result->right->val << std::endl;

}

