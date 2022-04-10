#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <numeric>

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

int largestSumAfterKNegations(vector<int>& nums, int k)
{
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() && k > 0; i++, k--) {
		if (nums[i] <= 0)
			nums[i] = -nums[i];
		else
			break;
	}
	int min_index = min_element(nums.begin(), nums.end()) - nums.begin();
	if (k % 2 == 1)
		nums[min_index] = -nums[min_index];
	return accumulate(nums.begin(), nums.end(), 0);	
}

int main()
{
	vector<int> vec = {8,-7,-3,-9,1,9,-6,-9,3};
	cout << largestSumAfterKNegations(vec, 8) << endl;
	return 0;
}
