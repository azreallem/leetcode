// 输入: ["2", "1", "+", "3", " * "]
// 输出: 9
#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

inline int myops(string s, int n1, int n2) {
	if (s == "+")
		return n1 + n2;
	else if (s == "-")
		return n1 - n2;
	else if (s == "*")
		return n1 * n2;
	else if (s == "/")
		return n1 / n2;
	else
		return 0;
}

int resSum(vector<string>& tokens) {
	stack<int> st;
	for (auto x : tokens) {
		if (x == "+" || x == "-" || \
		    x == "*" || x == "/") {
			int pre = st.top();
			st.pop();
			pre = myops(x, st.top(), pre);
			st.pop();
			st.push(pre);
		}
		else {
			st.push(stoi(x));
		}
	}
	return st.top();
}

int main()
{
	vector<string> vec = {"9","1","+","2","-"};
	cout << resSum(vec) << endl;
	return 0;
}

