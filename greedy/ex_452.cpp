#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;
namespace std {
	template<typename T>
	ostream& operator<<(ostream& os, vector<T> vec)
	{
		os << "{";
		for (int i = 0; i < vec.size(); i++) {
			if (i != vec.size() - 1)
				os << vec[i] << ", ";
			else
				os << vec[i];
		}
		os << "}";
		return os;
	}
}



int __findMinArrowShots(vector<vector<int>>& points)
{
	sort(points.begin(), points.end(), 	\
	     [](vector<int> a, vector<int> b){	\
	     	return a[1] < b[1];		\
	     });
	int res = 0;
	int n = points.size();

	for (int i = 0; i < n; i++) {
		int min_n = points[i][1];
		if (i+1 < n && points[i+1][0] <= min_n)
			continue;
		else
			res++;
	}
	return res;
}

int findMinArrowShots(vector<vector<int>>& points)
{
	sort(points.begin(), points.end(), 	\
	     [](vector<int> a, vector<int> b) {	\
	     	return a[1] > b[1];		\
	     });
	int res = 0;
	int n = points.size();

	for (int i = n - 1; i >= 0; i--) {
		int min_n = points[i][1];
		res++;
		while (i-1 >= 0 && points[i-1][0] <= min_n)
			i--;
	}
	return res;
}

int main()
{
	vector<vector<int>> points = {{1,2},{3,4},{5,6},{7,8}};
	cout << __findMinArrowShots(points) << endl;
	return 0;
}
