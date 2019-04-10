#include <iostream>
#include <vector>
#include <set>
#include <list>

struct ListNode
{
    int val; //������
    ListNode *next; //ָ����
    ListNode(int x) : val(x), next(NULL) {} //���캯��
};


/*
1�����������ȡ���� length��
2��length ���� k �õ�ÿ�������ƽ������ aveLength �� ���� remainder��remainder ��ֵ�����ж��ٸ�����Ϊ (aveLength + 1) ������������ǰ�档
    2.1���ٸ����Ӱ������һ�� 11 / 3 = 3 �� 2�� һ����3�Σ�ÿ��ƽ��3���ڵ㣬����ʣ����2���ڵ㣬ʣ�µ�2���ڵ㲻�ܶ�������ȫ����������������ȥ����ô���أ�
    2.2���������ⳤ��������ǰ�棬�̵������ź��棬����ֻ��ǰ�������������һ�˷ֵ�һ������Ľڵ㣬���һ�����γ��� 4 4 3 �Ľṹ��
3�����������¶��ͱȽϼ��ˣ�����ÿ��������Ӧ�õĳ���[4, 4, 3]ȥ�ضϸ���������
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

        int aveLen = len / k; //ÿ������ƽ��Ԫ�ظ���
        int re  = len % k; //����
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
    //vector�ı���
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

