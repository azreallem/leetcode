/*
 * https://zh.cppreference.com/w/cpp/container/vector
 * */

#include <iostream>
#include <vector>

using namespace std;

//s = 7, nums = [2,3,1,2,4,3] 
int small_length_sum(vector<int> v, int val)
{
    int pre = 0;
    int size = v.size();
    for (int i = 0; i < v.size(); i++) {
        val -= v[i];
    
        while (val <= 0 && val + v[pre] <= 0) {
            val += v[pre++];
        }
        if (val <= 0)
            size = (i - pre + 1) < size ? (i - pre + 1) : size;
    }
    if (val > 0)
        return 0;
    return size;
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

        vector<int> v {i, i+5, i+2, i+2, i+4, i+1};
        
        //before
        print_v(v);

        cout << small_length_sum(v, 7) << endl;

        //after
        //print_v(v);
    }

    return 0;
}
