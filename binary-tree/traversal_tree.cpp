#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

struct Treenode{
	int val;
	Treenode *left, *right;
	Treenode(int x): val(x), left(NULL), right(NULL) {}
};

/* pre travel */
void print_tree(Treenode* n1)
{
	if (n1 == NULL)
		return ;
	cout << n1->val << '\t';
	print_tree(n1->left);
	print_tree(n1->right);
}

/* pre travelsal */
vector<int> pre_travel(Treenode* root)
{
	stack<Treenode*> st;
	vector<int> res;
	Treenode *node = root;
	if (!node)
		return res;
	st.push(root);
	while (!st.empty()) {
		node = st.top();		/* current node  */
		res.push_back(node->val);
		st.pop();
		if (node->right)
			st.push(node->right);	/* right node */
		if (node->left)
			st.push(node->left);	/* left node */
	}
	return res;
}

/* inorder traversal: 2,9,5,3,4,1 */
/*     5
 *  2     4
 *   9  3   1
 * */
vector<int> in_travel(Treenode* root)
{
	vector<int> result;
	stack<Treenode*> st;
	Treenode* cur = root;
	while (cur != NULL || !st.empty()) {
		if (cur != NULL) { /* find last left node */
			st.push(cur);
			cur = cur->left;
		} else {
			cur = st.top(); /* current node */
			st.pop();
			result.push_back(cur->val);
			cur = cur->right; /* right node */
		}
	}
	return result;
}

/* postorder travelsal */
/* current, right, left --> reverse */
vector<int> postorderTraversal(Treenode* root) {
	stack<Treenode*> st;
	vector<int> result;
	if (root == NULL)
		return result;
	st.push(root);
	while (!st.empty()) {
		Treenode* node = st.top();
		st.pop();
		result.push_back(node->val);
		if (node->left)
			st.push(node->left); 
		if (node->right)
			st.push(node->right);
	}
	reverse(result.begin(), result.end());
	return result;
}

/* level traversal */
/*     5
 *  2     4
 *   9  3   1
 * */
vector<vector<int>> level_traversal(Treenode* root)
{
	vector<vector<int>> res;
	queue<Treenode*> que;
	Treenode *node;
	if (!root)
		return res;
	que.push(root);
	while (!que.empty()) {
		int size = que.size();
		vector<int> vec;
		for (int i = 0; i < size; i++) {
			node = que.front();
			vec.push_back(node->val);	// current node
			que.pop();
			if (node->left)
				que.push(node->left);	// left
			if (node->right)
				que.push(node->right);	// right
		}
		res.push_back(vec);
	}
	return res;
}


int main()
{
	Treenode *root = new Treenode(5);
	Treenode *n1 = new Treenode(4);
	Treenode *n2 = new Treenode(2);
	Treenode *n3 = new Treenode(1);
	Treenode *n4 = new Treenode(3);
	Treenode *n5 = new Treenode(9);
	root->right = n1;
	root->left = n2;
	n1->right = n3;
	n1->left = n4;
	n2->right = n5;
	cout << "pre print" << endl;
	print_tree(root);
	cout << endl;
	cout << "pre order" << endl;
	vector<int> res;
	res = pre_travel(root);
	for (auto x : res)
		cout << x << '\t';
	cout << endl;
	cout << "inorder" << endl;
	vector<int> res1;
	res1 = in_travel(root);
	for (auto x : res1)
		cout << x << '\t';
	cout << endl;
	cout << "postorder" << endl;
	vector<int> res2;
	res2 = postorderTraversal(root);
	for (auto x : res2)
		cout << x << '\t';
	cout << endl;
	cout << "level-order" << endl;
	vector<vector<int>> res3;
	res3 = level_traversal(root);
	for (int i = 0; i < res3.size(); i++)
		for (int j = 0; j < res3[i].size(); j++)
			cout << res3[i][j] << '\t';
	cout << endl;
	return 0;
}
