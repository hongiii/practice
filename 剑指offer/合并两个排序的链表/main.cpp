#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
//输入一个链表，输出该链表中倒数第k个结点。
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(){}
    ListNode(int x): val(x), next(nullptr){}
};
ListNode *insertNode(ListNode **head, int data)
{
    if(head == nullptr)
        return nullptr;
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
    return *head;
}

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
       if(pHead1 == nullptr)
           return pHead2;
        else if(pHead2 == nullptr)
            return pHead1;
        ListNode *mergeNode = nullptr;
        if(pHead1->val < pHead2->val)
        {
            mergeNode = pHead1;
            mergeNode->next = Merge(pHead1->next, pHead2);
        }
        else
        {
            mergeNode = pHead2;
            mergeNode->next = Merge(pHead1, pHead2->next);
        }
        return mergeNode;
    }
void print(ListNode *head)
{
    ListNode *pNode = head;
    while(pNode != nullptr)
    {
        cout << pNode->val << " ";
        pNode = pNode->next;
    }
    cout << endl;
}
int main()
{
    ListNode *test = nullptr;
    test = insertNode(&test, 1);
    insertNode(&test, 3);
    insertNode(&test, 12);
    ListNode *test2 = nullptr;
    insertNode(&test2, 4);
    insertNode(&test2, 4);
    insertNode(&test2, 6);
    insertNode(&test2, 9);
    print(test);
    print(test2);
    ListNode *mergeNode = nullptr;
    mergeNode = Merge(test, test2);
    print(mergeNode);
}
