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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head)
    {
        std::vector<int> list;
        ListNode* p = head;
        while(p)
        {
            list.push_back(p->val);
            p = p->next;
        }
        return pre(0,list.size() - 1,list);
    }
                                        //这里是取址符号
    TreeNode* pre(int left, int right, std::vector<int> &list)
    {
        if(left > right)
            return NULL;
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(list[mid]);
        root->left = pre(left, mid - 1, list);
        root->right = pre(mid + 1, right, list);
        return root;
    }
};

void printTree(TreeNode* r)
{
    if(r)
    {
        std::cout << r->val <<" ";
        printTree(r->left);
        printTree(r->right);
    }
}

int main()
{
    ListNode a1(-10);
    ListNode a2(-3);
    ListNode b1(0);
    ListNode b2(5);
    ListNode b3(9);
    //ListNode c1(6);
    //ListNode c2(7);
    //ListNode c3(8);

    a1.next = &a2;
    a2.next = &b1;
    b1.next = &b2;
    b2.next = &b3;
    //b3.next = &c1;
    //c1.next = &c2;
    //c1.next = &b2;

    Solution solve;

    TreeNode* result = solve.sortedListToBST(&a1);
    printTree(result);

    //std::cout << result->val << result->left->val << result->right->val << std::endl;



}

