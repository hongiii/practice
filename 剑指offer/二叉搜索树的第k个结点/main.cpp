#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    TreeNode* KthNodeCore(TreeNode* pRoot, int &k)
    {
        TreeNode *tNode = nullptr;
        if(pRoot != nullptr && pRoot->left != nullptr)
            tNode = KthNodeCore(pRoot->left, k);
        if(tNode == nullptr)
        {
            if(k == 1)
                tNode = pRoot;
            --k;
        }
        if(tNode == nullptr && pRoot->right != nullptr)
            tNode = KthNodeCore(pRoot->right, k);

        return tNode;
    }
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot == nullptr || k <= 0)
            return nullptr;
        return KthNodeCore(pRoot, k);
    }


};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
