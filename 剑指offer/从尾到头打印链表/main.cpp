#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() {}
    ListNode(int x) : val(x), next(NULL) {}
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
void deleteNode(ListNode **head, int target)
{
    if(head == nullptr || *head == nullptr)
        return;
    ListNode *toBeDelete = nullptr;
    if((*head)->val == target)
    {
        toBeDelete = *head;
        *head = (*head)->next;
    }
    else
    {
        ListNode *pDelBefore = *head;
        while(pDelBefore->next != nullptr && pDelBefore->next->val != target)
        {
            pDelBefore = pDelBefore->next;
        }
        if(pDelBefore->next != nullptr && pDelBefore->next->val == target)
        {
            toBeDelete = pDelBefore->next;
            pDelBefore->next = pDelBefore->next->next;
        }
        else
        {
            printf("don't exist the target.\n");
        }
    }
    if(toBeDelete != nullptr)
    {
        delete toBeDelete;
        toBeDelete = nullptr;
    }
}
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> vec;
        if(head == NULL)
            return vec;
        ListNode *temp = head;
        stack<ListNode*> sta;
        while(temp != NULL)
        {
            sta.push(temp);
            temp = temp->next;
        }
        while(!sta.empty())
        {
            int data = (sta.top())->val;
            vec.push_back(data);
            sta.pop();
        }
        return vec;
    }
    void RevprintListFromTailToHead(ListNode* head) {
        if(head != nullptr)
        {
            if(head->next != nullptr)
                RevprintListFromTailToHead(head->next);
            printf("test: %d\n", head->val);
        }
    }
};

int main()
{
    ListNode *res = nullptr;
    insertNode(&res, 1);
    insertNode(&res, 3);
    insertNode(&res, 0);
    ListNode *tmp = res;
    while(tmp != nullptr)
    {
        cout << tmp->val << endl;
        tmp = tmp->next;
    }
//    deleteNode(&res, 2);
//    deleteNode(&res, 3);
    tmp = res;
    while(tmp != nullptr)
    {
        cout << tmp->val << endl;
        tmp = tmp->next;
    }

    Solution s;
    vector<int> vec = s.printListFromTailToHead(res);
    vector<int>::iterator itr;
    for(itr = vec.begin(); itr != vec.end(); itr++)
    {
        cout << *itr << endl;
    }

    s.RevprintListFromTailToHead(res);

    return 0;
}
