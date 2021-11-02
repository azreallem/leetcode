#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 题目：
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 * 满足要求的四元组集合为： [ [-1, 0, 0, 1], [-2, -1, 1, 2], [-2, 0, 0, 2] ]
 * */
vector<vector<int>> four_nums_zero(vector<int> v, int target)
{
    vector<vector<int>> res;
    int i;
    sort(v.begin(), v.end());
    
    for (i = 0; i < v.size(); i++) {
        if (i > 0 && v[i] == v[i-1])
            continue;
        for (int j = i + 1; j < v.size(); j++) {
            if (j > i + 1 && v[j] == v[j - 1])
                continue;
            int left = j + 1;
            int right = v.size() - 1;
            while (left < right) {
    
                long t = v[i] + v[j];
                t += v[left] + v[right];
            
                if (t < target)
                    left++;
                else if (t > target)
                    right--;
                else {
                    res.push_back(vector<int>{v[i], v[j], v[left], v[right]});
                    while (left < right && v[left] == v[++left]) ;
                    while (left < right && v[right] == v[--right]) ;
                }
    
            }
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> res;
    vector v = {-5,-2,-1,0,2,2,4,4,4};
    //vector v = {-2, 1, 1};
    res = four_nums_zero(v, 12);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j <res[0].size(); j++)
            cout << res[i][j] << "\t";
        cout << endl;
    }

    return 0;
}
