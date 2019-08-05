#include <iostream>
#include <queue>
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> res;
        if(root == nullptr)
            return res;
        que.push(root);
        while(!que.empty())
        {
            TreeNode *top = que.front();
            res.push_back(top->val);
            if(top->left)
                que.push(top->left);
            if(top->right)
                que.push(top->right);
            que.pop();
        }
        return res;
    }
    //分行打印每一层
    void PrintFromTopToBottom2(TreeNode* root) {
        if(root == nullptr)
            return;
        queue<TreeNode*> que;
        que.push(root);
        int tobeprint = 1;
        int nextlevel = 0;
        while(!que.empty())
        {
            TreeNode *top = que.front();
            printf("%d ", top->val);
            if(top->left)
            {
                que.push(top->left);
                nextlevel++;
            }
            if(top->right)
            {
                que.push(top->right);
                nextlevel++;
            }
            --tobeprint;
            if(tobeprint == 0)
            {
                tobeprint = nextlevel;
                nextlevel = 0;
                printf("\n");
            }
            que.pop();
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
