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

 ListNode* FindKthToTail1(ListNode* pListHead, unsigned int k) {
        if(pListHead == nullptr || k <= 0)
            return nullptr;
        ListNode *pNode = pListHead;
        for(int i = 1; i <= k-1; i++)
        {
            if(pNode->next != nullptr)
                pNode = pNode->next;
            else
                return nullptr;
        }
        ListNode *pBeg = pListHead;
        while(pNode->next != nullptr)
        {
            pBeg = pBeg->next;
            pNode = pNode->next;
        }
        cout << pBeg->val << endl;
        return pBeg;
    }

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
    if(pListHead == nullptr || k <= 0)
        return nullptr;
    ListNode *pNode = pListHead;
    int n = k, frt = 0;
    while(pNode != nullptr)
    {
        pNode = pNode->next;
        n--;
        if(n < 0)
            frt++;
    }
    if(n > 0)
        return nullptr;
    else if(n == 0)
    {
        return pListHead;
    }
    pNode = pListHead;
    while(frt--)
        pNode = pNode->next;
 //   cout << pNode->val << endl;
    return pNode;
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
    insertNode(&test, 12);
    insertNode(&test, 3);
    insertNode(&test, 4);
    insertNode(&test, 7);
    insertNode(&test, 6);
    insertNode(&test, 9);
    print(test);

    ListNode *temp = nullptr;
    temp = FindKthToTail1(test, 7);
    temp = FindKthToTail1(test, 2);
    temp = FindKthToTail1(test, 3);
    temp = FindKthToTail1(test, 4);
    temp = FindKthToTail1(test, 5);
    temp = FindKthToTail1(test, 6);
}
