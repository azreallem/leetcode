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
 * function: copy_n(begin(v), n, iterator)
 * function: copy_if(begin(v), end(v), iterator, if)
 * head file: <algorithm>
 * */
namespace std {
	ostream& operator<<(ostream &os,const pair<int, string> &p)
	{
		return os << "(" << p.first << "," << p.second << ")";
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

	copy(v.begin(), v.end(), inserter(m, m.begin()));
	copy(m.begin(), m.end(), output_it);
	cout << endl;

	auto f = [](pair<int, string> a){ return a.first % 2 == 0; };
	copy_if(m.begin(), m.end(), output_it, f);
	cout << endl;
}


int main()
{
	//func_1_accumulate();
	//func_2_sort();
	func_3_copy();
	return 0;
}

