#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int v): val(v), left(NULL), right(NULL) {};
};

namespace std {
	ostream& operator<<(ostream &os, TreeNode *root)
	{
		if (!root)
			return os;
		os << root->val << "\t";
		if (root->left)
			operator<<(os, root->left);
		if (root->right)
			operator<<(os, root->right);
		return os;
	}
}

bool has_sum_path(TreeNode *root, int sum, int cur_sum)
{
	if (!root)
		return false;
	if (!root->left && !root->right) {
		if (cur_sum + root->val == sum) {
			return true;
		}
	}
	if (root->left) {
		if(has_sum_path(root->left, sum, cur_sum + root->val))
			return true;
	}
	if (root->right) {
		if(has_sum_path(root->right, sum, cur_sum + root->val))
			return true;
	}
	return false;
}

int main()
{
	int a[] = {1,2,3,4,5,6,7};
	int n = 0;
	TreeNode *root = new TreeNode(a[0]);
	TreeNode *node1 = new TreeNode(a[1]);
	TreeNode *node2 = new TreeNode(a[2]);
	TreeNode *node3 = new TreeNode(a[3]);
	TreeNode *node4 = new TreeNode(a[4]);
	TreeNode *node5 = new TreeNode(a[5]);
	TreeNode *node6 = new TreeNode(a[6]);
	root->left = node1;
	root->right = node2;
	root->left->left = node3;
	root->left->right = node4;
	root->right->left = node5;
	root->right->right = node6;
	/*        1
	 *    2      3
	 *  4   5  6   7
	 * */
	cout << has_sum_path(root, 20, 0) << endl;


	cout << root << endl;
	return 0;
}
