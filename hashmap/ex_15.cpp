#include <iostream>
#include <vector>
#include <unordered_map>
#include<algorithm>

using namespace std;

// 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
// 满足要求的三元组集合为： [ [-1, 0, 1], [-1, -1, 2] ]
vector<vector<int>> three_sum_zero(vector<int> v)
{
    vector<vector<int>> res;
    int i = 0;
    sort(v.begin(), v.end());

    for (i = 0; i < v.size() && v[i] < 0; i++) {
        if (i > 0 && v[i] == v[i-1])
            continue;
        int left = i + 1;
        int right = v.size() - 1;
        
        while(left < right) {
            if (v[i] + v[left] + v[right] < 0)
                left++;
            else if (v[i] + v[left] + v[right] > 0)
                right--;
            else {
                res.push_back(vector<int>{v[i], v[left], v[right]});
                while(left < right && v[left] == v[++left]) ;
                while(left < right && v[right] == v[--right]) ;
            }
        }
    }
    if (i + 3 <= v.size() && v[i] + v[i + 1] + v[i + 2] == 0)
        res.push_back(vector<int>{0, 0, 0});
    return res;
}


vector<vector<int>> three_sum_zero1(vector<int> v)
{
    vector<vector<int>> res;
    unordered_map<int ,int> u;
    vector<int> tmp;
    
    // 去重
    for (int i = 0; i < v.size(); i++) {
       if (u.count(v[i]) == 0) {
           u[v[i]] = 1;
           tmp.push_back(v[i]);
       }
       else
           u[v[i]]++;
    }

    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < tmp.size(); i++) {
            cout << tmp[i] << "\t";
        cout << endl;
    }

    for (int i = 0; i < tmp.size() && tmp[i] < 0; i++) {
        if (u[tmp[i]] >= 2 && u.count(0-tmp[i]*2) == 1) {
            res.push_back(vector<int>{tmp[i], tmp[i], 0-tmp[i]*2});
        }
        for (int j = i + 1; j < tmp.size(); j++) {
            int t3 = 0-tmp[i]-tmp[j];
            if ((u.count(t3) == 1 && tmp[j] < t3) || \
                    (u.count(t3) == 1 && tmp[j] == t3 &&u[t3] >= 2))
                    res.push_back(vector<int>{tmp[i], tmp[j], t3});
        }
    }
    
    if (u[0] >= 3)
        res.push_back(vector<int>{0, 0, 0});

    return res;
}

int main()
{
    vector<vector<int>> res;
    vector v = {-3,-3, -2,-2, -1, 0, 1, 2, 2,3, 3};
    //vector v = {-2, 1, 1};
    res = three_sum_zero(v);
    
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j <res[0].size(); j++)
            cout << res[i][j] << "\t";
        cout << endl;
    }

    return 0;
}
