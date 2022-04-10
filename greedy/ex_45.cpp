#include <iostream>
#include <iterator>
#include <vector>

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

int min_step(vector<int>& nums) {
	int res = 0;
	int max_distance = 0;
	int cur_distance = 0;
	/* i = [0:nums.size()-1) */
	for (int i = 0; i < nums.size() - 1; i++) {
		max_distance = max(nums[i] + i, max_distance);
		/* get max_distance from [0,nums[i]] */
		if (i == cur_distance) {
			cur_distance = max_distance;
			res++;
		}
	}
	return res;
}

int main()
{
	vector<int> nums = {2,3,1,1,4};
	cout << min_step(nums) << endl;
	return 0;
}
