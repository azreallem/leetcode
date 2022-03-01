#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

/* 输入: s = "abcdefg", k = 2
 * 输出: "cdefgab"
 * */
string reverseLeftWords(string s, int n)
{
	reverse(s.begin(), s.end());     // [0, size), number of reverse is (size-0)
	reverse(s.begin(), s.end() - n); // [0, size-n)
	reverse(s.end() - n, s.end());   // [size-n, size)
	return s;
}

int main()
{
	cout << reverseLeftWords("abcdefg", 2) << endl;
	return 0;
}
