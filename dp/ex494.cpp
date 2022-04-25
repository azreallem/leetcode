#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


int findTargetSumWays(vector<int>& nums, int target) {
	int n = nums.size();
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if (abs(target) > sum || (sum + target) % 2 == 1)
		return 0;
	int t = (sum + target) / 2;
	vector<int> dp(t + 1, 0);
	dp[0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = t; j >= nums[i]; j--) {
			dp[j] += dp[j - nums[i]];
		}
	}

	return dp[t];
}


int main()
{
	std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	cout << findTargetSumWays(v, 15) << endl;
	return 0;
}
