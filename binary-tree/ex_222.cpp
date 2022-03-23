#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int v): val(v), left(NULL), right(NULL) {};
};

namespace std {
	ostream& operator<<(ostream &os, const TreeNode *root)
	{
		if (!root)
			return os;
		os << root->val << ", ";
		if (root->left)
			operator<<(os, root->left);
		if (root->right)
			operator<<(os, root->right);
	
	}
}


int _count_node(TreeNode *root)
{
	if (!root)
		return 0;
	stack<TreeNode*> st;
	st.push(root);
	int count = 0;

	// mid, left, right
	while(!st.empty()) {
		count++;
		TreeNode *cur = st.top();
		st.pop();
		if (cur->right)
			st.push(cur->right);
		if (cur->left)
			st.push(cur->left);
	}

	return count;
}

int count_node(TreeNode *root)
{
	if (!root)
		return 0;
	TreeNode *left_node = root->left;
	TreeNode *right_node = root->right;
	int left_height = 0;
	int right_height = 0;

	while (left_node) {
		left_node = left_node->left;
		left_height++;
	}
	while (right_node) {
		right_node = right_node->right;
		right_height++;
	}
	
	if (left_height == right_height)
		return (2 << left_height) - 1;
	else
		return count_node(root->left) + count_node(root->right) + 1;
}


int main()
{
	int a[] = {1,2,3,4,5,6,7};
	int n = 0;
	TreeNode *root = new TreeNode(a[0]);
	TreeNode *node1 = new TreeNode(a[1]);
	TreeNode *node2 = new TreeNode(a[2]);
	TreeNode *node3 = new TreeNode(a[3]);
	root->left = node1;
	root->right = node2;
	root->left->left = node3;
	/*        1
	 *    2      3
	 *  4
	 * */

	cout << "count node: " << count_node(root) << endl;
	cout << root;
	return 0;
}
