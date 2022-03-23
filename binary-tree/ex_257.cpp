#include <iostream>
#include <iterator>
#include <vector>
#include <string>
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

void __get_path(TreeNode *root, vector<int> &path, vector<string> &res)
{
	// mid, left, right
	if (!root)
		return;

	path.push_back(root->val);
	// find leaf node
	if (!root->left && !root->right) {
		string tmp;
		for (auto x : path)
			tmp += to_string(x) + "->";
		tmp.resize(tmp.size() - 2);
		res.push_back(tmp);
		return ;
	}
	
	if (root->left) {
		__get_path(root->left, path, res);
		path.pop_back();
	}
	if (root->right) {
		__get_path(root->right, path, res);
		path.pop_back();
	}
}

vector<string> get_path(TreeNode *root)
{
	vector<int> path;
	vector<string> res;
	__get_path(root, path, res);
	return res;
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

	vector<string> res = get_path(root);
	copy(begin(res), end(res), ostream_iterator<string>{cout,"\n"});
	//cout << root << endl;
	return 0;
}
