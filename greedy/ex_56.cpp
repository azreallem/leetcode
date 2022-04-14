#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;
namespace std {
	template<typename T>
	ostream& operator<<(ostream& os, vector<T> vec)
	{
		int n = vec.size();
		os << "{";
		for (int i = 0; i < n; i++) {
			if (i != n - 1)
				os << vec[i] << ", ";
			else
				os << vec[i];
		}
		os << "}";
		return os;
	}
}


vector<vector<int>> merge(vector<vector<int>>& intervals)
{
	vector<vector<int>> res;
	sort(intervals.begin(), intervals.end(), 		\
			[](vector<int> a, vector<int> b){	\
				return a[0] < b[0];		\
			});
	int left = intervals[0][0];
	int right = intervals[0][1];
	for (int i = 1; i < intervals.size(); i++) {
		if (intervals[i][0] > right) {
			res.push_back({left, right});
			left = intervals[i][0];
		}
		right = max(right, intervals[i][1]);
	}
	res.push_back({left, right});


	return res;
}

int main()
{
	vector<vector<int>> res;
	vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
	res = merge(intervals);
	copy(res.begin(), res.end(),ostream_iterator<vector<int>>{cout, "\n"});
	return 0;
}
