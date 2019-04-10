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
方法二：
①首先扫描链表，复制所有的节点，并将复制的节点插入到原先节点的后面。
②再次扫描节点，复制所有原节点random指针域、
③再将两个链表拆开
*/

class Solution
{
public:
    Node* copyRandomList(Node* head)
    {
        if(head == NULL)
            return NULL;
        Node* p = head, *tempP;
        //1.扫描链表，复制所有节点
        while(p)
        {
            tempP = new Node(p->val,p->next,p->random);
            //将这个复制的节点插入到复制源的后面
            tempP->next = p->next;
            p->next = tempP;
            p = p->next->next;//移动必须是移动两个一次，因为刚刚在后面插入了一个复制的节点
        }
        //2.再次扫描链表，复制random节点
        p = head;
        while(p)
        {
            if(p->random)
            {
                //pHead->next是pHead的复制，所以pHead->random->next的复制是pHead->random
                p->next->random = p->random->next;
            }
            else
                p->next->random = NULL;
            p = p->next->next;
        }
        //3.将两个链表拆开
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



