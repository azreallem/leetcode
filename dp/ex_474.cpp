#include <iostream>
#include <vector>

using namespace std;

int findMaxForm(vector<string>& strs, int m, int n) {
	int size = strs.size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	
	for (int i = 0; i < size; i++) {
		int mi = 0;
		int ni = 0;
		for (char c : strs[i]) {
			if (c == '0')
				mi++;
			else if (c == '1')
				ni++;
		}
		for (int j = m; j - mi >= 0; j--)
			for (int k = n; k - ni >= 0; k--)
				dp[j][k] = max(dp[j][k], dp[j - mi][k - ni] + 1);
	}

	return dp[m][n];
}



int main()
{
	vector<string> strs = {"10", "0001", "111001", "1", "0"};
	cout << findMaxForm(strs, 5, 3) << endl;
	return 0;
}
