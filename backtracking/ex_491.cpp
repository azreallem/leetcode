#include <vector>
#include <unordered_set>
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

void backtracking(vector<int> vec, int index)
{
	if (path.size() >= 2)
		res.push_back(path);

	unordered_set<int> used;
	for (int i = index; i < vec.size(); i++) {
		if ((!path.empty() && vec[i] < path.back()) \
			|| used.find(vec[i]) != used.end())
			continue;
		path.push_back(vec[i]);
		used.insert(vec[i]);
		backtracking(vec, i + 1);
		path.pop_back();
	}
}

vector<vector<int>> combine(vector<int> vec)
{
	res.clear();
	path.clear();
	backtracking(vec, 0);
	return res;
}


int main()
{
	vector<vector<int>> vec = combine({4,7,4,7});
	copy(vec.begin(), vec.end(), ostream_iterator<vector<int>>{cout,"\n"});
	return 0;
}


