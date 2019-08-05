#include <iostream>
#include <vector>
#include <stack>
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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > res;
        if(pRoot == nullptr) return res;
        int cur = 0;
        int next = 1;
        stack<TreeNode*> s[2];
        s[cur].push(pRoot);
        vector<int> vec;
        while(!s[cur].empty() || !s[next].empty())
        {
            TreeNode *pTop = s[cur].top();
            s[cur].pop();
            vec.push_back(pTop->val);
            if(cur == 0)
            {
                if(pTop->left != nullptr) s[next].push(pTop->left);
                if(pTop->right != nullptr) s[next].push(pTop->right);
            }
            else
            {
                if(pTop->right != nullptr) s[next].push(pTop->right);
                if(pTop->left != nullptr) s[next].push(pTop->left);
            }
            if(s[cur].empty())
            {
                res.push_back(vec);
                vec.clear();
                cur = 1 - cur;
                next = 1 - next;
            }
        }
       return res;
    }

};

int main()
{
    return 0;
}
