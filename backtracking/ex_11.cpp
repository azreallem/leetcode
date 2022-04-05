#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

namespace std {
	ostream& operator<<(ostream &os, const vector<int> vec)
	{
		os << "[";
		for (int i = 0; i < vec.size(); i++) {
			os << vec[i];
			if (i != vec.size() - 1)
				os << ", ";
		}
		os << "]";
		return os;
	}
}


vector<string> res;
string path;



void backtracking(vector<string> str, int start_index)
{
	if (str.size() == 0)
		return ;
	if (path.size() == str.size()) {
		res.push_back(path);
		return ;
	}

	for (int i = 0; i <= str[start_index].size() - 1; i++) {
		path.push_back(str[start_index][i]);
		backtracking(str, start_index + 1);
		path.pop_back();
	}
}

vector<string> getabc(string str)
{
	vector<string> res;
	for (auto n : str) {
		switch (n) {
		case '2':
			res.push_back("abc");
			break;
		case '3':
			res.push_back("def");
			break;
		case '4':
			res.push_back("ghi");
			break;
		case '5':
			res.push_back("jkl");
			break;
		case '6':
			res.push_back("mno");
			break;
		case '7':
			res.push_back("pqrs");
			break;
		case '8':
			res.push_back("tuv");
			break;
		case '9':
			res.push_back("wxyz");
			break;
		default:
			break;
		}
	}
	return res;
}

vector<string> combine(string str)
{
	res.clear();
	path = "";
	vector<string> abc = getabc(str);
	backtracking(abc, 0);
	return res;
}


int main()
{
	vector<string> vec = combine("23");
	copy(vec.begin(), vec.end(), ostream_iterator<string>{cout,"\n"});
	return 0;
}


