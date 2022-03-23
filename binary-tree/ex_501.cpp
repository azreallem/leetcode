#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <iterator>

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

map<int, int> m;
void traversal_tree(TreeNode *root)
{
	if (!root)
		return;
	m[root->val]++;
	if (root->left)
		traversal_tree(root->left);
	if (root->right)
		traversal_tree(root->right);
}

vector<int> find_n(TreeNode *root)
{
	vector<int> res;
	m.clear();
	traversal_tree(root);
	vector<pair<int, int>> vec(m.begin(), m.end());
	sort(begin(vec), end(vec), \
			[](pair<int, int> a, pair<int, int> b){return a.second > b.second;});
	res.push_back(vec[0].first);
	for (int i = 1; i < vec.size(); i++)
		if (vec[0].second == vec[i].second)
			res.push_back(vec[i].first);
	return res;

}

TreeNode *pre;
vector<int> vec;
int max_count = 0;
int n_count = 0;
void traversal_search_tree(TreeNode *root)
{
	if (!root)
		return ;
	if (root->left)
		traversal_search_tree(root->left);
	
	if (!pre || (pre && root->val == pre->val))
		n_count++;
	else if (root->val != pre->val)
		n_count = 1;
	if (n_count > max_count) {
		max_count = n_count;
		vec.clear();
		vec.push_back(root->val);
	}
	else if (n_count == max_count)
		vec.push_back(root->val);
	pre = root;

	if (root->right)
		traversal_search_tree(root->right);
}

vector<int> find_x(TreeNode *root)
{
	vec.clear();
	traversal_search_tree(root);
	return vec;
}


int main()
{
	int a[] = {4,2,7,1,3,3};
	TreeNode *root = new TreeNode(a[0]);
	TreeNode *node1 = new TreeNode(a[1]);
	TreeNode *node2 = new TreeNode(a[2]);
	TreeNode *node3 = new TreeNode(a[3]);
	TreeNode *node4 = new TreeNode(a[4]);
	//TreeNode *node5 = new TreeNode(a[5]);
	root->left = node1;
	root->right = node2;
	root->left->left = node3;
	root->left->right = node4;
	//root->left->right->right = node5;
	/*        4
	 *    2      7
	 *  1   3    
	 * */
	vector<int> v = find_x(root);
	copy(begin(v), end(v), ostream_iterator<int>{cout,"\n"});
	cout << root << endl;
	return 0;
}
