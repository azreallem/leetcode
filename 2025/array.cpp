#include "functions.h"
#include <iostream>
#include <vector>

using namespace std;

// 示例函数 funcN（使用宏注册）
REGISTER_FUNCTION(funcNo) {
	std::cout << "Function funcNo called!" << std::endl;
}

// -------------------- 704. 二分查找 ----------
int search(vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1;
	while (left <= right) {
		int current = (left + right) / 2;
		if (target == nums[current])
			return current;
		else if (target < nums[current])
			right = current - 1;
		else if (target > nums[current])
			left = current + 1;
	}
	return -1;
}

REGISTER_FUNCTION(func704) {
#if 1
	std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
	int target = 9;
#endif
#if 0
	std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
	int target = 2;
#endif
	int result = search(nums, target);
	cout << result << endl;
}


// -------------------- 27. 移除元素 ----------
int removeElement(vector<int>& nums, int val) {
	int same = 0;
	for (int i = 0; i + same < nums.size(); i++) {
		while (i + same != nums.size() && nums[i + same] == val)
			same++;
		if (i + same != nums.size())
			nums[i] = nums[i + same];
	}
	return nums.size() - same;
}

REGISTER_FUNCTION(func27) {
#if 0
	std::vector<int> nums = {3, 2, 2, 3};
	int val = 3;
#endif
#if 1
	std::vector<int> nums = {0,1,2,2,3,0,4,2};
	int val = 2;
#endif
	int result = removeElement(nums, val);
	cout << result << endl;
	print_it(nums);
}

// -------------------- 977. 有序数组的平方 ----------
vector<int> sortedSquares(vector<int>& nums) {
	vector<int> result = nums;
	int left = 0, right = 0;
	for (; right < nums.size(); right++)
		if (nums[right] >= 0)
			break;
	left = right - 1;
	int i = 0;
	while (true) {
		int t0, t1;
		// 1. 左边都计算完成
		if (left < 0) {
			while (right < nums.size()) {
				result[i++] = nums[right] * nums[right];
				right++;
			}
			return result;
		}

		// 2. 右边都计算完成
		if (right >= nums.size()) {
			while (left >= 0) {
				result[i++] = nums[left] * nums[left];
				left--;
			}
			return result;
		}

		// 3. 两边都未计算完成
		t0 = nums[left] * nums[left];
		t1 = nums[right] * nums[right];
		if (t0 < t1) {
			result[i++] = t0;
			left--;
		}
		else {
			result[i++] = t1;
			right++;
		}
		if (i == nums.size())
			return result;
	}
}

vector<int> sortedSquares_2(vector<int>& nums) {
	vector<int> result = nums;
	int left = 0, right = nums.size() - 1;

	for(int i = nums.size() - 1; i >= 0; i--) {
		int t0 = nums[left] * nums[left];
		int t1 = nums[right] * nums[right];
		if (t0 < t1) {
			result[i] = t1;
			right--;
		} else {
			result[i] = t0;
			left++;
		}
	}
	return result;
}

REGISTER_FUNCTION(func977) {
#if 1
	//输入：nums = [-4,-1,0,3,10]
	//输出：[0,1,9,16,100]
	std::vector<int> nums = {-4,-1,0,3,10};
#endif
	std::vector<int> result = sortedSquares_2(nums);
	print_it(result);
}


// -------------------- 209.长度最小的子数组 ----------

// 暴力法：O(n^2)
int minSubArrayLen(int target, vector<int>& nums) {
	int len = nums.size() + 1;

	for (int i = 0; i < nums.size(); i++) {
		int t = i, sum = 0;
		if (nums[i] >= target)
			return 1;
		while (t < nums.size() && sum < target) {
			sum += nums[t++];
		}
		len = (t - i < len && sum >= target) ? t - i : len;
	}

	if (len == nums.size() + 1)
		len = 0;
	return len;
}

// 滑动窗口法：O(n)
int minSubArrayLen_2(int target, vector<int>& nums) {
	int len = nums.size() + 1;
	int sum = 0;
	int subLength = 0;
	int j = 0;

	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		while (sum >= target) {
			subLength = i - j + 1;
			len = (len < subLength) ? len : subLength;
			sum -= nums[j++];
		}
	}

	return len == nums.size() + 1 ? 0 : len;

}

REGISTER_FUNCTION(func209) {
//示例 1：
//
//输入：target = 7, nums = [2,3,1,2,4,3]
//输出：2
//解释：子数组 [4,3] 是该条件下的长度最小的子数组。
//示例 2：
//
//输入：target = 4, nums = [1,4,4]
//输出：1
//示例 3：
//
//输入：target = 11, nums = [1,1,1,1,1,1,1,1]
//输出：0

#if 1
	std::vector<int> nums = {2,3,1,2,4,3};
	int target = 7;
#endif
#if 0
	std::vector<int> nums = {1,4,4};
	int target = 4;
#endif
#if 0
	std::vector<int> nums = {1,1,1,1,1,1,1,1};
	int target = 11;
#endif
	int result = minSubArrayLen_2(target, nums);
	cout << result << endl;
}

// ---------- 58. 区间和 ----------
REGISTER_FUNCTION(func58) {
	int n, a, b;
	cin >> n;
	vector<int> vec(n);
	vector<int> p(n);
	cin >> vec[0];
	p[0] = vec[0];
	for (int i = 1; i < n; i++) {
		cin >> vec[i];
		p[i] = p[i - 1] + vec[i];
	}
	while (cin >> a >> b) {
		int sum;
		if (a == 0)
			sum = p[b];
		else
			sum = p[b] - p[a - 1];
		cout << sum << endl;
	}
}

// ---------- 59.螺旋矩阵II  ----------
// gener_q(a, 0, 3, k)
void gener_q(vector<vector<int>> &a, int from, int to, int &k) {
	// a[0][0], a[0][1], a[0][2], a[0][3]
	for (int i = from; i <= to; i++) {
		if (a[from][i] == 0) {
			a[from][i] = k;
			k++;
		}
	}
	// a[0][3], a[1][3], a[2][3], a[3][3]
	for (int i = from; i <= to; i++) {
		if (a[i][to] == 0) {
			a[i][to] = k;
			k++;
		}
	}
	// a[3][3], a[3][2], a[3][1], a[3][0]
	for (int i = to; i >= 0; i--) {
		if (a[to][i] == 0) {
			a[to][i] = k;
			k++;
		}
	}
	// a[3][0], a[2][0], a[1][0], a[0][0]
	for (int i = to; i >= 0; i--) {
		if (a[i][from] == 0) {
			a[i][from] = k;
			k++;
		}
	}
}

vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> result(n, vector<int>(n));
	int i = 0, j = n - 1, k = 1;
	while(i <= j) {
		gener_q(result, i, j, k);
		i++;
		j--;
	}
	return result;
}


REGISTER_FUNCTION(func59) {
	vector<vector<int>> result = generateMatrix(4);
	print_2it(result);
}
