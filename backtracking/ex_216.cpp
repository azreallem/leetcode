#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <numeric>

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

void backtracking(int k, int n, int start_index, int num)
{
	if (num == k && accumulate(begin(path), end(path), 0) == n) {
		res.push_back(path);
		return ;
	}
	else if (num == k && accumulate(begin(path), end(path), 0) != n) {
		return ;
	}

	//for (int i = start_index; i <= 9 - (k - path.size()) + 1; i++) {
	for (int i = start_index; i <= 9; i++) {
		path.push_back(i);
		backtracking(k, n, i + 1, num + 1);
		path.pop_back();
	}
}

vector<vector<int>> combine(int k, int n)
{
	res.clear();
	path.clear();
	backtracking(k, n, 1, 0);
	return res;
}


int main()
{
	vector<vector<int>> vec = combine(3, 7);
	copy(vec.begin(), vec.end(), ostream_iterator<vector<int>>{cout,"\n"});
	return 0;
}


