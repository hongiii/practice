#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
//给定一个单向链表的头指针和一个节点指针，在0(1)时间内删除链表节点
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() {}
    ListNode(int x): val(x), next(nullptr) {}
};

void insertNode(ListNode **head, int data)
{
    if(head == nullptr)
        return;
    ListNode *newNode = new ListNode(data);
    if(*head == nullptr)
        *head = newNode;
    else
    {
        ListNode *pNode = *head;
        while(pNode->next != nullptr)
            pNode = pNode->next;
        pNode->next = newNode;
    }
}
//不够好，假设被删除节点一定在单链表里。
//确定是否在链表中，需要额外的O(n)的时间对链表遍历一遍。
void deleteNode(ListNode **head, ListNode *pToDel)
{
    if(head == nullptr || pToDel == nullptr)
        return;
    //如果被删除的节点不是尾结点
    if(pToDel->next != nullptr)
    {
        ListNode *pNext = pToDel->next;
        pToDel->val = pNext->val;
        pToDel->next = pNext->next;
        delete pNext;
        pNext = nullptr;
    }
    //只有一个节点
    else if(pToDel == *head)
    {
        delete pToDel;
        head = nullptr;
        pToDel = nullptr;
    }
    //被删除的节点是尾结点
    else
    {
        ListNode *tmp = *head;
        while(tmp->next != pToDel)
            tmp = tmp->next;
        tmp->next = nullptr;
        delete tmp;
        tmp = nullptr;
    }
}
void print(ListNode *head)
{
    ListNode *tmp = head;
    while(tmp != nullptr)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main()
{
    ListNode *head = nullptr;
    insertNode(&head, 48);
    insertNode(&head, 1);
    insertNode(&head, 2);
    print(head);
    return 0;
}
