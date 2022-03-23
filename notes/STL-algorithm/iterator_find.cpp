#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

struct city {
	string name;
	unsigned int population;
};

bool operator==(const city &a, const city &b)
{
	return a.name == b.name && a.population == b.population;
}

ostream& operator<<(ostream &os, city &a)
{
	return os << "{ city:" << a.name << ", population:" << a.population << " }";
}

/* function: find(begin(v), end(v), type);
 * return:   iterator
 *
 * function: binary_search(begin(v), end(v), type);
 * return:   bool
 *
 * function: equal_range(begin(v), end(v), type);
 * return:   [lower_it, upper_it]
 *
 * function: lower_bound
 * return:   >= value
 * function: upper_bound
 * return:   > value
 * */

int main()
{
	vector<city> citys = {
		{"London", 125000},
		{"Beijing", 235000}
	};
	vector<city>::iterator it = find(begin(citys), end(citys), city{"London", 125000});
	if (it != end(citys))
		cout << *it << endl;
	else
		cout << "not found" << endl;
	auto it1 = find_if(begin(citys), end(citys), [](city a){ return a.name == "Anhui"; });
	if (it1 != end(citys))
		cout << *it1 << endl;
	else
		cout << "Anhui is not found." << endl;

	/* func2 */
	vector<int> v = {1,2,3,4,6,7,8,9,10};
	copy(begin(v), end(v), ostream_iterator<int>{cout, ", "});
	cout << endl;
	auto [lower_it, upper_it] = equal_range(begin(v), end(v), 6);
	if (binary_search(begin(v), end(v), 6))
		cout << *lower_it << "\t" << *upper_it << endl;


	return 0;
}
