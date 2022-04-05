#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

namespace std {
	template<typename T>
	ostream& operator<<(ostream &os, const vector<T> vec)
	{
		os << "[";
		for (int i = 0; i < vec.size(); i++) {
			os << vec[i];
			if (i != vec.size() - 1)
				os << ", ";
		}
		os << "]";
		return os;
	}
}


vector<vector<string>> res;
vector<string> path;

bool is_palinstr(const string& str, int pre, int last)
{
	while (pre <= last) {
		if (str[pre++] == str[last--])
			continue;
		return false;
	}
	return true;
}

void backtracking(const string& str, int index)
{
	if (index >= str.size()) {
		res.push_back(path);
		return ;
	}

	for (int i = index; i < str.size(); i++) {
		if (!is_palinstr(str, index, i)) {
			continue;
		}
		/* newstr = str[index : i] */
		string newstr = str.substr(index, i - index + 1);
		path.push_back(newstr);
		backtracking(str, i + 1);
		path.pop_back();
	}
}

vector<vector<string>> combine(string str)
{
	res.clear();
	path.clear();
	backtracking(str, 0);
	return res;
}


int main()
{
	vector<vector<string>> vec = combine("aab");
	copy(vec.begin(), vec.end(), ostream_iterator<vector<string>>{cout,"\n"});
	return 0;
}


