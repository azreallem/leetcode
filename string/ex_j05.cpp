#include <iostream>
#include <string>

using namespace std;

/* 示例 1： 输入：s = "We are happy."
 * 输出："We%20are%20happy."
 * */
string replaceSpace(string s)
{
	int oldn = s.size();
	int n = oldn;
	for (auto x : s)
		if (x == ' ')
			n += 2;
	s.resize(n);
	for (int i = oldn - 1, j = n - 1; i >= 0 ; i--, j--) {
		if (s[i] != ' ')
			s[j] = s[i];
		else {
			s.replace(j-2, 3, "%20");
			j = j-2;
		}
	}
	return s;
}

int main()
{
	cout << replaceSpace("We are happy.") <<endl;
	return 0;
}
