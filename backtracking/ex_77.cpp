#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

namespace std {
	ostream& operator<<(ostream &os, const vector<int> vec)
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

void backtracking(int n, int k, int start_index)
{
	if (path.size() == k) {
		res.push_back(path);
		return ;
	}

	for (int i = start_index; i + (k - path.size()) - 1 <= n; i++) {
		path.push_back(i);
		backtracking(n, k, i + 1);
		path.pop_back();
	}
}

vector<vector<int>> combine(int n, int k)
{
	res.clear();
	path.clear();
	backtracking(n, k, 1);
	return res;
}


int main()
{
	vector<vector<int>> vec = combine(4, 2);
	copy(vec.begin(), vec.end(), ostream_iterator<vector<int>>{cout,"\n"});
	return 0;
}


