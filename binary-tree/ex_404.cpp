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

void __get_left_node_sum(TreeNode *root, int &sum)
{
	if (!root)
		return ;
	
	if (root->left && !root->left->left && !root->left->right)
		sum += root->left->val;

	if (root->left)
		__get_left_node_sum(root->left, sum);
	if (root->right)
		__get_left_node_sum(root->right, sum);
}

int get_left_node_sum(TreeNode *root)
{
	int sum = 0;
	__get_left_node_sum(root, sum);
	return sum;
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

	cout << get_left_node_sum(root) << endl;
	cout << root << endl;
	return 0;
}
