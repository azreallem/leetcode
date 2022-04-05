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

bool is_valid(const vector<vector<char>> vec, char k, int row, int col)
{
	// row, col
	for (int i = 0; i < 9; i++) {
		if (vec[i][col] == k || vec[row][i] == k)
			return false;
	}
	
	// 3 x 3
	int r = row / 3;
	int c = col / 3;
	for (int offsetx = 0; offsetx < 3; offsetx++) {
		for (int offsety = 0; offsety < 3; offsety++) {
			if (vec[3 * r + offsetx][3 * c + offsety] == k)
				return false;
		}
	}
	return true;
}

bool backtracking(vector<vector<char>>& res)
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (res[i][j] != '.')
				continue;
			for (char k = '1'; k <= '9'; k++) {
				if (is_valid(res, k, i, j)) {
					res[i][j] = k;
					if(backtracking(res))
						return true;
					res[i][j] = '.';
				}
			}
			// 0-9 are not satisfied
			return false;
		}
	}
	return true;
}

vector<vector<char>> combine(vector<vector<char>> shudu)
{
	backtracking(shudu);
	return shudu;
}


int main()
{
	vector<vector<char>> shudu = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
	vector<vector<char>> vec = combine(shudu);
	copy(vec.begin(), vec.end(), ostream_iterator<vector<char>>{cout,"\n"});
	return 0;
}


