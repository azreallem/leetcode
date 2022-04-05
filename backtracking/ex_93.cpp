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


vector<vector<int>> res;
vector<int> path;

int str_is_int(const string& str, int pre, int last)
{
	/* "01" is false */
	if (last - pre + 1 > 1 && str[pre] == '0')
		return -1;
	if (last - pre + 1 <= 3 && last - pre +1 >= 1) {
		 int t = stoi(str.substr(pre, last - pre + 1));
		 if (t >= 0 && t <= 255)
			 return t;
	}
	return -1;
}

void backtracking(const string& str, int num, int index)
{
	if (num == 4 && str.size() == index) {
		res.push_back(path);
		return ;
	}
	if (num > 4)
		return;

	for (int i = index; i < str.size(); i++) {
		int t = str_is_int(str, index, i); 
		if (t < 0) {
			continue;
		}
		path.push_back(t);
		backtracking(str, num + 1, i + 1);
		path.pop_back();
	}
}

vector<string> combine(string str)
{
	res.clear();
	path.clear();
	backtracking(str, 0, 0);
	vector<string> __res;
	for (auto x : res) {
		string tmp = "";
		for (auto y : x) {
			tmp += to_string(y) + ".";
		}
		__res.push_back(tmp.substr(0, tmp.size()-1));
	}
	return __res;
}


int main()
{
	vector<string> vec = combine("25525511135");
	copy(vec.begin(), vec.end(), ostream_iterator<string>{cout,"\n"});
	return 0;
}


