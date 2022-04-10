#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <numeric>

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

/* 算法思想： 分3种情况，后面的评分比前面的大、相等、小；
 * cur 表示当前分配的糖果数，pre 表示当前评分极大值分配的糖果数，
 * count 表示递减数目；
 * */
int candy_1(vector<int>& ratings)
{
	int n = ratings.size();
	if (n <= 1)
		return n;
	
	int res = 1;
	int cur = 1;
	int count = 0;
	int pre = 0;
	for (int i = 1; i < n; i++) {
		if (ratings[i] > ratings[i - 1]) {
			cur++;
			count = 0;
			pre = cur;
		}
		else if (ratings[i] == ratings[i -1]) {
			cur = 1;
			pre = 1;
			count = 0;
		}
		else {
			cur = 1;
			res += count;
			count++;
			if (count >= pre)
				res++;
		}
		res += cur;
	}

	return res;
}

int candy(vector<int>& ratings)
{
	int n = ratings.size();
	vector<int> nums(n,1);
	for (int i = 1; i < n; i++)
		if (ratings[i] > ratings[i - 1])
			nums[i] = nums[i - 1] + 1;
	for (int i = n - 1; i >= 1; i--)
		if (ratings[i] < ratings[i - 1])
			nums[i - 1] = max(nums[i - 1], nums[i] + 1);
	return accumulate(begin(nums), end(nums), 0);
}


int main()
{
	vector<int> ratings = {1,0,2};
	//vector<int> ratings = {5,4,3,2,1};
	cout << candy(ratings) << endl;
	return 0;
}
