#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == nullptr || pHead2 == nullptr)
            return nullptr;
        unordered_map<ListNode*, int> ump;
        ListNode *pNode = pHead1;
        while(pNode != nullptr)
        {
            ump[pNode] = 1;
            pNode = pNode->next;
        }
        pNode = pHead2;
        while(pNode != nullptr)
        {
            if(ump.find(pNode) != ump.end())
                break;
            pNode = pNode->next;
        }
        return pNode;
    }
};

int main()
{
    return 0;
}
