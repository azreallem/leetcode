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


int res;
/* 0: no cover
 * 1: grammer
 * 2: has cover
 * */
int traveral_tree(TreeNode *root)
{
	if (root == NULL)
		return 2;
	int left = traveral_tree(root->left);
	int right = traveral_tree(root->right);

	if (left == 2 && right == 2)
		return 0;
	else if (left == 0 || right == 0) {
		res++;
		return 1;
	} else
		return 2;
}


int minCameraCover(TreeNode* root)
{
	res = 0;
	if (traveral_tree(root) == 0)
		res++;
	return res;
}

int main()
{
	int a[] = {1,2,3,4,5,6,7};
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
	cout << root << endl;
	cout << minCameraCover(root) << endl;
	return 0;
}
