#include <iostream>
#include <iterator>
#include <vector>

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

int maxProfit(vector<int>& prices) {
	int total = 0;
	for (int i = 1; i < prices.size(); i++) {
		if (prices[i] - prices[i-1] > 0)
			total += prices[i] - prices[i-1];
	}	
	return total;
}


int main()
{
	vector<int> vec = {7,1,5,3,6,4};
	cout << maxProfit(vec) << endl;
	return 0;
}
