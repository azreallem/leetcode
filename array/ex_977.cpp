/*
 * https://zh.cppreference.com/w/cpp/container/vector
 * */

#include <iostream>
#include <vector>

using namespace std;

inline int sq(int n)
{
    return n * n;
}

vector<int> sq_x(vector<int> v)
{
    int front = 0;
    int behind = v.size() - 1;
    vector<int> res(v);
    int pre = behind;

    while (pre>=0) {
        res[pre--] = sq(v[front]) > sq(v[behind]) ? \
                     sq(v[front++]) : sq(v[behind--]);
    }
    return res;
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

        vector<int> v {-i, i+1, i+2, -i+4, i+10};
        
        //before
        print_v(v);

        v = sq_x(v);

        //after
        print_v(v);
    }

    return 0;
}
