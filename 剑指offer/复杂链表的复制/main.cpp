#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    void firststep(RandomListNode* pHead)
    {
        if(pHead == nullptr)
            return;
        RandomListNode *pNode = pHead;
        while(pNode != nullptr)
        {
            RandomListNode *clone = new RandomListNode(pNode->label);
            clone->next = pNode->next;
            clone->random = nullptr;
            pNode->next = clone;
            pNode = clone->next;
        }
    }

    void connectRandom(RandomListNode* pHead)
    {
        if(pHead == nullptr)
            return;
        RandomListNode *pNode = pHead;
        RandomListNode *clone = nullptr;
        while(pNode != nullptr)
        {
            clone = pNode->next;
            if(pNode->random != nullptr)
                clone->random = pNode->random->next;
            pNode = clone->next;
        }
    }

    RandomListNode* reconnect(RandomListNode* pHead)
    {
        if(pHead == nullptr)
            return nullptr;
        RandomListNode* pNode = pHead;
        RandomListNode* clone = nullptr;
        RandomListNode* pClone = nullptr;
        if(pNode != nullptr)
        {
            clone = pClone = pNode->next;
            pNode->next = clone->next;
            pNode = pNode->next;
        }
        while(pNode != nullptr)
        {
            clone->next = pNode->next;
            clone = clone->next;
            pNode->next = clone->next;
            pNode = pNode->next;
        }
        return pClone;
    }

    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == nullptr)
            return nullptr;
        firststep(pHead);
        connectRandom(pHead);
        return reconnect(pHead);
    }
};

//class Solution {
//public:
//    unordered_map<RandomListNode*, RandomListNode*> ump;
//    RandomListNode* Clone(RandomListNode* pHead)
//    {
//        if(pHead == nullptr)
//            return nullptr;
//        RandomListNode *tNode = new RandomListNode(pHead->label);
//        RandomListNode *resHead = tNode;
//        RandomListNode *pHead1 = pHead;
//        while(pHead1 != nullptr)
//        {
//            if(tNode->next != nullptr)
//                tNode->next = new RandomListNode(tNode->next->label);
//            else
//                tNode->next = nullptr;
//            ump[pHead1] = tNode;
//            pHead1 = pHead1->next;
//            tNode = tNode->next;
//        }
//        pHead1 = pHead;
//        tNode = resHead;
//        while(pHead1 != nullptr)
//        {
//            tNode->random = ump[pHead1->random];
//            tNode = tNode->next;
//            pHead1 = pHead1->next;
//        }
//        return resHead;
//    }
//};



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
