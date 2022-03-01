#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

/* 输入: "the sky is blue"
 * 输出: "blue is sky the"
 * 输入: "  hello world!  "
 * 输出: "world! hello"
 * */
string reverseWords(string s)
{
	int n = s.size();
	int t = 0; //number of space
	int c = 0; //number of char
	reverse(s.begin(), s.end());
	for (int i = 0; i < n; i++) {
		s[i] == ' ' ? (t++) : (c++);
		if (c > 0 && t > 0 && s[i] == ' ') {
			reverse(s.begin() + i - c - t + 1, s.begin() + i);
			t--;
			c = 0;
		}
	}
	if (s[n - 1] != ' ')
		reverse(s.end() -c -t, s.end());
	// remove space of last
	t = 0;
	for (int i = n - 1; i >= 0 && s[i] == ' '; i--)
		t++;	
	s.resize(n - t);
	return s;
}

int main()
{
	cout << " the  sky is blue " << endl;
	cout << reverseWords("the  sky is blue") << endl;
	return 0;
}
