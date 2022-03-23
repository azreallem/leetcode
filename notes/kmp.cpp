#include <iostream>
#include <string>

using namespace std;


void getnext(string s1, int* next)
{
	/* initialize */
	int j = -1;	/* index of prev str */
	int i = 1;	/* index of next str */
	next[0] = -1;
	
	for (; i < s1.size(); i++) {
		/* not equal */
		while (j >= 0 && s1[j + 1] != s1[i])
			j = next[j]; /* back */
		/* equal */
		if (s1[j + 1] == s1[i])
			j++;
		next[i] = j;
	}
}


int kmp(string s1, string s2)
{
	// initialize
	int j = -1;	/* index of s1 */
	int i = 0;	/* index of s2 */
	int next[s1.size()];
	getnext(s1, next);

	if (s2.size() == 0)
		return 0;

	for (; i < s2.size(); i++) {
		//not equal
		while (j >= 0 && s1[j + 1] != s2[i])
			j = next[j];
		//equal
		if  (s1[j + 1] == s2[i])
			j++;
		// match
		if (j == s1.size() - 1)
			return i - j;
	}
	// not match
	return -1;
}

int main()
{
	string s1 = "aabaaf", s2 = "aabaabaaf";
	int res = kmp(s1, s2);
	cout << res << endl;
	return 0;
}
