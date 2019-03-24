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
    void reorderList(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
            return ;
        //1.����ָ�����е㣬�ֳ�������
        ListNode* fast = head, *slow = head;
        //����Ϊfast->next,ż��Ϊfast,��������=��=
        /*while(fast)
        {
            slow = slow->next;
            fast = fast->next ? fast->next->next : fast->next;
        }*/
        //��ż��ͨ��
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            //std::cout << 1 ;
        }
        //std::cout << slow->val;
        //std::cout << slow->next->val;
        //std::cout << slow->next->next->val;

        //2.��ת��벿��,���pre����
        ListNode* pre = NULL;
        while(slow)
        {
            ListNode* next = slow->next;
            slow->next = pre;
            pre = slow;
            slow = next;
        }

        //3.��������
        ListNode* cur = head;
         //�������ֹ����ʱpre->next
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

