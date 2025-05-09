#include "functions.h"
#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <climits>  // For INT_MIN and INT_MAX



using namespace std;
/*
特性		红黑树					AVL 树
平衡严格性	弱平衡（允许一定程度的不平衡）		强平衡（左右子树高度差 ≤ 1）
旋转次数  	插入/删除时最多 2 次旋转		插入/删除时可能，多次旋转
查找效率  	稍慢（高度略高）			更快（高度更小）
适用场景  	频繁插入/删除（如 std::set、std::map）	查找频繁（如数据库索引）
------------------------------------------------------------------------------------
集合		   	底层实现	特点
std::set	   	红黑树		有序，元素唯一，值不可变
std::multiset		红黑树		有序，元素可重复，值不可变
std::unordered_set	哈希表		无序，元素唯一，值不可变
------------------------------------------------------------------------------------
映射		   	底层实现	特点
std::map	   	红黑树		key有序，唯一，O(longn)
std::multimap		红黑树		key有序，可重复，O(logn)
std::unordered_map	哈希表		key无序，唯一，O(1)
 * */


REGISTER_FUNCTION(myset) {
	//set<int> mySet;
	//multiset<int> mySet;
	std::unordered_set<int> mySet;

	// 插入元素（自动排序）
	mySet.insert(3);
	mySet.insert(1);
	mySet.insert(4);
	mySet.insert(1);
	// 查找
	if (mySet.find(3) != mySet.end()) {
		cout << "3 is in the set" << endl;
	}
	// 删除
	mySet.erase(3);

	print_it(mySet);
}

REGISTER_FUNCTION(mymap) {
	//map<int, string> myMap;
	//multimap<int, string> myMap;
	std::unordered_map<int, string> myMap;

	// 插入元素（自动排序）
	myMap.insert(pair<int, string>(3, "three"));
	myMap.insert(pair<int, string>(1, "one"));
	myMap.insert(pair<int, string>(4, "four"));
	myMap.insert(pair<int, string>(1, "one again"));
	// 查找
	if (myMap.find(3) != myMap.end()) {
		cout << "3 is in the map" << endl;
	}
	// 删除
	myMap.erase(3);

	print_map(myMap);
}

// ---------------------  242. 有效的字母异位词 ------
// 时间复杂度：O(n)
// 空间复杂度：O(n)
bool isAnagram(string s, string t) {
	std::multiset<char> set1, set2;
	for (auto c : s) {
		set1.insert(c);
	}
	for (auto c : t) {
		set2.insert(c);
	}
	return set1 == set2 ? true : false;
}

// 时间复杂度：O(n * log26)
// 空间复杂度：O(1)
bool isAnagram_2(string s, string t) {
	std::map<char, int> map1, map2; //或直接用数组
	for (int i = 0; i < 26; i++) {
		char c = 'a' + i;
		map1.insert(pair<char, int>(c, 0));
		map2.insert(pair<char, int>(c, 0));
	}
	for (auto c : s) {
		map1[c]++;
	}
	for (auto c : t) {
		map2[c]++;
	}
	return map1 == map2 ? true : false;
}

REGISTER_FUNCTION(func242) {
	//输入: s = "anagram", t = "nagaram"
	//输出: true
	string s = "anagram", t = "nagaram";
	cout << isAnagram_2(s, t) << endl;
}

// ------  1002. 查找常用字符 ------
vector<string> commonChars(vector<string>& words) {
	std::map<char, int> map1;

	for (int i = 0; i < 26; i++) {
		char c = 'a' + i;
		map1.insert(pair<char, int>(c, 0));
	}
	for (auto c : words[0])
		map1[c]++;

	for (auto w : words) {
		std::map<char, int> map2;
		for (int i = 0; i < 26; i++) {
			char c = 'a' + i;
			map2.insert(pair<char, int>(c, 0));
		}
		for (auto c : w)
			map2[c]++;
		// map1 =  min_val(map1, map2)
		for (int i = 0; i < 26; i++) {
			char c = 'a' + i;
			map1[c] = map1[c] < map2[c] ? map1[c] : map2[c];
		}
	}
	//map1 to string
	vector<string> res;
	for (int i = 0; i < 26; i++) {
		char c = 'a' + i;
		while (map1[c] > 0) {
			map1[c]--;
			res.push_back(string(1,c));
		}
	}
	return res;
}

REGISTER_FUNCTION(func1002) {
	//输入：words = ["bella","label","roller"]
	//输出：["e","l","l"]
	//输入：words = ["cool","lock","cook"]
	//输出：["c","o"]

	//vector<string> words = {"bella","label","roller"};
	vector<string> words = {"cool","lock","cook"};
	vector<string> res = commonChars(words);
	for (auto s : res)
		cout << s << " ";
}

// ------  349. 两个数组的交集 ------
// 时间复杂度：O(n)
// 空间复杂度：O(n)
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	unordered_set<int> set1, set2;
	for (auto num : nums1)
		set1.insert(num);
	for (auto num : nums2)
		if (set1.find(num) != set1.end())
			set2.insert(num);
	// set to vector<int>
	vector<int> res;
	for (auto num : set2)
		res.push_back(num);
	return res;
}

REGISTER_FUNCTION(func349) {
	//输入：nums1 = [1,2,2,1], nums2 = [2,2]
	//输出：[2]
	vector<int> nums1 = {1,2,2,1}, nums2 = {2,2};
	vector<int> res = intersection(nums1, nums2);
	for (auto num : res)
		cout << num << " ";
}

// ------  202. 快乐数 ------
bool isHappy(int n) {
	unordered_set<int> a;
	int sum;
	while(true) {
		sum = 0;
		while (n != 0) {
			sum += (n % 10) * (n % 10);
			n /= 10;
		}
		n = sum;
		if (sum == 1)
			return true;
		if (a.find(sum) != a.end())
			return false;
		a.insert(sum);
	}
}

REGISTER_FUNCTION(func202) {
	//输入：n = 19
	//输出：true
	int n = 19;
	cout << isHappy(n) << endl;
}

// ------  1. 两数之和 ------
// 时间复杂度：O(n)
// 空间复杂度：O(n)
vector<int> twoSum(vector<int>& nums, int target) {
	unordered_set<int> a;
	vector<int> result;
	for (auto n : nums)
		a.insert(n);
	for (int i = 0; i < nums.size(); i++) {
		int n = target - nums[i];
		if (a.find(n) != a.end()) {
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[j] == n) {
					result.push_back(i);
					result.push_back(j);
					return result;
				}
			}
		}
	}
	return result;
}

REGISTER_FUNCTION(func1) {
	//输入：nums = [2,7,11,15], target = 9
	//输出：[0,1]
	//输入：nums = [3,2,4], target = 6
	//输出：[1,2]
	//输入：nums = [3,3], target = 6
	//输出：[0,1]
#if 0
	vector<int> nums = {2,7,11,15};
	int target = 9;
#endif
#if 0
	vector<int> nums = {3,2,4};
	int target = 6;
#endif
#if 1
	vector<int> nums = {3,3};
	int target = 6;
#endif
	vector<int> res = twoSum(nums, target);
	for (auto num : res)
		cout << num << " ";
}

// ------  454. 四数相加 II ------
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
	int count = 0;
	unordered_map<int, int> map1, map2;
	for (auto n1 : nums1)
		for (auto n2 : nums2) {
			map1[n1 + n2]++;
		}
	for (auto n1 : nums3)
		for (auto n2 : nums4)
			map2[n1 + n2]++;
	for (auto it = map1.begin(); it != map1.end(); it++)
		if (map2.find((it->first) * (-1)) != map2.end()) {
			count += it->second * map2[(it->first) * (-1)];
		}
	return count;
}

REGISTER_FUNCTION(func454) {
//nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2] //2
//nums1 = [-1,-1] nums2 = [-1,1] nums3 = [-1,1] nums4 = [1,-1]  //6
#if 0
	vector<int> nums1 = {1,2}, nums2 = {-2,-1}, nums3 = {-1,2}, nums4 = {0,2};
#endif
#if 1
	vector<int> nums1 = {-1, -1};
	vector<int> nums2 = {-1, 1};
	vector<int> nums3 = {-1, 1};
	vector<int> nums4 = {1, -1};
#endif
	int res = fourSumCount(nums1, nums2, nums3, nums4);
	cout << res << endl;
}

// ------  383. 赎金信 ------
// 时间复杂度：O(n)
// 空间复杂度：O(n)
bool canConstruct(string ransomNote, string magazine) {
	unordered_map<char,int> map1, map2;
	for (auto c : magazine)
		map1[c]++; //magazine
	for (auto c : ransomNote)
		map2[c]++; //ransomNote
	for (auto it = map2.begin(); it!= map2.end(); it++) {
		if (map1.find(it->first) == map1.end())
			return false;
		if (map1.find(it->first) != map1.end() && map1[it->first] < it->second)
			return false;
	}
	return true;
}

REGISTER_FUNCTION(func383) {
	//示例 1：
	//
	//输入：ransomNote = "a", magazine = "b"
	//输出：false
	//示例 2：
	//
	//输入：ransomNote = "aa", magazine = "ab"
	//输出：false
	//示例 3：
	//
	//输入：ransomNote = "aa", magazine = "aab"
	//输出：true
#if 0
	string ransomNote = "a", magazine = "b";
#endif
#if 0
	string ransomNote = "aa", magazine = "ab";
#endif
#if 1
	string ransomNote = "baa", magazine = "aab";
#endif
	cout << canConstruct(ransomNote, magazine) << endl;
}
// ------  15. 三数之和 ------
vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> res;
	unordered_map<int, int> map1;
	unordered_set<int> set1; // 无序，无重复
	vector<int> vec1;

	for (auto n : nums) {
		map1[n]++;
		set1.insert(n);
	}
	// 0,0,0
	if (map1[0] >= 3)
		res.push_back({0, 0, 0});
	// x,x,y
	for (auto it = map1.begin(); it != map1.end(); it++) {
		if (map1[it->first] >= 2 && it->first != 0) {
			int n = 0 - it->first * 2;
			if (map1.find(n) != map1.end()) {
				res.push_back({n, it->first, it->first});
			}
		}
	}
	// set to vector
	for (auto n : set1)
		vec1.push_back(n);
	// x,y,z
	for (int i = 0; i < vec1.size(); i++) {
		for (int j = i + 1; j < vec1.size(); j++) {
			int n = 0 - vec1[i] - vec1[j];
			if (vec1[i] > n || vec1[j] > n)
				continue;
			if (set1.find(n) != set1.end() && \
			    (n != vec1[i] && n != vec1[j]))
				res.push_back({vec1[i], vec1[j], n});
		}
	}
	return res;
}

REGISTER_FUNCTION(func15) {
	//示例 1：
	//
	//输入：nums = [-1,0,1,2,-1,-4]
	//输出：[[-1,-1,2],[-1,0,1]]
	//示例 2：
	//
	//输入：nums = []
	//输出：[]
	//示例 3：
	//
	//输入：nums = [0]
	//输出：[]
#if 1
	vector<int> nums = {-1,0,1,2,-1,-4};
#endif
#if 0
	vector<int> nums = {};
#endif
#if 0
	vector<int> nums = {0};
#endif
	vector<vector<int>> res = threeSum(nums);
	for (auto v : res) {
		for (auto n : v)
			cout << n << " ";
		cout << endl;
	}
}

// ------  18. 四数之和 ------
vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> res;
	map<int, int> map1;               //{key = nums[i], value = counts[i]}
	multimap<int, vector<int>> sums2; //{key = sum2, value = {n[i],n[j]}}
	if (nums.size() <= 3)
		return res;
	// map1 <-- pair(nums[i], counts[i])
	for (auto n : nums)
		map1[n]++;
	// n <-- map1.keys
	int n[map1.size()];
	int i = 0;
	for (auto it = map1.begin(); it != map1.end(); it++) {
		n[i++] = it->first;
	}
	// sums2 <-- pair(n[i] + n[j], {n[i], n[j]})
	for (int i = 0; i < map1.size(); i++) {
		for (int j = i + 1; j < map1.size(); j++) {
			sums2.insert(pair<int, vector<int>>(n[i] + n[j], {n[i], n[j]}));
		}
		if (map1[n[i]] >= 2)
			sums2.insert(pair<int, vector<int>>(n[i] + n[i], {n[i], n[i]}));
	}
#if 0
	//print sums2
	for (auto it = sums2.begin(); it != sums2.end(); it++) {
		cout << it->first << " : ";
		for (auto n : it->second)
			cout << n << " ";
		cout << endl;
	}
	cout << "^^^^^^^^^^^^^ sum2 ^^^^^^^^^^^^" << endl;
#endif

	// n2 <-- sums2.keys
	int n2[sums2.size()];
	i = 0;
	for (auto it = sums2.begin(); it != sums2.end(); it++) {
		n2[i++] = it->first;
	}
	// sum2[i] == target - sums2[i]
	for (int i = 0; i < sums2.size(); i++) {
		{
			long long temp = static_cast<long long>(target) - n2[i];
			if (temp < INT_MIN || temp > INT_MAX) {
				break;  // 溢出，跳过
			}
		}
		int sum2 = target - n2[i];
		if (sums2.find(sum2) != sums2.end()) {
			// res <-- sort{sums2[n2].value1, sums2[sum2].value1}
			// res <-- sort{sums2[n2].value1, sums2[sum2].value2} ...
			vector<vector<int>> vec1;
			vector<vector<int>> vec2;
			auto range1 = sums2.equal_range(n2[i]); //拆分 n2[i]
			for (auto it = range1.first; it != range1.second; ++it) {
				vec1.push_back({it->second[0], it->second[1]});
			}
			auto range = sums2.equal_range(sum2); //拆分 sum2
			for (auto it = range.first; it != range.second; ++it) {
				vec2.push_back({it->second[0], it->second[1]});
			}
			for (int j = 0; j < vec1.size(); j ++)
				for (int k = 0; k < vec2.size(); k++) {
					vector<int> vec3;
					map<int, int> map2 = map1;
					vec3.push_back(vec1[j][0]);
					vec3.push_back(vec1[j][1]);
					vec3.push_back(vec2[k][0]);
					vec3.push_back(vec2[k][1]);
					map2[vec1[j][0]]--;
					map2[vec1[j][1]]--;
					map2[vec2[k][0]]--;
					map2[vec2[k][1]]--;
					if (map2[vec1[j][0]] < 0 || \
					    map2[vec1[j][1]] < 0 || \
					    map2[vec2[k][0]] < 0 || \
					    map2[vec2[k][1]] < 0)
						continue;
					sort(vec3.begin(), vec3.end());
					res.push_back(vec3);
				}
		}
	}
	// res去重
	sort(res.begin(), res.end());
	auto last = unique(res.begin(), res.end());
	res.erase(last, res.end());
	return res;
}
REGISTER_FUNCTION(func18) {
	//示例 1：
	//
	//输入：nums = [1,0,-1,0,-2,2], target = 0
	//输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
	//示例 2：
	//
	//输入：nums = [2,2,2,2,2], target = 8
	//输出：[[2,2,2,2]]
	//
	//
	// nums ---> map<int,int> a (-2,-1,0(2),1,2) //有序、无重复
	//
	// multimap<int, vector<int>> sums2 : 选两个元素相加 {key = sum2,value = {a[i],a[j]}}
	//           	for sums2 <-- a[key1] + a[key2]...
	// if (sums2[i] + sums2[j] == target) ---> {sums2[i], sums2[j]} --(sort)-> vector<vector<int>> res2
	// res2 去重
	// sort(res2)
	// last = unique(res2)
	// erase(last, res2)
#if 1
	vector<int> nums = {1,0,-1,0,-2,2};
	int target = 0;
#endif
#if 0
	vector<int> nums = {0,0,0,0};
	int target = 0;
#endif
#if 0
	vector<int> nums = {2,2,2,2,2};
	int target = 8;
#endif
	vector<vector<int>> res = fourSum(nums, target);
	for (auto v : res) {
		for (auto n : v)
			cout << n << " ";
		cout << endl;
	}
}
