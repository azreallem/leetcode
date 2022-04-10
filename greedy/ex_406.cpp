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
		int n = vec.size();
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

void p_move(vector<vector<int>>& people, int i)
{
	int n = people[i][1];
	while (n--) {
		swap(people[i], people[i+1]);
		i++;
	}
}

vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
{
	int n = people.size();
	sort(people.begin(), people.end(), 	\
	     [](vector<int> a, vector<int> b) { \
	     	if (a[0] == b[0])		\
			return a[1] > b[1];	\
		return a[0] < b[0]; 		\
	     });
	for (int i = n - 1; i >= 0; i--) {
		if (people[i][1] > 0)
			p_move(people, i);
	}
	return people;
}

int main()
{
	vector<vector<int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
	vector<vector<int>> res = reconstructQueue(people);
	copy(res.begin(), res.end(), ostream_iterator<vector<int>>{cout, "\n"});
	return 0;
}
