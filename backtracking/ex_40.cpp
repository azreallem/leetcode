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

void backtracking(vector<int> c, int target, int sum, int index, vector<bool> used)
{
	if (sum == target) {
		res.push_back(path);
		return ;
	} else if (sum > target)
		return ;

	for (int i = index; i < c.size() && sum + c[i] <= target; i++) {
		/* the previous branch has already been used */
		if (i > 0 && c[i] == c[i - 1] && used[i - 1] == false)
			continue;
		path.push_back(c[i]);
		sum += c[i];
		used[i] = true;
		backtracking(c, target, sum, i + 1, used);
		used[i] = false;
		sum -= c[i];
		path.pop_back();
	}
}

vector<vector<int>> combine(vector<int> c, int target)
{
	res.clear();
	path.clear();
	vector<bool> used(c.size(), false);
	sort(c.begin(), c.end(), [](int a,int b){return a < b;});
	backtracking(c, target, 0, 0, used);
	return res;
}


int main()
{
	vector<vector<int>> vec = combine(vector<int>{10,1,2,7,6,1,5}, 8);
	copy(vec.begin(), vec.end(), ostream_iterator<vector<int>>{cout,"\n"});
	return 0;
}


