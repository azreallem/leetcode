#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d)
{
	int count = 0;
	unordered_map<int, int> u; // {a+b}的集合, 出现的次数

	for (const auto &n1 : a)
		for (const auto &n2 :b)
			u[n1 + n2]++;

	for (const auto &n1 : c)
		for (const auto &n2 :d) {
			int t = 0 - (n1 + n2);
			if (u.count(t) == 1)
				count += u[t];
		}

	return count;
}

int main()
{
    vector<int> a = {1, 2};
    vector<int> b = {-2,-1};
    vector<int> c = {-1, 2};
    vector<int> d = { 0, 2};
    cout << fourSumCount(a, b, c, d) << endl;
    return 0;
}

