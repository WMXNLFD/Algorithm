#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

struct ListNode
{
    int val; //数据域
    ListNode *next; //指针域
    ListNode(int x) : val(x), next(NULL) {} //构造函数
};


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    ListNode dummy(0);
    ListNode* ptr = &dummy;
    while(l1 && l2)
    {
        if(l1->val <= l2->val)
        {
            ptr->next= l1;
          //  ptr = l1;
            l1 = l1->next;
        }
        else
        {
            ptr->next = l2;
            //ptr = l2;
            l2 = l2->next;
        }
        ptr =ptr->next;
    }
        if(l1)
        {
            ptr->next = l1;
        }
        if(l2)
        {
            ptr->next = l2;
        }

        return dummy.next;
}

////分治算法
class Solution
{
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists)
    {
        if(lists.size() == 0)
            return NULL;
        if(lists.size() == 1)
            return lists[0];
        if(lists.size() == 2)
            return mergeTwoLists(lists[0],lists[1]);
        int mid = lists.size() / 2;
        std::vector<ListNode*> sub1_lists;
        std::vector<ListNode*> sub2_lists;
        for(int i = 0;i < mid; i++)
        {
            sub1_lists.push_back(lists[i]);
        }
        for(int i = mid; i < lists.size(); i++)
            sub2_lists.push_back(lists[i]);
        ListNode* l1 = mergeKLists(sub1_lists);
        ListNode* l2 = mergeKLists(sub2_lists);
        return mergeTwoLists(l1,l2);
    }
};


int main()
{
    ListNode a(1);
    ListNode b(4);
    ListNode c(5);

    ListNode d(1);
    ListNode e(3);
    ListNode f(4);

    ListNode g(2);
    ListNode h(6);

    a.next = &b;
    b.next = &c;
    //c.next = &d;
    d.next = &e;
    e.next = &f;

    g.next = &h;
    //e.next = NULL;
    Solution solve;
    std::vector<ListNode*> lists;
    lists.push_back(&a);
    lists.push_back(&d);
    lists.push_back(&g);
    ListNode *head = solve.mergeKLists(lists);
    while(head)
    {
        std::cout << head->val;
        head = head->next;
    }

    return 0;
}



