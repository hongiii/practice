#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <exception>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(){}
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    TreeNode* ConstructCore(vector<int> pre, int startpre, int endpre, vector<int> vin, int startin, int endin)
    {
        if(startpre > endpre || startin > endin)
            return nullptr;
        int rootValue = pre[startpre];
        TreeNode *root = new TreeNode(rootValue);
        for(int i = startin; i <= endin; i++)
        {
            if(rootValue == vin[i])
            {
                root->left = ConstructCore(pre, startpre+1, startpre+i-startin, vin, startin, i-1);
                root->right = ConstructCore(pre, startpre+i-startin+1, endpre, vin, i+1, endin);
                break;
            }
        }
        return root;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int lenpre = pre.size();
        int lenin = vin.size();
        if(lenpre == 0 || lenin == 0) return nullptr;
        TreeNode *root = ConstructCore(pre, 0, lenpre-1, vin, 0, lenin-1);
        return root;
    }
};


int main()
{
    vector<int> vec{1,2,3,4,5,6,7};
    return 0;
}



public class Solution {
    public TreeNode reConstructBinaryTree(int [] pre,int [] in) {
        TreeNode root=reConstructBinaryTree(pre,0,pre.length-1,in,0,in.length-1);
        return root;
    }
    //前序遍历{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}
    private TreeNode reConstructBinaryTree(int [] pre,int startPre,int endPre,int [] in,int startIn,int endIn) {

        if(startPre>endPre||startIn>endIn)
            return null;
        TreeNode root=new TreeNode(pre[startPre]);

        for(int i=startIn;i<=endIn;i++)
            if(in[i]==pre[startPre]){
                root.left=reConstructBinaryTree(pre,startPre+1,startPre+i-startIn,in,startIn,i-1);
                root.right=reConstructBinaryTree(pre,i-startIn+startPre+1,endPre,in,i+1,endIn);
                      break;
            }

        return root;
    }
}
