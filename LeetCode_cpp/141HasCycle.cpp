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
    ListNode* hasCycle(ListNode* head)
    {
        std::set<ListNode* >node_set;
        while(head)
        {
            if(node_set.find(head) != node_set.end())
                return head;
            node_set.insert(head);
            head = head->next;
        }
        return NULL;
    }
};


int main()
{
    ListNode a1(1);
    ListNode a2(2);
    ListNode b1(3);
    ListNode b2(4);
    ListNode b3(5);
    ListNode c1(6);
    ListNode c2(7);
    //ListNode c3(8);

    a1.next = &a2;
    a2.next = &b1;
    b1.next = &b2;
    b2.next = &b3;
    b3.next = &c1;
    c1.next = &c2;
    c1.next = &b1;
    Solution solve;
    //ListNode *head = &a;
    // m = solve.middleNode(&a)
    ListNode* result = solve.hasCycle(&a1);
    if(result)
        std::cout << "�л���" << result->val << std::endl;
    else
        std::cout << "�޻�" << std::endl;


}

