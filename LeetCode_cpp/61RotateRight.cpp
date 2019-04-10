#include <iostream>
#include <vector>

struct ListNode
{
    int val; //������
    ListNode *next; //ָ����
    ListNode(int x) : val(x), next(NULL) {} //���캯��
};


class Solution
{
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(head == NULL || k == 0)
            return head;
        ListNode* cur = head;
        ListNode* tail = NULL;
        int len = 1;
        while(cur->next)
        {
            cur = cur->next;
            len++;
        }
        int loop = len - (k%len); //�õ�ѭ������
        tail = cur;
        cur->next = head;//********
        cur = head;
        for(int i = 0; i < loop; i++)
        {
            cur = cur->next;
            tail = tail->next;
        }
        tail->next = NULL;
        return cur;
    }
};


int main()
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    //ListNode f(7);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    //e.next = &f;
    //e.next = NULL;
    Solution solve;
    ListNode *head = solve.rotateRight(&a,2);
    while(head)
    {
        std::cout << head->val <<"\n";
        head = head->next;
    }

    return 0;
}



