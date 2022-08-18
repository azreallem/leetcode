#include <iostream>
#include <vector>

using namespace std;


inline int max(int a, int b, int c)
{
	a = a > b ? a : b;
	return a > c ? a : c;
}

int integerBreak(int n)
{
	int f[n + 1];
	f[0] = 0;
	f[1] = 0;
	f[2] = 1;
	f[3] = 2;

	for (int i = 3; i <= n; i++) {
		f[i] = 0;
		for (int j = 1; i - j >= 1; j++) {
			f[i] = max(f[i], (i - j) * j, f[i - j] * j);
		}
	}

	return f[n];
}


int main()
{
	cout << integerBreak(10) << endl;
	return 0;
}
