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

TreeNode* find_near_node(TreeNode *root, TreeNode *p, TreeNode *q)
{
	if (!root || root == p || root == q)
		return root;
	TreeNode *left = find_near_node(root->left, p, q);
	TreeNode *right = find_near_node(root->right, p, q);
	if (left && right)
		return root;
	if (!left && right)
		return right;
	if (left && !right)
		return left;
	return NULL;
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
	cout << find_near_node(root, node5, node6) << endl;

	cout << root << endl;
	return 0;
}
