#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int __package(int w, vector<int> weight, vector<int> value)
{
	int n = weight.size();
	int dp[n][w + 1];

	for (int i = 0; i < n; i++) {
		dp[i][0] = 0;
		for (int j = 0; j <= w; j++) {
			if (i == 0 && j - weight[i] < 0)
				dp[i][j] = 0;
			else if (i == 0 && j - weight[i] >= 0)
				dp[i][j] = value[i];
			else if (i - 1 >= 0 && j - weight[i] >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}

	}
	return dp[n -1][w];

}



int package(int w, vector<int> weight, vector<int> value)
{
	int n = weight.size();
	vector<int> dp(w + 1, 0);

	for(int i = 0; i < n; i++) {
		for(int j = w; j >= weight[i]; j--) {
			dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
		}
	}

	return dp[w];
}

int main()
{
	vector<int> weight = {1,3,4};
	vector<int> value = {15,20,30};
	cout << package(4, weight, value) << endl;
	return 0;
}
