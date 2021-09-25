/*
 * https://zh.cppreference.com/w/cpp/container/vector
 * */

#include <iostream>
#include <vector>

using namespace std;

int func(vector<int> v)
{
    return 0;
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
        
        //before
        print_v(v);

        func(v);

        //after
        print_v(v);
    }

    return 0;
}
