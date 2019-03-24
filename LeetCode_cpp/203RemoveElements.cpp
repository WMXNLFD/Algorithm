#include <iostream>
#include <vector>

struct ListNode
{
    int val; //数据域
    ListNode *next; //指针域
    ListNode(int x) : val(x), next(NULL) {} //构造函数
};


class Solution
{
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        /*
        ListNode* temp = head;
        //while(temp != NULL && temp->next != NULL)
        //if(temp->val == val)
            //return temp->next;
        while(temp && temp->next)
        {
            if(temp->next->val != val){
                //std::cout << 1 << "\n";
                temp = temp->next;
            }
            else{
                //std::cout << 2 << "\n";
                temp->next = temp->next->next;
            }
        }
        return (head->val == val)?head->next : head;*/

        if(head == NULL)
            return NULL;
        ListNode temp_head(0);
        ListNode* temp = &temp_head;
        temp->next = head;
        while(temp->next)
        {
            if(temp->next->val != val)
                temp = temp->next;
            else
                temp->next = temp->next->next;
        }
        return temp->next;

    }
};


int main()
{
    ListNode a(6);
    //ListNode b(2);
    //ListNode c(6);
    //ListNode d(3);
    //ListNode e(4);
   // ListNode f(5);
    //ListNode g(6);

    //a.next = &b;
    //b.next = &c;
    //c.next = &d;
   // d.next = &e;
    //e.next = &f;
    //f.next = &g;
    //e.next = NULL;
    Solution solve;
    //ListNode *head = &a;
    // m = solve.middleNode(&a)
    ListNode* head = solve.removeElements(&a,6);

    std::cout << "删除元素6后的结果为:" << std::endl;
    while(head)
    {
        std::cout << head->val << "\n";
        head = head->next;
    }




}



