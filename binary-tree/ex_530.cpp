#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
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

vector<int> vec;
void __find_min_abs(TreeNode *root)
{
	if (!root)
		return ;
	if (root->left)
		__find_min_abs(root->left);
	vec.push_back(root->val);
	if (root->right)
		__find_min_abs(root->right);
	return ;
}

int find_min_abs(TreeNode *root)
{
	int t = INT_MAX;
	__find_min_abs(root);
	for (int i = 1; i < vec.size(); i++) {
		t = min(abs(vec[i] - vec[i-1]), t);
	}
	return t;
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
	cout << find_min_abs(root) << endl;

	cout << root << endl;
	return 0;
}
