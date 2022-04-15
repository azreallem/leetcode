#include <iostream>
#include <vector>

using namespace std;


int f(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return f(n - 1) + f(n - 2);
}

int fib(int n)
{
	// dp [0:n]
	vector<int> dp(n+1);
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

int main()
{
	cout << fib(10) << endl;
	return 0;
}
