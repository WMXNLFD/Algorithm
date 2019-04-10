#include <iostream>
#include <vector>
/*
struct ListNode
{
    int val; //������
    ListNode *next; //ָ����
    ListNode(int x) : val(x), next(NULL) {} //���캯��
};*/

//˫��������ƽ���༶˫������
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;


class Solution
{
public:
    ListNode* flatten(ListNode* head)
    {
        if(head == NULL)
            return NULL;
        Node* cur = head;
        while(cur)
        {
            if(cur->child)
            {
                Node* next = cur->next;
                Node* child = flatten(cur->child);
                cur->next = child;
                child->prev = cur;
                cur->child = NULL;
                //����
                if(next)
                {
                    while(cur->next)
                        cur = cur->next;
                cur->next = next;
                next->prev = cur;
                }
            }
            cur = cur->next;
        }
        return head;
    }
};


int main()
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(3);
    ListNode e(4);
    ListNode f(4);
    ListNode g(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;
    //e.next = NULL;
    Solution solve;
    ListNode *head = solve.flatten(&a);
    while(head)
    {
        std::cout << head->val <<"\n";
        head = head->next;
    }

    return 0;
}



