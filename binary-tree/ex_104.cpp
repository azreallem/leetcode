#include <iostream>
#include <queue>

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

int max_deep(TreeNode *root)
{
	queue<TreeNode*> que;
	int deep = 0;
	if (!root)
		return 0;
	que.push(root);

	while(!que.empty()) {
		int size = que.size();
		deep++;
		while(size--) {
			TreeNode *cur = que.front();
			que.pop();
			if (cur->left)
				que.push(cur->left);
			if (cur->right)
				que.push(cur->right);
		}
	
	}

	return deep;
}

int __max_deep(TreeNode *root)
{
	if (!root)
		return 0;
	int left = __max_deep(root->left);
	int right = __max_deep(root->right);
	return 1 + max(left, right);
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


	cout << "max deep: " << __max_deep(root) << endl;
	travel_tree(root);
	return 0;
}
