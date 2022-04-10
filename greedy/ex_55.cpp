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

bool canJump(vector<int>& nums) {
	if (nums.size() == 1)
		return true;
	int max_distance = 0;
	for (int i = 0; i <= max_distance; i++) {
		max_distance = max(nums[i] + i, max_distance);
		if (max_distance >= nums.size() - 1)
			return true;
	}
	return false;
}

int main()
{
	vector<int> nums = {2,3,1,1,4};
	cout << canJump(nums) << endl;
	return 0;
}
