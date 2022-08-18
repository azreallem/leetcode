#include <iostream>
#include <vector>

using namespace std;


int change(int amount, vector<int>& coins) {
	int n = coins.size();
	vector<int> dp(amount + 1, 0);
	dp[0] = 1;

	for (int i = 0; i < n; i++)
		for (int j = coins[i]; j < amount + 1; j++)
			dp[j] += dp[j - coins[i]];
	
	return dp[amount];
}


int main()
{
	vector<int> c = {1,2,5};
	cout << change(5, c) << endl;
	return 0;
}
