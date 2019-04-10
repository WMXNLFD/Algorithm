#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <stack>


struct ListNode
{
    int val; //数据域
    ListNode *next; //指针域
    ListNode(int x) : val(x), next(NULL) {} //构造函数
};



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if(l1 == NULL || l2 == NULL)
            return l1 == NULL ? l2 : l1;
        std::stack<int> s1;
        std::stack<int> s2;

        while(l1)
        {
            s1.push(l1->val);//这里是压入数值啊
            l1 = l1->next;
        }
        while(l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carried = 0;
        ListNode dummy(0);
        ListNode* p = &dummy;
        while(!s1.empty() || !s2.empty())
        {
            int sum = carried;//这部精髓

            auto val1 = s1.empty()? 0 : s1.top();
            auto val2 = s2.empty()? 0 : s2.top();
            sum = val1 + val2 + sum;
            carried = sum / 10;
            sum %= 10;
            ListNode* newNode = new ListNode(sum);
            newNode->next = p->next;
            p->next = newNode;

            if(!s1.empty())
                s1.pop();
            if(!s2.empty())
                s2.pop();
        }
         //判断最后一位是否还有个进位值
        if(carried)
        {
            ListNode* newNode = new ListNode(1);
            newNode->next = p->next;
            p->next = newNode;
        }
        return dummy.next;
    }
};



int main()
{
    ListNode a1(7);
    ListNode a2(2);
    ListNode b1(4);
    ListNode b2(3);

    ListNode b3(5);
    ListNode c1(6);
    ListNode c2(4);
    //ListNode c3(8);

    a1.next = &a2;
    a2.next = &b1;
    b1.next = &b2;

    //b2.next = &b3;
    b3.next = &c1;
    c1.next = &c2;
    //c1.next = &b2;

    Solution solve;

    ListNode* result = solve.addTwoNumbers(&a1,&b3);

    /*
    //vector的遍历
    for(int i = 0; i < result.size();i++)
    {
        if(result[i])
            std::cout << result[i]->val;
        else
            std::cout << NULL;
    }
*/



    while(result)
    {
        std::cout << result->val;
        result = result->next;
    }


    //std::cout << result->val << result->left->val << result->right->val << std::endl;

}

