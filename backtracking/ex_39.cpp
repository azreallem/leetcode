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

void backtracking(vector<int> c, int target, int sum, int index)
{
	if (sum == target) {
		res.push_back(path);
		return ;
	} else if (sum > target)
		return ;

	for (int i = index; i < c.size(); i++) {
		path.push_back(c[i]);
		sum += c[i];
		backtracking(c, target, sum, i);
		sum -= c[i];
		path.pop_back();
	}
}

vector<vector<int>> combine(vector<int> c, int target)
{
	res.clear();
	path.clear();
	backtracking(c, target, 0, 0);
	return res;
}


int main()
{
	vector<vector<int>> vec = combine(vector<int>{2,3,6,7}, 7);
	copy(vec.begin(), vec.end(), ostream_iterator<vector<int>>{cout,"\n"});
	return 0;
}


