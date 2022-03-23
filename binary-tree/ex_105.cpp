#include <iostream>
#include <vector>

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

TreeNode* traversal(vector<int> preorder, vector<int> inorder)
{
	if (inorder.size() == 0)
		return NULL;
	TreeNode *root = new TreeNode(preorder[0]);
	if (inorder.size() == 1)
		return root;

	// find deliver's index of inorder
	int deliver;
	for (deliver = 0; deliver < inorder.size() - 1; deliver++)
		if (inorder[deliver] == preorder[0])
			break;

	// deliver left, right
	vector<int> inorder_left(begin(inorder), begin(inorder) + deliver); //[0, deliver)
	vector<int> inorder_right(begin(inorder) + deliver + 1, end(inorder)); // [deliver,end)
	vector<int> preorder_left(begin(preorder) + 1, begin(preorder) + 1 + inorder_left.size());//[1,2)
	vector<int> preorder_right(begin(preorder) + 1 + inorder_left.size(), end(preorder));//[2,end)
	
	root->left = traversal(preorder_left, inorder_left);
	root->right = traversal(preorder_right, inorder_right);

	return root;
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
	vector<int> preorder = {3,9,20,15,7};
	vector<int> inorder = {9,3,15,20,7};
	TreeNode *root2 = traversal(preorder, inorder);

	cout << root2 << endl;

	return 0;
}
