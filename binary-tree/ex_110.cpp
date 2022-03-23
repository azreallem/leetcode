#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int v): val(v), left(NULL), right(NULL) {};
};

void travel_tree(TreeNode *root)
{
	if (!root)
		return ;
	cout << root->val << '\t';
	if (root->left)
		travel_tree(root->left);
	if (root->right)
		travel_tree(root->right);
}

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


int get_height(TreeNode *root)
{
	if (!root)
		return 0;

	int left_height = get_height(root->left);
	if (left_height == -1)
		return -1;

	int right_height = get_height(root->right);
	if (right_height == -1)
		return -1;

	return abs(left_height - right_height) <= 1 ? \
	           1 + max(left_height, right_height) : -1;
}

bool is_balance_tree(TreeNode *root)
{
	return get_height(root) == -1 ? false : true;
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

	cout << is_balance_tree(root) << endl;

	cout << root;
	return 0;
}
