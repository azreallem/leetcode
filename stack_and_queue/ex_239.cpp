/*
 * 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
 * 输出：[3,3,5,5,6,7]
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/* 单调递减队列 */
class myqueue {
public:
	/* 双端队列 */
	deque<int> q;
	void pop(int last) {
		if (!q.empty() && last == q.front())
			q.pop_front();
	}
	void push(int n) {
		while (!q.empty() && n > q.back())
			q.pop_back();
		q.push_back(n);
	}
	int front() {
		return q.front();
	}
};



vector<int> slideWin(vector<int> nums, int k)
{
	myqueue q;
	vector<int> vec;
	int i;
	for (i = 0; i < k; i++)
		q.push(nums[i]);
	vec.push_back(q.front());
	for (; i < nums.size(); i++) {
		q.pop(nums[i - k]);
		q.push(nums[i]);
		vec.push_back(q.front());
	}
	return vec;
}

int main()
{
	vector<int> vec;
	vec = slideWin(vector<int>{1,3,-1,-3,5,3,6,7}, 3);
	for (auto x: vec)
		cout << x << '\t';
	cout << endl;
}
