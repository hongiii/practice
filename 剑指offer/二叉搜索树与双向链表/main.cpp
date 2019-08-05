#include <iostream>

using namespace std;
//����һ�ö��������������ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
//pLastNodeInListָ���Ѿ�ת���õ���������һ���ڵ㣨ֵ���Ľڵ㣩
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
