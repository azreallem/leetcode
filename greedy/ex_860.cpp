#include <iostream>
#include <iterator>
#include <vector>
#include <unordered_map>

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


bool lemonadeChange(vector<int>& bills)
{
	unordered_map<int, int> money;
	for (auto x : bills) {
		money[x]++;
		x -= 5;
		while (x) {
			if (x >= 10 && money[10] >= 1) {
				money[10]--;
				x -= 10;
			} else if (x >= 5 && money[5] >= 1) {
				money[5]--;
				x -= 5;
			} else
				return false;
		}
	}
	return true;
}

int main()
{
	vector<int> bills = {5,5,5,10,20};
	cout << lemonadeChange(bills) << endl;
	return 0;
}
