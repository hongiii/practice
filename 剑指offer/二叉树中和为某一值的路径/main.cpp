#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
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
    vector<vector<int> > res;
    vector<int> vec;
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {

    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
