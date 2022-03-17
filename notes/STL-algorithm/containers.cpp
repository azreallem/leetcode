#include <iostream>
#include <tuple>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

/* function: accumulate(begin(v), end(v), 0);
 * head file: <numeric>
 * */
void func_1_accumulate()
{
	vector<int> vec = {1,2,3,4,5};
	auto x = accumulate(vec.begin() + 2, vec.end(), 0);
	cout << x << endl;
}

/* function: sort(begin(v), begin(v), lambda)
 * head file: <algorithm>
 * */
void func_2_sort()
{
	vector<int> v = {1,7,3,4,5};
	auto f = [](int a, int b){ return a > b; };
	sort(v.begin(), v.end(), f);
	if (is_sorted(v.begin(), v.end(), f))
		cout << "vector sort." << endl;
	for (auto x : v)
		cout << x << '\t';
	cout << endl;
}

/* function: copy(begin(v), end(v), iterator)
 * function: reverse_copy(begin(v), end(v), iterator)
 * function: copy_n(begin(v), n, iterator)
 * function: copy_if(begin(v), end(v), iterator, if)
 * head file: <algorithm>
 * */
namespace std {
	ostream& operator<<(ostream &os,const pair<int, string> &p)
	{
		return os << "(" << p.first << "," << p.second << ")";
	}
	ostream& operator<<(ostream &os,const vector<int> &p)
	{
		for (auto x : p)
			os << x << '\t';
		return os;
	}
};

void func_3_copy()
{
	vector<pair<int, string>> v = { {1, "one"},
					{2, "two"},
					{3,  "three"},
					{4,  "four"}
				      };
	map<int, string> m;

	copy_n(begin(v), 3, inserter(m, begin(m)));

	auto output_it(ostream_iterator<pair<int, string>>{ cout, ", " });
	copy(m.begin(), m.end(), output_it);
	cout << endl;

	reverse_copy(m.rbegin(), m.rend(), output_it);
	cout << endl;

	copy(v.begin(), v.end(), inserter(m, m.begin()));
	copy(m.begin(), m.end(), output_it);
	cout << endl;

	auto f = [](pair<int, string> a){ return a.first % 2 == 0; };
	copy_if(m.begin(), m.end(), output_it, f);
	cout << endl;

	vector<int> vec = {1,2,3,4,5};
	copy(vec.begin(), vec.end(), ostream_iterator<int>{cout, ","});
	cout << endl;

	vector<vector<int>> vec1 = {{1,2,3,4,5},{2}};
	copy(vec1.begin(), vec1.end(), ostream_iterator<vector<int>>{cout,"\n"});

}

/* function: auto new_end(remove_if(begin(v), end(v), lambda))
 * function: v.erase(new_end, end(v))
 * */
void func_4_remove_if()
{
	vector<pair<int, string>> v = { {1, "one"},
					{2, "two"},
					{3,  "three"},
					{4,  "four"}
				      };
	auto f = [](pair<int, string> v){ return v.first % 2 == 1; };	
	vector<pair<int, string>>::iterator new_end = remove_if(v.begin(), v.end(), f);
	v.erase(new_end, v.end());
	copy(v.begin(), v.end(), ostream_iterator<pair<int, string>>{cout, ", "});
}

/* function: transform(begin(v), end(v), v, lambda)
 * notes: lambda type of return
 * */
void func_5_transform()
{
	vector<pair<int, string>> v1;
	vector<pair<int, string>> v = { {1, "one"},
					{2, "two"},
					{3,  "three"},
					{4,  "four"}
				      };
	auto f = [](pair<int, string> x){ return pair<int, string>{x.first + 1, x.second}; };
	transform(v.begin(), v.end(), inserter(v1, v1.begin()), f);
	copy(v1.begin(), v1.end(), ostream_iterator<pair<int, string>>{cout, ", "});

}

int main()
{
	//func_1_accumulate();
	//func_2_sort();
	//func_3_copy();
	//func_4_remove_if();
	func_5_transform();
	return 0;
}

