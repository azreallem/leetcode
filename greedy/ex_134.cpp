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

// gas = [1,2,3,4,5], cost = [3,4,5,1,2]
// time complexity: O(n)
// space complexity: O(n)
int canCompleteCircuit_1(vector<int>& gas, vector<int>& cost)
{
	vector<int> sub;
	int n = gas.size();
	for (int i = 0; i < n; i++)
		sub.push_back(gas[i]-cost[i]);

	for (int i = 0; i < n; i++) {
		if (sub[i] >= 0) {
			int sum = 0;
			int j;
			for (j = i; j < i + n; j++) {
				sum += sub[j % n];
				if (sum < 0)
					break;
			}
			if (j == i + n)
				return i;
			else if (j < i)
				return -1;
			else
				i = j;
		}
	}
	return -1;
}

int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
	int n = gas.size();
	int start = 0;
	int cur_rest = 0, total = 0;
	for (int i = 0; i < n; i++) {
		cur_rest += gas[i] - cost[i];
		total += gas[i] - cost[i];
		if (cur_rest < 0) {
			start = i + 1;
			cur_rest = 0;
		}
	}
	if (total >= 0)
		return start;
	return -1;
}


int main()
{
	vector<int> gas = {1,2,3,4,5};
	vector<int> cost = {3,4,5,1,2};
	cout << canCompleteCircuit(gas, cost) << endl;
	return 0;
}
