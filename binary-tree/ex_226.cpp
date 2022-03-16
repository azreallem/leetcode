#include <iostream>
#include <stack>
#include <algorithm>

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

Treenode* invert_tree(Treenode *root)
{
	stack<Treenode *> st;
	if (!root)
		return root;
	st.push(root);
	Treenode *cur;

	while(!st.empty()) {
		cur = st.top();
		st.pop();
		swap(cur->right, cur->left);
		if (cur->right) {
			st.push(cur->right);
		}
		if (cur->left) {
			st.push(cur->left);
		}
	}

	return root;
	
}

int main()
{
	int a[] = {1,2,3,4,5,6,7};
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
	 *    2      3
	 *  4   5  6   7
	 * */
	Treenode *newroot = invert_tree(root);
	travel_tree(newroot);

	return 0;
}
