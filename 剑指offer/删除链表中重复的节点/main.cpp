#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
//ɾ���������ظ��Ľ��
//��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣 ���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
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
class Solution {
public:
    ListNode* deleteD(ListNode* pHead) //ֻȥ�ص�д��
    {
        if(pHead == nullptr || pHead->next == nullptr)
            return pHead;
        ListNode *newNode = new ListNode(0);
        newNode->next = pHead;
        ListNode *pNode = pHead;
        while(pNode->next != nullptr)
        {
            if(pNode->val == pNode->next->val)
                pNode->next = pNode->next->next;
            else
                pNode = pNode->next;
        }
        return newNode->next;
    }
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == nullptr || pHead->next == nullptr)
            return pHead;
        ListNode *newNode = new ListNode(0);
        newNode->next = pHead;
        ListNode *pre = newNode;
        ListNode *last = newNode->next;
        while(last != nullptr)
        {
            if(last->next != nullptr && last->next->val == last->val)
            {
                while(last->next != nullptr && last->next->val == last->val)
                    last = last->next;
                pre->next = last->next;
                last = last->next;
            }
            else
            {
                pre = pre->next;
                last = last->next;
            }
        }
        return newNode->next;
    }
};
int main()
{
    ListNode *head = nullptr;
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 4);insertNode(&head, 5);
  //  insertNode(&head, 5);
  //  insertNode(&head, 6);
    print(head);
    Solution s;
    head = s.deleteDuplication(head);
 //   head = s.deleteD(head);
    print(head);
    return 0;
}
