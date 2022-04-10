#include <iostream>
#include <iterator>
#include <vector>
#include <limits.h>
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


int wobble_sequence(vector<int>& vec)
{
	int count = 1;
	int pre_flag = 0;
	int flag;
	for (int i = 1; i < vec.size(); i++) {
		flag = vec[i] - vec[i-1];
		if((flag < 0 && pre_flag >= 0) || \
			flag > 0 && pre_flag <= 0) {
			pre_flag = flag;
			count++;
		}
	}
	return count;
}

int main()
{
	vector<int> vec = {33,53,12,64,50,41,45,21,97,35,47,92,39,0,93,55,40,46,69,42,6,95,51,68,72,9,32,84,34,64,6,2,26,98,3,43,30,60,3,68,82,9,97,19,27,98,99,4,30,96,37,9,78,43,64,4,65,30,84,90,87,64,18,50,60,1,40,32,48,50,76,100,57,29,63,53,46,57,93,98,42,80,82,9,41,55,69,84,82,79,30,79,18,97,67,23,52,38,74,15};
	int res = wobble_sequence(vec);
	cout << res << endl;
	return 0;
}
