#include <iostream>
#include <vector>
#include <algorithm>

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

// error:must  all left < root , all right > root
bool is_search_tree(TreeNode *root)
{
	bool left, right;
	if (!root)
		return true;
	if (root->left && root->val > root->left->val) {
		left = is_search_tree(root->left);
	}
	if (root->right && root->val < root->right->val) {
		right = is_search_tree(root->right);
	}
	if (root->left && root->val <= root->left->val && \
	    root->right && root->val >= root->right->val) 
		return false;
	return left && right;
}

vector<int> vec;
void get_vec(TreeNode *root)
{
	if (!root)
		return;
	if (root->left)
		get_vec(root->left);
	vec.push_back(root->val);
	if (root->right)
		get_vec(root->right);
	return;
}

bool is_binary_search_tree(TreeNode *root)
{
	vec.clear();
	get_vec(root);
	int max = vec[0];
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i] > max)
			max = vec[i];
		else
			return false;
	}
	return true;
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
	cout << is_binary_search_tree(root) << endl;
	cout << root << endl;
	return 0;
}
