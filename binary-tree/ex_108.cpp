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

TreeNode* create_tree(vector<int> vec, int left, int right)
{
	if (left > right)
		return NULL;
	int mid = left + (right - left) / 2;
	TreeNode *root = new TreeNode(vec[mid]);
	root->left = create_tree(vec, left, mid - 1);
	root->right = create_tree(vec, mid + 1, right);
	return root;
}

int main()
{
	vector<int> a = {4,7,10,33};
	cout << create_tree(a, 0, a.size() - 1) << endl;
	return 0;
}
