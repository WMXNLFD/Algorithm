#include <iostream>
#include <vector>
#include <set>

struct ListNode
{
    int val; //������
    ListNode *next; //ָ����
    ListNode(int x) : val(x), next(NULL) {} //���캯��
};



class Solution
{
public:
    bool isPalindrome(ListNode* head)
    {
        //1.����ָ���ҵ������е�            //*pre = NULLptr
        ListNode* slow = head, *fast = head, *pre = nullptr;
        while(fast)
        {
            slow = slow->next;
            //��δ������ţb
            fast = fast->next ? fast->next->next : fast->next;
        }
        //2.reverse �����벿�� ���pre����
        while(slow)
        {
            ListNode* next = slow->next;
            slow->next = pre;
            pre = slow;
            slow = next;
        }
        //3.check��ͷ���е㣬��ʼ�Ƚ��Ƿ���ͬ
        while(head && pre)
        {
            if(head->val != pre->val)
                return false;
            head = head->next;
            pre = pre->next;
        }
        return true;

    }
};


int main()
{
    ListNode a1(1);
    ListNode a2(2);
    ListNode b1(2);
    ListNode b2(1);
    //ListNode b3(5);
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
    //ListNode *head = &a;
    // m = solve.middleNode(&a)
    bool result = solve.isPalindrome(&a1);
    if(result)
        std::cout << "�ǻ�������\n" << result << std::endl;
    else
        std::cout << "���ǻ�������" << std::endl;


}

