#include <iostream>

using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == nullptr)
            return nullptr;
        if(pNode->left != nullptr && pNode->right == nullptr)
            return pNode->next;
        TreeLinkNode* tNode = pNode;
        if(tNode->right != nullptr)
        {
            tNode = tNode->right;
            while(tNode->left != nullptr)
            {
                tNode = tNode->left;
            }
            return tNode;
        }
        if(tNode->left == nullptr && tNode->right == nullptr)
        {
            while(tNode->next != nullptr && tNode != tNode->next->left)
            {
                 tNode = tNode->next;
            }
            return tNode->next;
        }
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
