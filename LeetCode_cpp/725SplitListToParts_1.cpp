#include <iostream>
#include <vector>
#include <set>
#include <list>

struct ListNode
{
    int val; //数据域
    ListNode *next; //指针域
    ListNode(int x) : val(x), next(NULL) {} //构造函数
};


/*
1，遍历链表获取长度 length；
2，length 除以 k 得到每段链表的平均长度 aveLength 和 余数 remainder，remainder 的值就是有多少个长度为 (aveLength + 1) 的子链表排在前面。
    2.1，举个例子帮助理解一下 11 / 3 = 3 余 2： 一共有3段，每段平均3个节点，但是剩下了2个节点，剩下的2个节点不能丢啊，得全部塞到子链表里面去，怎么塞呢？
    2.2，根据题意长的链表排前面，短的链表排后面，所以只有前面的两个子链表一人分担一个多余的节点，如此一来便形成了 4 4 3 的结构。
3，接下来的事儿就比较简单了，按照每个子链表应该的长度[4, 4, 3]去截断给定的链表。
*/
class Solution {
public:
    std::vector<ListNode*> splitListToParts(ListNode* root, int k)
    {
        ListNode* cur = root;
        int len = 0;
        while(cur)
        {
            cur = cur->next;
            len++;
        }

        int aveLen = len / k; //每个子链平均元素个数
        int re  = len % k; //余数
        std::vector<ListNode*> res(k,nullptr);
        ListNode* head = root;
        ListNode* pre = nullptr;
        for(int i = 0;i < k;i++)
        {
            res[i] = head;
            int tmplen = re > 0 ? (aveLen + 1) : aveLen;
            for(int j = 0;j < tmplen; j++)
            {
                pre = head;
                head = head->next;
                pre->next = nullptr;
            }
            //if(pre)
                //pre->next = nullptr;
            if(re)
                re--;
        }
        return res;
    }
};



int main()
{
    ListNode a1(1);
    ListNode a2(2);
    ListNode b1(3);
    //ListNode b2(3);
    //ListNode b3(4);
    //ListNode c1(6);
    //ListNode c2(7);
    //ListNode c3(8);

    a1.next = &a2;
    a2.next = &b1;
    //b1.next = &b2;
    //b2.next = &b3;
    //b3.next = &c1;
    //c1.next = &c2;
    //c1.next = &b2;

    Solution solve;

    std::vector<ListNode*> result = solve.splitListToParts(&a1,5);
    //vector的遍历
    for(int i = 0; i < result.size();i++)
    {
        if(result[i])
            std::cout << result[i]->val;
        else
            std::cout << NULL;
    }



/*
    while(result)
    {
        std::cout << result->val;
        result = result->next;
    }*/


    //std::cout << result->val << result->left->val << result->right->val << std::endl;

}

