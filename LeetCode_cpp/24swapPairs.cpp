#include <iostream>
#include <vector>
#include <set>
#include <list>

struct ListNode
{
    int val; //������
    ListNode *next; //ָ����
    ListNode(int x) : val(x), next(NULL) {} //���캯��
};



class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
        //�ݹ�ķ���������ţb
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
    }

};



int main()
{
    ListNode a1(1);
    ListNode a2(2);
    ListNode b1(3);
    ListNode b2(4);
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

    ListNode* head = solve.swapPairs(&a1);
    while(head)
    {
        std::cout << head->val;
        head = head->next;
    }


    //std::cout << result->val << result->left->val << result->right->val << std::endl;

}
