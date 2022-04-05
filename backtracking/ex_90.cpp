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

void backtracking(vector<int> vec, vector<bool> used, int index)
{
	res.push_back(path);

	for (int i = index; i < vec.size(); i++) {
		if (i > 0 && vec[i] == vec[i - 1] && used[i-1] == false)
			continue;
		path.push_back(vec[i]);
		used[i] = true;
		backtracking(vec, used, i + 1);
		used[i] = false;
		path.pop_back();
	}
}

vector<vector<int>> combine(vector<int> vec)
{
	res.clear();
	path.clear();
	vector<bool> used(vec.size(), false);
	sort(vec.begin(), vec.end(), [](int a, int b){return a < b;});
	backtracking(vec, used, 0);
	return res;
}


int main()
{
	vector<vector<int>> vec = combine({1,2,2});
	copy(vec.begin(), vec.end(), ostream_iterator<vector<int>>{cout,"\n"});
	return 0;
}


