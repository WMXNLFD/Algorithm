#include <iostream>

struct ListNode
{
    int val; //������
    ListNode *next; //ָ����
    ListNode(int x) : val(x), next(NULL) {} //���캯��
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *new_head = NULL; //ָ��������ͷ����ָ��
        while(head)
            {
                ListNode *next = head->next; //����head->next
                head->next = new_head; //����head->next
                new_head = head; //�ƶ�new_head
                head = next; //��������
            }
            return new_head; //����������ͷ���
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
