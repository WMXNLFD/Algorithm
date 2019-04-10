#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int carried = 0;
        ListNode dummy(0);
        ListNode* p = &dummy;
        while(l1 || l2)
        {
            int sum = carried;
            auto x = l1 ? l1->val : 0;//精髓
            auto y = l2 ? l2->val : 0;//精髓
            sum = x + y + sum;
            carried = sum / 10;
            sum = sum % 10;
            ListNode* newNode = new ListNode(sum);
            p->next = newNode;
            p = p->next;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        if(carried)
        {
            ListNode* newNode = new ListNode(1);
            p->next = newNode;
        }
        return dummy.next;
    }
};

int main()
{
    ListNode a(2);
    ListNode b(4);
    ListNode c(3);
    ListNode d(5);
    ListNode e(6);
    ListNode f(4);
    a.next = &b;
    b.next = &c;

    d.next = &e;
    e.next = &f;

    Solution solve;
    ListNode * result = solve.addTwoNumbers(&a,&d);
    while(result)
    {
        std::cout << result->val;
        result = result->next;
    }
    return 0;
}


