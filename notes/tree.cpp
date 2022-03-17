#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Treenode {
	int val;
	Treenode *left, *right;
	Treenode(int v): val(v), left(NULL), right(NULL) {}
};

void travel_tree(Treenode *root, int &n)
{
	if (!root)
		return ;
	cout << root->val << '\t';
	n++;
	if (root->left)
		travel_tree(root->left, n);
	if (root->right)
		travel_tree(root->right, n);
}

vector<int> preorder_traversal(Treenode *root)
{
	vector<int> res;
	stack<Treenode*> st;
	if(!root)
		return res;
	st.push(root);

	while(!st.empty()) {
		Treenode *cur = st.top();
		res.push_back(cur->val);
		st.pop();
		if (cur->right)
			st.push(cur->right);
		if (cur->left)
			st.push(cur->left);
	}
	return res;
}

vector<int> inorder_traversal(Treenode *root)
{
	vector<int> res;
	stack<Treenode*> st;
	if (!root)
		return res;
	Treenode *cur = root;

	while (cur || !st.empty()) {
		if (cur) {
			/* find last left node */
			st.push(cur);
			cur = cur->left;
		} else {
			cur = st.top();
			res.push_back(cur->val);
			st.pop();
			cur = cur->right;
		}
	}

	return res;
}

/* left, right, mid */
vector<int> postorder_traversal(Treenode *root)
{
	vector<int> res;
	stack<Treenode*> st;
	if (!root)
		return res;
	st.push(root);

	while (!st.empty()) {
		Treenode *cur = st.top(); 
		res.push_back(cur->val);
		st.pop();
		if (cur->left)
			st.push(cur->left);
		if (cur->right)
			st.push(cur->right);
	}
	reverse(res.begin(), res.end());

	return res;
}

vector<vector<int>> level_traversal(Treenode *root)
{
	vector<vector<int>> res;
	queue<Treenode*> que;
	if (!root)
		return res;
	que.push(root);

	while(!que.empty()) {
		int size = que.size();
		Treenode *cur;
		vector<int> vec;
		
		while (size--) {
			cur = que.front();
			vec.push_back(cur->val);
			que.pop();
			if (cur->left)
				que.push(cur->left);
			if (cur->right)
				que.push(cur->right);
		}
		res.push_back(vec);
	}

	return res;
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
	travel_tree(root, n);
	cout << "\ncount = "<< n << endl;

	/* preorder_travesal */
	vector<int> res;
	res = preorder_traversal(root);
	for (auto x : res)
		cout << x << '\t';
	cout << endl;

	/* inorder_travesal */
	res = inorder_traversal(root);
	for (auto x : res)
		cout << x << '\t';
	cout << endl;
	
	/* inorder_travesal */
	res = postorder_traversal(root);
	for (auto x : res)
		cout << x << '\t';
	cout << endl;
	
	/* level_traversal */
	vector<vector<int>> ress;
	ress = level_traversal(root);
	for (auto x : ress)
		for (auto xx : x)
			cout << xx << '\t';
	cout << endl;

	return 0;
}

