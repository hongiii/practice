#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
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
            vector<int> vec;
            if(pRoot == nullptr)
                return res;
            queue<TreeNode*> qu;
            qu.push(pRoot);
            TreeNode *tNode = nullptr;
            while(!qu.empty())
            {
                int lo = 0, len = qu.size();
                while(lo++ < len)
                {
                    tNode = qu.front();
                    vec.push_back(tNode->val);
                    qu.pop();
                    if(tNode->left)
                        qu.push(tNode->left);
                    if(tNode->right)
                        qu.push(tNode->right);
                }
                res.push_back(vec);
                vec.clear();
            }
            return res;
        }

};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
