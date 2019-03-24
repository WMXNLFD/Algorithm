#include <iostream>
#include <vector>
#include <set>

struct ListNode
{
    int val; //数据域
    ListNode *next; //指针域
    ListNode(int x) : val(x), next(NULL) {} //构造函数
};


class Solution
{
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        std::set<ListNode*> node_set;
        while(headA)
        {
            node_set.insert(headA);
            headA = headA->next;
        }
        while(headB)
        {
            if(node_set.find(headB) != node_set.end())
                return headB;
            headB = headB->next;
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
    ListNode c3(8);

    a1.next = &a2;
    a2.next = &c1;
    c1.next = &c2;
    c2.next = &c3;
    b1.next = &b2;
    b2.next = &b3;
    b3.next = &c1;
    Solution solve;
    //ListNode *head = &a;
    // m = solve.middleNode(&a)
    ListNode* result = solve.getIntersectionNode(&a1,&b1);

    std::cout << "有交点：" << result->val << std::endl;


}


/*
//测试STL set的使用
int main()
{
    std::set<int> test_set;
    const int A_LEN = 7;
    const int B_LEN = 8;

    int a[A_LEN] = {5,1,4,8,10,1,3};
    int b[B_LEN] = {2,7,6,3,1,6,0,1};

    for (int i = 0; i < A_LEN; i++)
    {
        test_set.insert(a[i]);
    }
    for (int i = 0; i < B_LEN; i++)
    {
        if(test_set.find(b[i]) != test_set.end())
        {
            std::cout << "b[" << i << "]" << "=" << b[i] << " in array A.\n";
        }
    }

    return 0;
}
*/

