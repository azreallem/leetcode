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


TreeNode* merge_tree(TreeNode *t1, TreeNode *t2)
{
	if (t1 == NULL)
		return t2;
	if (t2 == NULL)
		return t1;
	t1->val += t2->val;
	t1->left = merge_tree(t1->left, t2->left);
	t1->right = merge_tree(t1->right,t2->right);
	return t1;
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
	int a1[] = {2,4,5,6,7,8,9};
	TreeNode *root1 = new TreeNode(a1[0]);
	TreeNode *node11 = new TreeNode(a1[1]);
	TreeNode *node12 = new TreeNode(a1[2]);
	TreeNode *node13 = new TreeNode(a1[3]);
	TreeNode *node14 = new TreeNode(a1[4]);
	TreeNode *node15 = new TreeNode(a1[5]);
	TreeNode *node16 = new TreeNode(a1[6]);
	root1->left = node11;
	root1->right = node12;
	root1->left->left = node13;
	root1->left->right = node14;
	root1->right->left = node15;
	root1->right->right = node16;
	/*        1
	 *    2      3
	 *  4   5  6   7
	 * */
	TreeNode *root2 = merge_tree(root, root1);

	cout << root2 << endl;
	return 0;
}
