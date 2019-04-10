#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

struct ListNode
{
    int val; //������
    ListNode *next; //ָ����
    ListNode(int x) : val(x), next(NULL) {} //���캯��
};

//�����ѡ���С������,������ÿ�������Լ��ţ�������������
////�����㷨�����������
bool cmp(const ListNode* a, const ListNode* b)
{
    return a->val < b->val;
}
class Solution
{
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists)
    {
        std::vector<ListNode*> node_vec;
        for(int i = 0; i < lists.size(); i++)
        {
            ListNode* head = lists[i];//�����Ǵ��±�1��ʼ��
            while(head)
            {
                node_vec.push_back(head);
                head = head->next;
            }
        }
        if(node_vec.size() == 0)
            return NULL;
        std::sort(node_vec.begin(),node_vec.end(),cmp);
        for(int i = 1; i < node_vec.size(); i++)
            node_vec[i - 1]->next = node_vec[i];
        node_vec[node_vec.size() - 1]->next = NULL;
        return node_vec[0];
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



