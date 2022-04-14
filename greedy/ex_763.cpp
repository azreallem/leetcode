#include <iostream>
#include <iterator>
#include <vector>
#include <unordered_map>
#include <set>
#include <numeric>

using namespace std;
namespace std {
	ostream& operator<<(ostream &os, vector<int> vec)
	{
		int n = vec.size();
		os << "{";
		for (int i = 0; i < n; i++) {
			if (i != n - 1)
				os << vec[i] << ", ";
			else
				os << vec[i];
		}
		os << "}";
		return os;
	}
}

vector<int> partitionLabels(string s)
{
	/* initalization */
	vector<int> res;
	unordered_map<char, int> str;
	for (auto c : s)
		str[c]++;
	
	set<char> v;
	int count = 0;
	for (auto c : s) {
		count++;
		v.insert(c);
		str[c]--;
		if (str[c] == 0)
			v.erase(c);
		if (v.size() == 0) {
			res.push_back(count);
			count = 0;
		}
	}

	return res;
}

int main()
{
	cout << partitionLabels("ababcbacadefegdehijhklij") << endl;
	return 0;
}
