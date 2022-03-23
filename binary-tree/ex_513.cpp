#include <iostream>
#include <queue>

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

int maxLen = 0;
int maxValue = 0;
void __left_node(TreeNode *root, int deepth)
{
	if (!root)
		return;
	if (!root->left && !root->right) {
		if (deepth > maxLen) {
			maxLen = deepth;
			maxValue = root->val;
		}
		else
			return;
	}
	if (root->left) {
		deepth++;
		__left_node(root->left, deepth);
		deepth--;
	}
	if (root->right) {
		deepth++;
		__left_node(root->right, deepth);
		deepth--;
	}
	return;
}

int _left_node(TreeNode *root)
{
	maxLen = 0;
	maxValue = 0;
	__left_node(root, 1);
	return maxValue;
}

/* level-order travesal */
int left_node(TreeNode *root)
{
	int max_value = 0;
	queue<TreeNode*> que;
	if (!root)
		return 0;
	que.push(root);

	while (!que.empty()) {
		int size = que.size();
		TreeNode *cur = que.front();
		max_value = cur->val;
		while (size--) {
			cur = que.front();
			que.pop();
			if (cur->left)
				que.push(cur->left);
			if (cur->right)
				que.push(cur->right);
		}
	
	}
	return max_value;
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

	cout << left_node(root) << endl;

	cout << root << endl;
	return 0;
}
