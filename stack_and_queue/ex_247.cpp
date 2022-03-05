/*
* 示例 1:
* 输入: nums = [1,1,1,2,2,3], k = 2
* 输出: [1,2]
*
* 示例 2:
* 输入: nums = [1], k = 1
* 输出: [1]
* 
*/

#include <map>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> maxfrq(vector<int> nums, int k)
{
	map<int, int> m;
	vector<int> res;
	for (auto n : nums) {
		m.count(n) == 0 ? m[n] = 1 : m[n]++;
	}
	/* Using lambda to compare elements */
	auto cmp = [](pair<int, int> m1, pair<int, int>m2) { return m1.second < m2.second; };
	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pque(cmp);

	for (auto x : m)
		pque.push(x);
	for (int i = 0; i < k; i++) {
		auto m1 = pque.top();
		res.push_back(m1.first);
		pque.pop();
	}
	return res;
}


int main()
{
	vector<int> vec = maxfrq(vector<int>{1,1,1,2,2,3,3,3,3}, 2);
	for (auto x : vec)
		cout << x << endl;
	cout << endl;
	return 0;
}

