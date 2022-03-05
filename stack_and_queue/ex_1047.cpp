#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

string remove_adjacent_char(string str)
{
	stack<char> st;
	for (int i = 0; i < str.length(); i++) {
		if (!st.empty() && st.top() == str[i])
			st.pop();
		else
			st.push(str[i]);
	}
	string res;
	int i = 0;
	while (!st.empty()) {
		res += st.top();
		st.pop();
	}
	reverse(res.begin(), res.end());
	return res;
}


int main()
{
	cout << remove_adjacent_char("abbac") << endl;
	return 0;
}
