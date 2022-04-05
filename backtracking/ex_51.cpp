#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

namespace std {
	template<typename T>
	ostream& operator<<(ostream &os, const vector<T> vec)
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

bool is_valid(const vector<string> char2_row, int n, int row, int col)
{
	// verdify col of every row
	for (int i = row - 1; i >= 0; i--) {
		if (char2_row[i][col] == 'Q')
			return false;
	}

	//45o
	int c45 = col + 1;
	for (int i = row - 1; i >= 0 && c45 < n; i--) {
		if (char2_row[i][c45++] == 'Q')
			return false;
	}
	
	//135o
	int c135 = col - 1;
	for (int i = row - 1; i >= 0 && c135 >= 0; i--) {
		if (char2_row[i][c135--] == 'Q')
			return false;
	}

	return true;
}

vector<vector<string>> res;
vector<string> path;
void backtracking(int n, int r)
{
	if (r == n) {
		res.push_back(path);
		return ;
	}
	
	for (int c = 0; c < n; c++) {
		if (!is_valid(path, n, r, c))
			continue;
		path[r][c] = 'Q';
		backtracking(n, r + 1);
		path[r][c] = '.';
	}
}

vector<vector<string>> combine(int n)
{
	res.clear();
	path.clear();
	path = vector<string>(n, (string(n,'.')));
	backtracking(n,0);
	return res; 
}


int main()
{
	int n = 4;
	vector<vector<string>> vec = combine(n);
	copy(vec.begin(), vec.end(), ostream_iterator<vector<string>>{cout,"\n"});
	return 0;
}


