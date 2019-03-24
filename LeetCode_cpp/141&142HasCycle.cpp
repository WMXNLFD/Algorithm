#include <iostream>
#include <vector>
#include <set>

struct ListNode
{
    int val; //数据域
    ListNode *next; //指针域
    ListNode(int x) : val(x), next(NULL) {} //构造函数
};


//快慢指针的方法 空间复杂度为O(1)
class Solution
{
public:
    ListNode* hasCycle(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* meet = NULL;
        while(fast)
        {
            slow = slow->next;
            fast = fast->next;
            if(!fast)
                return NULL;
            fast = fast->next;
            if(fast == slow)
            {
                meet = fast;
                break;
            }
        }
        if(meet == NULL)
            return NULL;
        while(head && meet)
        {
            if(head == meet)
                return head;
            head =head->next;
            meet = meet->next;
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
    c1.next = &b2;
    Solution solve;
    //ListNode *head = &a;
    // m = solve.middleNode(&a)
    ListNode* result = solve.hasCycle(&a1);
    if(result)
        std::cout << "有环：" << result->val << std::endl;
    else
        std::cout << "无环" << std::endl;


}

