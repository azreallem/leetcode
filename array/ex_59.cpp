/* https://zh.cppreference.com/w/cpp/container/vector
 * */

#include <iostream>
#include <vector>

using namespace std;

/* 输入: 3 输出: [ [ 1, 2, 3 ], [ 8, 9, 4 ], [ 7, 6, 5 ] ]
 * */
vector<vector<int>> func(int n)
{
    vector<vector<int>> res(n, vector<int>(n,0));
    int x, y; // res[x][y]
    int loop = 0;
    int offset = 1;
    int count = 1;

    for (; loop < n / 2; loop++) {
        offset += loop;
        x = loop;
        y = loop;
        // y : [loop...n-offset)
        for (; y < n - offset; y++) {
            res[x][y] = count++; 
        }
        //x : [loop...n-offset)
        for (; x < n - offset; x++) {
            res[x][y] = count++;
        }
        //y : [n-offset...loop)
        for (; y > loop; y--) {
            res[x][y] = count++;
        }
        for (; x > loop; x--) {
            res[x][y] = count++;
        }
    }
    // n = 3; res[1][1] = 3
    if (n % 2 == 1)
        res[loop][loop] = count;

    return res;
}

void print_v(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            cout << v[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    for (int i = 0; i < 10; i++) {
        cout << "-----------" << i << "---------------" <<endl;

        vector<vector<int>> v = func(i);

        //after
        print_v(v);
    }

    return 0;
}
