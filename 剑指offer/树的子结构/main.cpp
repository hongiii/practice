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
    bool archEqual(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot2 == nullptr)
            return true;
        if(pRoot1 == nullptr)
            return false;
        if(pRoot1->val == pRoot2->val)
            return archEqual(pRoot1->left, pRoot2->left)
                && archEqual(pRoot1->right, pRoot2->right);
        else
            return false;
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool res = false;
        if(pRoot1 != nullptr && pRoot2 != nullptr)
        {
            if(pRoot1->val == pRoot2->val)
                res = archEqual(pRoot1, pRoot2);
            if(!res)
                res = HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
        }
        return res;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
