#include <iostream>
#include <vector>

using namespace std;


int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
{
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	int f[m][n];
	f[0][0] = 1;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (obstacleGrid[i][j] == 1)
				f[i][j] = 0;
			else if (i == 0 && j != 0) {
				f[i][j] = f[i][j - 1];
			}
			else if (j == 0 && i != 0) {
				f[i][j] = f[i - 1][j];
			}
			else if (i - 1 >= 0 && j - 1 >= 0) {
				f[i][j] = f[i - 1][j] + f[i][j - 1];
			}
		}
	}

	return f[m - 1][n - 1];
}


int main()
{
	vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
	cout << uniquePathsWithObstacles(obstacleGrid) << endl;
	return 0;
}
