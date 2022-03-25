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

TreeNode* delete_node(TreeNode *root, int n)
{
	if (!root)
		return NULL;
	if (root->val == n) {
		// root no left, no right node
		if (!root->left && !root->right) {
			delete root;
			return NULL;
		}
		// root no left,or no right node
		if (root->left && !root->right) {
			TreeNode *parent = root->left;
			delete root;
			return parent;
		}
		if (!root->left && root->right) {
			TreeNode *parent = root->right;
			delete root;
			return parent;
		}
		// root has left and right node
		if (root->left && root->right) {
			TreeNode *parent = root->right;
			TreeNode *cur = root->right;
			// find node->right->left...->left
			while (cur->left) {
				cur = cur->left;
			}
			cur->left = root->left;
			delete root;
			return parent;
		}
	} else if (n < root->val) {
		root->left = delete_node(root->left, n);
	} else if (n > root->val) {
		root->right = delete_node(root->right, n);
	}

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
	cout << delete_node(root, 2) << endl;

	cout << root << endl;
	return 0;
}
