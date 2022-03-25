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

TreeNode* insert_val(TreeNode *root, int n)
{
	if (!root) {
		TreeNode *node = new TreeNode(n);
		return node;
	}
	if (n < root->val)
		root->left = insert_val(root->left, n);
	if (n > root->val)
		root->right = insert_val(root->right, n);
	return root;

}

TreeNode* insert_val2(TreeNode *root, int n)
{
	if (!root) {
		TreeNode *node = new TreeNode(n);
		return node;
	}
	TreeNode *cur = root;
	TreeNode *parent;
	while (cur) {
		parent = cur;
		if (n < cur->val)
			cur = cur->left;
		else if (n > cur->val)
			cur = cur->right;
	}
	TreeNode *node = new TreeNode(n);
	if (n < parent->val)
		parent->left = node;
	if (n > parent->val)
		parent->right = node;
	return root;

}

int main()
{
	int a[] = {4,2,7,1,3};
	TreeNode *root = new TreeNode(a[0]);
	TreeNode *node1 = new TreeNode(a[1]);
	TreeNode *node2 = new TreeNode(a[2]);
	TreeNode *node3 = new TreeNode(a[3]);
	TreeNode *node4 = new TreeNode(a[4]);
	root->left = node1;
	root->right = node2;
	root->left->left = node3;
	root->left->right = node4;
	/*        4
	 *    2      7
	 *  1   3    
	 * */
	cout << insert_val2(root, 5) << endl;

	cout << root << endl;
	return 0;
}
