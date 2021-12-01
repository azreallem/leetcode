#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

/* 输入: s = "abcdefg", k = 2
 * 输出: "bacdfeg"
 * */
string reverseStr1(string s, int k)
{
	for (int i = 0; i < s.size() - 1; i += 2 * k) {
		int rest = s.size() - i; //rest of number
		int t = i;
		int j = rest >= k ? (t+k-1) : (t+rest-1);
		for (;j > t; j--, t++)
			swap(s[t], s[j]);
	}
	return s;
}

string reverseStr(string s, int k)
{
	int n = s.size();
	for (int i = 0; i < n - 1; i += 2 * k) {
		reverse(s.begin() + i, s.begin() + i + min(k, n - i));
	}
	return s;
}


int main()
{
	string s = "abcdefg";
	int k = 2;
	string s2 = reverseStr(s,k);
	cout << s2 << endl;
	return 0;
}
