#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
	stack<char> st;
	for (char c : s) {
		switch(c) {
		case '[':
		case '{':
		case '(':
			st.push(c);
			break;
		case ']':
			if (!st.empty() && st.top() == '[')
				st.pop();
			else
				return false;
			break;
		case '}':
			if (!st.empty() && st.top() == '{')
				st.pop();
			else
				return false;
			break;
		case ')':
			if (!st.empty() && st.top() == '(')
				st.pop();
			else
				return false;
			break;
		default:
			return false;
		}
	}
	return st.empty() ? true : false;
}

int main()
{
	cout << isValid("[]{}()") << endl;
	cout << isValid("[]{}(()") << endl;
	return 0;
}


