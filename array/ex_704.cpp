/*
 * https://zh.cppreference.com/w/cpp/container/vector
 * */

#include <iostream>
#include <vector>

using namespace std;

int find_x(vector<int> v, int val)
{
    int left = 0;
    int right = v.size() - 1;
    int mid = (left + right) / 2;

    //find v[left, right]
    while (left <= right) {
        if(v[mid] == val)
            return mid;
        else if (v[mid] > val)
            right = mid - 1;
        else
            left = mid + 1;
        mid = (right + left) / 2;
    }

    return -1;
}

void print_v(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << "\t";
    cout << endl;
}

int main()
{
    for (int i = 0; i < 10; i++) {
        cout << "-----------" << i << "---------------" <<endl;

        vector<int> v {i, i+1, i+2, i+4, i+10};
        if(i %2 == 0)
            v.pop_back();

        //before
        print_v(v);

        cout<< "find 3 in:" << find_x(v, 3) <<endl;

        //after
        //print_v(v);
    }

    return 0;
}
