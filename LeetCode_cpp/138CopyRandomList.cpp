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

class Solution
{
public:
    Node* copyRandomList(Node* head)
    {
        map<Node*,Node*> myMap;
        Node* p = head,*tempP;
        //扫描链表，复制所有的节点
        while(p)
        {
            tempP = new Node(p->val,p->next,p->random);
            myMap[p] = tempP;//将原点与新节点一一对应关联
            p = p->next;
        }
        myMap[NULL] = NULL;
        p = head;
        //再次扫描链表，复制
        while(p)
        {
            myMap[p]->next = myMap[p->next];
            myMap[p]->random = myMap[p->random];
            p = p->next;
        }
        return myMap[head];
    }
};


int main()
{
    Node* b =  new Node (2,nullptr,b);
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
    auto *head = solve.copyRandomList(a);
    while(head)
    {
        std::cout << head->val;
        head = head->random;
    }

    return 0;
}



