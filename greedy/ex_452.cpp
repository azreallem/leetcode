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


int __findMinArrowShots(vector<vector<int>>& points) {
	if (points.size() == 0) return 0;
	
	sort(points.begin(), points.end(), 
	     [](const vector<int>& a, const vector<int>& b) {
	     return a[0] < b[0];
	   });
	
	int res = 1;
	int n = points.size();
	for (int i = 1; i < n; i++) {
		if (points[i][0] > points[i - 1][1])
			res++;
		else
			points[i][1] = min(points[i-1][1], points[i][1]);

	}
	return res;
}



int main()
{
	//vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
	vector<vector<int>> points = {{3,9},{7,12},{3,8},{6,8},{9,10},{2,9},{0,9},{3,9},{0,6},{2,8}};

	cout << __findMinArrowShots(points) << endl;
	return 0;
}
