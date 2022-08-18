#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


bool canPartition(vector<int>& nums)
{
	sort(begin(nums), end(nums));
	float dt = (float)accumulate(begin(nums), end(nums), 0) / 2;
	int t = (int)dt;
	if (dt - (float)t > 0)
		return false;
	int n = nums.size();
	int dp[n][t + 1];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < t + 1; j++) {
			if (i == 0)
				dp[i][j] = nums[i] <= j ? nums[i] : 0;
			else if (j - nums[i] < 0)
				dp[i][j] = dp[i - 1][j];
			else if (j - nums[i] >= 0 && i - 1 >= 0) {
				dp[i][j] = max(dp[i-1][j-nums[i]] + nums[i], dp[i-1][j]);
				if (dp[i][j] == t)
					return true;
			}
		}
	} 
	return false;
}


int main()
{
	vector<int> nums = {2,3,1};
	cout << canPartition(nums) << endl;
	return 0;
}
