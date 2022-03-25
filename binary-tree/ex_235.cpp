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

TreeNode* find_node(TreeNode *root, TreeNode *p, TreeNode *q)
{
	if (!root)
		return NULL;
	if (root->val > p->val && root->val > q->val) {
		TreeNode *left = find_node(root->left, p ,q);
		if (left)
			return left;
	}
	if (root->val < p->val && root->val < q->val) {
		TreeNode *right = find_node(root->right, p ,q);
		if (right)
			return right;
	}
	return root;
}

TreeNode* find_node2(TreeNode *root, TreeNode *p, TreeNode *q)
{
	while (root) {
		if (root->val > p->val && root->val > q->val) {
			root = root->left;
		} else if (root->val < p->val && root->val < q->val) {
			root = root->right;
		} else
			return root;
	}
	return NULL;
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

	cout << find_node2(root, node3, node4) << endl;
	cout << root << endl;
	return 0;
}
