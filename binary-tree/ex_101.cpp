#include <iostream>
#include <stack>

using namespace std;

struct Treenode {
	int val;
	Treenode *left, *right;
	Treenode(int v): val(v), left(NULL), right(NULL) {};
};

void travel_tree(Treenode *root)
{
	if (!root)
		return ;
	cout << root->val << '\t';
	if (root->left)
		travel_tree(root->left);
	if (root->right)
		travel_tree(root->right);
}

bool __is_symmetric(Treenode *left, Treenode *right)
{
	if (!left && !right)
		return true;
	else if (left && right && left->val == right->val) {
		bool outside = __is_symmetric(left->left, right->right);
		bool inside = __is_symmetric(left->right, right->left);
		return outside && inside;
	}
	else
		return false;
}

bool is_symmetric(Treenode *root)
{
	if (!root)
		return true;
	return __is_symmetric(root->left, root->right);
}

bool is_symmetric_iterate(Treenode *root)
{
	stack<Treenode*> st;
	if (!root)
		return true;
	st.push(root->left);
	st.push(root->right);
	Treenode *left;
	Treenode *right;

	while(!st.empty()) {
		left = st.top();
		st.pop();
		right = st.top();
		st.pop();
		if (!left && !right)
			continue;
		else if (left && right && left->val == right->val) {
			st.push(left->left);
			st.push(right->right);
			st.push(left->right);
			st.push(right->left);
		} else
			return false;
	}
	return true;
}

int main()
{
	int a[] = {1,2,2,4,5,5,4};
	int n = 0;
	Treenode *root = new Treenode(a[0]);
	Treenode *node1 = new Treenode(a[1]);
	Treenode *node2 = new Treenode(a[2]);
	Treenode *node3 = new Treenode(a[3]);
	Treenode *node4 = new Treenode(a[4]);
	Treenode *node5 = new Treenode(a[5]);
	Treenode *node6 = new Treenode(a[6]);
	root->left = node1;
	root->right = node2;
	root->left->left = node3;
	root->left->right = node4;
	root->right->left = node5;
	root->right->right = node6;
	/*        1
	 *    2      2
	 *  4   5  5   4
	 * */
	cout << "Is smmertric? " << is_symmetric(root) << endl;
	cout << "Is smmertric_iterate? " << is_symmetric_iterate(root) << endl;

	travel_tree(root);
	return 0;
}
