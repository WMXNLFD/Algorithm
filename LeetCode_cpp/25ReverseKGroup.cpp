#include <iostream>
#include <vector>
#include <stack>

struct ListNode
{
    int val; //������
    ListNode *next; //ָ����
    ListNode(int x) : val(x), next(NULL) {} //���캯��
};


class Solution
{
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* next = NULL;
        //�������������ǲ��Ƿ��Ϸ�ת����Ȼ���һ��Ҳ�ᷭת
        //��ĿҪ������ڵ��������� k ������������ô�����ʣ��ڵ㱣��ԭ��˳��
        ListNode* check = head;
        int len = 0;
        int count = 0;
        while(len < k && check)
        {
            check = check->next;
            len++;
        }
        if(len == k)
        {
            while(count < k && cur)
            {
                next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
                count++;
            }
            if(next)
                head->next = reverseKGroup(next,k);
            return pre;
        }
        else
            return head;
    }
};


int main()
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    //ListNode f(4);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    //e.next = &f;
    //e.next = NULL;
    Solution solve;
    ListNode *head = solve.reverseKGroup(&a,3);
    while(head)
    {
        std::cout << head->val;
        head = head->next;
    }

    return 0;
}



