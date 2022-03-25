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

TreeNode* decrease_node(TreeNode *root, int low, int height)
{
	if (!root)
		return NULL;
	if (root->val < low)
		return decrease_node(root->right, low, height);
	if (root->val > height)
		return decrease_node(root->left, low ,height);
	root->left = decrease_node(root->left, low ,height);
	root->right = decrease_node(root->right, low ,height);
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
	cout << decrease_node(root,2,4) << endl;

	cout << root << endl;
	return 0;
}
