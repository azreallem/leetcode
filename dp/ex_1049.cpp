#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int lastStoneWeightII(vector<int>& stones) {
	vector<int> dp(15001, 0);
	int n = stones.size();
	int sum = accumulate(stones.begin(), stones.end(), 0);
	int t = sum / 2;

	for (int i = 0; i < n; i++) {
		for (int j = t; j - stones[i] >= 0; j--) {
			dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
		}
	}

	return sum - dp[t] - dp[t];
}



int main()
{
	vector<int> vec = {2,7,4,1,8,1};
	cout << lastStoneWeightII(vec) << endl;
	return 0;
}
