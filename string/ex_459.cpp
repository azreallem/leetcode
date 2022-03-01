#include <iostream>
#include <string>

using namespace std;

void getnext(string s, int* next) {
	// initialize
	int j = -1;
	next[0] = -1;
	int i = 1;

	for (; i < s.size(); i++) {
		// not equal
		while (j >= 0 && s[j + 1] != s[i])
			j = next[j];
		// equal
		if (s[j + 1] == s[i])
			j++;
		// next[0:s.size()-1]
		next[i] = j;
	}
}

bool repeatedSubstringPattern (string s) {
	int len = s.size();
	if (len == 0)
		return false;
	int next[len];

	getnext(s, next);
	if(len % (len - next[len - 1] - 1) == 0 && \
			len != (len - next[len - 1] - 1))
		return true;
	else
		return false;
}

int main()
{
	string s1 = "abcabcabcabc";
	bool res = repeatedSubstringPattern(s1);
	cout << res << endl;
	return 0;
}
