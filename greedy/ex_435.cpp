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

static bool cmp (const vector<int>& a, const vector<int>& b)
{
	return a[1] < b[1];
}

/* How many independent intervals are there at most */
int eraseOverlapIntervals(vector<vector<int>>& a)
{
	int n = a.size();
	if (n == 0)
		return 0;
	sort(a.begin(), a.end(), cmp);
	int alone = 1;
	int right = a[0][1];
	for (int i = 1; i < n; i++) {
		if (a[i][0] >= right) {
			alone++;
			right = a[i][1];
		}
	}
	return n - alone;
}

int main()
{
	vector<vector<int>> vec = {{1,100},{11,22},{1,11},{2,12}};
	cout << eraseOverlapIntervals(vec) << endl;
	return 0;
}
