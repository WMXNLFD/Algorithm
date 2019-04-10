#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
/*
��������
������ɨ�������������еĽڵ㣬�������ƵĽڵ���뵽ԭ�Ƚڵ�ĺ��档
���ٴ�ɨ��ڵ㣬��������ԭ�ڵ�randomָ����
���ٽ����������
*/

class Solution
{
public:
    Node* copyRandomList(Node* head)
    {
        if(head == NULL)
            return NULL;
        Node* p = head, *tempP;
        //1.ɨ�������������нڵ�
        while(p)
        {
            tempP = new Node(p->val,p->next,p->random);
            //��������ƵĽڵ���뵽����Դ�ĺ���
            tempP->next = p->next;
            p->next = tempP;
            p = p->next->next;//�ƶ��������ƶ�����һ�Σ���Ϊ�ո��ں��������һ�����ƵĽڵ�
        }
        //2.�ٴ�ɨ����������random�ڵ�
        p = head;
        while(p)
        {
            if(p->random)
            {
                //pHead->next��pHead�ĸ��ƣ�����pHead->random->next�ĸ�����pHead->random
                p->next->random = p->random->next;
            }
            else
                p->next->random = NULL;
            p = p->next->next;
        }
        //3.�����������
        p =head;
        Node* copyHead = p->next;
        while(p)
        {
            tempP = p->next;
            p->next = p->next->next;
            if(tempP->next)
                tempP->next = tempP->next->next;
            p = p->next;
        }
        return copyHead;
    }
};


int main()
{
    Node* b =  new Node (2,NULL,b);
    Node* a = new Node (1,b,b);
    //Node a(1);
    //Node b(2);
    //ListNode c(3);
    //ListNode d(4);
    //ListNode e(5);
    //ListNode f(4);

    //a.next = &b;
    //a.random = &b;
    //b.random = &b;
    //b.next = &c;
    //c.next = &d;
    //d.next = &e;

    //e.next = &f;
    //e.next = NULL;
    Solution solve;
    Node* head = solve.copyRandomList(a);
    while(head)
    {
        std::cout << head->val;
        head = head->random;
    }

    return 0;
}



