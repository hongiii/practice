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

ListNode* ReverseList(ListNode* pHead) {
        if(pHead == nullptr)
            return nullptr;
        if(pHead->next == nullptr)
            return pHead;
        ListNode *reverseHead = nullptr;
        ListNode *preNode = nullptr;
        ListNode *pNode = pHead;
        ListNode *nextNode = pHead;
        while(pNode != nullptr)
        {
            nextNode = pNode->next;
            if(pNode->next == nullptr)
                reverseHead = pNode;
            pNode->next = preNode;
            preNode = pNode;
            pNode = nextNode;
        }
        return reverseHead;
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
    test = ReverseList(test);
    print(test);
}
