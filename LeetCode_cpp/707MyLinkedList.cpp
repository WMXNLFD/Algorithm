#include <iostream>
#include <vector>
#include <set>
/*
struct ListNode
{
    int val; //数据域
    ListNode *next; //指针域
    ListNode(int x) : val(x), next(NULL) {} //构造函数
};
*/


class MyLinkedList {
private:
    struct ListNode
    {
        int val; //数据域
        ListNode *next; //指针域
        ListNode(int x) : val(x), next(NULL) {} //构造函数
    };


    ListNode* head; //头指针
    ListNode* tail; //尾指针
    int size;

public:
    /** Initialize your data structure here. */
    MyLinkedList()
    {
        head = new ListNode(0);
        tail = head;
        size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        if(index < 0 || index > size - 1)
            return -1;
        ListNode* cur = head->next;
        while(index--)
            cur = cur->next;
        std::cout << cur->val <<"\n";
        return cur->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        ListNode* newhead = new ListNode(val);
        newhead->next = head->next;
        head->next = newhead;
        size++;

    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        tail = head;
        while(tail->next !=NULL)
            tail = tail->next;//找到列表尾部的元素
        ListNode* newtail = new ListNode(val);
        tail->next = newtail;
        newtail->next = NULL;//**********
        size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if(index < 0 || index > size)//注意！！！这里为size，可以查在单个元素后面
            return ;
        ListNode* tmp = head;
        ListNode* add = new ListNode(val);
        for(int i = 0;i < index;i++)
            tmp = tmp->next;
        add->next = tmp->next;
        tmp->next = add;
        size++;

    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if(index < 0 || index > size - 1)
            return ;
        ListNode* tmp = head;
        for(int i = 0;i < index;i++)
            tmp = tmp->next;
        ListNode* del = tmp->next;
        tmp->next = del->next;
        del->next = NULL;
        size--;
    }

    //打印节点的函数
    void print()
    {
        int i = size;
        ListNode* cur = head->next;
        while(i--)
        {
            std::cout << cur->val ;
            cur = cur->next;
        }
        std::cout << "\n执行print" << std::endl;
    }



};



int main()
{
    MyLinkedList *linkedList = new MyLinkedList();

    linkedList->addAtHead(1);
    //linkedList->addAtHead(2);
    //linkedList->addAtHead(3);
    //linkedList->addAtHead(4);
    //linkedList->addAtTail(3);
    //linkedList->addAtTail(6);
    //linkedList->addAtTail(7);
    //linkedList->get(1);
    linkedList->addAtIndex(1,2);
    //linkedList->get(1);
    //linkedList->deleteAtIndex(1);
    //linkedList->get(1);
    //linkedList->get(0);
    //linkedList->get(2);

    linkedList->print();





}

