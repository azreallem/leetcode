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

TreeNode* traversal(vector<int> inorder, vector<int> postorder)
{
	// handle size = 0,1
	if (inorder.size() == 0)
		return NULL;
	TreeNode *root = new TreeNode(postorder[postorder.size() - 1]);
	if (postorder.size() == 1)
		return root;
	
	// find deliver index of inorder
	int deliver;
	for (deliver = 0; deliver < postorder.size() - 1; deliver++)
		if (inorder[deliver] == postorder[postorder.size() - 1])
			break;

	// deliver inorder
	// inorder left:  [begin(), deliver)
	// inorder right: [deliver+1, end())
	vector<int> inorder_left(inorder.begin(), inorder.begin() + deliver);
	vector<int> inorder_right(inorder.begin() + deliver + 1, inorder.end());

	// deliver postorder
	// postorder left:  [begin(), inorder_left.size())
	// postorder right: [begin() + inorder_left.size(), end() - 1)
	vector<int> postorder_left(postorder.begin(), postorder.begin() + inorder_left.size());
	vector<int> postorder_right(postorder.begin() + inorder_left.size(), postorder.end() - 1);

	// recursive
	root->left = traversal(inorder_left, postorder_left);
	root->right = traversal(inorder_right, postorder_right);

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

	vector<int> inorder = {9,3,15,20,7};
	vector<int> postorder = {9,15,7,20,3};
	TreeNode *root2 = traversal(inorder, postorder);
	cout << root2 << endl;
	return 0;
}
