#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

/* 输入：haystack = "hello", needle = "ll"
 * 输出：2
 * */

void getNext(int *next, string needle)
{
	int n = needle.size();
	int j = -1;
	next[0] = j;
	for (int i = 1; i < n; i++) {
		// The prefix and suffix are not the same.
		while (j >= 0 && needle[i] != needle[j + 1])
			j = next[j];	// back
		// The prefix and suffix are the same.
		if (needle[i] == needle[j + 1])
			j++;

		next[i] = j;
	}
}


int strStr(string haystack, string needle)
{
	int n1 = haystack.size();
	int n2 =needle.size();
	if (n2 == 0)
		return 0;
	int next[n2];
	int j = -1;

	getNext(next, needle);
	for (int i = 0; i < n1; i++) {
		// not match
		while (j >= 0 && haystack[i] != needle[j + 1])
			j = next[j];	// back
		// match
		if (haystack[i] == needle[j + 1])
			j++;
		if (j == n2 - 1)
			return i - n2 + 1;
	}

	return -1;
}

void myfunc(int s1)
{
	cout << s1 << endl;
}

int main()
{
	string s1 = "mississippi", s2 = "issip";
	myfunc(15);
	int n = strStr(s1, s2);
	cout << n << endl;
	return 0;
}
