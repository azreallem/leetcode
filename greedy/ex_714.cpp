#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
namespace std {
	template<typename T>
	ostream& operator<<(ostream& os, vector<T> vec)
	{
		int n = vec.size();
		os << "{";
		for (int i = 0; i < n; i++) {
			if (i != n - 1)
				os << vec[i] << ", ";
			else
				os << vec[i];
		}
		os << "}";
		return os;
	}
}


int maxProfit(vector<int>& prices, int fee)
{
	int res = 0;
	int min_n = prices[0];
	for (auto x : prices) {
		min_n = min(x, min_n);
		if (x - min_n > fee) {
			res += x - min_n - fee;
			min_n = x - fee;
		}
	}
	return res;
}

int main()
{
	vector<int> prices = {1,3,7,5,10,3};
	int fee = 3;
	cout << maxProfit(prices, fee) << endl;
	return 0;
}
