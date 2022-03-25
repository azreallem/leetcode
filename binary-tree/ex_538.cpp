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

// right, mid, left
int sum;
void traversal_tree(TreeNode *root)
{
	if (!root)
		return;
	
	traversal_tree(root->right);
	root->val += sum;
	sum = root->val;
	traversal_tree(root->left);

	return ;
}

TreeNode* sum_tree(TreeNode *root)
{
	sum = 0;
	traversal_tree(root);
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
	cout << sum_tree(root) << endl;
	cout << root << endl;
	return 0;
}
