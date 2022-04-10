#include <iostream>
#include <iterator>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;
namespace std {
	template<typename T>
	ostream& operator<<(ostream& os, vector<T> vec)
	{
		os << "{";
		for (int i = 0; i < vec.size(); i++) {
			if (i != vec.size() - 1)
				os << vec[i] << ", ";
			else
				os << vec[i];
		}
		return os;
	}
}

int distrubute_cookies(vector<int> g, vector<int> s)
{
	int res = 0, index = 0;
	sort(begin(g), end(g), less<int>());
	sort(begin(s), end(s), less<int>());
	for (auto x : g) {
		while (index < s.size()) {
			if (x <= s[index++]) {
				res++;
				break;
			}
		}
	}
	return res;
}

int main()
{
	int res = distrubute_cookies({1,2,3},{3});
	cout << res << endl;
	return 0;
}
