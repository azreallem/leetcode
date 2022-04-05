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

void backtracking(vector<int> vec, int index)
{
	res.push_back(path);

	for (int i = index; i < vec.size(); i++) {
		path.push_back(vec[i]);
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
	vector<vector<int>> vec = combine({1,2,3});
	copy(vec.begin(), vec.end(), ostream_iterator<vector<int>>{cout,"\n"});
	return 0;
}


