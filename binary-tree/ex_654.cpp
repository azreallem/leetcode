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

TreeNode* build_max_tree(vector<int> vec_tree)
{
	if (vec_tree.size() == 0)
		return NULL;
	if (vec_tree.size() == 1)
		return new TreeNode(vec_tree[0]);
	
	// 1. find max value and index
	int max_val = vec_tree[0]; 
	int max_index = 0;
	int tmp = 0;
	for (auto x : vec_tree) {
		if (x > max_val) {
			max_val = x;
			max_index = tmp;
		}
		tmp++;
	}
	TreeNode *root = new TreeNode(max_val);
	
	// 2. delver vector
	vector<int> left(begin(vec_tree), begin(vec_tree) + max_index); //[0,max_index)
	vector<int> right(begin(vec_tree) + max_index + 1, end(vec_tree)); //[max_index+1,end)

	// 3. curisive
	root->left = build_max_tree(left);
	root->right = build_max_tree(right);
	
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
	/*        6
	 *    3      5
	 *     2    0
	 *      1
	 * */
	vector<int> vec_tree = {3,2,1,6,0,5};
	

	cout << build_max_tree(vec_tree) << endl;
	return 0;
}
