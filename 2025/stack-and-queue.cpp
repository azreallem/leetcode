#include "functions.h"
#include <stack>
#include <queue>
#include <deque>
#include <iostream>
#include <vector>


using namespace std;


REGISTER_FUNCTION(mystack) {
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
	cout << s.size() << endl;
}

REGISTER_FUNCTION(myqueue) {
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}
	cout << q.size() << endl;
}

// 双端队列
REGISTER_FUNCTION(mydeque) {
	deque<int> d;
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_front(4);
	while (!d.empty()) {
		cout << d.front() << endl;
		d.pop_front();
	}
	cout << d.size() << endl;
}

// 优先级队列
REGISTER_FUNCTION(mypriorityqueue) {
	priority_queue<int> pq; // 默认是小顶堆
	priority_queue<int, vector<int>, greater<int>> pq2; // 大顶堆
	pq.push(1);
	pq.push(2);
	pq.push(3);
	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}
	cout << pq.size() << endl;
	pq2.push(1);
	pq2.push(2);
	pq2.push(3);
	while (!pq2.empty()) {
		cout << pq2.top() << endl;
		pq2.pop();
	}
	cout << pq2.size() << endl;
}

// ---------------------------------------------------------------------


// ------------------------- 20. 有效的括号 ----------------------------
bool isValid(string s) {
	stack<char> st;
	char ch[6] = {'(', ')', '{', '}', '[', ']'};
	for (auto c : s) {
		for (int i = 0; i < 6; i++) {
			if (c == ch[i] && i % 2 == 0)
				st.push(c);
			else if (c == ch[i] && i % 2 == 1) {
				if (st.empty())
					return false;
				if (st.top() != ch[i - 1])
					return false;
				st.pop();
			}
		}
	}
	return st.empty() ? true : false;
}

REGISTER_FUNCTION(func20) {
#if 1
	string s = "()[]{}";
#endif
#if 0
	string s = "([])";
#endif
	cout << isValid(s) << endl;
}

// ---------------------- 1047. 删除字符串中的所有相邻重复项 ----------
string removeDuplicates(string s) {
	stack<char> st;
	string res;
	for (auto c : s) {
		if (!st.empty() && c == st.top())
			st.pop();
		else
			st.push(c);
	}
	//stack to string
	while (!st.empty()) {
		res = st.top() + res;
		st.pop();
	}
	return res;
}

REGISTER_FUNCTION(func1047) {
#if 1
	string s = "abbaca";
#endif
#if 0
	string s = "abcabc";
#endif
	cout << removeDuplicates(s) << endl;
}

// ------------------------- 150. 逆波兰表达式求值 --------------------
int evalRPN(vector<string>& tokens) {
	stack<int> st;
	string op[4] = {"+", "-", "*", "/"};
	for (auto str : tokens) {
		int i, a, b;
		for (i = 0; i < 4; i++) {
			if (str == op[i]) {
				a = st.top();
				st.pop();
				b = st.top();
				st.pop();
				break;
			}
		}
		if (i == 0)
			st.push(b + a);
		else if (i == 1)
			st.push(b - a);
		else if (i == 2)
			st.push(b * a);
		else if (i == 3)
			st.push(b / a);
		else
			st.push(stoi(str));
	}
	return st.top();
}

REGISTER_FUNCTION(func150) {
#if 0
	vector<string> tokens = {"2", "1", "+", "3", "*"};
#endif
#if 1
	vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
#endif
	cout << evalRPN(tokens) << endl;
}

// ------------------------ 239. 滑动窗口最大值 ------------------
int max_in_range(const std::vector<int>& nums, int i, int k) {
    if (i < 0 || i + k > nums.size()) {
        throw std::out_of_range("Invalid range");
    }

    int max_val = nums[i];
    for (int j = i + 1; j < i + k; ++j) {
        if (nums[j] > max_val) {
            max_val = nums[j];
        }
    }
    return max_val;
}

// 时间复杂度：O(n * k)
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	vector<int> res;
	for (int i = 0; i <= nums.size() - k; i++) {
		res.push_back(max_in_range(nums, i, k));
	}
	return res;
}

// 使用单调递减队列
/* 单调递减队列 */
class Myqueue {
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

vector<int> maxSlidingWindow_2(vector<int>& nums, int k) {
	Myqueue q;
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

REGISTER_FUNCTION(func239) {
#if 1
	vector<int> nums = {1,3,-1,-3,5,3,6,7};
	int k = 3;
#endif
	vector<int> res = maxSlidingWindow_2(nums, k);
	print_it(res);
}
