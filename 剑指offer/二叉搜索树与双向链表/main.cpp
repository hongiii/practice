#include <iostream>

using namespace std;
//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
//pLastNodeInList指向已经转换好的链表的最后一个节点（值最大的节点）
class Solution {
public:
    void ConvertNode(TreeNode* pRootNode, TreeNode **pLastNodeInList)
    {
        if(pRootNode == nullptr)
            return;
        TreeNode *pCurrent = pRootNode;
        if(pCurrent->left != nullptr)
            ConvertNode(pCurrent->left, pLastNodeInList);

        pCurrent->left = *pLastNodeInList;
        if(*pLastNodeInList != nullptr)
            (*pLastNodeInList)->right = pCurrent;

        *pLastNodeInList = pCurrent;

         if(pCurrent->right != nullptr)
            ConvertNode(pCurrent->right, pLastNodeInList);
    }
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == nullptr)
            return nullptr;
        TreeNode *pLastNodeInList = nullptr;
        ConvertNode(pRootOfTree, &pLastNodeInList);

        TreeNode *pHeadOfLast = pLastNodeInList;
        while(pHeadOfLast != nullptr && pHeadOfLast->left != nullptr)
            pHeadOfLast = pHeadOfLast->left;
        return pHeadOfLast;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
