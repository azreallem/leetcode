#include "functions.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>  // For INT_MIN and INT_MAX

using namespace std;

// ------------------ 344. 反转字符串 ------------------
void reverseString(vector<char>& s) {
	int n = s.size();
	for (int i = 0; i < n / 2; i++) {
		swap(s[i], s[n - 1 - i]);
	}
}


REGISTER_FUNCTION(func344) {
	//示例 1：
	//
	//输入：s = ["h","e","l","l","o"]
	//输出：["o","l","l","e","h"]
	//示例 2：
	//
	//输入：s = ["H","a","n","n","a","h"]
	//输出：["h","a","n","n","a","H"]
#if 0
	vector<char> s = {'h','e','l','l','o'};
#endif
#if 1
	vector<char> s = {'H','a','n','n','a','h'};
#endif
	reverseString(s);
	print_it(s);
}

// ------------------ 541. 反转字符串 II ------------------
// start = 4, n = 2, s = "abcdefg", return "abcdfeg"
string swap_all(string str, int start, int n)
{
	// for 循环中的i用来控制次数
	for (int i = 0; i < n / 2; i++)
		swap(str[start + i], str[start + n - 1 - i]);
	return str;
}
string reverseStr(string s, int k) {
	int size = s.size();
	for (int i = 0; i < size; i += 2 * k) {
		if (i + k <= size) {
			//swap_all(s[i], s[i+k])
			s = swap_all(s, i, k);
		} else {
			//swap_all(s[i], s[size-1])
			s = swap_all(s, i, size - i);
		}
	}
	return s;
}

REGISTER_FUNCTION(func541) {
	//示例 1：
	//
	//输入：s = "abcdefg", k = 2
	//输出："bacdfeg"
	//
	//示例 2：
	//
	//输入：s = "abcd", k = 2
	//输出："bacd"
#if 1
	string s = "abcdefg";
	int k = 2;
#endif
#if 0
	string s = "abcd";
	int k = 2;
#endif
	s = reverseStr(s, k);
	cout << s << endl;
}

// ------------------ 151. 翻转字符串里的单词 ------------------
string reverseWords(string s) {
	vector<string> words;
	string res;
	int size = s.length();
	string word;
	for (int i = 0; i < size; i++) {
		if (s[i] == ' ' && word == "")
			continue;
		if (s[i] != ' ')
			word += s[i];
		if (s[i] == ' ' || i == size - 1) {
			words.push_back(word);
			word= "";
		}
	}
	for (int i = words.size() - 1; i > 0; i--) {
		res += words[i] + " ";
	}
	res += words[0]; // last word no space
	return res;
}
REGISTER_FUNCTION(func151) {
	//示例 1：
	//
	//输入：s = "the sky is blue"
	//输出："blue is sky the"
	//
	//示例 2：
	//
	//输入：s = "  hello world  "
	//输出："world hello"
	//
	//示例 3：
	//
	//输入：s = "a good   example"
	//输出："example good a"
#if 0
	string s = "the sky is blue";
#endif
#if 1
	string s = "  hello world  ";
#endif
#if 0
	string s = "a good   example";
#endif
	string res = reverseWords(s);
	cout << res << endl;
}

// ------------------ 459. 重复的子字符串 ------------------
bool repeatedSubstringPattern(string s) {
	// 判断前一半字符串是否是后一半字符串
	int n = s.length();
	int flag = 0;
	for (int i = 1; i < n; i++) {
		if (s[0] == s[i] && n % i == 0) {
			// 判定后面的字符串是否都等于s[0 : i]
			for (int j = i, t = 0; j < n; j++, t++) {
				if (s[t] == s[j]) {
					flag = 1;
					continue;
				}
				else {
					flag = 0;
					break;
				}
			}
			// 如果所有的if 都成立，则返回true
			if (flag == 1)
				return true;
		}
	}
	return false;
}
REGISTER_FUNCTION(func459) {
	//示例 1：
	//
	//输入：s = "abab"
	//输出：true
	//
	//示例 2：
	//
	//输入：s = "aba"
	//输出：false
	//
	//示例 3：
	//
	//输入：s = "abcabcabcabc"
	//输出：true
#if 0
	string s = "aba";
#endif
#if 0
	string s = "ababab";
#endif
#if 1
	string s = "abcabcabcabc";
#endif
	bool res = repeatedSubstringPattern(s);
	cout << res << endl;
}


