#include <iostream>

using namespace std;

class Solution {
public:
    int getDepth(TreeNode *pRoot)
    {
        if(pRoot == nullptr)
            return 0;
        int left = getDepth(pRoot->left);
        if(left == -1) return -1;
        int right = getDepth(pRoot->right);
        if(right == -1) return -1;

        return abs(left-right) > 1 ? -1 : 1 + max(left, right);
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return getDepth(pRoot) != -1;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
