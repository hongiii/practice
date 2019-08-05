#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
//����һ�����������ͷָ���һ���ڵ�ָ�룬��0(1)ʱ����ɾ������ڵ�
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
//�����ã����豻ɾ���ڵ�һ���ڵ������
//ȷ���Ƿ��������У���Ҫ�����O(n)��ʱ����������һ�顣
void deleteNode(ListNode **head, ListNode *pToDel)
{
    if(head == nullptr || pToDel == nullptr)
        return;
    //�����ɾ���Ľڵ㲻��β���
    if(pToDel->next != nullptr)
    {
        ListNode *pNext = pToDel->next;
        pToDel->val = pNext->val;
        pToDel->next = pNext->next;
        delete pNext;
        pNext = nullptr;
    }
    //ֻ��һ���ڵ�
    else if(pToDel == *head)
    {
        delete pToDel;
        head = nullptr;
        pToDel = nullptr;
    }
    //��ɾ���Ľڵ���β���
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
