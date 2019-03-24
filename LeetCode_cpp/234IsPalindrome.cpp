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
    bool isPalindrome(ListNode* head)
    {
        //1.快慢指针找到链表中点            //*pre = NULLptr
        ListNode* slow = head, *fast = head, *pre = nullptr;
        while(fast)
        {
            slow = slow->next;
            //这段代码真的牛b
            fast = fast->next ? fast->next->next : fast->next;
        }
        //2.reverse 逆序后半部分 存进pre里面
        while(slow)
        {
            ListNode* next = slow->next;
            slow->next = pre;
            pre = slow;
            slow = next;
        }
        //3.check从头，中点，开始比较是否相同
        while(head && pre)
        {
            if(head->val != pre->val)
                return false;
            head = head->next;
            pre = pre->next;
        }
        return true;

    }
};


int main()
{
    ListNode a1(1);
    ListNode a2(2);
    ListNode b1(2);
    ListNode b2(1);
    //ListNode b3(5);
    //ListNode c1(6);
    //ListNode c2(7);
    //ListNode c3(8);

    a1.next = &a2;
    a2.next = &b1;
    b1.next = &b2;
    //b2.next = &b3;
    //b3.next = &c1;
    //c1.next = &c2;
    //c1.next = &b2;
    Solution solve;
    //ListNode *head = &a;
    // m = solve.middleNode(&a)
    bool result = solve.isPalindrome(&a1);
    if(result)
        std::cout << "是回文链表\n" << result << std::endl;
    else
        std::cout << "不是回文链表" << std::endl;


}

